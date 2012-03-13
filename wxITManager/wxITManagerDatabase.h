#ifndef WXITMANAGERDATABASE_H_INCLUDED
#define WXITMANAGERDATABASE_H_INCLUDED

#include <wx/wx.h>
#include <wx/event.h>
#include "wx/wxsqlite3.h"

#include "GlobalValue.h"
#include "wxITManagerConfig.h"
#include "wxITManagerEvent.h"
#include "wxITManagerThread.h"

class Database : public wxEvtHandler
{
    private:
        size_t          *m_resultrow;
        wxString        *m_errstr;

    protected:
        ManagerConfig   *m_config;

    public:
        Database(ManagerConfig *database_config);
        ~Database();

        wxObject *m_sender;

        //virtual void InitDBTable() {return;};
        virtual bool InitDBByConfig() {return NULL;};
        virtual wxString GetDBTableInitStr() {return wxT("");};
        virtual size_t ExecuteUpdate(wxString sql_string) {return 0;};

        void OnDatabaseCreate(wxDatabaseEvent& event);

        inline size_t *GetResultRowPointer(){return m_resultrow;};
        inline wxString *GetErrorStrPointer(){return m_errstr;};
        //inline void SetConfig(ManagerConfig *database_config){m_config = database_config;};
};

class DatabaseSqlite : public Database
{
    private:
        wxSQLite3Database m_sqlitedb;

    public:
        DatabaseSqlite(ManagerConfig *database_config);
        ~DatabaseSqlite();

        //void InitDBTable();
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
