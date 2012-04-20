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

DEFINE_EVENT_TYPE(wxEVT_DATABASE_GETVCARDLIST)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_ADDVCARD)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_DELETEVCARD)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_UPDATEVCARD)

DEFINE_EVENT_TYPE(wxEVT_DATABASE_GETVCARDGROUPLIST)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_ADDVCARDGROUP)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_DELETEVCARDGROUP)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_UPDATEVCARDGROUP)

DEFINE_EVENT_TYPE(wxEVT_DATABASE_GETCOMPANYLIST)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_ADDCOMPANY)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_DELETECOMPANY)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_UPDATECOMPANY)

DEFINE_EVENT_TYPE(wxEVT_DATABASE_GETCOMPANYTYPELIST)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_ADDCOMPANYTYPE)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_DELETECOMPANYTYPE)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_UPDATECOMPANYTYPE)

DEFINE_EVENT_TYPE(wxEVT_DATABASE_GETLOCATIONLIST)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_ADDLOCATION)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_DELETELOCATION)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_UPDATELOCATION)

DEFINE_EVENT_TYPE(wxEVT_DATABASE_GETRESOURCELIST)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_ADDRESOURCE)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_DELETERESOURCE)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_UPDATERESOURCE)

DEFINE_EVENT_TYPE(wxEVT_DATABASE_GETRESOURCETYPELIST)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_ADDRESOURCETYPE)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_DELETERESOURCETYPE)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_UPDATERESOURCETYPE)

DEFINE_EVENT_TYPE(wxEVT_DATABASE_GETRESOURCESTATUSLIST)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_ADDRESOURCESTATUS)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_DELETERESOURCESTATUS)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_UPDATERESOURCESTATUS)

DEFINE_EVENT_TYPE(wxEVT_DATABASE_GETRESOURCEFEETYPELIST)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_ADDRESOURCEFEETYPE)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_DELETERESOURCEFEETYPE)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_UPDATERESOURCEFEETYPE)

DEFINE_EVENT_TYPE(wxEVT_DATABASE_GETRESOURCEDEPOLYLIST)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_ADDRESOURCEDEPOLY)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_DELETERESOURCEDEPOLY)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_UPDATERESOURCEDEPOLY)


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

void AuthorityController::OnDatabaseRequest(wxDatabaseEvent& event)
{
    wxEventType event_type = event.GetEventType();

    wxDatabaseEvent controller_event;
    controller_event.SetEventType(event_type);

    if(event_type == wxEVT_DATABASE_USERLOGIN)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        sql_str += wxT("SELECT a.id, a.name, a.group_id, b.name as group_name FROM 'user' a JOIN 'user_group' b ON a.group_id = b.id WHERE a.valid = 1 AND a.name = '");
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

///////////////////////////////////////////////////////////////////////////////////

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
}

