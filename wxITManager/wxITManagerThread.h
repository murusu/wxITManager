#ifndef WXITMANAGERTHREAD_H_INCLUDED
#define WXITMANAGERTHREAD_H_INCLUDED

#include <wx/thread.h>

#include "wxITManagerMain.h"
#include "wxITManagerDatabase.h"

class Database;
class wxEventHandler;

class DatabaseUpdateThread : public wxThread
{
    protected:
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
