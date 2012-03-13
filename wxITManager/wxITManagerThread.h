#ifndef WXITMANAGERTHREAD_H_INCLUDED
#define WXITMANAGERTHREAD_H_INCLUDED

#include <wx/thread.h>

#include "wxITManagerMain.h"
#include "wxITManagerDatabase.h"

class Database;
class wxEventHandler;
//#include <wx/event.h>
/*
class wxDatabaseEvent : public wxNotifyEvent
{
    public:
        wxDatabaseEvent(wxEventType commandType = wxEVT_NULL, int id = 0):
            wxNotifyEvent(commandType, id) {}
        wxDatabaseEvent(const wxDatabaseEvent& event):
            wxNotifyEvent(event) {}
        virtual wxEvent *Clone() const {
            return new wxDatabaseEvent(*this);
        }

    DECLARE_DYNAMIC_CLASS(wxDatabaseEvent);
};

typedef void (wxEvtHandler::*wxDatabaseEventFunction) (wxDatabaseEvent&);

BEGIN_DECLARE_EVENT_TYPES()
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_UPDATE_SUCCESS, 100)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_UPDATE_ERROR, 101)
END_DECLARE_EVENT_TYPES()

#define EVT_DATABASE_UPDATE_SUCCESS(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_UPDATE_SUCCESS, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_UPDATE_ERROR(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_UPDATE_ERROR, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),

#define wxDatabaseEventHandler(func) \
    (wxObjectEventFunction)(wxEventFunction)wxStaticCastEvent(wxDatabaseEventFunction, &func)
*/

class DatabaseUpdateThread : public wxThread
{
    protected:
        //size_t          *m_resultrow;
        //wxString        *m_errstr;
        wxObject        *m_sender;
        wxEvtHandler    *m_controller;
        Database        *m_database;
        wxString         m_sql;

    public:
        DatabaseUpdateThread(wxObject* sender, size_t controller_id, Database *database, wxString sql);

        void *Entry();
        void OnExit();
};

#endif // WXITMANAGERTHREAD_H_INCLUDED