void UserController::OnDatabaseRequest(wxDatabaseEvent& event)
{
    wxEventType event_type = event.GetEventType();

    wxDatabaseEvent controller_event;
    controller_event.SetEventType(event_type);

    if(event_type == wxEVT_DATABASE_GETUSERLIST)
    {
        controller_event.SetSqlString(wxT("SELECT a.id, a.name, a.group_id, b.name as group_name FROM 'user' a JOIN 'user_group' b ON a.group_id = b.id WHERE a.valid = 1;"));
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
            sql_str += wxT("UPDATE 'user' SET 'valid' = 0 WHERE id = ");
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

        sql_str += wxT("UPDATE 'user' SET name = '");
        sql_str += request_data[0].AsString();

        if(!(request_data[1].AsString().IsEmpty()))
        {
            sql_str += wxT("', password = '");
            sql_str += request_data[1].AsString();
        }

        sql_str += wxT("', group_id = ");
        sql_str += request_data[2].AsString();
        sql_str += wxT(" WHERE id = ");
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

////////////////////////////////////////////////////////////////////////////////

UserGroupController::UserGroupController()
{
    m_usergrouplist = new UserGroupInfoArray();

    this->Connect(wxEVT_DATABASE_GETUSERGROUPLIST, wxDatabaseEventHandler(UserGroupController::OnDatabaseEvent));
    this->Connect(wxEVT_DATABASE_ADDUSERGROUP, wxDatabaseEventHandler(UserGroupController::OnDatabaseEvent));
    this->Connect(wxEVT_DATABASE_DELETEUSERGROUP, wxDatabaseEventHandler(UserGroupController::OnDatabaseEvent));
    this->Connect(wxEVT_DATABASE_UPDATEUSERGROUP, wxDatabaseEventHandler(UserGroupController::OnDatabaseEvent));
}

UserGroupController::~UserGroupController()
{
    m_usergrouplist->Clear();

    if(m_usergrouplist) delete m_usergrouplist;
}

void UserGroupController::OnDatabaseRequest(wxDatabaseEvent& event)
{
    wxEventType event_type = event.GetEventType();

    wxDatabaseEvent controller_event;
    controller_event.SetEventType(event_type);

    if(event_type == wxEVT_DATABASE_GETUSERGROUPLIST)
    {
        controller_event.SetSqlString(wxT("SELECT id, name FROM 'user_group' WHERE valid = 1;"));
        controller_event.SetSqlType(SQLTYPE_QUERY);
    }

    if(event_type == wxEVT_DATABASE_ADDUSERGROUP)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        sql_str += wxT("INSERT INTO 'user_group' ('name') VALUES ('");
        sql_str += request_data[0].AsString();
        sql_str += wxT("')");

        controller_event.SetSqlString(sql_str);
        controller_event.SetSqlType(SQLTYPE_UPDATE);
    }

    if(event_type == wxEVT_DATABASE_DELETEUSERGROUP)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        for ( int i = 0; i < request_data.Size(); i++ )
        {
            sql_str += wxT("UPDATE 'user_group' SET 'valid' = 0 WHERE id = ");
            sql_str += request_data[i].AsString();
            sql_str += wxT(";");
        }

        controller_event.SetSqlString(sql_str);
        controller_event.SetSqlType(SQLTYPE_UPDATE);
    }

    if(event_type == wxEVT_DATABASE_UPDATEUSERGROUP)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        sql_str += wxT("UPDATE 'user_group' SET name = '");
        sql_str += request_data[0].AsString();

        sql_str += wxT("' WHERE id = ");
        sql_str += request_data[1].AsString();

        controller_event.SetSqlString(sql_str);
        controller_event.SetSqlType(SQLTYPE_UPDATE);
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

////////////////////////////////////////////////////////////////////////////////

VcardController::VcardController()
{
    m_vcardlist = new VcardInfoArray();

    this->Connect(wxEVT_DATABASE_GETVCARDLIST, wxDatabaseEventHandler(VcardController::OnDatabaseEvent));
    this->Connect(wxEVT_DATABASE_ADDVCARD, wxDatabaseEventHandler(VcardController::OnDatabaseEvent));
    this->Connect(wxEVT_DATABASE_DELETEVCARD, wxDatabaseEventHandler(VcardController::OnDatabaseEvent));
    this->Connect(wxEVT_DATABASE_UPDATEVCARD, wxDatabaseEventHandler(VcardController::OnDatabaseEvent));
}

VcardController::~VcardController()
{
    m_vcardlist->Clear();

    if(m_vcardlist) delete m_vcardlist;
}

void VcardController::OnDatabaseRequest(wxDatabaseEvent& event)
{
    wxEventType event_type = event.GetEventType();

    wxDatabaseEvent controller_event;
    controller_event.SetEventType(event_type);

    if(event_type == wxEVT_DATABASE_GETVCARDLIST)
    {
        controller_event.SetSqlString(wxT("SELECT id, fullname, nickname, work_phone, mobie_phone, email, title, company FROM 'vcard' WHERE valid = 1;"));
        controller_event.SetSqlType(SQLTYPE_QUERY);
    }

    if(event_type == wxEVT_DATABASE_ADDVCARD)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        sql_str += wxT("INSERT INTO 'vcard' ('fullname', 'nickname', 'work_phone', 'mobie_phone', 'email', 'title', 'company') VALUES ('");
        sql_str += request_data[0].AsString();
        sql_str += wxT("','");
        sql_str += request_data[1].AsString();
        sql_str += wxT("','");
        sql_str += request_data[2].AsString();
        sql_str += wxT("','");
        sql_str += request_data[3].AsString();
        sql_str += wxT("','");
        sql_str += request_data[4].AsString();
        sql_str += wxT("','");
        sql_str += request_data[5].AsString();
        sql_str += wxT("','");
        sql_str += request_data[6].AsString();
        sql_str += wxT("')");

        controller_event.SetSqlString(sql_str);
        controller_event.SetSqlType(SQLTYPE_UPDATE);
    }

    if(event_type == wxEVT_DATABASE_DELETEVCARD)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        for ( int i = 0; i < request_data.Size(); i++ )
        {
            sql_str += wxT("UPDATE 'vcard' SET 'valid' = 0 WHERE id = ");
            sql_str += request_data[i].AsString();
            sql_str += wxT(";");
        }

        controller_event.SetSqlString(sql_str);
        controller_event.SetSqlType(SQLTYPE_UPDATE);
    }

    if(event_type == wxEVT_DATABASE_UPDATEVCARD)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        sql_str += wxT("UPDATE 'vcard' SET fullname = '");
        sql_str += request_data[0].AsString();
        sql_str += wxT("', nickname = '");
        sql_str += request_data[1].AsString();
        sql_str += wxT("', work_phone = '");
        sql_str += request_data[2].AsString();
        sql_str += wxT("', mobie_phone = '");
        sql_str += request_data[3].AsString();
        sql_str += wxT("', email = '");
        sql_str += request_data[4].AsString();
        sql_str += wxT("', title = '");
        sql_str += request_data[5].AsString();
        sql_str += wxT("', company = '");
        sql_str += request_data[6].AsString();

        sql_str += wxT("' WHERE id = ");
        sql_str += request_data[7].AsString();

        controller_event.SetSqlString(sql_str);
        controller_event.SetSqlType(SQLTYPE_UPDATE);
    }

    controller_event.SetEventObject(event.GetEventObject());
    controller_event.SetStatus(event.GetStatus());
    controller_event.SetId(event.GetId());
    (wxGetApp().GetDatabase())->AddPendingEvent(controller_event);
}

void VcardController::OnDatabaseResponse(wxDatabaseEvent& event)
{
    if(event.GetEventType() == wxEVT_DATABASE_GETVCARDLIST)
    {
        m_vcardlist->Clear();

        wxJSONValue result_data = event.GetJsonData();
        for ( int i = 0; i < result_data.Size(); i++ )
        {
            m_vcardlist->Add(VcardInfo(wxAtoi(result_data[i][0].AsString()), result_data[i][1].AsString(), result_data[i][2].AsString(), result_data[i][3].AsString(), result_data[i][4].AsString(), result_data[i][5].AsString(), result_data[i][6].AsString(), result_data[i][7].AsString()));
        }
    }

    wxDatabaseEvent controller_event(event.GetEventType());
    controller_event.SetStatus(event.GetStatus());
    controller_event.SetErrorString(event.GetErrorString());
    controller_event.SetResultRow(event.GetResultRow());
    controller_event.SetJsonData(event.GetJsonData());
    ((wxEvtHandler *)event.GetEventObject())->AddPendingEvent(controller_event);
}

////////////////////////////////////////////////////////////////////////////////

VcardGroupController::VcardGroupController()
{
    m_vcardgrouplist = new VcardGroupInfoArray();

    this->Connect(wxEVT_DATABASE_GETVCARDGROUPLIST, wxDatabaseEventHandler(VcardGroupController::OnDatabaseEvent));
    this->Connect(wxEVT_DATABASE_ADDVCARDGROUP, wxDatabaseEventHandler(VcardGroupController::OnDatabaseEvent));
    this->Connect(wxEVT_DATABASE_DELETEVCARDGROUP, wxDatabaseEventHandler(VcardGroupController::OnDatabaseEvent));
    this->Connect(wxEVT_DATABASE_UPDATEVCARDGROUP, wxDatabaseEventHandler(VcardGroupController::OnDatabaseEvent));
}

