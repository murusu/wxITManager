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

    this->Connect(wxEVT_DATABASE_CREATEDATABSE, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_TESTDATABSE, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_USERLOGIN, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_GETUSERLIST, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_GETUSERGROUPLIST, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_DELETEUSER, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_ADDUSER, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_UPDATEUSER, wxDatabaseEventHandler(Database::OnRequest));
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

        wxDatabaseEvent controller_event(event.GetEventType());
        controller_event.SetStatus(EVENTSTATUS_FAIL);
        controller_event.SetEventObject(event.GetEventObject());
        handler->AddPendingEvent(controller_event);
    }
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
    wxString init_sql = wxT("");

    init_sql += wxT("CREATE TABLE `user`(id integer PRIMARY KEY, name varchar(30) UNIQUE, password varchar(50), group_id integer, vaild bool);");
    init_sql += wxT("CREATE TABLE `user_group`(id integer PRIMARY KEY, name varchar(30));");
    init_sql += wxT("CREATE TABLE `vcard`(id integer PRIMARY KEY, FN varchar(30), NICKNAME varchar(30), WORKTEL varchar(40), MOBILETEL varchar(40), EMAIL varchar(50), TITLE varchar(40), ORG varchar(50), VERSION varchar(20));");

    init_sql += wxT("INSERT INTO 'user' VALUES (NULL, 'admin', '21232f297a57a5a743894a0e4a801fc3', 1, 1);");
    init_sql += wxT("INSERT INTO 'user_group' VALUES (NULL, 'administrator');");
    //init_sql += wxT("INSERT INTO 'vcard' VALUES (NULL, `admin`, ``, ``, ``, ``, ``, `3.0`);");

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

wxJSONValue DatabaseSqlite::ExecuteQuery(wxString sql_string)
{
    wxJSONValue result_json;

    wxSQLite3ResultSet dataset = m_sqlitedb.ExecuteQuery(sql_string);
    size_t colnum = dataset.GetColumnCount();
    size_t count = 0;

	while (dataset.NextRow())
	{
		for(size_t index = 0; index < colnum; index++ )
		{
		    result_json[count][index] = dataset.GetAsString(index);
		}

		count++;
	}

	dataset.Finalize();

    return result_json;
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
