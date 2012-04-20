#include "wxITManagerUIExtend.h"

DECLARE_APP(wxITManagerApp)

UserListCtrl::UserListCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style):wxListCtrl(parent, id, pos, size, style)
{
    this->Connect(wxEVT_DATABASE_GETUSERLIST, wxDatabaseEventHandler(UserListCtrl::OnRefreshList));
    this->Connect(wxEVT_DATABASE_DELETEUSER, wxDatabaseEventHandler(UserListCtrl::OnListChange));
    this->Connect(wxEVT_DATABASE_ADDUSER, wxDatabaseEventHandler(UserListCtrl::OnListChange));
    this->Connect(wxEVT_DATABASE_UPDATEUSER, wxDatabaseEventHandler(UserListCtrl::OnListChange));
}

void UserListCtrl::OnListChange( wxDatabaseEvent& event)
{
    RefreshList();
}

void UserListCtrl::OnRefreshList( wxDatabaseEvent& event)
{
    SetItemCount(((UserController *)(wxGetApp().GetController(CONTROLLER_USER)))->getItemNumber());
    Refresh();
}

void UserListCtrl::RefreshList()
{
    wxEvtHandler *handler = wxGetApp().GetController(CONTROLLER_USER);
    wxDatabaseEvent database_event(wxEVT_DATABASE_GETUSERLIST, CONTROLLER_USER);
    database_event.SetStatus(EVENTSTATUS_REQUEST);
    database_event.SetEventObject(this);
    handler->AddPendingEvent(database_event);
}

wxString UserListCtrl::OnGetItemText(long item, long column) const
{
    wxString ItemText = wxT("");

    UserInfoArray* list = ((UserController *)(wxGetApp().GetController(CONTROLLER_USER)))->GetList();

    switch(column)
    {
        case 0:
            ItemText = list->Item(item).m_name;
            break;

        case 1:
            ItemText = list->Item(item).m_usergroupname;
            break;
    }

    return ItemText;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

UserGroupListCtrl::UserGroupListCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style):wxListCtrl(parent, id, pos, size, style)
{
    this->Connect(wxEVT_DATABASE_GETUSERGROUPLIST, wxDatabaseEventHandler(UserGroupListCtrl::OnRefreshList));
    this->Connect(wxEVT_DATABASE_DELETEUSERGROUP, wxDatabaseEventHandler(UserGroupListCtrl::OnListChange));
    this->Connect(wxEVT_DATABASE_ADDUSERGROUP, wxDatabaseEventHandler(UserGroupListCtrl::OnListChange));
    this->Connect(wxEVT_DATABASE_UPDATEUSERGROUP, wxDatabaseEventHandler(UserGroupListCtrl::OnListChange));
}

void UserGroupListCtrl::OnListChange( wxDatabaseEvent& event)
{
    RefreshList();
}

void UserGroupListCtrl::OnRefreshList( wxDatabaseEvent& event)
{
    SetItemCount(((UserGroupController *)(wxGetApp().GetController(CONTROLLER_USERGROUP)))->getItemNumber());
    Refresh();
}

void UserGroupListCtrl::RefreshList()
{
    wxEvtHandler *handler = wxGetApp().GetController(CONTROLLER_USERGROUP);
    wxDatabaseEvent database_event(wxEVT_DATABASE_GETUSERGROUPLIST, CONTROLLER_USERGROUP);
    database_event.SetStatus(EVENTSTATUS_REQUEST);
    database_event.SetEventObject(this);
    handler->AddPendingEvent(database_event);
}

wxString UserGroupListCtrl::OnGetItemText(long item, long column) const
{
    wxString ItemText = wxT("");

    UserGroupInfoArray* list = ((UserGroupController *)(wxGetApp().GetController(CONTROLLER_USERGROUP)))->GetList();

    switch(column)
    {
        case 0:
            ItemText = list->Item(item).m_name;
            break;
    }

    return ItemText;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

VcardListCtrl::VcardListCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style):wxListCtrl(parent, id, pos, size, style)
{
    this->Connect(wxEVT_DATABASE_GETVCARDLIST, wxDatabaseEventHandler(VcardListCtrl::OnRefreshList));
    this->Connect(wxEVT_DATABASE_DELETEVCARD, wxDatabaseEventHandler(VcardListCtrl::OnListChange));
    this->Connect(wxEVT_DATABASE_ADDVCARD, wxDatabaseEventHandler(VcardListCtrl::OnListChange));
    this->Connect(wxEVT_DATABASE_UPDATEVCARD, wxDatabaseEventHandler(VcardListCtrl::OnListChange));
}

