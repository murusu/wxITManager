#ifndef WXITMANAGEREVENT_H_INCLUDED
#define WXITMANAGEREVENT_H_INCLUDED

#include <wx/event.h>

class wxDatabaseEvent : public wxNotifyEvent
{
    private:
        size_t          m_resultrow;
        wxString        m_errstr;

    public:
        wxDatabaseEvent(wxEventType commandType = wxEVT_NULL, int id = 0):
            wxNotifyEvent(commandType, id) {m_resultrow = 0;m_errstr = wxT("");};
        wxDatabaseEvent(const wxDatabaseEvent& event):
            wxNotifyEvent(event) {};
        virtual wxEvent *Clone() const {
            return new wxDatabaseEvent(*this);
        };

        inline size_t GetResultRow(){return m_resultrow;};
        inline void SetResultRow(size_t result_row){m_resultrow = result_row;};
        inline wxString GetErrorString(){return m_errstr;};
        inline void SetErrorString(wxString error_str){m_errstr = error_str;};

    DECLARE_DYNAMIC_CLASS(wxDatabaseEvent);
};

typedef void (wxEvtHandler::*wxDatabaseEventFunction) (wxDatabaseEvent&);

BEGIN_DECLARE_EVENT_TYPES()
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_CREATE, 100)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_CREATE_SUCCESS, 101)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_CREATE_ERROR, 102)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_UPDATE, 103)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_UPDATE_SUCCESS, 104)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_UPDATE_ERROR, 105)
END_DECLARE_EVENT_TYPES()

#define EVT_DATABASE_CREATE(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_CREATE, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_CREATE_SUCCESS(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_CREATE_SUCCESS, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_CREATE_ERROR(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_CREATE_ERROR, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_UPDATE(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_UPDATE, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
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


#endif // WXITMANAGEREVENT_H_INCLUDED
