#include "wxITManagerController.h"

DECLARE_APP(wxITManagerApp)

DEFINE_EVENT_TYPE(wxEVT_DATABASE_UPDATEREQUEST)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_UPDATESUCCESS)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_UPDATEERROR)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_QUERYREQUEST)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_QUERYSUCCESS)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_QUERYERROR)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_CREATEDATABSE)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_TESTDATABSE)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_GETUSERLIST)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_ADDUSER)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_DELETEUSER)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_USERLOGIN)

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
        }

        if(event.GetEventType() == wxEVT_DATABASE_TESTDATABSE)
        {
            controller_event.SetSqlString(m_database->GetDBTestStr());
        }

        controller_event.SetEventObject(event.GetEventObject());
        controller_event.SetStatus(EVENTSTATUS_REQUEST);
        controller_event.SetId(CONTROLLER_DATABASE);
        m_database->AddPendingEvent(controller_event);
    }
    else
    {
        ::wxMilliSleep(100);

        wxDatabaseEvent controller_event(event.GetEventType());
        controller_event.SetStatus(EVENTSTATUS_REQUEST);
        controller_event.SetId(CONTROLLER_DATABASE);
        controller_event.SetEventObject(event.GetEventObject());
        this->AddPendingEvent(controller_event);
    }
}

UserController::UserController()
{
    m_currentuser   = NULL;
    m_userlist      = new UserInfoArray();

    this->Connect(wxEVT_DATABASE_USERLOGIN, wxDatabaseEventHandler(UserController::OnUserLogin));
    this->Connect(wxEVT_DATABASE_GETUSERLIST, wxDatabaseEventHandler(UserController::OnGetUserList));
}

UserController::~UserController()
{
    m_userlist->Clear();

    if(m_userlist) delete m_userlist;
    if(m_currentuser) delete m_currentuser;
}

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
        controller_event.SetSqlString(wxT("SELECT * FROM 'user';"));
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
            m_userlist->Add(UserInfo(result_data[i][0].AsInt(), result_data[i][1].AsString(), result_data[i][2].AsInt()));
        }

        wxDatabaseEvent controller_event(event.GetEventType());
        controller_event.SetStatus(event.GetStatus());
        ((wxEvtHandler *)event.GetEventObject())->AddPendingEvent(controller_event);
    }
}

void UserController::OnAddUser(wxDatabaseEvent& event)
{
}

void UserController::OnDeleteUser(wxDatabaseEvent& event)
{
}

UserGroupController::UserGroupController()
{
    m_usergrouplist = new UserGroupInfoArray();
}

UserGroupController::~UserGroupController()
{
    m_usergrouplist->Clear();

    if(m_usergrouplist) delete m_usergrouplist;
}