void VcardListCtrl::OnListChange( wxDatabaseEvent& event)
{
    RefreshList();
}

void VcardListCtrl::OnRefreshList( wxDatabaseEvent& event)
{
    SetItemCount(((VcardController *)(wxGetApp().GetController(CONTROLLER_VCARD)))->getItemNumber());
    Refresh();
}

void VcardListCtrl::RefreshList()
{
    wxEvtHandler *handler = wxGetApp().GetController(CONTROLLER_VCARD);
    wxDatabaseEvent database_event(wxEVT_DATABASE_GETVCARDLIST, CONTROLLER_VCARD);
    database_event.SetStatus(EVENTSTATUS_REQUEST);
    database_event.SetEventObject(this);
    handler->AddPendingEvent(database_event);
}

wxString VcardListCtrl::OnGetItemText(long item, long column) const
{
    wxString ItemText = wxT("");

    VcardInfoArray* list = ((VcardController *)(wxGetApp().GetController(CONTROLLER_VCARD)))->GetList();

    switch(column)
    {
        case 0:
            ItemText = list->Item(item).m_fullname;
            break;

        case 1:
            ItemText = list->Item(item).m_nickname;
            break;

        case 2:
            ItemText = list->Item(item).m_workphone;
            break;

        case 3:
            ItemText = list->Item(item).m_email;
            break;

        case 4:
            ItemText = list->Item(item).m_company;
            break;
    }

    return ItemText;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

VcardGroupListCtrl::VcardGroupListCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style):wxListCtrl(parent, id, pos, size, style)
{
    this->Connect(wxEVT_DATABASE_GETVCARDGROUPLIST, wxDatabaseEventHandler(VcardGroupListCtrl::OnRefreshList));
    this->Connect(wxEVT_DATABASE_DELETEVCARDGROUP, wxDatabaseEventHandler(VcardGroupListCtrl::OnListChange));
    this->Connect(wxEVT_DATABASE_ADDVCARDGROUP, wxDatabaseEventHandler(VcardGroupListCtrl::OnListChange));
    this->Connect(wxEVT_DATABASE_UPDATEVCARDGROUP, wxDatabaseEventHandler(VcardGroupListCtrl::OnListChange));
}

void VcardGroupListCtrl::OnListChange( wxDatabaseEvent& event)
{
    RefreshList();
}

void VcardGroupListCtrl::OnRefreshList( wxDatabaseEvent& event)
{
    SetItemCount(((VcardGroupController *)(wxGetApp().GetController(CONTROLLER_VCARDGROUP)))->getItemNumber());
    Refresh();
}

void VcardGroupListCtrl::RefreshList()
{
    wxEvtHandler *handler = wxGetApp().GetController(CONTROLLER_VCARDGROUP);
    wxDatabaseEvent database_event(wxEVT_DATABASE_GETVCARDGROUPLIST, CONTROLLER_VCARDGROUP);
    database_event.SetStatus(EVENTSTATUS_REQUEST);
    database_event.SetEventObject(this);
    handler->AddPendingEvent(database_event);
}

wxString VcardGroupListCtrl::OnGetItemText(long item, long column) const
{
    wxString ItemText = wxT("");

    VcardGroupInfoArray* list = ((VcardGroupController *)(wxGetApp().GetController(CONTROLLER_VCARDGROUP)))->GetList();

    switch(column)
    {
        case 0:
            ItemText = list->Item(item).m_name;
            break;
    }

    return ItemText;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

CompanyListCtrl::CompanyListCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style):wxListCtrl(parent, id, pos, size, style)
{
    this->Connect(wxEVT_DATABASE_GETCOMPANYLIST, wxDatabaseEventHandler(CompanyListCtrl::OnRefreshList));
    this->Connect(wxEVT_DATABASE_DELETECOMPANY, wxDatabaseEventHandler(CompanyListCtrl::OnListChange));
    this->Connect(wxEVT_DATABASE_ADDCOMPANY, wxDatabaseEventHandler(CompanyListCtrl::OnListChange));
    this->Connect(wxEVT_DATABASE_UPDATECOMPANY, wxDatabaseEventHandler(CompanyListCtrl::OnListChange));
}