VcardGroupController::~VcardGroupController()
{
    m_vcardgrouplist->Clear();

    if(m_vcardgrouplist) delete m_vcardgrouplist;
}

void VcardGroupController::OnDatabaseRequest(wxDatabaseEvent& event)
{
    wxEventType event_type = event.GetEventType();

    wxDatabaseEvent controller_event;
    controller_event.SetEventType(event_type);

    if(event_type == wxEVT_DATABASE_GETVCARDGROUPLIST)
    {
        controller_event.SetSqlString(wxT("SELECT id, name FROM 'vcard_group' WHERE valid = 1;"));
        controller_event.SetSqlType(SQLTYPE_QUERY);
    }

    if(event_type == wxEVT_DATABASE_ADDVCARDGROUP)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        sql_str += wxT("INSERT INTO 'vcard_group' ('name') VALUES ('");
        sql_str += request_data[0].AsString();
        sql_str += wxT("')");

        controller_event.SetSqlString(sql_str);
        controller_event.SetSqlType(SQLTYPE_UPDATE);
    }

    if(event_type == wxEVT_DATABASE_DELETEVCARDGROUP)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        for ( int i = 0; i < request_data.Size(); i++ )
        {
            sql_str += wxT("UPDATE 'vcard_group' SET 'valid' = 0 WHERE id = ");
            sql_str += request_data[i].AsString();
            sql_str += wxT(";");
        }

        controller_event.SetSqlString(sql_str);
        controller_event.SetSqlType(SQLTYPE_UPDATE);
    }

    if(event_type == wxEVT_DATABASE_UPDATEVCARDGROUP)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        sql_str += wxT("UPDATE 'vcard_group' SET name = '");
        sql_str += request_data[0].AsString();

        sql_str += wxT("' WHERE id = ");
        sql_str += request_data[1].AsString();

        controller_event.SetSqlString(sql_str);
        controller_event.SetSqlType(SQLTYPE_UPDATE);
    }

    controller_event.SetEventObject(event.GetEventObject());
    controller_event.SetStatus(event.GetStatus());
    controller_event.SetId(event.GetId());
    (wxGetApp().GetDatabase())->AddPendingEvent(controller_event);
}

void VcardGroupController::OnDatabaseResponse(wxDatabaseEvent& event)
{
    if(event.GetEventType() == wxEVT_DATABASE_GETVCARDGROUPLIST)
    {
        m_vcardgrouplist->Clear();

        wxJSONValue result_data = event.GetJsonData();
        for ( int i = 0; i < result_data.Size(); i++ )
        {
            m_vcardgrouplist->Add(VcardGroupInfo(wxAtoi(result_data[i][0].AsString()), result_data[i][1].AsString()));
        }
    }

    wxDatabaseEvent controller_event(event.GetEventType());
    controller_event.SetStatus(event.GetStatus());
    controller_event.SetErrorString(event.GetErrorString());
    controller_event.SetResultRow(event.GetResultRow());
    controller_event.SetJsonData(event.GetJsonData());
    ((wxEvtHandler *)event.GetEventObject())->AddPendingEvent(controller_event);
}

////////////////////////////////////////////////////////////////////////////////

CompanyController::CompanyController()
{
    m_companylist = new CompanyInfoArray();

    this->Connect(wxEVT_DATABASE_GETCOMPANYLIST, wxDatabaseEventHandler(CompanyController::OnDatabaseEvent));
    this->Connect(wxEVT_DATABASE_ADDCOMPANY, wxDatabaseEventHandler(CompanyController::OnDatabaseEvent));
    this->Connect(wxEVT_DATABASE_DELETECOMPANY, wxDatabaseEventHandler(CompanyController::OnDatabaseEvent));
    this->Connect(wxEVT_DATABASE_UPDATECOMPANY, wxDatabaseEventHandler(CompanyController::OnDatabaseEvent));
}

CompanyController::~CompanyController()
{
    m_companylist->Clear();

    if(m_companylist) delete m_companylist;
}

void CompanyController::OnDatabaseRequest(wxDatabaseEvent& event)
{
    wxEventType event_type = event.GetEventType();

    wxDatabaseEvent controller_event;
    controller_event.SetEventType(event_type);

    if(event_type == wxEVT_DATABASE_GETCOMPANYLIST)
    {
        controller_event.SetSqlString(wxT("SELECT a.id, a.name, a.companytype_id, b.name as companytype_name FROM 'company' a JOIN 'company_type' b ON a.companytype_id = b.id WHERE a.valid = 1;"));
        controller_event.SetSqlType(SQLTYPE_QUERY);
    }

    if(event_type == wxEVT_DATABASE_ADDCOMPANY)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        sql_str += wxT("INSERT INTO 'company' ('name','companytype_id') VALUES ('");
        sql_str += request_data[0].AsString();
        sql_str += wxT("',");
        sql_str += request_data[1].AsString();
        sql_str += wxT(")");

        controller_event.SetSqlString(sql_str);
        controller_event.SetSqlType(SQLTYPE_UPDATE);
    }

    if(event_type == wxEVT_DATABASE_DELETECOMPANY)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        for ( int i = 0; i < request_data.Size(); i++ )
        {
            sql_str += wxT("UPDATE 'company' SET 'valid' = 0 WHERE id = ");
            sql_str += request_data[i].AsString();
            sql_str += wxT(";");
        }

        controller_event.SetSqlString(sql_str);
        controller_event.SetSqlType(SQLTYPE_UPDATE);
    }

    if(event_type == wxEVT_DATABASE_UPDATECOMPANY)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        sql_str += wxT("UPDATE 'company' SET name = '");
        sql_str += request_data[0].AsString();
        sql_str += wxT("', companytype_id = ");
        sql_str += request_data[1].AsString();
        sql_str += wxT(" WHERE id = ");
        sql_str += request_data[2].AsString();

        controller_event.SetSqlString(sql_str);
        controller_event.SetSqlType(SQLTYPE_UPDATE);
    }

    controller_event.SetEventObject(event.GetEventObject());
    controller_event.SetStatus(event.GetStatus());
    controller_event.SetId(event.GetId());
    (wxGetApp().GetDatabase())->AddPendingEvent(controller_event);
}

