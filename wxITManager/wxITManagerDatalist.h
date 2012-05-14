#ifndef WXITMANAGERDATALIST_H_INCLUDED
#define WXITMANAGERDATALIST_H_INCLUDED

#include <wx/dynarray.h>
#include <wx/arrimpl.cpp>
#include <wx/arrstr.h>

class UserInfo;
class UserGroupInfo;

class VcardInfo;
class VcardGroupInfo;
class CompanyInfo;
class CompanyTypeInfo;
class LocationInfo;

class ResourceInfo;
class ResourceTypeInfo;
class ResourceStatusInfo;
class ResourceFeeTypeInfo;

class ResourceDeployInfo;
class ResourceFeeInfo;
class ResourceLogInfo;

WX_DECLARE_OBJARRAY(UserInfo, UserInfoArray);
WX_DECLARE_OBJARRAY(UserGroupInfo, UserGroupInfoArray);

WX_DECLARE_OBJARRAY(VcardInfo, VcardInfoArray);
WX_DECLARE_OBJARRAY(VcardGroupInfo, VcardGroupInfoArray);
WX_DECLARE_OBJARRAY(CompanyInfo, CompanyInfoArray);
WX_DECLARE_OBJARRAY(CompanyTypeInfo, CompanyTypeInfoArray);
WX_DECLARE_OBJARRAY(LocationInfo, LocationInfoArray);

WX_DECLARE_OBJARRAY(ResourceInfo, ResourceInfoArray);
WX_DECLARE_OBJARRAY(ResourceTypeInfo, ResourceTypeInfoArray);
WX_DECLARE_OBJARRAY(ResourceStatusInfo, ResourceStatusInfoArray);
WX_DECLARE_OBJARRAY(ResourceFeeTypeInfo, ResourceFeeTypeInfoArray);

WX_DECLARE_OBJARRAY(ResourceDeployInfo, ResourceDeployInfoArray);
WX_DECLARE_OBJARRAY(ResourceFeeInfo, ResourceFeeInfoArray);
WX_DECLARE_OBJARRAY(ResourceLogInfo, ResourceLogInfoArray);

class UserInfo
{
    public:
        size_t          m_id;
        wxString        m_name;
        size_t          m_usergroupid;
        wxString        m_usergroupname;

        UserInfo(size_t user_id, const wxString& user_name, size_t user_group, wxString user_groupname){m_id = user_id; m_name = user_name; m_usergroupid = user_group; m_usergroupname = user_groupname;};
};

class UserGroupInfo
{
    public:
        size_t          m_id;
        wxString        m_name;

        UserGroupInfo(size_t usergroup_id, const wxString& usergroup_name){m_id = usergroup_id; m_name = usergroup_name;};
};

class VcardInfo
{
    public:
        size_t          m_id;
        wxString        m_fullname;
        wxString        m_nickname;
        wxString        m_workphone;
        wxString        m_mobiephone;
        wxString        m_email;
        wxString        m_title;
        wxString        m_company;

        VcardInfo(size_t vcard_id, const wxString& full_name, const wxString& nick_name, const wxString& work_phone, const wxString& mobie_phone, const wxString& email, const wxString& title, const wxString& company){m_id = vcard_id; m_fullname = full_name; m_nickname = nick_name; m_workphone = work_phone; m_mobiephone = mobie_phone; m_email = email; m_title = title; m_company = company;};
};

class VcardGroupInfo
{
    public:
        size_t          m_id;
        wxString        m_name;

        VcardGroupInfo(size_t vcardgroup_id, const wxString& vcardgroup_name){m_id = vcardgroup_id; m_name = vcardgroup_name;};
};

class CompanyInfo
{
    public:
        size_t          m_id;
        wxString        m_name;
        size_t          m_companytypeid;
        wxString        m_companytypename;

        CompanyInfo(size_t company_id, const wxString& company_name, size_t companytype_id, const wxString& companytype_name){m_id = company_id; m_name = company_name; m_companytypeid = companytype_id; m_companytypename = companytype_name;};
};

class CompanyTypeInfo
{
    public:
        size_t          m_id;
        wxString        m_name;

        CompanyTypeInfo(size_t companytype_id, const wxString& companytype_name){m_id = companytype_id; m_name = companytype_name;};
};

class LocationInfo
{
    public:
        size_t          m_id;
        wxString        m_name;

        LocationInfo(size_t location_id, const wxString& location_name){m_id = location_id; m_name = location_name;};
};

class ResourceInfo
{
    public:
        size_t          m_id;
        wxString        m_name;
        size_t          m_resourcetypeid;
        wxString        m_resourcetypename;
        wxString        m_pattern;
        size_t          m_weight;

        ResourceInfo(size_t resource_id, const wxString& resource_name, size_t resourcetype_id, const wxString& resourcetype_name, const wxString& pattern, size_t weight){m_id = resource_id; m_name = resource_name; m_resourcetypeid = resourcetype_id; m_resourcetypename = resourcetype_name; m_pattern = pattern; m_weight = weight;};
};