void CompanyListCtrl::OnListChange( wxDatabaseEvent& event)
{
    RefreshList();
}

void CompanyListCtrl::OnRefreshList( wxDatabaseEvent& event)
{
    SetItemCount(((CompanyController *)(wxGetApp().GetController(CONTROLLER_COMPANY)))->getItemNumber());
    Refresh();
}

void CompanyListCtrl::RefreshList()
{
    wxEvtHandler *handler = wxGetApp().GetController(CONTROLLER_COMPANY);
    wxDatabaseEvent database_event(wxEVT_DATABASE_GETCOMPANYLIST, CONTROLLER_COMPANY);
    database_event.SetStatus(EVENTSTATUS_REQUEST);
    database_event.SetEventObject(this);
    handler->AddPendingEvent(database_event);
}

wxString CompanyListCtrl::OnGetItemText(long item, long column) const
{
    wxString ItemText = wxT("");

    CompanyInfoArray* list = ((CompanyController *)(wxGetApp().GetController(CONTROLLER_COMPANY)))->GetList();

    switch(column)
    {
        case 0:
            ItemText = list->Item(item).m_name;
            break;

        case 1:
            ItemText = list->Item(item).m_companytypename;
            break;
    }

    return ItemText;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

CompanyTypeListCtrl::CompanyTypeListCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style):wxListCtrl(parent, id, pos, size, style)
{
    this->Connect(wxEVT_DATABASE_GETCOMPANYTYPELIST, wxDatabaseEventHandler(CompanyTypeListCtrl::OnRefreshList));
    this->Connect(wxEVT_DATABASE_DELETECOMPANYTYPE, wxDatabaseEventHandler(CompanyTypeListCtrl::OnListChange));
    this->Connect(wxEVT_DATABASE_ADDCOMPANYTYPE, wxDatabaseEventHandler(CompanyTypeListCtrl::OnListChange));
    this->Connect(wxEVT_DATABASE_UPDATECOMPANYTYPE, wxDatabaseEventHandler(CompanyTypeListCtrl::OnListChange));
}

void CompanyTypeListCtrl::OnListChange( wxDatabaseEvent& event)
{
    RefreshList();
}

void CompanyTypeListCtrl::OnRefreshList( wxDatabaseEvent& event)
{
    SetItemCount(((CompanyTypeController *)(wxGetApp().GetController(CONTROLLER_COMPANYTYPE)))->getItemNumber());
    Refresh();
}

void CompanyTypeListCtrl::RefreshList()
{
    wxEvtHandler *handler = wxGetApp().GetController(CONTROLLER_COMPANYTYPE);
    wxDatabaseEvent database_event(wxEVT_DATABASE_GETCOMPANYTYPELIST, CONTROLLER_COMPANYTYPE);
    database_event.SetStatus(EVENTSTATUS_REQUEST);
    database_event.SetEventObject(this);
    handler->AddPendingEvent(database_event);
}

wxString CompanyTypeListCtrl::OnGetItemText(long item, long column) const
{
    wxString ItemText = wxT("");

    CompanyTypeInfoArray* list = ((CompanyTypeController *)(wxGetApp().GetController(CONTROLLER_COMPANYTYPE)))->GetList();

    switch(column)
    {
        case 0:
            ItemText = list->Item(item).m_name;
            break;
    }

    return ItemText;
}

///////////////////////////////////////////////////////////////////////////////////////////
LocationListCtrl::LocationListCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style):wxListCtrl(parent, id, pos, size, style)
{
    this->Connect(wxEVT_DATABASE_GETLOCATIONLIST, wxDatabaseEventHandler(LocationListCtrl::OnRefreshList));
    this->Connect(wxEVT_DATABASE_DELETELOCATION, wxDatabaseEventHandler(LocationListCtrl::OnListChange));
    this->Connect(wxEVT_DATABASE_ADDLOCATION, wxDatabaseEventHandler(LocationListCtrl::OnListChange));
    this->Connect(wxEVT_DATABASE_UPDATELOCATION, wxDatabaseEventHandler(LocationListCtrl::OnListChange));
}

