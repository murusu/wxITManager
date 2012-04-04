#ifndef WXITMANAGEREVENT_H_INCLUDED
#define WXITMANAGEREVENT_H_INCLUDED

#include <wx/event.h>

#include "wx/jsonreader.h"
#include "wx/jsonwriter.h"

class wxDatabaseEvent : public wxNotifyEvent
{
    private:
        size_t          m_status;
        size_t          m_resultrow;
        wxString        m_errstr;
        wxString        m_sqlstr;
        wxJSONValue     m_json;

    public:
        wxDatabaseEvent(wxEventType commandType = wxEVT_NULL, int id = 0):
            wxNotifyEvent(commandType, id) {m_status = EVENTSTATUS_REQUEST;m_resultrow = 0;m_errstr = wxT("");m_sqlstr = wxT("");};
        wxDatabaseEvent(const wxDatabaseEvent& event):
            wxNotifyEvent(event),
            m_status(event.m_status),
            m_resultrow(event.m_resultrow),
            m_errstr(event.m_errstr),
            m_sqlstr(event.m_sqlstr),
            m_json(event.m_json)
            {};
        virtual wxEvent *Clone() const {
            return new wxDatabaseEvent(*this);
        };

        inline size_t GetStatus(){return m_status;};
        inline void SetStatus(size_t status){m_status = status;};
        inline size_t GetResultRow(){return m_resultrow;};
        inline void SetResultRow(size_t result_row){m_resultrow = result_row;};
        inline wxString GetErrorString(){return m_errstr;};
        inline void SetErrorString(wxString error_str){m_errstr = error_str;};
        inline wxString GetSqlString(){return m_sqlstr;};
        inline void SetSqlString(wxString sql_str){m_sqlstr = sql_str;};
        inline wxJSONValue GetJsonData(){return m_json;};
        inline void SetJsonData(wxJSONValue json){m_json = json;};

    DECLARE_DYNAMIC_CLASS(wxDatabaseEvent);
};

typedef void (wxEvtHandler::*wxDatabaseEventFunction) (wxDatabaseEvent&);

BEGIN_DECLARE_EVENT_TYPES()

    DECLARE_EVENT_TYPE(wxEVT_DATABASE_UPDATEREQUEST, 100)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_UPDATESUCCESS, 101)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_UPDATEERROR, 102)

    DECLARE_EVENT_TYPE(wxEVT_DATABASE_QUERYREQUEST, 103)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_QUERYSUCCESS, 104)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_QUERYERROR, 105)

    DECLARE_EVENT_TYPE(wxEVT_DATABASE_CREATEDATABSE, 106)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_TESTDATABSE, 107)

    DECLARE_EVENT_TYPE(wxEVT_DATABASE_GETUSERLIST, 108)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_ADDUSER, 109)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_DELETEUSER, 110)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_USERLOGIN, 111)

END_DECLARE_EVENT_TYPES()

#define EVT_DATABASE_UPDATEREQUEST(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_UPDATEREQUEST, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_UPDATESUCCESS(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_UPDATESUCCESS, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_UPDATEERROR(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_UPDATEERROR, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),

#define EVT_DATABASE_QUERYREQUEST(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_QUERYEQUEST, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_QUERYSUCCESS(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_QUERYSUCCESS, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_QUERYERROR(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_QUERYERROR, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),

#define EVT_DATABASE_CREATEDATABSE(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_CREATEDATABSE, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_TESTDATABSE(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_TESTDATABSE, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),

#define EVT_DATABASE_GETUSERLIST(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_GETUSERLIST, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_ADDUSER(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_ADDUSER, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_DELETEUSER(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_DELETEUSER, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),

#define wxDatabaseEventHandler(func) \
    (wxObjectEventFunction)(wxEventFunction)wxStaticCastEvent(wxDatabaseEventFunction, &func)


#endif // WXITMANAGEREVENT_H_INCLUDED
