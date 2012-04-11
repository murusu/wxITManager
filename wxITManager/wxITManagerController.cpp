#include "wxITManagerController.h"

DECLARE_APP(wxITManagerApp)

DEFINE_EVENT_TYPE(wxEVT_DATABASE_CREATEDATABSE)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_TESTDATABSE)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_USERLOGIN)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_GETUSERLIST)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_ADDUSER)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_DELETEUSER)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_UPDATEUSER)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_GETUSERGROUPLIST)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_ADDUSERGROUP)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_DELETEUSERGROUP)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_UPDATEUSERGROUP)


IMPLEMENT_DYNAMIC_CLASS(wxDatabaseEvent, wxNotifyEvent)

DatabaseController::DatabaseController()
{
    m_database  = NULL;
    m_config    = NULL;
    m_locker    = NULL;
    m_mutex     = new wxMutex();

    m_config = new ManagerConfig();

    this->Connect(wxEVT_DATABASE_CREATEDATABSE, wxDatabaseEventHandler(DatabaseController::OnDatabaseEvent));
    this->Connect(wxEVT_DATABASE_TESTDATABSE, wxDatabaseEventHandler(DatabaseController::OnDatabaseEvent));
}

DatabaseController::~DatabaseController()
{
    if(m_database) delete m_database;
    if(m_config) delete m_config;
    if(m_locker) delete m_locker;
    if(m_mutex)  delete m_mutex;
}

void DatabaseController::OnDatabaseEvent(wxDatabaseEvent& event)
{
    if(event.GetStatus() == EVENTSTATUS_REQUEST)
    {
        OnDatabaseRequest(event);
    }
    else
    {
        OnDatabaseResponse(event);
    }
}

void DatabaseController::OnDatabaseResponse(wxDatabaseEvent& event)
{
    if(m_locker) delete m_locker;
    if(m_database) delete m_database;
    m_database = NULL;
    m_locker = NULL;

    wxDatabaseEvent controller_event(event.GetEventType());
    controller_event.SetStatus(event.GetStatus());
    controller_event.SetErrorString(event.GetErrorString());
    controller_event.SetResultRow(event.GetResultRow());
    controller_event.SetJsonData(event.GetJsonData());
    ((wxEvtHandler *)event.GetEventObject())->AddPendingEvent(controller_event);
}

void DatabaseController::OnDatabaseRequest(wxDatabaseEvent& event)
{
    m_locker = new wxMutexLocker(*m_mutex);

    if(m_locker->IsOk())
    {
        m_database = DatabaseFactory::CreateDatabase(m_config->GetDatabaseType(), m_config);

        wxDatabaseEvent controller_event;
        controller_event.SetEventType(event.GetEventType());

        if(event.GetEventType() == wxEVT_DATABASE_CREATEDATABSE)
        {
            controller_event.SetSqlString(m_database->GetDBTableInitStr());
            controller_event.SetSqlType(SQLTYPE_UPDATE);
        }

        if(event.GetEventType() == wxEVT_DATABASE_TESTDATABSE)
        {
            controller_event.SetSqlString(m_database->GetDBTestStr());
            controller_event.SetSqlType(SQLTYPE_QUERY);
        }

        controller_event.SetEventObject(event.GetEventObject());
        controller_event.SetStatus(event.GetStatus());
        controller_event.SetId(event.GetId());
        m_database->AddPendingEvent(controller_event);
    }
    else
    {
        ::wxMilliSleep(100);

        wxDatabaseEvent controller_event(event.GetEventType());
        controller_event.SetStatus(event.GetStatus());
        controller_event.SetId(event.GetId());
        controller_event.SetEventObject(event.GetEventObject());
        this->AddPendingEvent(controller_event);
    }
}

AuthorityController::AuthorityController()
{
    Clear();

    this->Connect(wxEVT_DATABASE_USERLOGIN, wxDatabaseEventHandler(AuthorityController::OnDatabaseEvent));
}