void CompanyController::OnDatabaseResponse(wxDatabaseEvent& event)
{
    if(event.GetEventType() == wxEVT_DATABASE_GETCOMPANYLIST)
    {
        m_companylist->Clear();

        wxJSONValue result_data = event.GetJsonData();
        for ( int i = 0; i < result_data.Size(); i++ )
        {
            m_companylist->Add(CompanyInfo(wxAtoi(result_data[i][0].AsString()), result_data[i][1].AsString(), wxAtoi(result_data[i][2].AsString()), result_data[i][3].AsString()));
        }
    }

    wxDatabaseEvent controller_event(event.GetEventType());
    controller_event.SetStatus(event.GetStatus());
    controller_event.SetErrorString(event.GetErrorString());
    controller_event.SetResultRow(event.GetResultRow());
    controller_event.SetJsonData(event.GetJsonData());
    ((wxEvtHandler *)event.GetEventObject())->AddPendingEvent(controller_event);
}

////////////////////////////////////////////////////////////////////////////////

CompanyTypeController::CompanyTypeController()
{
    m_companytypelist = new CompanyTypeInfoArray();

    this->Connect(wxEVT_DATABASE_GETCOMPANYTYPELIST, wxDatabaseEventHandler(CompanyTypeController::OnDatabaseEvent));
    this->Connect(wxEVT_DATABASE_ADDCOMPANYTYPE, wxDatabaseEventHandler(CompanyTypeController::OnDatabaseEvent));
    this->Connect(wxEVT_DATABASE_DELETECOMPANYTYPE, wxDatabaseEventHandler(CompanyTypeController::OnDatabaseEvent));
    this->Connect(wxEVT_DATABASE_UPDATECOMPANYTYPE, wxDatabaseEventHandler(CompanyTypeController::OnDatabaseEvent));
}

CompanyTypeController::~CompanyTypeController()
{
    m_companytypelist->Clear();

    if(m_companytypelist) delete m_companytypelist;
}

void CompanyTypeController::OnDatabaseRequest(wxDatabaseEvent& event)
{
    wxEventType event_type = event.GetEventType();

    wxDatabaseEvent controller_event;
    controller_event.SetEventType(event_type);

    if(event_type == wxEVT_DATABASE_GETCOMPANYTYPELIST)
    {
        controller_event.SetSqlString(wxT("SELECT id, name FROM 'company_type' WHERE valid = 1;"));
        controller_event.SetSqlType(SQLTYPE_QUERY);
    }

    if(event_type == wxEVT_DATABASE_ADDCOMPANYTYPE)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        sql_str += wxT("INSERT INTO 'company_type' ('name') VALUES ('");
        sql_str += request_data[0].AsString();
        sql_str += wxT("')");

        controller_event.SetSqlString(sql_str);
        controller_event.SetSqlType(SQLTYPE_UPDATE);
    }

    if(event_type == wxEVT_DATABASE_DELETECOMPANYTYPE)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        for ( int i = 0; i < request_data.Size(); i++ )
        {
            sql_str += wxT("UPDATE 'company_type' SET 'valid' = 0 WHERE id = ");
            sql_str += request_data[i].AsString();
            sql_str += wxT(";");
        }

        controller_event.SetSqlString(sql_str);
        controller_event.SetSqlType(SQLTYPE_UPDATE);
    }

    if(event_type == wxEVT_DATABASE_UPDATECOMPANYTYPE)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        sql_str += wxT("UPDATE 'company_type' SET name = '");
        sql_str += request_data[0].AsString();

        sql_str += wxT("' WHERE id = ");
        sql_str += request_data[1].AsString();

        controller_event.SetSqlString(sql_str);
        controller_event.SetSqlType(SQLTYPE_UPDATE);
    }

    controller_event.SetEventObject(event.GetEventObject());
    controller_event.SetStatus(event.GetStatus());
    controller_event.SetId(event.GetId());
    (wxGetApp().GetDatabase())->AddPendingEvent(controller_event);
}

void CompanyTypeController::OnDatabaseResponse(wxDatabaseEvent& event)
{
    if(event.GetEventType() == wxEVT_DATABASE_GETCOMPANYTYPELIST)
    {
        m_companytypelist->Clear();

        wxJSONValue result_data = event.GetJsonData();
        for ( int i = 0; i < result_data.Size(); i++ )
        {
            m_companytypelist->Add(CompanyTypeInfo(wxAtoi(result_data[i][0].AsString()), result_data[i][1].AsString()));
        }
    }

    wxDatabaseEvent controller_event(event.GetEventType());
    controller_event.SetStatus(event.GetStatus());
    controller_event.SetErrorString(event.GetErrorString());
    controller_event.SetResultRow(event.GetResultRow());
    controller_event.SetJsonData(event.GetJsonData());
    ((wxEvtHandler *)event.GetEventObject())->AddPendingEvent(controller_event);
}

/////////////////////////////////////////////////////////////////////////////////

LocationController::LocationController()
{
    m_locationlist = new LocationInfoArray();

    this->Connect(wxEVT_DATABASE_GETLOCATIONLIST, wxDatabaseEventHandler(LocationController::OnDatabaseEvent));
    this->Connect(wxEVT_DATABASE_ADDLOCATION, wxDatabaseEventHandler(LocationController::OnDatabaseEvent));
    this->Connect(wxEVT_DATABASE_DELETELOCATION, wxDatabaseEventHandler(LocationController::OnDatabaseEvent));
    this->Connect(wxEVT_DATABASE_UPDATELOCATION, wxDatabaseEventHandler(LocationController::OnDatabaseEvent));
}

LocationController::~LocationController()
{
    m_locationlist->Clear();

    if(m_locationlist) delete m_locationlist;
}

