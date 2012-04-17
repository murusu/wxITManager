#include "wxITManagerThread.h"

DECLARE_APP(wxITManagerApp)

DatabaseProcessThread::DatabaseProcessThread(wxObject* sender, size_t controller_id, Database *database, wxString sql, wxEventType event_type, size_t sql_type) : wxThread()
{
    m_sender        = sender;
    m_controller    = wxGetApp().GetController(controller_id);
    m_database      = database;
    m_sql           = sql;
    m_eventtype     = event_type;
    m_sqltype       = sql_type;
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

    try
    {
        if(m_sqltype == SQLTYPE_UPDATE)
        {
            result_row = m_database->ExecuteUpdate(m_sql);
        }
        if(m_sqltype == SQLTYPE_QUERY)
        {
            result_json = m_database->ExecuteQuery(m_sql);
        }
    }
    catch(wxSQLite3Exception e)
    {
        error_str = e.GetMessage();
        status = EVENTSTATUS_FAIL;
    }

    wxDatabaseEvent event(m_eventtype);
    event.SetEventObject(m_sender);
    event.SetStatus(status);
    event.SetResultRow(result_row);
    event.SetErrorString(error_str);
    event.SetJsonData(result_json);

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
