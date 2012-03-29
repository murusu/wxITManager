#include "wxITManagerDatabase.h"

DECLARE_APP(wxITManagerApp)

/////////////////////////////////////////////////////////////////
//
//
//
//
//
//
/////////////////////////////////////////////////////////////////
Database::Database(ManagerConfig *database_config)
{
    m_config = database_config;

    this->Connect(wxEVT_DATABASE_UPDATEREQUEST, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_QUERYREQUEST, wxDatabaseEventHandler(Database::OnRequest));
}

Database::~Database()
{
}

void Database::OnRequest(wxDatabaseEvent& event)
{
    bool check_flag = false;

    if(InitDBByConfig())
    {
        DatabaseProcessThread *database_thread = new DatabaseProcessThread(event.GetEventObject(), event.GetId(), this, event.GetSqlString(), event.GetEventType());

        if(database_thread->Create() == wxTHREAD_NO_ERROR)
        {
            database_thread->Run();
            check_flag = true;
        }
    }

    if(!check_flag)
    {
        wxEvtHandler *handler = wxGetApp().GetController(event.GetId());

        wxDatabaseEvent controller_event(wxEVT_DATABASE_UPDATEERROR);
        controller_event.SetEventObject(event.GetEventObject());
        handler->AddPendingEvent(controller_event);
    }
}

/*
void Database::OnDatabaseCreate(wxDatabaseEvent& event)
{
    bool check_flag = false;

    if(InitDBByConfig())
    {
        DatabaseUpdateThread *database_thread = new DatabaseUpdateThread(event.GetEventObject(), event.GetId(), this, GetDBTableInitStr());

        if(database_thread->Create() == wxTHREAD_NO_ERROR)
        {
            database_thread->Run();
            check_flag = true;
        }
    }

    if(!check_flag)
    {
        wxEvtHandler *handler = wxGetApp().GetController(event.GetId());

        wxDatabaseEvent controller_event(wxEVT_DATABASE_ERROR);
        controller_event.SetEventObject(event.GetEventObject());
        handler->AddPendingEvent(controller_event);
    }
}

void Database::OnDatabaseTest(wxDatabaseEvent& event)
{
    //no testing code, add later
    wxEvtHandler *handler = wxGetApp().GetController(event.GetId());

    wxDatabaseEvent controller_event(wxEVT_DATABASE_SUCCESS);
    controller_event.SetEventObject(event.GetEventObject());
    handler->AddPendingEvent(controller_event);
}
*/

/////////////////////////////////////////////////////////////////
//
//
//
//
//
//
/////////////////////////////////////////////////////////////////
DatabaseSqlite::DatabaseSqlite(ManagerConfig *database_config):Database(database_config)
{
}

DatabaseSqlite::~DatabaseSqlite()
{
    m_sqlitedb.Close();
}


wxString DatabaseSqlite::GetDBTableInitStr()
{
    wxString init_sql = wxT("");

    init_sql += wxT("CREATE TABLE `user`(id integer PRIMARY KEY, name varchar(30) UNIQUE, password varchar(50), group_id integer, vcard_id integer);");
    init_sql += wxT("CREATE TABLE `user_group`(id integer PRIMARY KEY, name varchar(30));");
    init_sql += wxT("CREATE TABLE `vcard`(id integer PRIMARY KEY, FN varchar(30), NICKNAME varchar(30), WORKTEL varchar(40), MOBILETEL varchar(40), EMAIL varchar(50), TITLE varchar(40), ORG varchar(50), VERSION varchar(20));");

    //init_sql += wxT("INSERT INTO `user` VALUES (NULL, `admin`, `21232f297a57a5a743894a0e4a801fc3`, 1, 1);");
    //init_sql += wxT("INSERT INTO `user_group` VALUES (NULL, `administrator`);");
    //init_sql += wxT("INSERT INTO `vcard` VALUES (NULL, `admin`, ``, ``, ``, ``, ``, `3.0`);");

    return init_sql;
}

wxString DatabaseSqlite::GetDBTestStr()
{
    wxString test_sql = wxT("");

    test_sql += wxT("select count(*) from sqlite_master WHERE type = 'table';");

    return test_sql;
}

bool DatabaseSqlite::InitDBByConfig()
{
    wxSQLite3Database::InitializeSQLite();

    try
    {
        m_sqlitedb.Open(m_config->GetDatabaseFile(), m_config->GetDatabaseKey());
    }
    catch(...)
    {
        return false;
    }

    return true;
}

size_t DatabaseSqlite::ExecuteUpdate(wxString sql_string)
{
    return m_sqlitedb.ExecuteUpdate(sql_string);
}

size_t DatabaseSqlite::ExecuteQuery(wxString sql_string)
{
    return 0;
}

DatabaseFactory::DatabaseFactory()
{
}

DatabaseFactory::~DatabaseFactory()
{
}

Database* DatabaseFactory::CreateDatabase(size_t database_type, ManagerConfig *database_config)
{
    switch(database_type)
    {
        case DATABASE_SQLITE:
            return new DatabaseSqlite(database_config);
            break;
    }

    return NULL;
}