class ResourceTypeInfo
{
    public:
        size_t          m_id;
        wxString        m_name;

        ResourceTypeInfo(size_t resourcetype_id, const wxString& resourcetype_name){m_id = resourcetype_id; m_name = resourcetype_name;};
};

class ResourceStatusInfo
{
    public:
        size_t          m_id;
        wxString        m_name;
        bool            m_available;

        ResourceStatusInfo(size_t resourcestatus_id, const wxString& resourcestatus_name, bool available){m_id = resourcestatus_id; m_name = resourcestatus_name; m_available = available;};
};

class ResourceFeeTypeInfo
{
    public:
        size_t          m_id;
        wxString        m_name;
        bool            m_haveexpiration;

        ResourceFeeTypeInfo(size_t resourcefeetype_id, const wxString& resourcefeetype_name, bool have_expiration){m_id = resourcefeetype_id; m_name = resourcefeetype_name; m_haveexpiration = have_expiration;};
};

class ResourceDeployInfo
{
    public:
        size_t          m_id;
        wxString        m_systemcode;
        wxString        m_code;
        size_t          m_resourceid;
        wxString        m_resource;
        size_t          m_resourcestatusid;
        wxString        m_resourcestatus;
        size_t          m_locationid;
        wxString        m_location;
        size_t          m_vcardid;
        wxString        m_vcardfullname;
        size_t          m_parentid;
        wxString        m_parentsystemcode;
        wxString        m_remark;

        ResourceDeployInfo(size_t resourcedeploy_id, const wxString& resourcedeploy_systemcode, const wxString& resourcedeploy_code, size_t resourcedeploy_resourceid, const wxString& resourcedeploy_resource, size_t resourcedeploy_resourcestatusid, const wxString& resourcedeploy_resourcestatus, size_t resourcedeploy_locationid, const wxString& resourcedeploy_location, size_t resourcedeploy_vcardid, const wxString& resourcedeploy_vcardfullname, size_t resourcedeploy_parentid, const wxString& resourcedeploy_parentsystemcode, const wxString& resourcedeploy_remark)
        {
            m_id = resourcedeploy_id;
            m_systemcode = resourcedeploy_systemcode;
            m_code = resourcedeploy_code;
            m_resourceid = resourcedeploy_resourceid;
            m_resource = resourcedeploy_resource;
            m_resourcestatusid = resourcedeploy_resourcestatusid;
            m_resourcestatus = resourcedeploy_resourcestatus;
            m_locationid = resourcedeploy_locationid;
            m_location = resourcedeploy_location;
            m_vcardid = resourcedeploy_vcardid;
            m_vcardfullname = resourcedeploy_vcardfullname;
            m_parentid = resourcedeploy_parentid;
            m_parentsystemcode = resourcedeploy_parentsystemcode;
            m_remark = resourcedeploy_remark;
        };
};

class ResourceFeeInfo
{
    public:
        size_t          m_id;
        size_t          m_resourcefeetypeid;
        wxString        m_resourcefeetypename;
        size_t          m_companyid;
        wxString        m_companyname;
        float           m_price;
        time_t          m_purchasedate;
        time_t          m_expirationdate;

        ResourceFeeInfo(size_t resourcefee_id, size_t resourcefee_feetypeid, const wxString& resourcefee_feetypename, size_t resourcefee_companyid, const wxString& resourcefee_companyname, float resourcefee_price, time_t resourcefee_purchasedate, time_t resourcefee_expirationdate)
        {
            m_id = resourcefee_id;
            m_resourcefeetypeid = resourcefee_feetypeid;
            m_resourcefeetypename = resourcefee_feetypename;
            m_companyid = resourcefee_companyid;
            m_companyname = resourcefee_companyname;
            m_price = resourcefee_price;
            m_purchasedate = resourcefee_purchasedate;
            m_expirationdate = resourcefee_expirationdate;
        }
};

class ResourceLogInfo
{
    public:
        size_t          m_id;
        size_t          m_userid;
        wxString        m_username;
        size_t          m_operationtype;
        wxString        m_operationcontent;
        time_t          m_operationdate;

        ResourceLogInfo(size_t resourcelog_id, size_t resourcelog_userid, const wxString& resourcelog_username, size_t resourcelog_operationtype, const wxString& resourcelog_operationcontent, time_t resourcelog_operationdate)
        {
            m_id = resourcelog_id;
            m_userid = resourcelog_userid;
            m_username = resourcelog_username;
            m_operationtype = resourcelog_operationtype;
            m_operationcontent = resourcelog_operationcontent;
            m_operationdate = resourcelog_operationdate;
        }
};

#endif // WXITMANAGERDATALIST_H_INCLUDED
