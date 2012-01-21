#ifndef WXITMANAGERDATABASE_H_INCLUDED
#define WXITMANAGERDATABASE_H_INCLUDED

#include <wx/wx.h>
#include "wx/wxsqlite3.h"

#include "GlobalValue.h"
#include "wxITManagerConfig.h"

class Database : public wxEvtHandler
{
    public:
        Database();
        ~Database();

        void SetupTable();

        virtual bool InitDatabase(ManagerConfig *database_config) {return NULL;};
        virtual size_t RunSql(wxString sql_string) {return NULL;};
};

class DatabaseSqlite : public Database
{
    private:
        wxSQLite3Database m_sqlitedb;

    public:
        DatabaseSqlite();
        ~DatabaseSqlite();

        bool InitDatabase(ManagerConfig *database_config);
        size_t RunSql(wxString sql_string);
};

class DatabaseFactory
{
    public:
        DatabaseFactory();
        ~DatabaseFactory();

        static Database* CreateDatabase(size_t database_type);
};

#endif // WXITMANAGERDATABASE_H_INCLUDED
