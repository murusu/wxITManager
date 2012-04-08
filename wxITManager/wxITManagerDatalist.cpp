#include "wxITManagerDatalist.h"

WX_DEFINE_OBJARRAY(UserInfoArray);

UserInfo::UserInfo(size_t user_id, const wxString& user_name, size_t user_group)
{
    m_id            = user_id;
    m_name          = user_name;
    m_usergroup     = user_group;
}

UserInfo::~UserInfo()
{
}


