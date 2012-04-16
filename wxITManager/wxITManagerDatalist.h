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

class ResourceInfo;
class ResourceTypeInfo;
class ResourceStatusInfo;
class ResourceFeeTypeInfo;

WX_DECLARE_OBJARRAY(UserInfo, UserInfoArray);
WX_DECLARE_OBJARRAY(UserGroupInfo, UserGroupInfoArray);

WX_DECLARE_OBJARRAY(VcardInfo, VcardInfoArray);
WX_DECLARE_OBJARRAY(VcardGroupInfo, VcardGroupInfoArray);
WX_DECLARE_OBJARRAY(CompanyInfo, CompanyInfoArray);
WX_DECLARE_OBJARRAY(CompanyTypeInfo, CompanyTypeInfoArray);

WX_DECLARE_OBJARRAY(ResourceInfo, ResourceInfoArray);
WX_DECLARE_OBJARRAY(ResourceTypeInfo, ResourceTypeInfoArray);
WX_DECLARE_OBJARRAY(ResourceStatusInfo, ResourceStatusInfoArray);
WX_DECLARE_OBJARRAY(ResourceFeeTypeInfo, ResourceFeeTypeInfoArray);

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

#endif // WXITMANAGERDATALIST_H_INCLUDED
