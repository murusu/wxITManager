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

WX_DECLARE_OBJARRAY(UserInfo, UserInfoArray);
WX_DECLARE_OBJARRAY(UserGroupInfo, UserGroupInfoArray);

WX_DECLARE_OBJARRAY(VcardInfo, VcardInfoArray);
WX_DECLARE_OBJARRAY(VcardGroupInfo, VcardGroupInfoArray);
WX_DECLARE_OBJARRAY(CompanyInfo, CompanyInfoArray);
WX_DECLARE_OBJARRAY(CompanyTypeInfo, CompanyTypeInfoArray);

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

        CompanyInfo(size_t company_id, const wxString& company_name, size_t companytype_id, const wxString& companytype_name){m_id = company_id; m_name = company_name; m_companytypeid = companytype_id; m_companytypename = companytype_name};
};

class CompanyTypeInfo
{
    public:
        size_t          m_id;
        wxString        m_name;

        CompanyTypeInfo(size_t companytype_id, const wxString& companytype_name){m_id = companytype_id; m_name = companytype_name;};
};


#endif // WXITMANAGERDATALIST_H_INCLUDED
