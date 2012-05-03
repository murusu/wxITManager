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
    this->Connect(wxEVT_DATABASE_DELETEUSER, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_ADDUSER, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_UPDATEUSER, wxDatabaseEventHandler(Database::OnRequest));

    this->Connect(wxEVT_DATABASE_GETUSERGROUPLIST, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_DELETEUSERGROUP, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_ADDUSERGROUP, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_UPDATEUSERGROUP, wxDatabaseEventHandler(Database::OnRequest));

    this->Connect(wxEVT_DATABASE_GETVCARDLIST, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_DELETEVCARD, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_ADDVCARD, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_UPDATEVCARD, wxDatabaseEventHandler(Database::OnRequest));

    this->Connect(wxEVT_DATABASE_GETVCARDGROUPLIST, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_DELETEVCARDGROUP, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_ADDVCARDGROUP, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_UPDATEVCARDGROUP, wxDatabaseEventHandler(Database::OnRequest));

    this->Connect(wxEVT_DATABASE_GETCOMPANYLIST, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_DELETECOMPANY, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_ADDCOMPANY, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_UPDATECOMPANY, wxDatabaseEventHandler(Database::OnRequest));

    this->Connect(wxEVT_DATABASE_GETCOMPANYTYPELIST, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_DELETECOMPANYTYPE, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_ADDCOMPANYTYPE, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_UPDATECOMPANYTYPE, wxDatabaseEventHandler(Database::OnRequest));

    this->Connect(wxEVT_DATABASE_GETLOCATIONLIST, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_DELETELOCATION, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_ADDLOCATION, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_UPDATELOCATION, wxDatabaseEventHandler(Database::OnRequest));

    this->Connect(wxEVT_DATABASE_GETRESOURCELIST, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_DELETERESOURCE, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_ADDRESOURCE, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_UPDATERESOURCE, wxDatabaseEventHandler(Database::OnRequest));

    this->Connect(wxEVT_DATABASE_GETRESOURCETYPELIST, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_DELETERESOURCETYPE, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_ADDRESOURCETYPE, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_UPDATERESOURCETYPE, wxDatabaseEventHandler(Database::OnRequest));

    this->Connect(wxEVT_DATABASE_GETRESOURCESTATUSLIST, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_DELETERESOURCESTATUS, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_ADDRESOURCESTATUS, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_UPDATERESOURCESTATUS, wxDatabaseEventHandler(Database::OnRequest));

    this->Connect(wxEVT_DATABASE_GETRESOURCEFEETYPELIST, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_DELETERESOURCEFEETYPE, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_ADDRESOURCEFEETYPE, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_UPDATERESOURCEFEETYPE, wxDatabaseEventHandler(Database::OnRequest));

    this->Connect(wxEVT_DATABASE_GETRESOURCEDEPLOYLIST, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_DELETERESOURCEDEPLOY, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_ADDRESOURCEDEPLOY, wxDatabaseEventHandler(Database::OnRequest));
    this->Connect(wxEVT_DATABASE_UPDATERESOURCEDEPLOY, wxDatabaseEventHandler(Database::OnRequest));
}

Database::~Database()
{
}

void Database::OnRequest(wxDatabaseEvent& event)
{
    bool check_flag = false;

    //if(InitDBByConfig())
    //{
    DatabaseProcessThread *database_thread = new DatabaseProcessThread(event.GetEventObject(), event.GetId(), this, event.GetSqlString(), event.GetEventType(), event.GetSqlType());

    if(database_thread->Create() == wxTHREAD_NO_ERROR)
    {
        database_thread->Run();
        check_flag = true;
    }
    //}

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

    init_sql += wxT("CREATE TABLE `datbase_info` (id INTEGER PRIMARY KEY, name VARCHAR, value INTEGER);");
    init_sql += wxT("CREATE TABLE `user`(id INTEGER PRIMARY KEY, name VARCHAR, password VARCHAR, group_id INTEGER, valid bool DEFAULT 1);");
    init_sql += wxT("CREATE TABLE `user_group`(id INTEGER PRIMARY KEY, name VARCHAR, valid bool DEFAULT 1);");
    init_sql += wxT("CREATE TABLE `vcard`(id INTEGER PRIMARY KEY, fullname VARCHAR, nickname VARCHAR, work_phone varchar, mobie_phone varchar, email varchar, title varchar, company varchar, valid bool DEFAULT 1);");
    init_sql += wxT("CREATE TABLE `vcard_group`(id INTEGER PRIMARY KEY, name VARCHAR, valid BOOL DEFAULT 1);");
    init_sql += wxT("CREATE TABLE `company` (id INTEGER PRIMARY KEY, name VARCHAR, companytype_id INTEGER, valid BOOL DEFAULT 1);");
    init_sql += wxT("CREATE TABLE `company_type` (id INTEGER PRIMARY KEY, name VARCHAR, valid BOOL DEFAULT 1);");
    init_sql += wxT("CREATE TABLE `location` (id INTEGER PRIMARY KEY, name VARCHAR, valid BOOL DEFAULT 1);");
    init_sql += wxT("CREATE TABLE `resource` (id INTEGER PRIMARY KEY, name VARCHAR, resourcetype_id INTEGER, pattern VARCHAR, weight INTEGER, valid BOOL DEFAULT 1);");
    init_sql += wxT("CREATE TABLE `resource_type` (id INTEGER PRIMARY KEY, name VARCHAR, valid BOOL DEFAULT 1);");
    init_sql += wxT("CREATE TABLE `resource_status` (id INTEGER PRIMARY KEY, name VARCHAR, available BOOL DEFAULT 1, valid BOOL DEFAULT 1);");
    init_sql += wxT("CREATE TABLE `resource_feetype` (id INTEGER PRIMARY KEY, name VARCHAR, have_expiration BOOL DEFAULT 0, valid BOOL DEFAULT 1);");
    init_sql += wxT("CREATE TABLE `resource_deploy` (id INTEGER PRIMARY KEY, system_code VARCHAR, code VARCHAR, resource_id INTEGER, resourcestatus_id INTEGER, location_id INTEGER, vcard_id INTEGER, parentdeploy_id INTEGER, remark VARCHAR, valid INTEGER);");

    init_sql += wxT("INSERT INTO 'user' ('name','password','group_id') VALUES ('admin','admin',1);");
    init_sql += wxT("INSERT INTO 'user_group' ('name') VALUES ('administrator');");
    init_sql += wxT("INSERT INTO 'datbase_info' ('name', value) VALUES ('version', ") + wxString::Format(wxT("%d"), DATABASE_VERSION) + wxT(");");

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