void LocationController::OnDatabaseRequest(wxDatabaseEvent& event)
{
    wxEventType event_type = event.GetEventType();

    wxDatabaseEvent controller_event;
    controller_event.SetEventType(event_type);

    if(event_type == wxEVT_DATABASE_GETLOCATIONLIST)
    {
        controller_event.SetSqlString(wxT("SELECT id, name FROM 'location' WHERE valid = 1;"));
        controller_event.SetSqlType(SQLTYPE_QUERY);
    }

    if(event_type == wxEVT_DATABASE_ADDLOCATION)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        sql_str += wxT("INSERT INTO 'location' ('name') VALUES ('");
        sql_str += request_data[0].AsString();
        sql_str += wxT("')");

        controller_event.SetSqlString(sql_str);
        controller_event.SetSqlType(SQLTYPE_UPDATE);
    }

    if(event_type == wxEVT_DATABASE_DELETELOCATION)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        for ( int i = 0; i < request_data.Size(); i++ )
        {
            sql_str += wxT("UPDATE 'location' SET 'valid' = 0 WHERE id = ");
            sql_str += request_data[i].AsString();
            sql_str += wxT(";");
        }

        controller_event.SetSqlString(sql_str);
        controller_event.SetSqlType(SQLTYPE_UPDATE);
    }

    if(event_type == wxEVT_DATABASE_UPDATELOCATION)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        sql_str += wxT("UPDATE 'location' SET name = '");
        sql_str += request_data[0].AsString();

        sql_str += wxT("' WHERE id = ");
        sql_str += request_data[1].AsString();

        controller_event.SetSqlString(sql_str);
        controller_event.SetSqlType(SQLTYPE_UPDATE);
    }

    controller_event.SetEventObject(event.GetEventObject());
    controller_event.SetStatus(event.GetStatus());
    controller_event.SetId(event.GetId());
    (wxGetApp().GetDatabase())->AddPendingEvent(controller_event);
}

void LocationController::OnDatabaseResponse(wxDatabaseEvent& event)
{
    if(event.GetEventType() == wxEVT_DATABASE_GETLOCATIONLIST)
    {
        m_locationlist->Clear();

        wxJSONValue result_data = event.GetJsonData();
        for ( int i = 0; i < result_data.Size(); i++ )
        {
            m_locationlist->Add(LocationInfo(wxAtoi(result_data[i][0].AsString()), result_data[i][1].AsString()));
        }
    }

    wxDatabaseEvent controller_event(event.GetEventType());
    controller_event.SetStatus(event.GetStatus());
    controller_event.SetErrorString(event.GetErrorString());
    controller_event.SetResultRow(event.GetResultRow());
    controller_event.SetJsonData(event.GetJsonData());
    ((wxEvtHandler *)event.GetEventObject())->AddPendingEvent(controller_event);
}

/////////////////////////////////////////////////////////////////////////////////

ResourceController::ResourceController()
{
    //m_currentuser   = NULL;
    m_resourcelist      = new ResourceInfoArray();

    this->Connect(wxEVT_DATABASE_GETRESOURCELIST, wxDatabaseEventHandler(ResourceController::OnDatabaseEvent));
    this->Connect(wxEVT_DATABASE_DELETERESOURCE, wxDatabaseEventHandler(ResourceController::OnDatabaseEvent));
    this->Connect(wxEVT_DATABASE_ADDRESOURCE, wxDatabaseEventHandler(ResourceController::OnDatabaseEvent));
    this->Connect(wxEVT_DATABASE_UPDATERESOURCE, wxDatabaseEventHandler(ResourceController::OnDatabaseEvent));
}

ResourceController::~ResourceController()
{
    m_resourcelist->Clear();

    if(m_resourcelist) delete m_resourcelist;
}

void ResourceController::OnDatabaseRequest(wxDatabaseEvent& event)
{
    wxEventType event_type = event.GetEventType();

    wxDatabaseEvent controller_event;
    controller_event.SetEventType(event_type);

    if(event_type == wxEVT_DATABASE_GETRESOURCELIST)
    {
        controller_event.SetSqlString(wxT("SELECT a.id, a.name, a.resourcetype_id, b.name as resourcetype_name, a.pattern, a.weight FROM 'resource' a JOIN 'resource_type' b ON a.resourcetype_id = b.id WHERE a.valid = 1;"));
        controller_event.SetSqlType(SQLTYPE_QUERY);
    }

    if(event_type == wxEVT_DATABASE_ADDRESOURCE)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        sql_str += wxT("INSERT INTO 'resource' ('name','resourcetype_id','pattern','weight') VALUES ('");
        sql_str += request_data[0].AsString();
        sql_str += wxT("',");
        sql_str += request_data[1].AsString();
        sql_str += wxT(",'");
        sql_str += request_data[2].AsString();
        sql_str += wxT("',");
        sql_str += request_data[3].AsString();
        sql_str += wxT(")");

        controller_event.SetSqlString(sql_str);
        controller_event.SetSqlType(SQLTYPE_UPDATE);
    }

    if(event_type == wxEVT_DATABASE_DELETERESOURCE)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        for ( int i = 0; i < request_data.Size(); i++ )
        {
            sql_str += wxT("UPDATE 'resource' SET 'valid' = 0 WHERE id = ");
            sql_str += request_data[i].AsString();
            sql_str += wxT(";");
        }

        controller_event.SetSqlString(sql_str);
        controller_event.SetSqlType(SQLTYPE_UPDATE);
    }

    if(event_type == wxEVT_DATABASE_UPDATERESOURCE)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        sql_str += wxT("UPDATE 'resource' SET name = '");
        sql_str += request_data[0].AsString();
        sql_str += wxT("',");

        if(!(request_data[1].AsString().IsEmpty()))
        {
            sql_str += wxT("resourcetype_id = ");
            sql_str += request_data[1].AsString();
            sql_str += wxT(",");
        }

        sql_str += wxT("pattern = '");
        sql_str += request_data[2].AsString();
        sql_str += wxT("'");

        if(!(request_data[3].AsString().IsEmpty()))
        {
            sql_str += wxT(",weight = ");
            sql_str += request_data[3].AsString();
        }

        sql_str += wxT(" WHERE id = ");
        sql_str += request_data[4].AsString();

        controller_event.SetSqlString(sql_str);
        controller_event.SetSqlType(SQLTYPE_UPDATE);
    }

    controller_event.SetEventObject(event.GetEventObject());
    controller_event.SetStatus(event.GetStatus());
    controller_event.SetId(event.GetId());
    (wxGetApp().GetDatabase())->AddPendingEvent(controller_event);
}