void AuthorityController::OnDatabaseEvent(wxDatabaseEvent& event)
{
    if(event.GetStatus() == EVENTSTATUS_REQUEST)
    {
        OnDatabaseRequest(event);
    }
    else
    {
        OnDatabaseResponse(event);
    }
}

void AuthorityController::OnDatabaseRequest(wxDatabaseEvent& event)
{
    wxEventType event_type = event.GetEventType();

    wxDatabaseEvent controller_event;
    controller_event.SetEventType(event_type);

    if(event_type == wxEVT_DATABASE_USERLOGIN)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        sql_str += wxT("SELECT a.id, a.name, a.group_id, b.name as group_name FROM 'user' a JOIN 'user_group' b ON a.group_id = b.id WHERE a.vaild = 1 AND a.name = '");
        sql_str += request_data[0].AsString();
        sql_str += wxT("' AND a.password ='");
        sql_str += request_data[1].AsString();
        sql_str += wxT("'");

        controller_event.SetSqlString(sql_str);
        controller_event.SetSqlType(SQLTYPE_QUERY);
    }

    controller_event.SetEventObject(event.GetEventObject());
    controller_event.SetStatus(event.GetStatus());
    controller_event.SetId(event.GetId());
    (wxGetApp().GetDatabase())->AddPendingEvent(controller_event);
}

void AuthorityController::OnDatabaseResponse(wxDatabaseEvent& event)
{
    if(event.GetEventType() == wxEVT_DATABASE_USERLOGIN)
    {
        wxJSONValue result_data = event.GetJsonData();

        m_id            = wxAtoi(result_data[0][0].AsString());
        m_name          = result_data[1][0].AsString();
        m_usergroupid   = wxAtoi(result_data[2][0].AsString());
        m_usergroupname = result_data[3][0].AsString();
    }

    wxDatabaseEvent controller_event(event.GetEventType());
    controller_event.SetStatus(event.GetStatus());
    controller_event.SetErrorString(event.GetErrorString());
    controller_event.SetResultRow(event.GetResultRow());
    controller_event.SetJsonData(event.GetJsonData());
    ((wxEvtHandler *)event.GetEventObject())->AddPendingEvent(controller_event);
}



UserController::UserController()
{
    //m_currentuser   = NULL;
    m_userlist      = new UserInfoArray();

    this->Connect(wxEVT_DATABASE_GETUSERLIST, wxDatabaseEventHandler(UserController::OnDatabaseEvent));
    this->Connect(wxEVT_DATABASE_DELETEUSER, wxDatabaseEventHandler(UserController::OnDatabaseEvent));
    this->Connect(wxEVT_DATABASE_ADDUSER, wxDatabaseEventHandler(UserController::OnDatabaseEvent));
    this->Connect(wxEVT_DATABASE_UPDATEUSER, wxDatabaseEventHandler(UserController::OnDatabaseEvent));
}

