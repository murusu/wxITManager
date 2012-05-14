#ifndef GLOBALVALUE_H_INCLUDED
#define GLOBALVALUE_H_INCLUDED

const size_t DATABASE_VERSION       = 2012042001;

const char * const CONFIGFILE_NAME      = "config.xml";
const char * const CONFIGFILE_ROOTNAME  = "wxITmanager_Config";

const char * const CONFIGFILE_DATABASE  = "database";
const char * const DATABASE_PROPERTY    = "data";
const char * const DATABASE_TYPE        = "Database_Type";
const char * const DATABASE_FILENAME    = "Database_Filename";
const char * const DATABASE_KEY         = "Database_Key";

const size_t NULL_ID                = -1;

const size_t EVENTSTATUS_REQUEST    = 0;
const size_t EVENTSTATUS_SUCCESS    = 1;
const size_t EVENTSTATUS_FAIL       = 2;

const size_t SQLTYPE_QUERY          = 1;
const size_t SQLTYPE_UPDATE         = 2;

const size_t CONTROLLER_NULL            = 0;
const size_t CONTROLLER_DATABASE        = 1;
const size_t CONTROLLER_AUTH            = 2;
const size_t CONTROLLER_USER            = 3;
const size_t CONTROLLER_USERGROUP       = 4;
const size_t CONTROLLER_VCARD           = 5;
const size_t CONTROLLER_VCARDGROUP      = 6;
const size_t CONTROLLER_COMPANY         = 7;
const size_t CONTROLLER_COMPANYTYPE     = 8;
const size_t CONTROLLER_LOCATION        = 9;
const size_t CONTROLLER_RESOURCE        = 10;
const size_t CONTROLLER_RESOURCETYPE    = 11;
const size_t CONTROLLER_RESOURCESTATUS  = 12;
const size_t CONTROLLER_RESOURCEFEETYPE = 13;
const size_t CONTROLLER_RESOURCEDEPLOY  = 14;
const size_t CONTROLLER_RESOURCEFEE     = 15;
const size_t CONTROLLER_RESOURCELOG     = 16;

const size_t DATABASE_SQLITE    = 0;
const size_t DATABASE_MYSQL     = 1;

#endif // GLOBALVALUE_H_INCLUDED
