#include "wxITManagerMain.h"

IMPLEMENT_APP(wxITManagerApp)

bool wxITManagerApp::OnInit(void)
{
    m_locale        = NULL;
    m_mainframe     = NULL;
    m_loginframe    = NULL;
    m_config        = NULL;
    m_database      = NULL;

    m_config = new ManagerConfig();
    //if(!m_config->InitConfig()) return false;
    //Database* mydatabase = DatabaseFactory::CreateDatabase(DATABASE_SQLITE);
    //mydatabase->InitDatabase(m_config);
    //mydatabase->SetupTable();

    //delete mydatabase;

    m_loginframe = new LoginFrame(NULL);
    m_loginframe->Show(true);

    SetupLocale();
/*
wxSQLite3Database::InitializeSQLite();
wxSQLite3Database db;
db.Open(wxT("test.db"), wxT("wecanfly"));
db.ExecuteUpdate("create table emp(empno integer primary key, empname char(20), salary double);");
wxString insertCmd(wxT("insert into emp values (null,'Franz Beckenbauer', 2000.10);"));
db.ExecuteUpdate(insertCmd);
db.Close();
*/
    return true;
}

int wxITManagerApp::OnExit()
{
    if(m_locale)        delete m_locale;
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
