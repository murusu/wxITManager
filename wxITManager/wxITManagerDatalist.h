#ifndef WXITMANAGERDATALIST_H_INCLUDED
#define WXITMANAGERDATALIST_H_INCLUDED

#include <wx/dynarray.h>
#include <wx/arrimpl.cpp>
#include <wx/arrstr.h>

class UserInfo;

WX_DECLARE_OBJARRAY(UserInfo, UserInfoArray);

class UserInfo
{
    public:
        size_t          m_id;
        wxString        m_name;
        size_t          m_usergroup;

        UserInfo(size_t user_id, const wxString& user_name, size_t user_group);
        ~UserInfo();
};


#endif // WXITMANAGERDATALIST_H_INCLUDED
