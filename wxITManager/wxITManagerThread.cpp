#include "wxITManagerThread.h"
/*
DEFINE_EVENT_TYPE(wxEVT_DATABASE_UPDATE_SUCCESS)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_UPDATE_ERROR)
IMPLEMENT_DYNAMIC_CLASS(wxDatabaseEvent, wxNotifyEvent)
*/
DECLARE_APP(wxITManagerApp)

DatabaseProcessThread::DatabaseProcessThread(wxObject* sender, size_t controller_id, Database *database, wxString sql, wxEventType type) : wxThread()
{
    m_sender        = sender;
    m_controller    = wxGetApp().GetController(controller_id);
    m_database      = database;
    m_sql           = sql;
    m_type          = type;
}

void DatabaseProcessThread::OnExit()
{
}

void *DatabaseProcessThread::Entry()
{
    size_t status       = EVENTSTATUS_SUCCESS;
    size_t result_row   = 0;
    wxString error_str  = wxT("");
    wxJSONValue result_json;

/*
    size_t event_id = 0;
    if(m_type == wxEVT_DATABASE_UPDATEREQUEST)
    {
        event_id = wxEVT_DATABASE_UPDATESUCCESS;
    }
    else
    {
        event_id = wxEVT_DATABASE_QUERYSUCCESS;
    }
*/
    try
    {
        if((m_type == wxEVT_DATABASE_CREATEDATABSE) )
        {
            result_row = m_database->ExecuteUpdate(m_sql);
        }

        if ((m_type == wxEVT_DATABASE_TESTDATABSE) )
        {
            result_json = m_database->ExecuteQuery(m_sql);
        }
    }
    catch(wxSQLite3Exception e)
    {
        error_str = e.GetMessage();
        status = EVENTSTATUS_FAIL;
    }

    wxDatabaseEvent event(m_type);
    event.SetEventObject(m_sender);
    event.SetStatus(status);
    event.SetResultRow(result_row);
    event.SetErrorString(error_str);
    event.SetResultJson(result_json);

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
