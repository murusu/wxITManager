#ifndef WXITMANAGERMAIN_H_INCLUDED
#define WXITMANAGERMAIN_H_INCLUDED

#include <wx/wx.h>
#include <wx/xml/xml.h>
#include <wx/event.h>
#include "wx/jsonreader.h"
#include "wx/jsonwriter.h"
#include <wx/dynarray.h>
#include <wx/arrimpl.cpp>
#include <wx/arrstr.h>
#include <wx/thread.h>
#include <wx/msgdlg.h>
#include <wx/listctrl.h>

#include "wx/wxsqlite3.h"

#include "md5.h"


#include "GlobalValue.h"
#include "wxITManagerMisc.h"
#include "wxITManagerEvent.h"
#include "wxITManagerDatalist.h"
#include "wxITManagerController.h"
#include "wxITManagerConfig.h"
#include "wxITManagerDatabase.h"
#include "wxITManagerThread.h"
#include "wxITManagerUIExtend.h"
#include "wxITManagerUIBase.h"
#include "wxITManagerUI.h"


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
class LocationController;

class ResourceController;
class ResourceTypeController;
class ResourceStatusController;
class ResourceFeeTypeController;

class ResourceDepolyController;

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
        LocationController          *m_locationcontroller;

        ResourceController          *m_resourcecontroller;
        ResourceTypeController      *m_resourcetypecontroller;
        ResourceStatusController    *m_resourcestatuscontroller;
        ResourceFeeTypeController   *m_resourcefeetypecontroller;

        ResourceDepolyController    *m_resourcedepolycontroller;

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
