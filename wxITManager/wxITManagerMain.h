#ifndef WXITMANAGERMAIN_H_INCLUDED
#define WXITMANAGERMAIN_H_INCLUDED

#include <wx/wx.h>

#include "wxITManagerUI.h"
#include "wxITManagerConfig.h"
//#include "wxITManagerDatabase.h"
#include "wxITManagerController.h"

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

        inline ManagerConfig* GetConfig(){return m_config;}
};



#endif // WXITMANAGERMAIN_H_INCLUDED