void LocationListCtrl::OnListChange( wxDatabaseEvent& event)
{
    RefreshList();
}

void LocationListCtrl::OnRefreshList( wxDatabaseEvent& event)
{
    SetItemCount(((LocationController *)(wxGetApp().GetController(CONTROLLER_LOCATION)))->getItemNumber());
    Refresh();
}

void LocationListCtrl::RefreshList()
{
    wxEvtHandler *handler = wxGetApp().GetController(CONTROLLER_LOCATION);
    wxDatabaseEvent database_event(wxEVT_DATABASE_GETLOCATIONLIST, CONTROLLER_LOCATION);
    database_event.SetStatus(EVENTSTATUS_REQUEST);
    database_event.SetEventObject(this);
    handler->AddPendingEvent(database_event);
}

wxString LocationListCtrl::OnGetItemText(long item, long column) const
{
    wxString ItemText = wxT("");

    LocationInfoArray* list = ((LocationController *)(wxGetApp().GetController(CONTROLLER_LOCATION)))->GetList();

    switch(column)
    {
        case 0:
            ItemText = list->Item(item).m_name;
            break;
    }

    return ItemText;
}

///////////////////////////////////////////////////////////////////////////////////////////

ResourceListCtrl::ResourceListCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style):wxListCtrl(parent, id, pos, size, style)
{
    this->Connect(wxEVT_DATABASE_GETRESOURCELIST, wxDatabaseEventHandler(ResourceListCtrl::OnRefreshList));
    this->Connect(wxEVT_DATABASE_DELETERESOURCE, wxDatabaseEventHandler(ResourceListCtrl::OnListChange));
    this->Connect(wxEVT_DATABASE_ADDRESOURCE, wxDatabaseEventHandler(ResourceListCtrl::OnListChange));
    this->Connect(wxEVT_DATABASE_UPDATERESOURCE, wxDatabaseEventHandler(ResourceListCtrl::OnListChange));
}

void ResourceListCtrl::OnListChange( wxDatabaseEvent& event)
{
    RefreshList();
}

void ResourceListCtrl::OnRefreshList( wxDatabaseEvent& event)
{
    SetItemCount(((ResourceController *)(wxGetApp().GetController(CONTROLLER_RESOURCE)))->getItemNumber());
    Refresh();
}

void ResourceListCtrl::RefreshList()
{
    wxEvtHandler *handler = wxGetApp().GetController(CONTROLLER_RESOURCE);
    wxDatabaseEvent database_event(wxEVT_DATABASE_GETRESOURCELIST, CONTROLLER_RESOURCE);
    database_event.SetStatus(EVENTSTATUS_REQUEST);
    database_event.SetEventObject(this);
    handler->AddPendingEvent(database_event);
}

wxString ResourceListCtrl::OnGetItemText(long item, long column) const
{
    wxString ItemText = wxT("");

    ResourceInfoArray* list = ((ResourceController *)(wxGetApp().GetController(CONTROLLER_RESOURCE)))->GetList();

    switch(column)
    {
        case 0:
            ItemText = list->Item(item).m_name;
            break;

        case 1:
            ItemText = list->Item(item).m_resourcetypename;
            break;

        case 2:
            ItemText = list->Item(item).m_pattern;
            break;

        case 3:
            ItemText = wxString::Format(wxT("%d"),list->Item(item).m_weight);
            break;
    }

    return ItemText;
}

////////////////////////////////////////////////////////////////////////////////////////////////

ResourceTypeListCtrl::ResourceTypeListCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style):wxListCtrl(parent, id, pos, size, style)
{
    this->Connect(wxEVT_DATABASE_GETRESOURCETYPELIST, wxDatabaseEventHandler(ResourceTypeListCtrl::OnRefreshList));
    this->Connect(wxEVT_DATABASE_DELETERESOURCETYPE, wxDatabaseEventHandler(ResourceTypeListCtrl::OnListChange));
    this->Connect(wxEVT_DATABASE_ADDRESOURCETYPE, wxDatabaseEventHandler(ResourceTypeListCtrl::OnListChange));
    this->Connect(wxEVT_DATABASE_UPDATERESOURCETYPE, wxDatabaseEventHandler(ResourceTypeListCtrl::OnListChange));
}

