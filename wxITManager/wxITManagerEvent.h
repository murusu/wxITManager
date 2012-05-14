#ifndef WXITMANAGEREVENT_H_INCLUDED
#define WXITMANAGEREVENT_H_INCLUDED

#include "wxITManagerMain.h"

class wxDatabaseEvent : public wxNotifyEvent
{
    private:
        size_t          m_status;
        size_t          m_resultrow;
        size_t          m_sqltype;
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
            m_sqltype(event.m_sqltype),
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
        inline size_t GetSqlType(){return m_sqltype;};
        inline void SetSqlType(size_t sqltype){m_sqltype = sqltype;};
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
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_CREATEDATABSE, 106)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_TESTDATABSE, 107)

    DECLARE_EVENT_TYPE(wxEVT_DATABASE_USERLOGIN, 108)

    DECLARE_EVENT_TYPE(wxEVT_DATABASE_GETUSERLIST, 109)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_ADDUSER, 110)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_DELETEUSER, 111)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_UPDATEUSER, 112)

    DECLARE_EVENT_TYPE(wxEVT_DATABASE_GETUSERGROUPLIST, 113)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_ADDUSERGROUP, 114)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_DELETEUSERGROUP, 115)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_UPDATEUSERGROUP, 116)

    DECLARE_EVENT_TYPE(wxEVT_DATABASE_GETVCARDLIST, 117)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_ADDVCARD, 118)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_DELETEVCARD, 119)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_UPDATEVCARD, 120)

    DECLARE_EVENT_TYPE(wxEVT_DATABASE_GETVCARDGROUPLIST, 121)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_ADDVCARDGROUP, 122)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_DELETEVCARDGROUP, 123)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_UPDATEVCARDGROUP, 124)

    DECLARE_EVENT_TYPE(wxEVT_DATABASE_GETCOMPANYLIST, 125)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_ADDCOMPANY, 126)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_DELETECOMPANY, 127)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_UPDATECOMPANY, 128)

    DECLARE_EVENT_TYPE(wxEVT_DATABASE_GETCOMPANYTYPELIST, 129)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_ADDCOMPANYTYPE, 130)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_DELETECOMPANYTYPE, 131)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_UPDATECOMPANYTYPE, 132)

    DECLARE_EVENT_TYPE(wxEVT_DATABASE_GETLOCATIONLIST, 133)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_ADDLOCATION, 134)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_DELETELOCATION, 135)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_UPDATELOCATION, 136)

    DECLARE_EVENT_TYPE(wxEVT_DATABASE_GETRESOURCELIST, 137)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_ADDRESOURCE, 138)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_DELETERESOURCE, 139)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_UPDATERESOURCE, 140)

    DECLARE_EVENT_TYPE(wxEVT_DATABASE_GETRESOURCETYPELIST, 141)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_ADDRESOURCETYPE, 142)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_DELETERESOURCETYPE, 143)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_UPDATERESOURCETYPE, 144)

    DECLARE_EVENT_TYPE(wxEVT_DATABASE_GETRESOURCESTATUSLIST, 145)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_ADDRESOURCESTATUS, 146)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_DELETERESOURCESTATUS, 147)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_UPDATERESOURCESTATUS, 148)

    DECLARE_EVENT_TYPE(wxEVT_DATABASE_GETRESOURCEFEETYPELIST, 149)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_ADDRESOURCEFEETYPE, 150)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_DELETERESOURCEFEETYPE, 151)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_UPDATERESOURCEFEETYPE, 152)

    DECLARE_EVENT_TYPE(wxEVT_DATABASE_GETRESOURCEDEPLOYLIST, 153)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_ADDRESOURCEDEPLOY, 154)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_DELETERESOURCEDEPLOY, 155)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_UPDATERESOURCEDEPLOY, 156)

    DECLARE_EVENT_TYPE(wxEVT_DATABASE_GETRESOURCEFEELIST, 157)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_ADDRESOURCEFEE, 158)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_DELETERESOURCEFEE, 159)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_UPDATERESOURCEFEE, 160)

    DECLARE_EVENT_TYPE(wxEVT_DATABASE_GETRESOURCELOGLIST, 161)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_ADDRESOURCELOG, 162)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_DELETERESOURCELOG, 163)
    DECLARE_EVENT_TYPE(wxEVT_DATABASE_UPDATERESOURCELOG, 164)

END_DECLARE_EVENT_TYPES()
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
#define EVT_DATABASE_UPDATEUSER(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_UPDATEUSER, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),

#define EVT_DATABASE_GETUSERGROUPLIST(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_GETUSERGROUPLIST, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_ADDUSERGROUP(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_ADDUSERGROUP, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_DELETEUSERGROUP(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_DELETEUSERGROUP, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_UPDATEUSERGROUP(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_UPDATEUSERGROUP, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),

