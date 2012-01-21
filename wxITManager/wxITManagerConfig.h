#ifndef WXITMANAGERCONFIG_H_INCLUDED
#define WXITMANAGERCONFIG_H_INCLUDED

#include <wx/wx.h>
#include <wx/xml/xml.h>

#include "GlobalValue.h"

class ManagerConfig
{
    protected:
        size_t          m_databasetype;
        wxString        m_databasefile;
        wxString        m_databasekey;

    public:
        ManagerConfig();
        ~ManagerConfig();

        bool ReadConfigData();
        bool WriteConfigData();

        inline size_t GetDatabaseType(){return m_databasetype;}
        inline wxString GetDatabaseFile(){return m_databasefile;}
        inline wxString GetDatabaseKey(){return m_databasekey;}

        inline void SetDatabaseType(size_t type){m_databasetype = type;}
        inline void SetDatabaseFile(wxString filename){m_databasefile = filename;}
        inline void SetDatabaseKey(wxString key){m_databasekey = key;}
};

#endif // WXITMANAGERCONFIG_H_INCLUDED
