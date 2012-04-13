#ifndef WXITMANAGERCONTROLLER_H_INCLUDED
#define WXITMANAGERCONTROLLER_H_INCLUDED

#include "wxITManagerMain.h"
//#include "wxITManagerEvent.h"
//#include "wxITManagerDatabase.h"

class Database;
class ManagerConfig;

class Controller : public wxEvtHandler
{
    public:
        void OnDatabaseEvent(wxDatabaseEvent& event)
        {
            if(event.GetStatus() == EVENTSTATUS_REQUEST)
            {
                OnDatabaseRequest(event);
            }
            else
            {
                OnDatabaseResponse(event);
            }
        };
        virtual void OnDatabaseRequest(wxDatabaseEvent& event){};
        virtual void OnDatabaseResponse(wxDatabaseEvent& event){};
};

class DatabaseController : public Controller
{
    private:
        Database        *m_database;
        ManagerConfig   *m_config;

        wxMutex         *m_mutex;
        wxMutexLocker   *m_locker;

    public:
        DatabaseController();
        ~DatabaseController();

        //void OnDatabaseEvent(wxDatabaseEvent& event);
        void OnDatabaseRequest(wxDatabaseEvent& event);
        void OnDatabaseResponse(wxDatabaseEvent& event);

        inline ManagerConfig* GetConfig(){return m_config;}
};

class AuthorityController : public Controller
{
    private:
        size_t          m_id;
        wxString        m_name;
        size_t          m_usergroupid;
        wxString        m_usergroupname;

    public:
        AuthorityController();

        //void OnDatabaseEvent(wxDatabaseEvent& event);
        void OnDatabaseRequest(wxDatabaseEvent& event);
        void OnDatabaseResponse(wxDatabaseEvent& event);

        void Clear(){m_id = 0; m_name = wxT(""); m_usergroupid = 0; m_usergroupname = wxT("");};

        inline size_t GetUserId(){return m_id;};
        inline wxString GetUserName(){return m_name;};
        inline wxString GetUserGroupName(){return m_usergroupname;};
};

class UserController : public Controller
{
    private:
        UserInfoArray *m_userlist;

    public:
        UserController();
        ~UserController();

        //void OnDatabaseEvent(wxDatabaseEvent& event);
        void OnDatabaseRequest(wxDatabaseEvent& event);
        void OnDatabaseResponse(wxDatabaseEvent& event);

        size_t getItemNumber() {return m_userlist->GetCount();};
        UserInfoArray* GetList() {return m_userlist;};
};

class UserGroupController : public Controller
{
    private:
        UserGroupInfoArray *m_usergrouplist;

    public:
        UserGroupController();
        ~UserGroupController();

        //void OnDatabaseEvent(wxDatabaseEvent& event);
        void OnDatabaseRequest(wxDatabaseEvent& event);
        void OnDatabaseResponse(wxDatabaseEvent& event);

        size_t getItemNumber() {return m_usergrouplist->GetCount();};
        UserGroupInfoArray* GetList() {return m_usergrouplist;};
};

class VcardController : public Controller
{
    private:
        VcardInfoArray *m_vcardlist;

    public:
        VcardController();
        ~VcardController();

        //void OnDatabaseEvent(wxDatabaseEvent& event);
        void OnDatabaseRequest(wxDatabaseEvent& event);
        void OnDatabaseResponse(wxDatabaseEvent& event);

        size_t getItemNumber() {return m_vcardlist->GetCount();};
        VcardInfoArray* GetList() {return m_vcardlist;};
};

class VcardGroupController : public Controller
{
    private:
        VcardGroupInfoArray *m_vcardgrouplist;

    public:
        VcardGroupController();
        ~VcardGroupController();

        //void OnDatabaseEvent(wxDatabaseEvent& event);
        void OnDatabaseRequest(wxDatabaseEvent& event);
        void OnDatabaseResponse(wxDatabaseEvent& event);

        size_t getItemNumber() {return m_vcardgrouplist->GetCount();};
        VcardGroupInfoArray* GetList() {return m_vcardgrouplist;};
};

class CompanyController : public Controller
{
    private:
        CompanyInfoArray *m_companylist;

    public:
        CompanyController();
        ~CompanyController();

        //void OnDatabaseEvent(wxDatabaseEvent& event);
        void OnDatabaseRequest(wxDatabaseEvent& event);
        void OnDatabaseResponse(wxDatabaseEvent& event);

        size_t getItemNumber() {return m_companylist->GetCount();};
        CompanyInfoArray* GetList() {return m_companylist;};
};

class CompanyTypeController : public Controller
{
    private:
        CompanyTypeInfoArray *m_companytypelist;

    public:
        CompanyTypeController();
        ~CompanyTypeController();

        //void OnDatabaseEvent(wxDatabaseEvent& event);
        void OnDatabaseRequest(wxDatabaseEvent& event);
        void OnDatabaseResponse(wxDatabaseEvent& event);

        size_t getItemNumber() {return m_companytypelist->GetCount();};
        CompanyTypeInfoArray* GetList() {return m_companytypelist;};
};

#endif // WXITMANAGERCONTROLLER_H_INCLUDED