void ResourceController::OnDatabaseResponse(wxDatabaseEvent& event)
{
    if(event.GetEventType() == wxEVT_DATABASE_GETRESOURCELIST)
    {
        m_resourcelist->Clear();

        wxJSONValue result_data = event.GetJsonData();
        for ( int i = 0; i < result_data.Size(); i++ )
        {
            m_resourcelist->Add(ResourceInfo(wxAtoi(result_data[i][0].AsString()), result_data[i][1].AsString(), wxAtoi(result_data[i][2].AsString()), result_data[i][3].AsString(), result_data[i][4].AsString(), wxAtoi(result_data[i][5].AsString())));
        }
    }

    wxDatabaseEvent controller_event(event.GetEventType());
    controller_event.SetStatus(event.GetStatus());
    controller_event.SetErrorString(event.GetErrorString());
    controller_event.SetResultRow(event.GetResultRow());
    controller_event.SetJsonData(event.GetJsonData());
    ((wxEvtHandler *)event.GetEventObject())->AddPendingEvent(controller_event);
}

////////////////////////////////////////////////////////////////////////////////

ResourceTypeController::ResourceTypeController()
{
    m_resourcetypelist = new ResourceTypeInfoArray();

    this->Connect(wxEVT_DATABASE_GETRESOURCETYPELIST, wxDatabaseEventHandler(ResourceTypeController::OnDatabaseEvent));
    this->Connect(wxEVT_DATABASE_ADDRESOURCETYPE, wxDatabaseEventHandler(ResourceTypeController::OnDatabaseEvent));
    this->Connect(wxEVT_DATABASE_DELETERESOURCETYPE, wxDatabaseEventHandler(ResourceTypeController::OnDatabaseEvent));
    this->Connect(wxEVT_DATABASE_UPDATERESOURCETYPE, wxDatabaseEventHandler(ResourceTypeController::OnDatabaseEvent));
}

ResourceTypeController::~ResourceTypeController()
{
    m_resourcetypelist->Clear();

    if(m_resourcetypelist) delete m_resourcetypelist;
}

void ResourceTypeController::OnDatabaseRequest(wxDatabaseEvent& event)
{
    wxEventType event_type = event.GetEventType();

    wxDatabaseEvent controller_event;
    controller_event.SetEventType(event_type);

    if(event_type == wxEVT_DATABASE_GETRESOURCETYPELIST)
    {
        controller_event.SetSqlString(wxT("SELECT id, name FROM 'resource_type' WHERE valid = 1;"));
        controller_event.SetSqlType(SQLTYPE_QUERY);
    }

    if(event_type == wxEVT_DATABASE_ADDRESOURCETYPE)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        sql_str += wxT("INSERT INTO 'resource_type' ('name') VALUES ('");
        sql_str += request_data[0].AsString();
        sql_str += wxT("')");

        controller_event.SetSqlString(sql_str);
        controller_event.SetSqlType(SQLTYPE_UPDATE);
    }

    if(event_type == wxEVT_DATABASE_DELETERESOURCETYPE)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        for ( int i = 0; i < request_data.Size(); i++ )
        {
            sql_str += wxT("UPDATE 'resource_type' SET 'valid' = 0 WHERE id = ");
            sql_str += request_data[i].AsString();
            sql_str += wxT(";");
        }

        controller_event.SetSqlString(sql_str);
        controller_event.SetSqlType(SQLTYPE_UPDATE);
    }

    if(event_type == wxEVT_DATABASE_UPDATERESOURCETYPE)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        sql_str += wxT("UPDATE 'resource_type' SET name = '");
        sql_str += request_data[0].AsString();

        sql_str += wxT("' WHERE id = ");
        sql_str += request_data[1].AsString();

        controller_event.SetSqlString(sql_str);
        controller_event.SetSqlType(SQLTYPE_UPDATE);
    }

    controller_event.SetEventObject(event.GetEventObject());
    controller_event.SetStatus(event.GetStatus());
    controller_event.SetId(event.GetId());
    (wxGetApp().GetDatabase())->AddPendingEvent(controller_event);
}

void ResourceTypeController::OnDatabaseResponse(wxDatabaseEvent& event)
{
    if(event.GetEventType() == wxEVT_DATABASE_GETRESOURCETYPELIST)
    {
        m_resourcetypelist->Clear();

        wxJSONValue result_data = event.GetJsonData();
        for ( int i = 0; i < result_data.Size(); i++ )
        {
            m_resourcetypelist->Add(ResourceTypeInfo(wxAtoi(result_data[i][0].AsString()), result_data[i][1].AsString()));
        }
    }

    wxDatabaseEvent controller_event(event.GetEventType());
    controller_event.SetStatus(event.GetStatus());
    controller_event.SetErrorString(event.GetErrorString());
    controller_event.SetResultRow(event.GetResultRow());
    controller_event.SetJsonData(event.GetJsonData());
    ((wxEvtHandler *)event.GetEventObject())->AddPendingEvent(controller_event);
}

////////////////////////////////////////////////////////////////////////////////

ResourceStatusController::ResourceStatusController()
{
    m_resourcestatuslist = new ResourceStatusInfoArray();

    this->Connect(wxEVT_DATABASE_GETRESOURCESTATUSLIST, wxDatabaseEventHandler(ResourceStatusController::OnDatabaseEvent));
    this->Connect(wxEVT_DATABASE_ADDRESOURCESTATUS, wxDatabaseEventHandler(ResourceStatusController::OnDatabaseEvent));
    this->Connect(wxEVT_DATABASE_DELETERESOURCESTATUS, wxDatabaseEventHandler(ResourceStatusController::OnDatabaseEvent));
    this->Connect(wxEVT_DATABASE_UPDATERESOURCESTATUS, wxDatabaseEventHandler(ResourceStatusController::OnDatabaseEvent));
}

ResourceStatusController::~ResourceStatusController()
{
    m_resourcestatuslist->Clear();

    if(m_resourcestatuslist) delete m_resourcestatuslist;
}

