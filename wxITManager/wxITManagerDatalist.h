#ifndef WXITMANAGERDATALIST_H_INCLUDED
#define WXITMANAGERDATALIST_H_INCLUDED

#include <wx/dynarray.h>
#include <wx/arrimpl.cpp>
#include <wx/arrstr.h>

class UserInfo;
class UserGroupInfo;

WX_DECLARE_OBJARRAY(UserInfo, UserInfoArray);
WX_DECLARE_OBJARRAY(UserGroupInfo, UserGroupInfoArray);

class UserInfo
{
    public:
        size_t          m_id;
        wxString        m_name;
        size_t          m_usergroup;

        UserInfo(size_t user_id, const wxString& user_name, size_t user_group){m_id = user_id; m_name = user_name; m_usergroup = user_group;};
};

class UserGroupInfo
{
    public:
        size_t          m_id;
        wxString        m_name;

        UserGroupInfo(size_t usergroup_id, const wxString& usergroup_name){m_id = usergroup_id; m_name = usergroup_name;};
};


#endif // WXITMANAGERDATALIST_H_INCLUDED
