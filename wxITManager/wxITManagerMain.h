#ifndef WXITMANAGERMAIN_H_INCLUDED
#define WXITMANAGERMAIN_H_INCLUDED

#include <wx/wx.h>

#include "wxITManagerUI.h"
#include "wxITManagerConfig.h"
#include "wxITManagerDatabase.h"



class MainFrame;
class LoginFrame;
class ManagerConfig;

class wxITManagerApp: public wxApp
{
    private:
        wxLocale        *m_locale;
        MainFrame       *m_mainframe;
        LoginFrame      *m_loginframe;
        ManagerConfig   *m_config;
        Database        *m_database;

    public:
        bool    OnInit(void);
        int     OnExit(void);
        void    SetupLocale();

        void    DoLogin();
        void    DoLogout();
        void    DoExit();

        inline ManagerConfig* GetConfig(){return m_config;}
        inline Database* GetDatabase(){return m_database;}
};



#endif // WXITMANAGERMAIN_H_INCLUDED