UserController::~UserController()
{
    m_userlist->Clear();

    if(m_userlist) delete m_userlist;
    //if(m_currentuser) delete m_currentuser;
}
/*
void UserController::OnUserLogin(wxDatabaseEvent& event)
{
    if(event.GetStatus() == EVENTSTATUS_REQUEST)
    {
        wxDatabaseEvent controller_event;
        controller_event.SetEventType(event.GetEventType());
        controller_event.SetSqlString(wxT("SELECT * FROM 'user';"));
        controller_event.SetEventObject(event.GetEventObject());
        controller_event.SetStatus(EVENTSTATUS_REQUEST);
        controller_event.SetId(CONTROLLER_USER);
        (wxGetApp().GetDatabase())->AddPendingEvent(controller_event);
    }
    else
    {
        wxDatabaseEvent controller_event(event.GetEventType());
        controller_event.SetStatus(event.GetStatus());
        controller_event.SetErrorString(event.GetErrorString());
        controller_event.SetResultRow(event.GetResultRow());
        controller_event.SetJsonData(event.GetJsonData());
        ((wxEvtHandler *)event.GetEventObject())->AddPendingEvent(controller_event);
    }
}

void UserController::OnGetUserList(wxDatabaseEvent& event)
{
    if(event.GetStatus() == EVENTSTATUS_REQUEST)
    {
        wxDatabaseEvent controller_event(event.GetEventType());
        controller_event.SetSqlString(wxT("SELECT a.id, a.name, a.group_id, b.name as group_name FROM 'user' a JOIN 'user_group' b ON a.group_id = b.id WHERE a.vaild = 1;"));
        controller_event.SetEventObject(event.GetEventObject());
        controller_event.SetStatus(EVENTSTATUS_REQUEST);
        controller_event.SetId(CONTROLLER_USER);
        (wxGetApp().GetDatabase())->AddPendingEvent(controller_event);
    }
    else
    {
        m_userlist->Clear();

        wxJSONValue result_data = event.GetJsonData();
        for ( int i = 0; i < result_data.Size(); i++ )
        {
            m_userlist->Add(UserInfo(wxAtoi(result_data[i][0].AsString()), result_data[i][1].AsString(), wxAtoi(result_data[i][2].AsString()), result_data[i][3].AsString()));
        }

        wxDatabaseEvent controller_event(event.GetEventType());
        controller_event.SetStatus(event.GetStatus());
        ((wxEvtHandler *)event.GetEventObject())->AddPendingEvent(controller_event);
    }
}

void UserController::OnAddUser(wxDatabaseEvent& event)
{
    if(event.GetStatus() == EVENTSTATUS_REQUEST)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        sql_str += wxT("INSERT INTO 'user' ('name','password','group_id') VALUES ('");
        sql_str += request_data[0].AsString();
        sql_str += wxT("','");
        sql_str += request_data[1].AsString();
        sql_str += wxT("',");
        sql_str += request_data[2].AsString();
        sql_str += wxT(")");

        wxDatabaseEvent controller_event(event.GetEventType());
        controller_event.SetSqlString(sql_str);
        controller_event.SetEventObject(event.GetEventObject());
        controller_event.SetStatus(EVENTSTATUS_REQUEST);
        controller_event.SetId(CONTROLLER_USER);
        (wxGetApp().GetDatabase())->AddPendingEvent(controller_event);
    }
    else
    {
        wxDatabaseEvent controller_event(event.GetEventType());
        controller_event.SetStatus(event.GetStatus());
        ((wxEvtHandler *)event.GetEventObject())->AddPendingEvent(controller_event);
    }
}

void UserController::OnDeleteUser(wxDatabaseEvent& event)
{
    if(event.GetStatus() == EVENTSTATUS_REQUEST)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        for ( int i = 0; i < request_data.Size(); i++ )
        {
            sql_str += wxT("DELETE FROM 'user' WHERE id = ");
            sql_str += request_data[i].AsString();
            sql_str += wxT(";");
        }

        wxDatabaseEvent controller_event(event.GetEventType());
        controller_event.SetSqlString(sql_str);
        controller_event.SetEventObject(event.GetEventObject());
        controller_event.SetStatus(EVENTSTATUS_REQUEST);
        controller_event.SetId(CONTROLLER_USER);
        (wxGetApp().GetDatabase())->AddPendingEvent(controller_event);
    }
    else
    {
        wxDatabaseEvent controller_event(event.GetEventType());
        controller_event.SetStatus(event.GetStatus());
        ((wxEvtHandler *)event.GetEventObject())->AddPendingEvent(controller_event);
    }
}

void UserController::OnUpdateUser(wxDatabaseEvent& event)
{
    if(event.GetStatus() == EVENTSTATUS_REQUEST)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        sql_str += wxT("UPDATE 'user' SET 'name' = '");
        sql_str += request_data[0].AsString();
        sql_str += wxT("', 'password' = '");
        sql_str += request_data[1].AsString();
        sql_str += wxT("', 'group_id' = ");
        sql_str += request_data[2].AsString();

        wxDatabaseEvent controller_event(event.GetEventType());
        controller_event.SetSqlString(sql_str);
        controller_event.SetEventObject(event.GetEventObject());
        controller_event.SetStatus(EVENTSTATUS_REQUEST);
        controller_event.SetId(CONTROLLER_USER);
        (wxGetApp().GetDatabase())->AddPendingEvent(controller_event);
    }
    else
    {
        wxDatabaseEvent controller_event(event.GetEventType());
        controller_event.SetStatus(event.GetStatus());
        ((wxEvtHandler *)event.GetEventObject())->AddPendingEvent(controller_event);
    }
}
*/
void UserController::OnDatabaseEvent(wxDatabaseEvent& event)
{
    if(event.GetStatus() == EVENTSTATUS_REQUEST)
    {
        OnDatabaseRequest(event);
    }
    else
    {
        OnDatabaseResponse(event);
    }
}

