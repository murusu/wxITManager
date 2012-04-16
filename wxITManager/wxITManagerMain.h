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
#include "wxITManagerMisc.h"

class MainFrame;
class LoginFrame;
class ManagerConfig;
class Database;
class DatabaseController;
class AuthorityController;
class UserController;
class UserGroupController;
class VcardController;
class VcardGroupController;
class CompanyController;
class CompanyTypeController;

class ResourceController;
class ResourceTypeController;
class ResourceStatusController;
class ResourceFeeTypeController;

class wxITManagerApp: public wxApp
{
    private:
        wxLocale            *m_locale;
        MainFrame           *m_mainframe;
        LoginFrame          *m_loginframe;

        ManagerConfig       *m_config;
        Database            *m_database;

        DatabaseController          *m_dbcontroller;
        AuthorityController         *m_authcontroller;

        UserController              *m_usercontroller;
        UserGroupController         *m_usergroupcontroller;

        VcardController             *m_vcardcontroller;
        VcardGroupController        *m_vcardgroupcontroller;
        CompanyController           *m_companycontroller;
        CompanyTypeController       *m_companytypecontroller;

        ResourceController          *m_resourcecontroller;
        ResourceTypeController      *m_resourcetypecontroller;
        ResourceStatusController    *m_resourcestatuscontroller;
        ResourceFeeTypeController   *m_resourcefeetypecontroller;

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

        inline MainFrame* GetMainFrame(){return m_mainframe;};
};



#endif // WXITMANAGERMAIN_H_INCLUDED