void ResourceTypeListCtrl::OnListChange( wxDatabaseEvent& event)
{
    RefreshList();
}

void ResourceTypeListCtrl::OnRefreshList( wxDatabaseEvent& event)
{
    SetItemCount(((ResourceTypeController *)(wxGetApp().GetController(CONTROLLER_RESOURCETYPE)))->getItemNumber());
    Refresh();
}

void ResourceTypeListCtrl::RefreshList()
{
    wxEvtHandler *handler = wxGetApp().GetController(CONTROLLER_RESOURCETYPE);
    wxDatabaseEvent database_event(wxEVT_DATABASE_GETRESOURCETYPELIST, CONTROLLER_RESOURCETYPE);
    database_event.SetStatus(EVENTSTATUS_REQUEST);
    database_event.SetEventObject(this);
    handler->AddPendingEvent(database_event);
}

wxString ResourceTypeListCtrl::OnGetItemText(long item, long column) const
{
    wxString ItemText = wxT("");

    ResourceTypeInfoArray* list = ((ResourceTypeController *)(wxGetApp().GetController(CONTROLLER_RESOURCETYPE)))->GetList();

    switch(column)
    {
        case 0:
            ItemText = list->Item(item).m_name;
            break;
    }

    return ItemText;
}

////////////////////////////////////////////////////////////////////////////////////////////////

ResourceStatusListCtrl::ResourceStatusListCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style):wxListCtrl(parent, id, pos, size, style)
{
    this->Connect(wxEVT_DATABASE_GETRESOURCESTATUSLIST, wxDatabaseEventHandler(ResourceStatusListCtrl::OnRefreshList));
    this->Connect(wxEVT_DATABASE_DELETERESOURCESTATUS, wxDatabaseEventHandler(ResourceStatusListCtrl::OnListChange));
    this->Connect(wxEVT_DATABASE_ADDRESOURCESTATUS, wxDatabaseEventHandler(ResourceStatusListCtrl::OnListChange));
    this->Connect(wxEVT_DATABASE_UPDATERESOURCESTATUS, wxDatabaseEventHandler(ResourceStatusListCtrl::OnListChange));
}

void ResourceStatusListCtrl::OnListChange( wxDatabaseEvent& event)
{
    RefreshList();
}

void ResourceStatusListCtrl::OnRefreshList( wxDatabaseEvent& event)
{
    SetItemCount(((ResourceStatusController *)(wxGetApp().GetController(CONTROLLER_RESOURCESTATUS)))->getItemNumber());
    Refresh();
}

void ResourceStatusListCtrl::RefreshList()
{
    wxEvtHandler *handler = wxGetApp().GetController(CONTROLLER_RESOURCESTATUS);
    wxDatabaseEvent database_event(wxEVT_DATABASE_GETRESOURCESTATUSLIST, CONTROLLER_RESOURCESTATUS);
    database_event.SetStatus(EVENTSTATUS_REQUEST);
    database_event.SetEventObject(this);
    handler->AddPendingEvent(database_event);
}

wxString ResourceStatusListCtrl::OnGetItemText(long item, long column) const
{
    wxString ItemText = wxT("");

    ResourceStatusInfoArray* list = ((ResourceStatusController *)(wxGetApp().GetController(CONTROLLER_RESOURCESTATUS)))->GetList();

    switch(column)
    {
        case 0:
            ItemText = list->Item(item).m_name;
            break;

        case 1:
            if(list->Item(item).m_available)
            {
                ItemText = _("Yes");
            }
            else
            {
                ItemText = _("No");
            }
            break;
    }

    return ItemText;
}

////////////////////////////////////////////////////////////////////////////////////////////////

