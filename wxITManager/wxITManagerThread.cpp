#include "wxITManagerThread.h"
/*
DEFINE_EVENT_TYPE(wxEVT_DATABASE_UPDATE_SUCCESS)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_UPDATE_ERROR)
IMPLEMENT_DYNAMIC_CLASS(wxDatabaseEvent, wxNotifyEvent)
*/
DECLARE_APP(wxITManagerApp)

DatabaseUpdateThread::DatabaseUpdateThread(wxObject* sender, size_t controller_id, Database *database, wxString sql) : wxThread()
{
    m_sender        = sender;
    m_controller    = wxGetApp().GetController(controller_id);
    m_database      = database;
    m_sql           = sql;
}

void DatabaseUpdateThread::OnExit()
{
}

void *DatabaseUpdateThread::Entry()
{
    size_t result_row = 0;
    wxString error_str = wxT("");
    size_t event_id = wxEVT_DATABASE_UPDATE_SUCCESS;

    try
    {
        result_row = m_database->ExecuteUpdate(m_sql);
    }
    catch(wxSQLite3Exception e)
    {
        error_str = e.GetMessage();
        event_id = wxEVT_DATABASE_UPDATE_ERROR;
    }

    wxDatabaseEvent event(event_id);
    event.SetEventObject(m_sender);
    event.SetResultRow(result_row);
    event.SetErrorString(error_str);

    if(m_controller)
    {
       m_controller->AddPendingEvent(event);
    }
    else
    {
        ((wxEvtHandler *)m_sender)->AddPendingEvent(event);
    }

    return NULL;
}
