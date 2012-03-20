#ifndef WXITMANAGERDATABASE_H_INCLUDED
#define WXITMANAGERDATABASE_H_INCLUDED

#include <wx/wx.h>
#include <wx/event.h>
#include "wx/wxsqlite3.h"

#include "wxITManagerMain.h"

class Database : public wxEvtHandler
{
    protected:
        ManagerConfig   *m_config;

    public:
        Database(ManagerConfig *database_config);
        ~Database();

        virtual bool InitDBByConfig() {return NULL;};
        virtual wxString GetDBTableInitStr() {return wxT("");};
        virtual size_t ExecuteUpdate(wxString sql_string) {return 0;};

        void OnDatabaseCreate(wxDatabaseEvent& event);
        void OnDatabaseTest(wxDatabaseEvent& event);
};

class DatabaseSqlite : public Database
{
    private:
        wxSQLite3Database m_sqlitedb;

    public:
        DatabaseSqlite(ManagerConfig *database_config);
        ~DatabaseSqlite();

        bool InitDBByConfig();
        wxString GetDBTableInitStr();
        size_t ExecuteUpdate(wxString sql_string);
};

class DatabaseFactory
{
    public:
        DatabaseFactory();
        ~DatabaseFactory();

        static Database* CreateDatabase(size_t database_type, ManagerConfig *database_config);
};

#endif // WXITMANAGERDATABASE_H_INCLUDED