void ResourceStatusController::OnDatabaseRequest(wxDatabaseEvent& event)
{
    wxEventType event_type = event.GetEventType();

    wxDatabaseEvent controller_event;
    controller_event.SetEventType(event_type);

    if(event_type == wxEVT_DATABASE_GETRESOURCESTATUSLIST)
    {
        controller_event.SetSqlString(wxT("SELECT id, name, available FROM 'resource_status' WHERE valid = 1;"));
        controller_event.SetSqlType(SQLTYPE_QUERY);
    }

    if(event_type == wxEVT_DATABASE_ADDRESOURCESTATUS)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        sql_str += wxT("INSERT INTO 'resource_status' ('name', available) VALUES ('");
        sql_str += request_data[0].AsString();
        sql_str += wxT("',");
        sql_str += request_data[1].AsString();
        sql_str += wxT(")");

        controller_event.SetSqlString(sql_str);
        controller_event.SetSqlType(SQLTYPE_UPDATE);
    }

    if(event_type == wxEVT_DATABASE_DELETERESOURCESTATUS)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        for ( int i = 0; i < request_data.Size(); i++ )
        {
            sql_str += wxT("UPDATE 'resource_status' SET 'valid' = 0 WHERE id = ");
            sql_str += request_data[i].AsString();
            sql_str += wxT(";");
        }

        controller_event.SetSqlString(sql_str);
        controller_event.SetSqlType(SQLTYPE_UPDATE);
    }

    if(event_type == wxEVT_DATABASE_UPDATERESOURCESTATUS)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        sql_str += wxT("UPDATE 'resource_status' SET name = '");
        sql_str += request_data[0].AsString();
        sql_str += wxT("'");

        if(!(request_data[1].AsString().IsEmpty()))
        {
            sql_str += wxT(",available = ");
            sql_str += request_data[1].AsString();
        }

        sql_str += wxT(" WHERE id = ");
        sql_str += request_data[2].AsString();

        controller_event.SetSqlString(sql_str);
        controller_event.SetSqlType(SQLTYPE_UPDATE);
    }

    controller_event.SetEventObject(event.GetEventObject());
    controller_event.SetStatus(event.GetStatus());
    controller_event.SetId(event.GetId());
    (wxGetApp().GetDatabase())->AddPendingEvent(controller_event);
}

void ResourceStatusController::OnDatabaseResponse(wxDatabaseEvent& event)
{
    if(event.GetEventType() == wxEVT_DATABASE_GETRESOURCESTATUSLIST)
    {
        m_resourcestatuslist->Clear();

        wxJSONValue result_data = event.GetJsonData();
        for ( int i = 0; i < result_data.Size(); i++ )
        {
            m_resourcestatuslist->Add(ResourceStatusInfo(wxAtoi(result_data[i][0].AsString()), result_data[i][1].AsString(), wxAtoi(result_data[i][2].AsString())));
        }
    }

    wxDatabaseEvent controller_event(event.GetEventType());
    controller_event.SetStatus(event.GetStatus());
    controller_event.SetErrorString(event.GetErrorString());
    controller_event.SetResultRow(event.GetResultRow());
    controller_event.SetJsonData(event.GetJsonData());
    ((wxEvtHandler *)event.GetEventObject())->AddPendingEvent(controller_event);
}

////////////////////////////////////////////////////////////////////////////////

ResourceFeeTypeController::ResourceFeeTypeController()
{
    m_resourcefeetypelist = new ResourceFeeTypeInfoArray();

    this->Connect(wxEVT_DATABASE_GETRESOURCEFEETYPELIST, wxDatabaseEventHandler(ResourceFeeTypeController::OnDatabaseEvent));
    this->Connect(wxEVT_DATABASE_ADDRESOURCEFEETYPE, wxDatabaseEventHandler(ResourceFeeTypeController::OnDatabaseEvent));
    this->Connect(wxEVT_DATABASE_DELETERESOURCEFEETYPE, wxDatabaseEventHandler(ResourceFeeTypeController::OnDatabaseEvent));
    this->Connect(wxEVT_DATABASE_UPDATERESOURCEFEETYPE, wxDatabaseEventHandler(ResourceFeeTypeController::OnDatabaseEvent));
}

ResourceFeeTypeController::~ResourceFeeTypeController()
{
    m_resourcefeetypelist->Clear();

    if(m_resourcefeetypelist) delete m_resourcefeetypelist;
}

void ResourceFeeTypeController::OnDatabaseRequest(wxDatabaseEvent& event)
{
    wxEventType event_type = event.GetEventType();

    wxDatabaseEvent controller_event;
    controller_event.SetEventType(event_type);

    if(event_type == wxEVT_DATABASE_GETRESOURCEFEETYPELIST)
    {
        controller_event.SetSqlString(wxT("SELECT id, name, have_expiration FROM 'resource_feetype' WHERE valid = 1;"));
        controller_event.SetSqlType(SQLTYPE_QUERY);
    }

    if(event_type == wxEVT_DATABASE_ADDRESOURCEFEETYPE)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        sql_str += wxT("INSERT INTO 'resource_feetype' ('name', have_expiration) VALUES ('");
        sql_str += request_data[0].AsString();
        sql_str += wxT("',");
        sql_str += request_data[1].AsString();
        sql_str += wxT(")");

        controller_event.SetSqlString(sql_str);
        controller_event.SetSqlType(SQLTYPE_UPDATE);
    }

    if(event_type == wxEVT_DATABASE_DELETERESOURCEFEETYPE)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        for ( int i = 0; i < request_data.Size(); i++ )
        {
            sql_str += wxT("UPDATE 'resource_feetype' SET 'valid' = 0 WHERE id = ");
            sql_str += request_data[i].AsString();
            sql_str += wxT(";");
        }

        controller_event.SetSqlString(sql_str);
        controller_event.SetSqlType(SQLTYPE_UPDATE);
    }

    if(event_type == wxEVT_DATABASE_UPDATERESOURCEFEETYPE)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        sql_str += wxT("UPDATE 'resource_feetype' SET name = '");
        sql_str += request_data[0].AsString();
        sql_str += wxT("'");

        if(!(request_data[1].AsString().IsEmpty()))
        {
            sql_str += wxT(",have_expiration = ");
            sql_str += request_data[1].AsString();
        }

        sql_str += wxT(" WHERE id = ");
        sql_str += request_data[2].AsString();

        controller_event.SetSqlString(sql_str);
        controller_event.SetSqlType(SQLTYPE_UPDATE);
    }

    controller_event.SetEventObject(event.GetEventObject());
    controller_event.SetStatus(event.GetStatus());
    controller_event.SetId(event.GetId());
    (wxGetApp().GetDatabase())->AddPendingEvent(controller_event);
}

