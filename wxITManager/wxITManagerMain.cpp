#include "wxITManagerMain.h"

IMPLEMENT_APP(wxITManagerApp)

bool wxITManagerApp::OnInit(void)
{
    m_locale        = NULL;
    m_mainframe     = NULL;
    m_loginframe    = NULL;

    m_config        = NULL;
    m_database      = NULL;

    m_dbcontroller      = NULL;
    m_usercontroller    = NULL;

    SetupLocale();

    //m_config = new ManagerConfig();
    //m_dbcontroller = new DatabaseController();
    //if(!m_config->InitConfig()) return false;
    //Database* mydatabase = DatabaseFactory::CreateDatabase(DATABASE_SQLITE);
    //mydatabase->InitDatabase(m_config);
    //mydatabase->SetupTable();

    //delete mydatabase;

    m_loginframe = new LoginFrame(NULL);
    m_loginframe->Show(true);


/*
wxSQLite3Database::InitializeSQLite();
wxSQLite3Database db;
db.Open(wxT("test.db"));
db.ExecuteUpdate("create table emp(empno integer primary key, empname char(20), salary double);create table test(testno integer primary key, empname char(20), salary double);");
wxString insertCmd(wxT("insert into emp values (null,'Franz Beckenbauer', 2000.10);insert into emp values (null,'test test', 2011.11);"));
db.ExecuteUpdate(insertCmd);
db.Close();
*/
    return true;
}

int wxITManagerApp::OnExit()
{
    if(m_locale)    delete m_locale;
    if(m_config)    delete m_config;
    if(m_database)  delete m_database;

    if(m_dbcontroller) delete m_dbcontroller;
    if(m_usercontroller) delete m_usercontroller;
    //if(m_mainframe)     delete m_mainframe;
    //if(m_loginframe)    delete m_loginframe;
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

        case CONTROLLER_USER:
            if(!m_usercontroller) m_usercontroller = new UserController();
            handler = m_usercontroller;
            break;
    }

    return handler;
}