#define EVT_DATABASE_GETVCARDLIST(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_GETVCARDLIST, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_ADDVCARD(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_ADDVCARD, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_DELETEVCARD(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_DELETEVCARD, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_UPDATEVCARD(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_UPDATEVCARD, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),

#define EVT_DATABASE_GETVCARDGROUPLIST(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_GETVCARDGROUPLIST, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_ADDVCARDGROUP(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_ADDVCARDGROUP, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_DELETEVCARDGROUP(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_DELETEVCARDGROUP, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_UPDATEVCARDGROUP(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_UPDATEVCARDGROUP, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),

#define EVT_DATABASE_GETCOMPANYLIST(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_GETCOMPANYLIST, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_ADDCOMPANY(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_ADDCOMPANY, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_DELETECOMPANY(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_DELETECOMPANY, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_UPDATECOMPANY(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_UPDATECOMPANY, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),

#define EVT_DATABASE_GETCOMPANYTYPELIST(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_GETCOMPANYTYPELIST, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_ADDCOMPANYTYPE(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_ADDCOMPANYTYPE, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_DELETECOMPANYTYPE(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_DELETECOMPANYTYPE, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_UPDATECOMPANYTYPE(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_UPDATECOMPANYTYPE, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),

#define EVT_DATABASE_GETLOCATIONLIST(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_GETLOCATIONLIST, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_ADDLOCATION(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_ADDLOCATION, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_DELETELOCATION(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_DELETELOCATION, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_UPDATELOCATION(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_UPDATELOCATION, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),

#define EVT_DATABASE_GETRESOURCELIST(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_GETRESOURCELIST, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_ADDRESOURCE(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_ADDRESOURCE, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_DELETERESOURCE(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_DELETERESOURCE, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_UPDATERESOURCE(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_UPDATERESOURCE, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),

#define EVT_DATABASE_GETRESOURCETYPELIST(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_GETRESOURCETYPELIST, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_ADDRESOURCETYPE(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_ADDRESOURCETYPE, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_DELETERESOURCETYPE(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_DELETERESOURCETYPE, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_UPDATERESOURCETYPE(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_UPDATERESOURCETYPE, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),

#define EVT_DATABASE_GETRESOURCESTATUSLIST(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_GETRESOURCESTATUSLIST, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_ADDRESOURCESTATUS(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_ADDRESOURCESTATUS, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_DELETERESOURCESTATUS(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_DELETERESOURCESTATUS, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_UPDATERESOURCESTATUS(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_UPDATERESOURCESTATUS, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),

#define EVT_DATABASE_GETRESOURCEFEETYPELIST(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_GETRESOURCEFEETYPELIST, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_ADDRESOURCEFEETYPE(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_ADDRESOURCEFEETYPE, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_DELETERESOURCEFEETYPE(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_DELETERESOURCEFEETYPE, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_UPDATERESOURCEFEETYPE(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_UPDATERESOURCEFEETYPE, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),

#define EVT_DATABASE_GETRESOURCEDEPLOYLIST(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_GETRESOURCEDEPLOYLIST, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_ADDRESOURCEDEPLOY(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_ADDRESOURCEDEPLOY, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_DELETERESOURCEDEPLOY(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_DELETERESOURCEDEPLOY, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_UPDATERESOURCEDEPLOY(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_UPDATERESOURCEDEPLOY, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),

#define EVT_DATABASE_GETRESOURCEFEELIST(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_GETRESOURCEFEELIST, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_ADDRESOURCEFEE(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_ADDRESOURCEFEE, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_DELETERESOURCEFEE(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_DELETERESOURCEFEE, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_UPDATERESOURCEFEE(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_UPDATERESOURCEFEE, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),

#define EVT_DATABASE_GETRESOURCELOGLIST(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_GETRESOURCELOGLIST, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_ADDRESOURCELOG(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_ADDRESOURCELOG, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_DELETERESOURCELOG(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_DELETERESOURCELOG, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),
#define EVT_DATABASE_UPDATERESOURCELOG(fn) DECLARE_EVENT_TABLE_ENTRY( \
    wxEVT_DATABASE_UPDATERESOURCELOG, 0, -1, (wxObjectEventFunction) \
    (wxEventFunction) (wxDatabaseEventFunction) & fn, \
    (wxObject *) NULL ),

#define wxDatabaseEventHandler(func) \
    (wxObjectEventFunction)(wxEventFunction)wxStaticCastEvent(wxDatabaseEventFunction, &func)


#endif // WXITMANAGEREVENT_H_INCLUDED