void ResourceFeeTypeController::OnDatabaseResponse(wxDatabaseEvent& event)
{
    if(event.GetEventType() == wxEVT_DATABASE_GETRESOURCEFEETYPELIST)
    {
        m_resourcefeetypelist->Clear();

        wxJSONValue result_data = event.GetJsonData();
        for ( int i = 0; i < result_data.Size(); i++ )
        {
            m_resourcefeetypelist->Add(ResourceFeeTypeInfo(wxAtoi(result_data[i][0].AsString()), result_data[i][1].AsString(), wxAtoi(result_data[i][2].AsString())));
        }
    }

    wxDatabaseEvent controller_event(event.GetEventType());
    controller_event.SetStatus(event.GetStatus());
    controller_event.SetErrorString(event.GetErrorString());
    controller_event.SetResultRow(event.GetResultRow());
    controller_event.SetJsonData(event.GetJsonData());
    ((wxEvtHandler *)event.GetEventObject())->AddPendingEvent(controller_event);
}

////////////////////////////////////////////////////////////////////////////////

ResourceDepolyController::ResourceDepolyController()
{
    m_resourcedepolylist = new ResourceDepolyInfoArray();

    this->Connect(wxEVT_DATABASE_GETRESOURCEDEPOLYLIST, wxDatabaseEventHandler(ResourceDepolyController::OnDatabaseEvent));
    this->Connect(wxEVT_DATABASE_ADDRESOURCEDEPOLY, wxDatabaseEventHandler(ResourceDepolyController::OnDatabaseEvent));
    this->Connect(wxEVT_DATABASE_DELETERESOURCEDEPOLY, wxDatabaseEventHandler(ResourceDepolyController::OnDatabaseEvent));
    this->Connect(wxEVT_DATABASE_UPDATERESOURCEDEPOLY, wxDatabaseEventHandler(ResourceDepolyController::OnDatabaseEvent));
}

ResourceDepolyController::~ResourceDepolyController()
{
    m_resourcedepolylist->Clear();

    if(m_resourcedepolylist) delete m_resourcedepolylist;
}

void ResourceDepolyController::OnDatabaseRequest(wxDatabaseEvent& event)
{
    wxEventType event_type = event.GetEventType();

    wxDatabaseEvent controller_event;
    controller_event.SetEventType(event_type);

    if(event_type == wxEVT_DATABASE_GETRESOURCEDEPOLYLIST)
    {
        controller_event.SetSqlString(wxT("SELECT id, name, have_expiration FROM 'resource_depoly' WHERE valid = 1;"));
        controller_event.SetSqlType(SQLTYPE_QUERY);
    }

    if(event_type == wxEVT_DATABASE_ADDRESOURCEDEPOLY)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        sql_str += wxT("INSERT INTO 'resource_depoly' ('name') VALUES ('");
        sql_str += request_data[0].AsString();
        sql_str += wxT("'");
        //sql_str += request_data[1].AsString();
        sql_str += wxT(")");

        controller_event.SetSqlString(sql_str);
        controller_event.SetSqlType(SQLTYPE_UPDATE);
    }

    if(event_type == wxEVT_DATABASE_DELETERESOURCEDEPOLY)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        for ( int i = 0; i < request_data.Size(); i++ )
        {
            sql_str += wxT("UPDATE 'resource_depoly' SET 'valid' = 0 WHERE id = ");
            sql_str += request_data[i].AsString();
            sql_str += wxT(";");
        }

        controller_event.SetSqlString(sql_str);
        controller_event.SetSqlType(SQLTYPE_UPDATE);
    }

    if(event_type == wxEVT_DATABASE_UPDATERESOURCEDEPOLY)
    {
        wxString sql_str = wxT("");
        wxJSONValue request_data = event.GetJsonData();

        sql_str += wxT("UPDATE 'resource_depoly' SET name = '");
        sql_str += request_data[0].AsString();
        sql_str += wxT("'");

        sql_str += wxT(" WHERE id = ");
        sql_str += request_data[1].AsString();

        controller_event.SetSqlString(sql_str);
        controller_event.SetSqlType(SQLTYPE_UPDATE);
    }

    controller_event.SetEventObject(event.GetEventObject());
    controller_event.SetStatus(event.GetStatus());
    controller_event.SetId(event.GetId());
    (wxGetApp().GetDatabase())->AddPendingEvent(controller_event);
}

void ResourceDepolyController::OnDatabaseResponse(wxDatabaseEvent& event)
{
    if(event.GetEventType() == wxEVT_DATABASE_GETRESOURCEDEPOLYLIST)
    {
        m_resourcedepolylist->Clear();

        wxJSONValue result_data = event.GetJsonData();
        for ( int i = 0; i < result_data.Size(); i++ )
        {
            m_resourcedepolylist->Add(ResourceDepolyInfo(
                wxAtoi(result_data[i][0].AsString()),
                result_data[i][1].AsString(),
                result_data[i][2].AsString(),
                wxAtoi(result_data[i][3].AsString()),
                result_data[i][4].AsString(),
                wxAtoi(result_data[i][5].AsString()),
                result_data[i][6].AsString(),
                wxAtoi(result_data[i][7].AsString()),
                result_data[i][8].AsString(),
                wxAtoi(result_data[i][9].AsString()),
                result_data[i][10].AsString(),
                wxAtoi(result_data[i][11].AsString()),
                result_data[i][12].AsString(),
                result_data[i][13].AsString()
            ));
        }
    }

    wxDatabaseEvent controller_event(event.GetEventType());
    controller_event.SetStatus(event.GetStatus());
    controller_event.SetErrorString(event.GetErrorString());
    controller_event.SetResultRow(event.GetResultRow());
    controller_event.SetJsonData(event.GetJsonData());
    ((wxEvtHandler *)event.GetEventObject())->AddPendingEvent(controller_event);
}
