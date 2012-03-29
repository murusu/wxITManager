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

        void OnDatabaseRequest(wxDatabaseEvent& event);
        void OnDatabaseResponse(wxDatabaseEvent& event);

        inline ManagerConfig* GetConfig(){return m_config;}
};

class UserController : public wxEvtHandler
{
    private:
        UserInfoArray *m_userlist;
        UserInfo      *m_currentuser;

    public:
        UserController();
        ~UserController();

        void OnRequest(wxDatabaseEvent& event);
        void OnUpdate(wxDatabaseEvent& event);
};

#endif // WXITMANAGERCONTROLLER_H_INCLUDED
