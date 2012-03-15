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

    this->Connect(wxEVT_DATABASE_CREATE, wxDatabaseEventHandler(Database::OnDatabaseCreate));
    this->Connect(wxEVT_DATABASE_TEST, wxDatabaseEventHandler(Database::OnDatabaseTest));
}

Database::~Database()
{
}

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

        wxDatabaseEvent controller_event(wxEVT_DATABASE_CREATE_ERROR);
        controller_event.SetEventObject(event.GetEventObject());
        handler->AddPendingEvent(controller_event);
    }
}

void Database::OnDatabaseTest(wxDatabaseEvent& event)
{
    //no testing code, add later
    wxEvtHandler *handler = wxGetApp().GetController(event.GetId());

    wxDatabaseEvent controller_event(wxEVT_DATABASE_TEST_SUCCESS);
    controller_event.SetEventObject(event.GetEventObject());
    handler->AddPendingEvent(controller_event);
}

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
    //wxString update_sql = wxT("DROP TABLE `user`;" + "DROP TABLE `user_group`;");// +
                          //wxString("DROP TABLE `user_group`;") +
                          //wxT("DROP TABLE `vcard`;") +
                          //wxT("CREATE TABLE `user`(id integer PRIMARY KEY, name varchar(30) UNIQUE, password varchar(50), group_id integer, vcard_id integer);") +
                          //wxT("CREATE TABLE `user_group`(id integer PRIMARY KEY, name varchar(30));") +
                          //wxT("CREATE TABLE `vcard`(id integer PRIMARY KEY, FN varchar(30), NICKNAME varchar(30), TEL varchar(40), EMAIL varchar(50), TITLE varchar(40), ORG varchar(50), VERSION varchar(20));");
    wxString init_sql = wxT("");

    //init_sql += wxString::Format(wxT("DROP TABLE `user`;"));
    //init_sql += wxString::Format(wxT("DROP TABLE `user_group`;"));
    //init_sql += wxString::Format(wxT("DROP TABLE `vcard`;"));
    //init_sql += wxString::Format(wxT("CREATE TABLE `user`(id integer PRIMARY KEY, name varchar(30) UNIQUE, password varchar(50), group_id integer, vcard_id integer);"));
    //init_sql += wxString::Format(wxT("CREATE TABLE `user_group`(id integer PRIMARY KEY, name varchar(30));"));
    //init_sql += wxString::Format(wxT("CREATE TABLE `vcard`(id integer PRIMARY KEY, FN varchar(30), NICKNAME varchar(30), TEL varchar(40), EMAIL varchar(50), TITLE varchar(40), ORG varchar(50), VERSION varchar(20));"));

    //init_sql += wxT("DROP TABLE `user`;");
    //init_sql += wxT("DROP TABLE `user_group`;");
    //init_sql += wxT("DROP TABLE `vcard`;");

    init_sql += wxT("CREATE TABLE `user`(id integer PRIMARY KEY, name varchar(30) UNIQUE, password varchar(50), group_id integer, vcard_id integer);");
    init_sql += wxT("CREATE TABLE `user_group`(id integer PRIMARY KEY, name varchar(30));");
    init_sql += wxT("CREATE TABLE `vcard`(id integer PRIMARY KEY, FN varchar(30), NICKNAME varchar(30), TEL varchar(40), EMAIL varchar(50), TITLE varchar(40), ORG varchar(50), VERSION varchar(20));");

    //init_sql += wxT("INSERT INTO `user` VALUES (NULL, `admin`, `21232f297a57a5a743894a0e4a801fc3`, 1, 1);");
    //init_sql += wxT("INSERT INTO `user_group` VALUES (NULL, `administrator`);");
    //init_sql += wxT("INSERT INTO `vcard` VALUES (NULL, `admin`, ``, ``, ``, ``, ``, `3.0`);");

    return init_sql;
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
