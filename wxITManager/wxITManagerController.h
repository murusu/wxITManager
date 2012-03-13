#ifndef WXITMANAGERCONTROLLER_H_INCLUDED
#define WXITMANAGERCONTROLLER_H_INCLUDED

#include "wxITManagerMain.h"
#include "wxITManagerEvent.h"
#include "wxITManagerDatabase.h"

class Database;

class DatabaseController : public wxEvtHandler
{
    private:
        Database        *m_database;
        ManagerConfig   *m_config;

    public:
        DatabaseController();
        ~DatabaseController();

        void OnDatabaseCreate(wxDatabaseEvent& event);

        inline ManagerConfig* GetConfig(){return m_config;}
        //inline DatabaseController* GetDatabaseController(){return m_dbcontroller;}
};

#endif // WXITMANAGERCONTROLLER_H_INCLUDED
