#ifndef WXITMANAGERTHREAD_H_INCLUDED
#define WXITMANAGERTHREAD_H_INCLUDED

#include "wxITManagerMain.h"

class Database;
class wxEventHandler;

class DatabaseProcessThread : public wxThread
{
    protected:
        wxObject        *m_sender;
        wxEvtHandler    *m_controller;
        Database        *m_database;
        wxString         m_sql;
        wxEventType      m_eventtype;
        size_t           m_sqltype;

    public:
        DatabaseProcessThread(wxObject* sender, size_t controller_id, Database *database, wxString sql, wxEventType event_type, size_t sql_type);

        void *Entry();
        void OnExit();
};

#endif // WXITMANAGERTHREAD_H_INCLUDED
