#include "wxITManagerController.h"

DEFINE_EVENT_TYPE(wxEVT_DATABASE_CREATE)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_CREATE_SUCCESS)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_CREATE_ERROR)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_TEST)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_TEST_SUCCESS)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_TEST_ERROR)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_UPDATE)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_UPDATE_SUCCESS)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_UPDATE_ERROR)
IMPLEMENT_DYNAMIC_CLASS(wxDatabaseEvent, wxNotifyEvent)


DatabaseController::DatabaseController()
{
    m_database  = NULL;
    m_config    = NULL;

    m_config = new ManagerConfig();

    this->Connect(wxEVT_DATABASE_CREATE, wxDatabaseEventHandler(DatabaseController::OnDatabaseCreate));
    this->Connect(wxEVT_DATABASE_UPDATE_SUCCESS, wxDatabaseEventHandler(DatabaseController::OnDatabaseUpdate));
    this->Connect(wxEVT_DATABASE_UPDATE_ERROR, wxDatabaseEventHandler(DatabaseController::OnDatabaseUpdate));

    this->Connect(wxEVT_DATABASE_TEST, wxDatabaseEventHandler(DatabaseController::OnDatabaseTest));
    this->Connect(wxEVT_DATABASE_TEST_SUCCESS, wxDatabaseEventHandler(DatabaseController::OnDatabaseUpdate));
    this->Connect(wxEVT_DATABASE_TEST_ERROR, wxDatabaseEventHandler(DatabaseController::OnDatabaseUpdate));
}

DatabaseController::~DatabaseController()
{
    if(m_database) delete m_database;
    if(m_config) delete m_config;
}

void DatabaseController::OnDatabaseCreate(wxDatabaseEvent& event)
{
    if(m_database) delete m_database;
    m_database = NULL;
    m_database = DatabaseFactory::CreateDatabase(m_config->GetDatabaseType(), m_config);

    wxDatabaseEvent controller_event(event.GetEventType());
    controller_event.SetEventObject(event.GetEventObject());
    controller_event.SetId(CONTROLLER_DATABASE);
    m_database->AddPendingEvent(controller_event);
}

void DatabaseController::OnDatabaseUpdate(wxDatabaseEvent& event)
{
    if(m_database) delete m_database;
    m_database = NULL;

    wxDatabaseEvent controller_event(event.GetEventType());
    ((wxEvtHandler *)event.GetEventObject())->AddPendingEvent(controller_event);
}

void DatabaseController::OnDatabaseTest(wxDatabaseEvent& event)
{
    if(m_database) delete m_database;
    m_database = NULL;
    m_database = DatabaseFactory::CreateDatabase(m_config->GetDatabaseType(), m_config);

    wxDatabaseEvent controller_event(event.GetEventType());
    controller_event.SetEventObject(event.GetEventObject());
    controller_event.SetId(CONTROLLER_DATABASE);
    m_database->AddPendingEvent(controller_event);
}