ResourceFeeTypeListCtrl::ResourceFeeTypeListCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style):wxListCtrl(parent, id, pos, size, style)
{
    this->Connect(wxEVT_DATABASE_GETRESOURCEFEETYPELIST, wxDatabaseEventHandler(ResourceFeeTypeListCtrl::OnRefreshList));
    this->Connect(wxEVT_DATABASE_DELETERESOURCEFEETYPE, wxDatabaseEventHandler(ResourceFeeTypeListCtrl::OnListChange));
    this->Connect(wxEVT_DATABASE_ADDRESOURCEFEETYPE, wxDatabaseEventHandler(ResourceFeeTypeListCtrl::OnListChange));
    this->Connect(wxEVT_DATABASE_UPDATERESOURCEFEETYPE, wxDatabaseEventHandler(ResourceFeeTypeListCtrl::OnListChange));
}

void ResourceFeeTypeListCtrl::OnListChange( wxDatabaseEvent& event)
{
    RefreshList();
}

void ResourceFeeTypeListCtrl::OnRefreshList( wxDatabaseEvent& event)
{
    SetItemCount(((ResourceFeeTypeController *)(wxGetApp().GetController(CONTROLLER_RESOURCEFEETYPE)))->getItemNumber());
    Refresh();
}

void ResourceFeeTypeListCtrl::RefreshList()
{
    wxEvtHandler *handler = wxGetApp().GetController(CONTROLLER_RESOURCEFEETYPE);
    wxDatabaseEvent database_event(wxEVT_DATABASE_GETRESOURCEFEETYPELIST, CONTROLLER_RESOURCEFEETYPE);
    database_event.SetStatus(EVENTSTATUS_REQUEST);
    database_event.SetEventObject(this);
    handler->AddPendingEvent(database_event);
}

wxString ResourceFeeTypeListCtrl::OnGetItemText(long item, long column) const
{
    wxString ItemText = wxT("");

    ResourceFeeTypeInfoArray* list = ((ResourceFeeTypeController *)(wxGetApp().GetController(CONTROLLER_RESOURCEFEETYPE)))->GetList();

    switch(column)
    {
        case 0:
            ItemText = list->Item(item).m_name;
            break;

        case 1:
            if(list->Item(item).m_haveexpiration)
            {
                ItemText = _("Yes");
            }
            else
            {
                ItemText = _("No");
            }
            break;
    }

    return ItemText;
}

///////////////////////////////////////////////////////////////////////////////////////////////

ResourceDepolyListCtrl::ResourceDepolyListCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style):wxListCtrl(parent, id, pos, size, style)
{
    this->Connect(wxEVT_DATABASE_GETRESOURCEFEETYPELIST, wxDatabaseEventHandler(ResourceDepolyListCtrl::OnRefreshList));
    this->Connect(wxEVT_DATABASE_DELETERESOURCEFEETYPE, wxDatabaseEventHandler(ResourceDepolyListCtrl::OnListChange));
    this->Connect(wxEVT_DATABASE_ADDRESOURCEFEETYPE, wxDatabaseEventHandler(ResourceDepolyListCtrl::OnListChange));
    this->Connect(wxEVT_DATABASE_UPDATERESOURCEFEETYPE, wxDatabaseEventHandler(ResourceDepolyListCtrl::OnListChange));
}

void ResourceDepolyListCtrl::OnListChange( wxDatabaseEvent& event)
{
    RefreshList();
}

void ResourceDepolyListCtrl::OnRefreshList( wxDatabaseEvent& event)
{
    SetItemCount(((ResourceDepolyController *)(wxGetApp().GetController(CONTROLLER_RESOURCEDEPOLY)))->getItemNumber());
    Refresh();
}

void ResourceDepolyListCtrl::RefreshList()
{
    wxEvtHandler *handler = wxGetApp().GetController(CONTROLLER_RESOURCEDEPOLY);
    wxDatabaseEvent database_event(wxEVT_DATABASE_GETRESOURCEDEPOLYLIST, CONTROLLER_RESOURCEDEPOLY);
    database_event.SetStatus(EVENTSTATUS_REQUEST);
    database_event.SetEventObject(this);
    handler->AddPendingEvent(database_event);
}

wxString ResourceDepolyListCtrl::OnGetItemText(long item, long column) const
{
    wxString ItemText = wxT("");

    ResourceDepolyInfoArray* list = ((ResourceDepolyController *)(wxGetApp().GetController(CONTROLLER_RESOURCEDEPOLY)))->GetList();

    switch(column)
    {
        case 0:
            ItemText = list->Item(item).m_systemcode;
            break;
    }

    return ItemText;
}
