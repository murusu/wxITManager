#include "wxITManagerController.h"

DEFINE_EVENT_TYPE(wxEVT_DATABASE_CREATE)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_CREATE_SUCCESS)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_CREATE_ERROR)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_UPDATE)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_UPDATE_SUCCESS)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_UPDATE_ERROR)
IMPLEMENT_DYNAMIC_CLASS(wxDatabaseEvent, wxNotifyEvent)

DECLARE_APP(wxITManagerApp)

DatabaseController::DatabaseController()
{
    m_database  = NULL;
    m_config    = NULL;

    m_config = new ManagerConfig();

    this->Connect(wxEVT_DATABASE_CREATE, wxDatabaseEventHandler(DatabaseController::OnDatabaseCreate));
}

DatabaseController::~DatabaseController()
{
    if(m_database) delete m_database;
    if(m_config) delete m_config;
}

void DatabaseController::OnDatabaseCreate(wxDatabaseEvent& event)
{
    if(m_database) delete m_database;
    m_database = DatabaseFactory::CreateDatabase(m_config->GetDatabaseType(), m_config);
    //m_database->InitDBByConfig(m_config);

    wxDatabaseEvent controller_event(event.GetEventType());
    controller_event.SetEventObject(event.GetEventObject());
    controller_event.SetId(event.GetId());
    //controller_event = event.Clone();
    //controller_event.SetEventObject(event.GetEventObject());
    m_database->AddPendingEvent(controller_event);
}
