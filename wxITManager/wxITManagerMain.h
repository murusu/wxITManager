#ifndef WXITMANAGERMAIN_H_INCLUDED
#define WXITMANAGERMAIN_H_INCLUDED

#include <wx/wx.h>

#include "GlobalValue.h"
#include "wxITManagerEvent.h"
#include "wxITManagerUI.h"
#include "wxITManagerConfig.h"
#include "wxITManagerDatalist.h"
#include "wxITManagerController.h"
#include "wxITManagerDatabase.h"
#include "wxITManagerThread.h"

class MainFrame;
class LoginFrame;
class ManagerConfig;
class Database;
class DatabaseController;

class wxITManagerApp: public wxApp
{
    private:
        wxLocale            *m_locale;
        MainFrame           *m_mainframe;
        LoginFrame          *m_loginframe;

        ManagerConfig       *m_config;
        Database            *m_database;

        DatabaseController  *m_dbcontroller;

    public:
        bool    OnInit(void);
        int     OnExit(void);
        void    SetupLocale();

        void    DoLogin();
        void    DoLogout();
        void    DoExit();

        wxEvtHandler* GetController(size_t controller_id);

        ManagerConfig* GetConfig();
        Database* GetDatabase();
};



#endif // WXITMANAGERMAIN_H_INCLUDED
