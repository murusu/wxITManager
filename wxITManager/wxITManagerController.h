#ifndef WXITMANAGERCONTROLLER_H_INCLUDED
#define WXITMANAGERCONTROLLER_H_INCLUDED

#include "wxITManagerMain.h"

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

        void OnDatabaseRequest(wxDatabaseEvent& event);
        void OnDatabaseResponse(wxDatabaseEvent& event);

        size_t getItemNumber() {return m_companytypelist->GetCount();};
        CompanyTypeInfoArray* GetList() {return m_companytypelist;};
};

class LocationController : public Controller
{
    private:
        LocationInfoArray *m_locationlist;

    public:
        LocationController();
        ~LocationController();

        void OnDatabaseRequest(wxDatabaseEvent& event);
        void OnDatabaseResponse(wxDatabaseEvent& event);

        size_t getItemNumber() {return m_locationlist->GetCount();};
        LocationInfoArray* GetList() {return m_locationlist;};
};

class ResourceController : public Controller
{
    private:
        ResourceInfoArray *m_resourcelist;

    public:
        ResourceController();
        ~ResourceController();

        void OnDatabaseRequest(wxDatabaseEvent& event);
        void OnDatabaseResponse(wxDatabaseEvent& event);

        size_t getItemNumber() {return m_resourcelist->GetCount();};
        ResourceInfoArray* GetList() {return m_resourcelist;};
};

class ResourceTypeController : public Controller
{
    private:
        ResourceTypeInfoArray *m_resourcetypelist;

    public:
        ResourceTypeController();
        ~ResourceTypeController();

        void OnDatabaseRequest(wxDatabaseEvent& event);
        void OnDatabaseResponse(wxDatabaseEvent& event);

        size_t getItemNumber() {return m_resourcetypelist->GetCount();};
        ResourceTypeInfoArray* GetList() {return m_resourcetypelist;};
};

class ResourceStatusController : public Controller
{
    private:
        ResourceStatusInfoArray *m_resourcestatuslist;

    public:
        ResourceStatusController();
        ~ResourceStatusController();

        void OnDatabaseRequest(wxDatabaseEvent& event);
        void OnDatabaseResponse(wxDatabaseEvent& event);

        size_t getItemNumber() {return m_resourcestatuslist->GetCount();};
        ResourceStatusInfoArray* GetList() {return m_resourcestatuslist;};
};

class ResourceFeeTypeController : public Controller
{
    private:
        ResourceFeeTypeInfoArray *m_resourcefeetypelist;

    public:
        ResourceFeeTypeController();
        ~ResourceFeeTypeController();

        void OnDatabaseRequest(wxDatabaseEvent& event);
        void OnDatabaseResponse(wxDatabaseEvent& event);

        size_t getItemNumber() {return m_resourcefeetypelist->GetCount();};
        ResourceFeeTypeInfoArray* GetList() {return m_resourcefeetypelist;};
};

class ResourceDepolyController : public Controller
{
    private:
        ResourceDepolyInfoArray *m_resourcedepolylist;

    public:
        ResourceDepolyController();
        ~ResourceDepolyController();

        void OnDatabaseRequest(wxDatabaseEvent& event);
        void OnDatabaseResponse(wxDatabaseEvent& event);

        size_t getItemNumber() {return m_resourcedepolylist->GetCount();};
        ResourceDepolyInfoArray* GetList() {return m_resourcedepolylist;};
};

#endif // WXITMANAGERCONTROLLER_H_INCLUDED
