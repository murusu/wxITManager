#include "wxITManagerMain.h"

IMPLEMENT_APP(wxITManagerApp)

bool wxITManagerApp::OnInit(void)
{
    m_locale        = NULL;
    m_mainframe     = NULL;
    m_loginframe    = NULL;

    m_config        = NULL;
    m_database      = NULL;

    m_dbcontroller          = NULL;
    m_authcontroller        = NULL;

    m_usercontroller        = NULL;
    m_usergroupcontroller   = NULL;

    m_vcardcontroller       = NULL;
    m_vcardgroupcontroller  = NULL;
    m_companycontroller     = NULL;
    m_companytypecontroller = NULL;
    m_locationcontroller    = NULL;

    m_resourcecontroller        = NULL;
    m_resourcetypecontroller    = NULL;
    m_resourcestatuscontroller  = NULL;
    m_resourcefeetypecontroller = NULL;

    m_resourcedepolycontroller  = NULL;

    SetupLocale();

    m_loginframe = new LoginFrame(NULL);
    m_loginframe->Show(true);

    return true;
}

int wxITManagerApp::OnExit()
{
    if(m_locale)    delete m_locale;
    if(m_config)    delete m_config;
    if(m_database)  delete m_database;

    if(m_dbcontroller) delete m_dbcontroller;
    if(m_authcontroller) delete m_authcontroller;

    if(m_usercontroller) delete m_usercontroller;
    if(m_usergroupcontroller) delete m_usergroupcontroller;

    if(m_vcardcontroller) delete m_vcardcontroller;
    if(m_vcardgroupcontroller) delete m_vcardgroupcontroller;
    if(m_companycontroller) delete m_companycontroller;
    if(m_companytypecontroller) delete m_companytypecontroller;
    if(m_locationcontroller) delete m_locationcontroller;

    if(m_resourcecontroller) delete m_resourcecontroller;
    if(m_resourcetypecontroller) delete m_resourcetypecontroller;
    if(m_resourcestatuscontroller) delete m_resourcestatuscontroller;
    if(m_resourcefeetypecontroller) delete m_resourcefeetypecontroller;

    if(m_resourcedepolycontroller) delete m_resourcedepolycontroller;

    return 0;
}

void wxITManagerApp::SetupLocale()
{
    m_locale = new wxLocale();
    m_locale->Init();

    m_locale->AddCatalogLookupPathPrefix(wxT("./lng"));
    m_locale->AddCatalog(m_locale->GetCanonicalName());
}

void wxITManagerApp::DoLogin()
{
    if(!m_mainframe) m_mainframe = new MainFrame(m_loginframe);

    m_loginframe->Show(false);
    m_mainframe->Show(true);
}

void wxITManagerApp::DoLogout()
{
    m_loginframe->Show(true);
    m_mainframe->Show(false);
}

void wxITManagerApp::DoExit()
{
    m_loginframe->Destroy();
}

ManagerConfig* wxITManagerApp::GetConfig()
{
    if(!m_config) m_config = new ManagerConfig();

    if(!(m_config->ReadConfigData()))
    {
        delete m_config;
        m_config = NULL;
    }

    return m_config;
}

Database* wxITManagerApp::GetDatabase()
{
    if(!m_database)
    {
        m_database = DatabaseFactory::CreateDatabase(GetConfig()->GetDatabaseType(), GetConfig());
        if(!m_database->InitDBByConfig())
        {
            delete m_database;
            m_database = NULL;
        }
    }

    return m_database;
}

wxEvtHandler* wxITManagerApp::GetController(size_t controller_id)
{
    wxEvtHandler* handler = NULL;

    switch(controller_id)
    {
        case CONTROLLER_DATABASE:
            if(!m_dbcontroller) m_dbcontroller = new DatabaseController();
            handler = m_dbcontroller;
            break;

        case CONTROLLER_AUTH:
            if(!m_authcontroller) m_authcontroller = new AuthorityController();
            handler = m_authcontroller;
            break;

        case CONTROLLER_USER:
            if(!m_usercontroller) m_usercontroller = new UserController();
            handler = m_usercontroller;
            break;

        case CONTROLLER_USERGROUP:
            if(!m_usergroupcontroller) m_usergroupcontroller = new UserGroupController();
            handler = m_usergroupcontroller;
            break;

        case CONTROLLER_VCARD:
            if(!m_vcardcontroller) m_vcardcontroller = new VcardController();
            handler = m_vcardcontroller;
            break;

        case CONTROLLER_VCARDGROUP:
            if(!m_vcardgroupcontroller) m_vcardgroupcontroller = new VcardGroupController();
            handler = m_vcardgroupcontroller;
            break;

        case CONTROLLER_COMPANY:
            if(!m_companycontroller) m_companycontroller = new CompanyController();
            handler = m_companycontroller;
            break;

        case CONTROLLER_COMPANYTYPE:
            if(!m_companytypecontroller) m_companytypecontroller = new CompanyTypeController();
            handler = m_companytypecontroller;
            break;

        case CONTROLLER_LOCATION:
            if(!m_locationcontroller) m_locationcontroller = new LocationController();
            handler = m_locationcontroller;
            break;

        case CONTROLLER_RESOURCE:
            if(!m_resourcecontroller) m_resourcecontroller = new ResourceController();
            handler = m_resourcecontroller;
            break;

        case CONTROLLER_RESOURCETYPE:
            if(!m_resourcetypecontroller) m_resourcetypecontroller = new ResourceTypeController();
            handler = m_resourcetypecontroller;
            break;

        case CONTROLLER_RESOURCESTATUS:
            if(!m_resourcestatuscontroller) m_resourcestatuscontroller = new ResourceStatusController();
            handler = m_resourcestatuscontroller;
            break;

        case CONTROLLER_RESOURCEFEETYPE:
            if(!m_resourcefeetypecontroller) m_resourcefeetypecontroller = new ResourceFeeTypeController();
            handler = m_resourcefeetypecontroller;
            break;

        case CONTROLLER_RESOURCEDEPOLY:
            if(!m_resourcedepolycontroller) m_resourcedepolycontroller = new ResourceDepolyController();
            handler = m_resourcedepolycontroller;
            break;
    }

    return handler;
}
