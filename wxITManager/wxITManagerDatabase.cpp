#include "wxITManagerDatabase.h"

Database::Database()
{
}

Database::~Database()
{
}

void Database::SetupTable()
{
    RunSql(wxT("create table user(id integer primary key, name wchar(20), groupid integer);"));
    RunSql(wxT("create table user_group(id integer primary key, name wchar(20));"));
}

DatabaseSqlite::DatabaseSqlite()
{
}

DatabaseSqlite::~DatabaseSqlite()
{
    m_sqlitedb.Close();
}

bool DatabaseSqlite::InitDatabase(ManagerConfig *database_config)
{
    wxSQLite3Database::InitializeSQLite();
    database_config->ReadConfigData();

    try
    {
        m_sqlitedb.Open(database_config->GetDatabaseFile(), database_config->GetDatabaseKey());
    }
    catch(...)
    {
        return false;
    }

    return true;
}

size_t DatabaseSqlite::RunSql(wxString sql_string)
{
    return m_sqlitedb.ExecuteUpdate(sql_string);
}

DatabaseFactory::DatabaseFactory()
{
}

DatabaseFactory::~DatabaseFactory()
{
}

Database* DatabaseFactory::CreateDatabase(size_t database_type)
{
    switch(database_type)
    {
        case DATABASE_SQLITE:
            return new DatabaseSqlite();
            break;
    }

    return NULL;
}