void UserController::OnDatabaseRequest(wxDatabaseEvent& event)
{
    wxEventType event_type = event.GetEventType();

    wxDatabaseEvent controller_event;
    controller_event.SetEventType(event_type);

    if(event_type == wxEVT_DATABASE_GETUSERLIST)
    {
        controller_event.SetSqlString(wxT("SELECT a.id, a.name, a.group_id, b.name as group_name FROM 'user' a JOIN 'user_group' b ON a.group_id = b.id WHERE a.vaild = 1;"));
        controller_event.SetSqlType(SQLTYPE_QUERY);
    }

    if(event_type == wxEVT_DATABASE_ADDUSER)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        sql_str += wxT("INSERT INTO 'user' ('name','password','group_id') VALUES ('");
        sql_str += request_data[0].AsString();
        sql_str += wxT("','");
        sql_str += request_data[1].AsString();
        sql_str += wxT("',");
        sql_str += request_data[2].AsString();
        sql_str += wxT(")");

        controller_event.SetSqlString(sql_str);
        controller_event.SetSqlType(SQLTYPE_UPDATE);
    }

    if(event_type == wxEVT_DATABASE_DELETEUSER)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        for ( int i = 0; i < request_data.Size(); i++ )
        {
            sql_str += wxT("UPDATE 'user' SET 'vaild' = 0 WHERE id = ");
            sql_str += request_data[i].AsString();
            sql_str += wxT(";");
        }

        controller_event.SetSqlString(sql_str);
        controller_event.SetSqlType(SQLTYPE_UPDATE);
    }

    if(event_type == wxEVT_DATABASE_UPDATEUSER)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        sql_str += wxT("UPDATE 'user' SET 'name' = '");
        sql_str += request_data[0].AsString();

        if(!(request_data[1].AsString().IsEmpty()))
        {
            sql_str += wxT("', 'password' = '");
            sql_str += request_data[1].AsString();
        }

        sql_str += wxT("', 'group_id' = ");
        sql_str += request_data[2].AsString();
        sql_str += wxT(" WHERE 'id' = ");
        sql_str += request_data[3].AsString();


        controller_event.SetSqlString(sql_str);
        controller_event.SetSqlType(SQLTYPE_UPDATE);
    }

    controller_event.SetEventObject(event.GetEventObject());
    controller_event.SetStatus(event.GetStatus());
    controller_event.SetId(event.GetId());
    (wxGetApp().GetDatabase())->AddPendingEvent(controller_event);
}

void UserController::OnDatabaseResponse(wxDatabaseEvent& event)
{
    if(event.GetEventType() == wxEVT_DATABASE_GETUSERLIST)
    {
        m_userlist->Clear();

        wxJSONValue result_data = event.GetJsonData();
        for ( int i = 0; i < result_data.Size(); i++ )
        {
            m_userlist->Add(UserInfo(wxAtoi(result_data[i][0].AsString()), result_data[i][1].AsString(), wxAtoi(result_data[i][2].AsString()), result_data[i][3].AsString()));
        }
    }

    wxDatabaseEvent controller_event(event.GetEventType());
    controller_event.SetStatus(event.GetStatus());
    controller_event.SetErrorString(event.GetErrorString());
    controller_event.SetResultRow(event.GetResultRow());
    controller_event.SetJsonData(event.GetJsonData());
    ((wxEvtHandler *)event.GetEventObject())->AddPendingEvent(controller_event);
}

