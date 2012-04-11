#ifndef WXITMANAGERCONTROLLER_H_INCLUDED
#define WXITMANAGERCONTROLLER_H_INCLUDED

#include "wxITManagerMain.h"
//#include "wxITManagerEvent.h"
//#include "wxITManagerDatabase.h"

class Database;
class ManagerConfig;

class DatabaseController : public wxEvtHandler
{
    private:
        Database        *m_database;
        ManagerConfig   *m_config;

        wxMutex         *m_mutex;
        wxMutexLocker   *m_locker;

    public:
        DatabaseController();
        ~DatabaseController();

        void OnDatabaseEvent(wxDatabaseEvent& event);
        void OnDatabaseRequest(wxDatabaseEvent& event);
        void OnDatabaseResponse(wxDatabaseEvent& event);

        inline ManagerConfig* GetConfig(){return m_config;}
};

class AuthorityController : public wxEvtHandler
{
    private:
        size_t          m_id;
        wxString        m_name;
        size_t          m_usergroupid;
        wxString        m_usergroupname;

    public:
        AuthorityController();

        void OnDatabaseEvent(wxDatabaseEvent& event);
        void OnDatabaseRequest(wxDatabaseEvent& event);
        void OnDatabaseResponse(wxDatabaseEvent& event);

        void Clear(){m_id = 0; m_name = wxT(""); m_usergroupid = 0; m_usergroupname = wxT("");};

        inline size_t GetUserId(){return m_id;};
        inline wxString GetUserName(){return m_name;};
        inline wxString GetUserGroupName(){return m_usergroupname;};
};

class UserController : public wxEvtHandler
{
    private:
        UserInfoArray *m_userlist;
        //UserInfo      *m_currentuser;

    public:
        UserController();
        ~UserController();

        //void OnUserLogin(wxDatabaseEvent& event);
        //void OnGetUserList(wxDatabaseEvent& event);
        //void OnAddUser(wxDatabaseEvent& event);
        //void OnDeleteUser(wxDatabaseEvent& event);
        //void OnUpdateUser(wxDatabaseEvent& event);

        void OnDatabaseEvent(wxDatabaseEvent& event);
        void OnDatabaseRequest(wxDatabaseEvent& event);
        void OnDatabaseResponse(wxDatabaseEvent& event);

        size_t getItemNumber() {return m_userlist->GetCount();};
        UserInfoArray* GetList() {return m_userlist;};
};

class UserGroupController : public wxEvtHandler
{
    private:
        UserGroupInfoArray *m_usergrouplist;

    public:
        UserGroupController();
        ~UserGroupController();

        //void OnGetUserGroupList(wxDatabaseEvent& event);

        void OnDatabaseEvent(wxDatabaseEvent& event);
        void OnDatabaseRequest(wxDatabaseEvent& event);
        void OnDatabaseResponse(wxDatabaseEvent& event);

        size_t getItemNumber() {return m_usergrouplist->GetCount();};
        UserGroupInfoArray* GetList() {return m_usergrouplist;};
};

#endif // WXITMANAGERCONTROLLER_H_INCLUDED