UserGroupController::UserGroupController()
{
    m_usergrouplist = new UserGroupInfoArray();

    this->Connect(wxEVT_DATABASE_GETUSERGROUPLIST, wxDatabaseEventHandler(UserGroupController::OnDatabaseEvent));
}

UserGroupController::~UserGroupController()
{
    m_usergrouplist->Clear();

    if(m_usergrouplist) delete m_usergrouplist;
}
/*
void UserGroupController::OnGetUserGroupList(wxDatabaseEvent& event)
{
    if(event.GetStatus() == EVENTSTATUS_REQUEST)
    {
        wxDatabaseEvent controller_event(event.GetEventType());
        controller_event.SetSqlString(wxT("SELECT * FROM 'user_group';"));
        controller_event.SetEventObject(event.GetEventObject());
        controller_event.SetStatus(EVENTSTATUS_REQUEST);
        controller_event.SetId(CONTROLLER_USERGROUP);
        (wxGetApp().GetDatabase())->AddPendingEvent(controller_event);
    }
    else
    {
        m_usergrouplist->Clear();

        wxJSONValue result_data = event.GetJsonData();
        for ( int i = 0; i < result_data.Size(); i++ )
        {
            m_usergrouplist->Add(UserGroupInfo(wxAtoi(result_data[i][0].AsString()), result_data[i][1].AsString()));
        }

        wxDatabaseEvent controller_event(event.GetEventType());
        controller_event.SetStatus(event.GetStatus());
        ((wxEvtHandler *)event.GetEventObject())->AddPendingEvent(controller_event);
    }
}
*/
void UserGroupController::OnDatabaseEvent(wxDatabaseEvent& event)
{
    if(event.GetStatus() == EVENTSTATUS_REQUEST)
    {
        OnDatabaseRequest(event);
    }
    else
    {
        OnDatabaseResponse(event);
    }
}

void UserGroupController::OnDatabaseRequest(wxDatabaseEvent& event)
{
    wxEventType event_type = event.GetEventType();

    wxDatabaseEvent controller_event;
    controller_event.SetEventType(event_type);

    if(event_type == wxEVT_DATABASE_GETUSERGROUPLIST)
    {
        controller_event.SetSqlString(wxT("SELECT id, name FROM 'user_group' WHERE vaild = 1;"));
        controller_event.SetSqlType(SQLTYPE_QUERY);
    }

    controller_event.SetEventObject(event.GetEventObject());
    controller_event.SetStatus(event.GetStatus());
    controller_event.SetId(event.GetId());
    (wxGetApp().GetDatabase())->AddPendingEvent(controller_event);
}

void UserGroupController::OnDatabaseResponse(wxDatabaseEvent& event)
{
    if(event.GetEventType() == wxEVT_DATABASE_GETUSERGROUPLIST)
    {
        m_usergrouplist->Clear();

        wxJSONValue result_data = event.GetJsonData();
        for ( int i = 0; i < result_data.Size(); i++ )
        {
            m_usergrouplist->Add(UserGroupInfo(wxAtoi(result_data[i][0].AsString()), result_data[i][1].AsString()));
        }
    }

    wxDatabaseEvent controller_event(event.GetEventType());
    controller_event.SetStatus(event.GetStatus());
    controller_event.SetErrorString(event.GetErrorString());
    controller_event.SetResultRow(event.GetResultRow());
    controller_event.SetJsonData(event.GetJsonData());
    ((wxEvtHandler *)event.GetEventObject())->AddPendingEvent(controller_event);
}
