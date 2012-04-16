#include "wxITManagerUI.h"

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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

LoginFrame::LoginFrame(wxFrame *frame) : LoginFrameBase(frame)
{
    m_configdialog = NULL;
    this->Connect(wxEVT_DATABASE_USERLOGIN, wxDatabaseEventHandler(LoginFrame::OnLoginRespone));
}

LoginFrame::~LoginFrame()
{
}

void LoginFrame::OnButtonLoginClick( wxCommandEvent& event )
{
    using namespace CryptoPP;

    EnableFrame(false);
    m_staticText_Status->SetLabel(_("Loging in......"));

    wxEvtHandler *handler = wxGetApp().GetController(CONTROLLER_AUTH);

    wxJSONValue param_json;
    param_json[0] = m_comboBox_username->GetValue();
    param_json[1] = m_textCtrl_password->GetValue();//MiscFunction::MD5(m_textCtrl_password->GetValue());

    wxDatabaseEvent database_event(wxEVT_DATABASE_USERLOGIN, CONTROLLER_AUTH);
    database_event.SetStatus(EVENTSTATUS_REQUEST);
    database_event.SetEventObject(this);
    database_event.SetJsonData(param_json);
    handler->AddPendingEvent(database_event);
}

void LoginFrame::OnButtonConfigClick( wxCommandEvent& event )
{
    if(!m_configdialog) m_configdialog = new DatabaseConfigDialog(this);

    m_configdialog->ClearContent();
    m_configdialog->LoadConfig();
    m_configdialog->ShowModal();
}

void LoginFrame::OnLoginRespone(wxDatabaseEvent& event)
{
    EnableFrame(true);
    m_textCtrl_password->SetValue(wxT(""));

    if(event.GetStatus() == EVENTSTATUS_SUCCESS)
    {
        size_t id = ((AuthorityController *)(wxGetApp().GetController(CONTROLLER_AUTH)))->GetUserId();

        if(id)
        {
            m_comboBox_username->SetValue(wxT(""));
            m_staticText_Status->SetLabel(wxT(""));
            wxGetApp().DoLogin();
        }
        else
        {
            m_staticText_Status->SetLabel(_("User Name Or Password Incorrect!"));
        }
    }
    else
    {
        m_staticText_Status->SetLabel(_("Database Error!Please Check The Database Setting!"));
    }
}

void LoginFrame::EnableFrame(bool flag)
{
    m_comboBox_username->Enable(flag);
    m_textCtrl_password->Enable(flag);
    m_button_login->Enable(flag);
    m_button_config->Enable(flag);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

DatabaseConfigDialog::DatabaseConfigDialog(wxFrame *frame) : DatabaseConfigDialogBase(frame)
{
    m_sqlitedialog = NULL;
    LoadConfig();

    this->Connect(wxEVT_DATABASE_TESTDATABSE, wxDatabaseEventHandler(DatabaseConfigDialog::OnDatabaseTest));
    //this->Connect(wxEVT_DATABASE_QUERYERROR, wxDatabaseEventHandler(DatabaseConfigDialog::OnDatabaseTest));
}

DatabaseConfigDialog::~DatabaseConfigDialog()
{
}

void DatabaseConfigDialog::OnChoiceDatabaseType( wxCommandEvent& event )
{

}

void DatabaseConfigDialog::OnButtonSqliteBrowse( wxCommandEvent& event )
{
    wxFileDialog file_dialog(this, _("Please Choose Database File"), wxT(""), wxT(""), wxT("Database Files (*.db)|*.db"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if(file_dialog.ShowModal() == wxID_OK)
    {
        m_textCtrl_databasefile->SetValue(file_dialog.GetPath());
    }
}

void DatabaseConfigDialog::OnCheckBoxEncryptedClick( wxCommandEvent& event )
{
    if(m_checkBox_encrypteddatabase->GetValue())
    {
        m_textCtrl_databasekey->Enable(true);
    }
    else
    {
        m_textCtrl_databasekey->Enable(false);
    }
}

void DatabaseConfigDialog::OnCreateDatabaseClick( wxHyperlinkEvent& event )
{
    if(!m_sqlitedialog) m_sqlitedialog = new SqliteCreateDialog(this);

    m_sqlitedialog->ClearContent();
    m_sqlitedialog->ShowModal();
}

void DatabaseConfigDialog::OnButtonTestClick( wxCommandEvent& event )
{
    EnableDialog(false);
    m_staticTextStatus->SetLabel(_("Testing Database Connection......"));

    wxEvtHandler *handler = wxGetApp().GetController(CONTROLLER_DATABASE);
    ManagerConfig *config = ((DatabaseController *)handler)->GetConfig();

    config->SetDatabaseType(m_choice_databasetype->GetCurrentSelection());
    config->SetDatabaseFile(m_textCtrl_databasefile->GetValue());

    if(m_checkBox_encrypteddatabase->GetValue())
    {
        config ->SetDatabaseKey(m_textCtrl_databasekey->GetValue());
    }
    else
    {
        config ->SetDatabaseKey(wxT(""));
    }

    wxDatabaseEvent database_event(wxEVT_DATABASE_TESTDATABSE, CONTROLLER_DATABASE);
    database_event.SetEventObject(this);
    handler->AddPendingEvent(database_event);
}

void DatabaseConfigDialog::OnButtonSaveClick( wxCommandEvent& event )
{
    ManagerConfig *config = wxGetApp().GetConfig();

    config->SetDatabaseType(m_choice_databasetype->GetCurrentSelection());
    config->SetDatabaseFile(m_textCtrl_databasefile->GetValue());

    if(m_checkBox_encrypteddatabase->GetValue())
    {
        config ->SetDatabaseKey(m_textCtrl_databasekey->GetValue());
    }
    else
    {
        config ->SetDatabaseKey(wxT(""));
    }

    if(!(config->WriteConfigData()))
    {
        m_staticTextStatus->SetLabel(_("Fail To Save Config File"));
    }
    else
    {
        m_staticTextStatus->SetLabel(_("Config File Saved"));
    }
}

void DatabaseConfigDialog::OnButtonCloseClick( wxCommandEvent& event )
{
    Close();
}

void DatabaseConfigDialog::LoadConfig()
{
    ManagerConfig *config = wxGetApp().GetConfig();
    m_panel_sqlite->Enable(false);
    m_panel_mysql->Enable(false);

    if(!config)
    {
        m_staticTextStatus->SetLabel(_("Fail On Reading Config"));
    }
    else
    {
        switch(config->GetDatabaseType())
        {
            case DATABASE_SQLITE:
                m_panel_sqlite->Enable(true);
                m_choice_databasetype->SetSelection(DATABASE_SQLITE);
                m_textCtrl_databasefile->SetValue(config->GetDatabaseFile());
                if(!(config->GetDatabaseKey().IsEmpty()))
                {
                    m_checkBox_encrypteddatabase->SetValue(true);
                    m_textCtrl_databasekey->Enable(true);
                    m_textCtrl_databasekey->SetValue(config->GetDatabaseKey());
                }
                break;

            default:
                break;
        }
    }
}

void DatabaseConfigDialog::EnableDialog(bool flag)
{
   m_choice_databasetype->Enable(flag);
   m_textCtrl_databasefile->Enable(flag);
   m_button_databasefile->Enable(flag);
   m_checkBox_encrypteddatabase->Enable(flag);
   m_textCtrl_databasekey->Enable(flag);
   m_button_test->Enable(flag);
   m_button_save->Enable(flag);
   m_button_cancel->Enable(flag);
}

void DatabaseConfigDialog::ClearContent()
{
    m_textCtrl_databasefile->SetValue(wxT(""));
    m_checkBox_encrypteddatabase->SetValue(false);
    m_textCtrl_databasekey->SetValue(wxT(""));
    m_textCtrl_databasekey->Enable(false);
    m_staticTextStatus->SetLabel(wxT(""));
}

void DatabaseConfigDialog::OnDatabaseTest( wxDatabaseEvent& event)
{
    EnableDialog(true);

    if(event.GetStatus() == EVENTSTATUS_SUCCESS)
    {
        wxJSONValue result(event.GetJsonData());

        if(wxAtoi(result[0][0].AsString()) > 1)
        {
            m_staticTextStatus->SetLabel(_("Connected Database Successfully"));
        }
        else
        {
            m_staticTextStatus->SetLabel(_("Database Corrupted!"));
        }
    }
    else
    {
        m_staticTextStatus->SetLabel(_("Fail To Connecte Database"));
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

SqliteCreateDialog::SqliteCreateDialog(wxDialog *dialog) : SqliteCreateDialogBase(dialog)
{
    this->Connect(wxEVT_DATABASE_CREATEDATABSE, wxDatabaseEventHandler(SqliteCreateDialog::OnDatabaseUpdate));
}

SqliteCreateDialog::~SqliteCreateDialog()
{
}

void SqliteCreateDialog::OnButtonBrowseClick( wxCommandEvent& event )
{
    wxFileDialog file_dialog(this, _("Save Database File As"), wxT(""), wxT(""), _("Database Files (*.db)|*.db"), wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

    if(file_dialog.ShowModal() == wxID_OK)
    {
        m_textCtrl_databasefile->SetValue(file_dialog.GetPath());
    }
}

void SqliteCreateDialog::OnCheckBoxEncryptedClick( wxCommandEvent& event )
{
    if(m_checkBox_encrypteddatabase->GetValue())
    {
        m_textCtrl_databasekey->Enable(true);
    }
    else
    {
        m_textCtrl_databasekey->Enable(false);
    }
}


void SqliteCreateDialog::OnButtonCreateClick( wxCommandEvent& event )
{
    EnableDialog(false);
    m_staticTextStatus->SetLabel(_("Creating Database"));

    wxEvtHandler *handler = wxGetApp().GetController(CONTROLLER_DATABASE);
    ManagerConfig *config = ((DatabaseController *)handler)->GetConfig();

    config->SetDatabaseType(DATABASE_SQLITE);
    config->SetDatabaseFile(m_textCtrl_databasefile->GetValue());
    config->SetDatabaseKey(m_textCtrl_databasekey->GetValue());

    wxDatabaseEvent database_event(wxEVT_DATABASE_CREATEDATABSE, CONTROLLER_DATABASE);
    database_event.SetStatus(EVENTSTATUS_REQUEST);
    database_event.SetEventObject(this);
    handler->AddPendingEvent(database_event);

    return;
}

void SqliteCreateDialog::OnButtonCloseClick( wxCommandEvent& event )
{
    Close();
}

void SqliteCreateDialog::OnDatabaseUpdate( wxDatabaseEvent& event)
{
    EnableDialog(true);
    ClearContent();

    if(event.GetStatus() == EVENTSTATUS_SUCCESS)
    {
        m_staticTextStatus->SetLabel(_("Database Created"));
    }
    else
    {
        m_staticTextStatus->SetLabel(_("Fail To Create Database"));
    }
}

void SqliteCreateDialog::EnableDialog(bool flag)
{
    m_textCtrl_databasefile->Enable(flag);
    m_button_browse->Enable(flag);
    m_checkBox_encrypteddatabase->Enable(flag);
    m_textCtrl_databasekey->Enable(flag);
    m_button_create->Enable(flag);
    m_button_close->Enable(flag);
}

void SqliteCreateDialog::ClearContent()
{
    m_textCtrl_databasefile->SetValue(wxT(""));
    m_checkBox_encrypteddatabase->SetValue(false);
    m_textCtrl_databasekey->SetValue(wxT(""));
    m_textCtrl_databasekey->Enable(false);
    m_staticTextStatus->SetLabel(wxT(""));
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame(wxFrame *frame) : MainFrameBase(frame)
{
    m_listCtrl_user->InsertColumn(0,_("User Name"),wxLIST_FORMAT_LEFT,200);
    m_listCtrl_user->InsertColumn(1,_("User Group"),wxLIST_FORMAT_RIGHT,200);

    m_listCtrl_usergroup->InsertColumn(0,_("Group Name"),wxLIST_FORMAT_LEFT,200);

    m_listCtrl_vcard->InsertColumn(0,_("Full Name"),wxLIST_FORMAT_LEFT,200);
    m_listCtrl_vcard->InsertColumn(1,_("Nick Name"),wxLIST_FORMAT_LEFT,200);
    m_listCtrl_vcard->InsertColumn(2,_("Work Phone"),wxLIST_FORMAT_LEFT,200);
    m_listCtrl_vcard->InsertColumn(3,_("Email"),wxLIST_FORMAT_LEFT,200);
    m_listCtrl_vcard->InsertColumn(4,_("Company"),wxLIST_FORMAT_LEFT,200);

    m_listCtrl_vcardgroup->InsertColumn(0,_("Group Name"),wxLIST_FORMAT_LEFT,200);

    m_listCtrl_company->InsertColumn(0,_("Company Name"),wxLIST_FORMAT_LEFT,200);
    m_listCtrl_company->InsertColumn(1,_("Company Type"),wxLIST_FORMAT_LEFT,200);

    m_listCtrl_companytype->InsertColumn(0,_("Type Name"),wxLIST_FORMAT_LEFT,200);

    DoListSize();
}

MainFrame::~MainFrame()
{
}

void MainFrame::OnMainFrameClose( wxCloseEvent& event )
{
    wxGetApp().DoExit();
}

void MainFrame::OnMenuLogoutSelection( wxCommandEvent& event )
{
    wxGetApp().DoLogout();
}

void MainFrame::OnMenuExitSelection( wxCommandEvent& event )
{
    wxGetApp().DoExit();
}

void MainFrame::OnMenuSettingSelect( wxCommandEvent& event )
{
    wxPanel *select_panel = NULL;

    m_panel_setting->Show(true);

    m_panel_user->Show(false);
    m_panel_usergroup->Show(false);

    m_panel_vcard->Show(false);
    m_panel_vcardgroup->Show(false);
    m_panel_company->Show(false);
    m_panel_companytype->Show(false);

    switch(event.GetId())
    {
        case wxID_MENUITEM_USER:
            select_panel = m_panel_user;
            break;

        case wxID_MENUITEM_USERGROUP:
            select_panel = m_panel_usergroup;
            break;

        case wxID_MENUITEM_VCARD:
            select_panel = m_panel_vcard;
            break;

        case wxID_MENUITEM_VCARDGROUP:
            select_panel = m_panel_vcardgroup;
            break;

        case wxID_MENUITEM_COMPANY:
            select_panel = m_panel_company;
            break;

        case wxID_MENUITEM_COMPANYTYPE:
            select_panel = m_panel_companytype;
            break;
    }

    select_panel->Show(true);

    select_panel->SetSize(this->GetSizer()->GetSize());
    wxPoint temppoint = this->GetSizer()->GetPosition();
    temppoint.y++;
    select_panel->Move(temppoint);
}

void MainFrame::OnButtonSettingAdd( wxCommandEvent& event )
{
    wxDialog    *dialog   = NULL;
    wxListCtrl  *listctrl = NULL;

    if(m_panel_user->IsShown())
    {
        dialog   = new UserDialog(this);
        listctrl = m_listCtrl_user;
    }

    if(m_panel_usergroup->IsShown())
    {
        dialog   = new UserGroupDialog(this);
        listctrl = m_listCtrl_usergroup;
    }

    if(m_panel_vcard->IsShown())
    {
        dialog   = new VcardDialog(this);
        listctrl = m_listCtrl_vcard;
    }

    if(m_panel_vcardgroup->IsShown())
    {
        dialog   = new VcardGroupDialog(this);
        listctrl = m_listCtrl_vcardgroup;
    }

    if(m_panel_company->IsShown())
    {
        dialog   = new CompanyDialog(this);
        listctrl = m_listCtrl_company;
    }

    if(m_panel_companytype->IsShown())
    {
        dialog   = new CompanyTypeDialog(this);
        listctrl = m_listCtrl_companytype;
    }

    dialog->ShowModal();
    listctrl->Refresh();

    delete dialog;
}

void MainFrame::OnButtonSettingDelete( wxCommandEvent& event )
{
    if (wxMessageBox(_("Delete Selected Items?"), _("Confirm"), wxYES_NO, this) == wxNO) return;

    size_t       controller_id = CONTROLLER_NULL;
    wxListCtrl  *listctrl = NULL;
    wxEventType  event_type = wxEVT_DATABASE_DELETEUSER;

    if(m_panel_user->IsShown())
    {
        controller_id = CONTROLLER_USER;
        listctrl = m_listCtrl_user;
        event_type = wxEVT_DATABASE_DELETEUSER;
    }

    if(m_panel_usergroup->IsShown())
    {
        controller_id = CONTROLLER_USERGROUP;
        listctrl = m_listCtrl_usergroup;
        event_type = wxEVT_DATABASE_DELETEUSERGROUP;
    }

    if(m_panel_vcard->IsShown())
    {
        controller_id = CONTROLLER_VCARD;
        listctrl = m_listCtrl_vcard;
        event_type = wxEVT_DATABASE_DELETEVCARD;
    }

    if(m_panel_vcardgroup->IsShown())
    {
        controller_id = CONTROLLER_VCARDGROUP;
        listctrl = m_listCtrl_vcardgroup;
        event_type = wxEVT_DATABASE_DELETEVCARDGROUP;
    }

    if(m_panel_company->IsShown())
    {
        controller_id = CONTROLLER_COMPANY;
        listctrl = m_listCtrl_company;
        event_type = wxEVT_DATABASE_DELETECOMPANY;
    }

    if(m_panel_companytype->IsShown())
    {
        controller_id = CONTROLLER_COMPANYTYPE;
        listctrl = m_listCtrl_companytype;
        event_type = wxEVT_DATABASE_DELETECOMPANYTYPE;
    }

    size_t item = -1;
    size_t index = 0;
    wxJSONValue delete_json;

    for ( ;; )
    {
        item = listctrl->GetNextItem(item, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);
        if (item == -1) break;

        if(m_panel_user->IsShown()) delete_json[index] = ((UserController *)(wxGetApp().GetController(controller_id)))->GetList()->Item(item).m_id;
        if(m_panel_usergroup->IsShown()) delete_json[index] = ((UserGroupController *)(wxGetApp().GetController(controller_id)))->GetList()->Item(item).m_id;

        if(m_panel_vcard->IsShown()) delete_json[index] = ((VcardController *)(wxGetApp().GetController(controller_id)))->GetList()->Item(item).m_id;
        if(m_panel_vcardgroup->IsShown()) delete_json[index] = ((VcardGroupController *)(wxGetApp().GetController(controller_id)))->GetList()->Item(item).m_id;
        if(m_panel_company->IsShown()) delete_json[index] = ((CompanyController *)(wxGetApp().GetController(controller_id)))->GetList()->Item(item).m_id;
        if(m_panel_companytype->IsShown()) delete_json[index] = ((CompanyTypeController *)(wxGetApp().GetController(controller_id)))->GetList()->Item(item).m_id;

        index++;
    }

    wxEvtHandler *handler = wxGetApp().GetController(controller_id);
    wxDatabaseEvent database_event(event_type, controller_id);
    database_event.SetStatus(EVENTSTATUS_REQUEST);
    database_event.SetEventObject(listctrl);
    database_event.SetJsonData(delete_json);
    handler->AddPendingEvent(database_event);
}

void MainFrame::OnButtonSettingRefresh( wxCommandEvent& event )
{
    if(m_panel_user->IsShown()) m_listCtrl_user->RefreshList();
    if(m_panel_usergroup->IsShown()) m_listCtrl_usergroup->RefreshList();

    if(m_panel_vcard->IsShown()) m_listCtrl_vcard->RefreshList();
    if(m_panel_vcardgroup->IsShown()) m_listCtrl_vcardgroup->RefreshList();
    if(m_panel_company->IsShown()) m_listCtrl_company->RefreshList();
    if(m_panel_companytype->IsShown()) m_listCtrl_companytype->RefreshList();
}

void MainFrame::OnSettingItemActivated( wxListEvent& event )
{
    wxDialog    *dialog = NULL;
    wxListCtrl  *listctrl = NULL;

    if(m_panel_user->IsShown())
    {
        dialog = new UserDialog(this, event.GetIndex());
        listctrl = m_listCtrl_user;
    }

    if(m_panel_usergroup->IsShown())
    {
        dialog = new UserGroupDialog(this, event.GetIndex());
        listctrl = m_listCtrl_usergroup;
    }

    if(m_panel_vcard->IsShown())
    {
        dialog = new VcardDialog(this, event.GetIndex());
        listctrl = m_listCtrl_vcard;
    }

    if(m_panel_vcardgroup->IsShown())
    {
        dialog = new VcardGroupDialog(this, event.GetIndex());
        listctrl = m_listCtrl_vcardgroup;
    }

    if(m_panel_company->IsShown())
    {
        dialog = new CompanyDialog(this, event.GetIndex());
        listctrl = m_listCtrl_company;
    }

    if(m_panel_companytype->IsShown())
    {
        dialog = new CompanyTypeDialog(this, event.GetIndex());
        listctrl = m_listCtrl_companytype;
    }

    dialog->ShowModal();
    listctrl->Refresh();

    delete dialog;
}

void MainFrame::OnListSizeChange( wxSizeEvent& event )
{
    DoListSize();
    event.Skip();
}

void MainFrame::DoListSize()
{
    wxSize size = GetClientSize();

    m_listCtrl_user->SetSize(0, 0, size.x - 5, size.y - (m_panel_settingbutton->GetSize()).GetHeight());
    m_listCtrl_usergroup->SetSize(0, 0, size.x - 5, size.y - (m_panel_settingbutton->GetSize()).GetHeight());

    m_listCtrl_vcard->SetSize(0, 0, size.x - 5, size.y - (m_panel_settingbutton->GetSize()).GetHeight());
    m_listCtrl_vcardgroup->SetSize(0, 0, size.x - 5, size.y - (m_panel_settingbutton->GetSize()).GetHeight());
    m_listCtrl_company->SetSize(0, 0, size.x - 5, size.y - (m_panel_settingbutton->GetSize()).GetHeight());
    m_listCtrl_companytype->SetSize(0, 0, size.x - 5, size.y - (m_panel_settingbutton->GetSize()).GetHeight());
}

/////////////////////////////////////////////////////////////////////////////////////

UserDialog::UserDialog(wxWindow* parent, size_t id):UserDialogBase(parent)
{
    m_id = id;

    RefreshUserGroupChoice();

    if(m_id != NULL_ID)
    {
        UserInfo user_info = ((UserController *)(wxGetApp().GetController(CONTROLLER_USER)))->GetList()->Item(m_id);

        m_textCtrl_username->SetValue(user_info.m_name);

        for(size_t index = 0; index < m_choice_usergroup->GetCount(); index++)
        {
            if(*(size_t *)(m_choice_usergroup->GetClientData(index)) == user_info.m_usergroupid)
                m_choice_usergroup->SetSelection(index);
        }
    }
    else
    {
        m_choice_usergroup->SetSelection(0);
    }

    this->Connect(wxEVT_DATABASE_ADDUSER, wxDatabaseEventHandler(UserDialog::OnUserInfoUpdate));
    this->Connect(wxEVT_DATABASE_UPDATEUSER, wxDatabaseEventHandler(UserDialog::OnUserInfoUpdate));
}

void UserDialog::EnableDialog(bool flag)
{
    m_textCtrl_username->Enable(flag);
    m_textCtrl_userpassword->Enable(flag);
    m_choice_usergroup->Enable(flag);
    m_button_addusergroup->Enable(flag);
    m_button_save->Enable(flag);
    m_button_close->Enable(flag);
}

void UserDialog::OnButtonSaveClick( wxCommandEvent& event )
{
    if(m_textCtrl_username->GetValue().IsEmpty())
    {
        m_staticTextStatus->SetLabel(_("User Name Cannot Be Empty!"));
        return;
    }

    m_staticTextStatus->SetLabel(_("Saving Data......"));
    EnableDialog(false);

    wxJSONValue request_json;
    request_json[0] = m_textCtrl_username->GetValue();
    request_json[1] = m_textCtrl_userpassword->GetValue();
    request_json[2] = *(size_t *)(m_choice_usergroup->GetClientData(m_choice_usergroup->GetSelection()));//m_choiceidarray.Item(m_choice_usergroup->GetSelection());

    if(m_id != NULL_ID)
    {
        UserInfo user_info = ((UserController *)(wxGetApp().GetController(CONTROLLER_USER)))->GetList()->Item(m_id);
        request_json[3] = user_info.m_id;
    }

    wxEventType event_type = wxEVT_DATABASE_ADDUSER;
    if(m_id != NULL_ID) event_type = wxEVT_DATABASE_UPDATEUSER;

    wxEvtHandler *handler = wxGetApp().GetController(CONTROLLER_USER);
    wxDatabaseEvent database_event(event_type, CONTROLLER_USER);
    database_event.SetStatus(EVENTSTATUS_REQUEST);
    database_event.SetEventObject(this);
    database_event.SetJsonData(request_json);
    handler->AddPendingEvent(database_event);
}

void UserDialog::OnButtonAddUserGroupClick( wxCommandEvent& event )
{
    UserGroupDialog *dialog = new UserGroupDialog(this);
    dialog->ShowModal();

    delete dialog;
    RefreshUserGroupChoice();
}

void UserDialog::RefreshUserGroupChoice()
{
    m_choice_usergroup->Clear();

    UserGroupInfoArray* usergroup_array = ((UserGroupController *)(wxGetApp().GetController(CONTROLLER_USERGROUP)))->GetList();
    for(size_t index = 0; index < usergroup_array->GetCount(); index++)
    {
        m_choice_usergroup->Append(usergroup_array->Item(index).m_name, &(usergroup_array->Item(index).m_id));
    }
}

void UserDialog::OnUserInfoUpdate( wxDatabaseEvent& event)
{
    EnableDialog(true);

    if(event.GetStatus() == EVENTSTATUS_SUCCESS && event.GetResultRow())
    {
        if(event.GetEventType() == wxEVT_DATABASE_ADDUSER)
        {
            m_staticTextStatus->SetLabel(_("Add User Successfully"));
        }
        else
        {
            m_staticTextStatus->SetLabel(_("Update User Info Successfully"));
        }

        m_textCtrl_username->SetValue(wxT(""));
        m_textCtrl_userpassword->SetValue(wxT(""));
        m_choice_usergroup->SetSelection(0);
        m_id = NULL_ID;

        wxGetApp().GetMainFrame()->GetUserListctrl()->RefreshList();
    }
    else
    {
        if(event.GetEventType() == wxEVT_DATABASE_ADDUSER)
        {
            m_staticTextStatus->SetLabel(_("Fail To Add User"));
        }
        else
        {
            m_staticTextStatus->SetLabel(_("Fail To Update User Info"));
        }
    }
}

/////////////////////////////////////////////////////////////////////////////

UserGroupDialog::UserGroupDialog(wxWindow* parent, size_t id):UserGroupDialogBase(parent)
{
    m_id = id;

    if(m_id != NULL_ID)
    {
        UserGroupInfo usergroup_info = ((UserGroupController *)(wxGetApp().GetController(CONTROLLER_USERGROUP)))->GetList()->Item(m_id);

        m_textCtrl_groupname->SetValue(usergroup_info.m_name);
    }

    this->Connect(wxEVT_DATABASE_ADDUSERGROUP, wxDatabaseEventHandler(UserGroupDialog::OnUserGroupInfoUpdate));
    this->Connect(wxEVT_DATABASE_UPDATEUSERGROUP, wxDatabaseEventHandler(UserGroupDialog::OnUserGroupInfoUpdate));
}

void UserGroupDialog::EnableDialog(bool flag)
{
    m_textCtrl_groupname->Enable(flag);
    m_button_save->Enable(flag);
    m_button_close->Enable(flag);
}

void UserGroupDialog::OnButtonSaveClick( wxCommandEvent& event )
{
    if(m_textCtrl_groupname->GetValue().IsEmpty())
    {
        m_staticTextStatus->SetLabel(_("Group Name Cannot Be Empty!"));
        return;
    }

    m_staticTextStatus->SetLabel(_("Saving Data......"));
    EnableDialog(false);

    wxJSONValue request_json;
    request_json[0] = m_textCtrl_groupname->GetValue();

    if(m_id != NULL_ID)
    {
        UserGroupInfo usergroup_info = ((UserGroupController *)(wxGetApp().GetController(CONTROLLER_USERGROUP)))->GetList()->Item(m_id);
        request_json[1] = usergroup_info.m_id;
    }

    wxEventType event_type = wxEVT_DATABASE_ADDUSERGROUP;
    if(m_id != NULL_ID) event_type = wxEVT_DATABASE_UPDATEUSERGROUP;

    wxEvtHandler *handler = wxGetApp().GetController(CONTROLLER_USERGROUP);
    wxDatabaseEvent database_event(event_type, CONTROLLER_USERGROUP);
    database_event.SetStatus(EVENTSTATUS_REQUEST);
    database_event.SetEventObject(this);
    database_event.SetJsonData(request_json);
    handler->AddPendingEvent(database_event);
}

void UserGroupDialog::OnUserGroupInfoUpdate( wxDatabaseEvent& event)
{
    EnableDialog(true);

    if(event.GetStatus() == EVENTSTATUS_SUCCESS && event.GetResultRow())
    {
        if(event.GetEventType() == wxEVT_DATABASE_ADDUSERGROUP)
        {
            m_staticTextStatus->SetLabel(_("Add User Group Successfully"));
        }
        else
        {
            m_staticTextStatus->SetLabel(_("Update User Group Info Successfully"));
        }

        m_textCtrl_groupname->SetValue(wxT(""));
        m_id = NULL_ID;

        wxGetApp().GetMainFrame()->GetUserGroupListctrl()->RefreshList();
    }
    else
    {
        if(event.GetEventType() == wxEVT_DATABASE_ADDUSERGROUP)
        {
            m_staticTextStatus->SetLabel(_("Fail To Add User Group"));
        }
        else
        {
            m_staticTextStatus->SetLabel(_("Fail To Update User Group Info"));
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////

VcardDialog::VcardDialog(wxWindow* parent, size_t id):VcardDialogBase(parent)
{
    m_id = id;

    if(m_id != NULL_ID)
    {
        VcardInfo vcard_info = ((VcardController *)(wxGetApp().GetController(CONTROLLER_VCARD)))->GetList()->Item(m_id);

        m_textCtrl_fullname->SetValue(vcard_info.m_fullname);
        m_textCtrl_nickname->SetValue(vcard_info.m_nickname);
        m_textCtrl_workphone->SetValue(vcard_info.m_workphone);
        m_textCtrl_mobiephone->SetValue(vcard_info.m_mobiephone);
        m_textCtrl_email->SetValue(vcard_info.m_email);
        m_textCtrl_title->SetValue(vcard_info.m_title);
        m_textCtrl_company->SetValue(vcard_info.m_company);
    }

    this->Connect(wxEVT_DATABASE_ADDVCARD, wxDatabaseEventHandler(VcardDialog::OnVcardInfoUpdate));
    this->Connect(wxEVT_DATABASE_UPDATEVCARD, wxDatabaseEventHandler(VcardDialog::OnVcardInfoUpdate));
}

void VcardDialog::EnableDialog(bool flag)
{
    m_textCtrl_fullname->Enable(flag);
    m_textCtrl_nickname->Enable(flag);
    m_textCtrl_workphone->Enable(flag);
    m_textCtrl_mobiephone->Enable(flag);
    m_textCtrl_email->Enable(flag);
    m_textCtrl_title->Enable(flag);
    m_textCtrl_company->Enable(flag);
    m_button_save->Enable(flag);
    m_button_close->Enable(flag);
}

void VcardDialog::OnButtonSaveClick( wxCommandEvent& event )
{
    if(m_textCtrl_fullname->GetValue().IsEmpty() || m_textCtrl_nickname->GetValue().IsEmpty())
    {
        m_staticTextStatus->SetLabel(_("Full Name And Nick Name Cannot Be Empty!"));
        return;
    }

    m_staticTextStatus->SetLabel(_("Saving Data......"));
    EnableDialog(false);

    wxJSONValue request_json;
    request_json[0] = m_textCtrl_fullname->GetValue();
    request_json[1] = m_textCtrl_nickname->GetValue();
    request_json[2] = m_textCtrl_workphone->GetValue();
    request_json[3] = m_textCtrl_mobiephone->GetValue();
    request_json[4] = m_textCtrl_email->GetValue();
    request_json[5] = m_textCtrl_title->GetValue();
    request_json[6] = m_textCtrl_company->GetValue();

    if(m_id != NULL_ID)
    {
        VcardInfo vcard_info = ((VcardController *)(wxGetApp().GetController(CONTROLLER_VCARD)))->GetList()->Item(m_id);
        request_json[7] = vcard_info.m_id;
    }

    wxEventType event_type = wxEVT_DATABASE_ADDVCARD;
    if(m_id != NULL_ID) event_type = wxEVT_DATABASE_UPDATEVCARD;

    wxEvtHandler *handler = wxGetApp().GetController(CONTROLLER_VCARD);
    wxDatabaseEvent database_event(event_type, CONTROLLER_VCARD);
    database_event.SetStatus(EVENTSTATUS_REQUEST);
    database_event.SetEventObject(this);
    database_event.SetJsonData(request_json);
    handler->AddPendingEvent(database_event);
}

void VcardDialog::OnVcardInfoUpdate( wxDatabaseEvent& event)
{
    EnableDialog(true);

    if(event.GetStatus() == EVENTSTATUS_SUCCESS && event.GetResultRow())
    {
        if(event.GetEventType() == wxEVT_DATABASE_ADDVCARD)
        {
            m_staticTextStatus->SetLabel(_("Add Vcard Successfully"));
        }
        else
        {
            m_staticTextStatus->SetLabel(_("Update Vcard Successfully"));
        }

        m_textCtrl_fullname->SetValue(wxT(""));
        m_textCtrl_nickname->SetValue(wxT(""));
        m_textCtrl_workphone->SetValue(wxT(""));
        m_textCtrl_mobiephone->SetValue(wxT(""));
        m_textCtrl_email->SetValue(wxT(""));
        m_textCtrl_title->SetValue(wxT(""));
        m_textCtrl_company->SetValue(wxT(""));

        m_id = NULL_ID;

        wxGetApp().GetMainFrame()->GetVcardListctrl()->RefreshList();
    }
    else
    {
        if(event.GetEventType() == wxEVT_DATABASE_ADDVCARD)
        {
            m_staticTextStatus->SetLabel(_("Fail To Add Vcard"));
        }
        else
        {
            m_staticTextStatus->SetLabel(_("Fail To Update Vcard Info"));
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////

VcardGroupDialog::VcardGroupDialog(wxWindow* parent, size_t id):VcardGroupDialogBase(parent)
{
    m_id = id;

    if(m_id != NULL_ID)
    {
        VcardGroupInfo vcardgroup_info = ((VcardGroupController *)(wxGetApp().GetController(CONTROLLER_VCARDGROUP)))->GetList()->Item(m_id);

        m_textCtrl_groupname->SetValue(vcardgroup_info.m_name);
    }

    this->Connect(wxEVT_DATABASE_ADDVCARDGROUP, wxDatabaseEventHandler(VcardGroupDialog::OnVcardGroupInfoUpdate));
    this->Connect(wxEVT_DATABASE_UPDATEVCARDGROUP, wxDatabaseEventHandler(VcardGroupDialog::OnVcardGroupInfoUpdate));
}

void VcardGroupDialog::EnableDialog(bool flag)
{
    m_textCtrl_groupname->Enable(flag);
    m_button_save->Enable(flag);
    m_button_close->Enable(flag);
}

void VcardGroupDialog::OnButtonSaveClick( wxCommandEvent& event )
{
    if(m_textCtrl_groupname->GetValue().IsEmpty())
    {
        m_staticTextStatus->SetLabel(_("Group Name Cannot Be Empty!"));
        return;
    }

    m_staticTextStatus->SetLabel(_("Saving Data......"));
    EnableDialog(false);

    wxJSONValue request_json;
    request_json[0] = m_textCtrl_groupname->GetValue();

    if(m_id != NULL_ID)
    {
        VcardGroupInfo vcardgroup_info = ((VcardGroupController *)(wxGetApp().GetController(CONTROLLER_VCARDGROUP)))->GetList()->Item(m_id);
        request_json[1] = vcardgroup_info.m_id;
    }

    wxEventType event_type = wxEVT_DATABASE_ADDVCARDGROUP;
    if(m_id != NULL_ID) event_type = wxEVT_DATABASE_UPDATEVCARDGROUP;

    wxEvtHandler *handler = wxGetApp().GetController(CONTROLLER_VCARDGROUP);
    wxDatabaseEvent database_event(event_type, CONTROLLER_VCARDGROUP);
    database_event.SetStatus(EVENTSTATUS_REQUEST);
    database_event.SetEventObject(this);
    database_event.SetJsonData(request_json);
    handler->AddPendingEvent(database_event);
}

void VcardGroupDialog::OnVcardGroupInfoUpdate( wxDatabaseEvent& event)
{
    EnableDialog(true);

    if(event.GetStatus() == EVENTSTATUS_SUCCESS && event.GetResultRow())
    {
        if(event.GetEventType() == wxEVT_DATABASE_ADDVCARDGROUP)
        {
            m_staticTextStatus->SetLabel(_("Add Vcard Group Successfully"));
        }
        else
        {
            m_staticTextStatus->SetLabel(_("Update Vcard Group Successfully"));
        }

        m_textCtrl_groupname->SetValue(wxT(""));

        m_id = NULL_ID;

        wxGetApp().GetMainFrame()->GetVcardGroupListctrl()->RefreshList();
    }
    else
    {
        if(event.GetEventType() == wxEVT_DATABASE_ADDVCARDGROUP)
        {
            m_staticTextStatus->SetLabel(_("Fail To Add Vcard Group"));
        }
        else
        {
            m_staticTextStatus->SetLabel(_("Fail To Update Vcard Group"));
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////

CompanyDialog::CompanyDialog(wxWindow* parent, size_t id):CompanyDialogBase(parent)
{
    m_id = id;

    RefreshCompanyTypeChoice();

    if(m_id != NULL_ID)
    {
        CompanyInfo company_info = ((CompanyController *)(wxGetApp().GetController(CONTROLLER_COMPANY)))->GetList()->Item(m_id);

        m_textCtrl_companyname->SetValue(company_info.m_name);

        for(size_t index = 0; index < m_choice_companytype->GetCount(); index++)
        {
            if(*(size_t *)(m_choice_companytype->GetClientData(index)) == company_info.m_companytypeid)
                m_choice_companytype->SetSelection(index);
        }
    }
    else
    {
        m_choice_companytype->SetSelection(0);
    }

    this->Connect(wxEVT_DATABASE_ADDCOMPANY, wxDatabaseEventHandler(CompanyDialog::OnCompanyInfoUpdate));
    this->Connect(wxEVT_DATABASE_UPDATECOMPANY, wxDatabaseEventHandler(CompanyDialog::OnCompanyInfoUpdate));
}

void CompanyDialog::EnableDialog(bool flag)
{
    m_textCtrl_companyname->Enable(flag);
    m_choice_companytype->Enable(flag);
    m_button_addcompanytype->Enable(flag);
    m_button_save->Enable(flag);
    m_button_close->Enable(flag);
}

void CompanyDialog::OnButtonSaveClick( wxCommandEvent& event )
{
    if(m_textCtrl_companyname->GetValue().IsEmpty())
    {
        m_staticTextStatus->SetLabel(_("Company Name Cannot Be Empty!"));
        return;
    }

    m_staticTextStatus->SetLabel(_("Saving Data......"));
    EnableDialog(false);

    wxJSONValue request_json;
    request_json[0] = m_textCtrl_companyname->GetValue();
    request_json[1] = *(size_t *)(m_choice_companytype->GetClientData(m_choice_companytype->GetSelection()));//m_choiceidarray.Item(m_choice_usergroup->GetSelection());

    if(m_id != NULL_ID)
    {
        CompanyInfo company_info = ((CompanyController *)(wxGetApp().GetController(CONTROLLER_COMPANY)))->GetList()->Item(m_id);
        request_json[2] = company_info.m_id;
    }

    wxEventType event_type = wxEVT_DATABASE_ADDCOMPANY;
    if(m_id != NULL_ID) event_type = wxEVT_DATABASE_UPDATECOMPANY;

    wxEvtHandler *handler = wxGetApp().GetController(CONTROLLER_COMPANY);
    wxDatabaseEvent database_event(event_type, CONTROLLER_COMPANY);
    database_event.SetStatus(EVENTSTATUS_REQUEST);
    database_event.SetEventObject(this);
    database_event.SetJsonData(request_json);
    handler->AddPendingEvent(database_event);
}

void CompanyDialog::OnButtonAddCompanyTypeClick( wxCommandEvent& event )
{
    CompanyTypeDialog *dialog = new CompanyTypeDialog(this);
    dialog->ShowModal();

    delete dialog;
    RefreshCompanyTypeChoice();
}

void CompanyDialog::RefreshCompanyTypeChoice()
{
    m_choice_companytype->Clear();

    CompanyTypeInfoArray* companytype_array = ((CompanyTypeController *)(wxGetApp().GetController(CONTROLLER_COMPANYTYPE)))->GetList();
    for(size_t index = 0; index < companytype_array->GetCount(); index++)
    {
        m_choice_companytype->Append(companytype_array->Item(index).m_name, &(companytype_array->Item(index).m_id));
    }
}

void CompanyDialog::OnCompanyInfoUpdate( wxDatabaseEvent& event)
{
    EnableDialog(true);

    if(event.GetStatus() == EVENTSTATUS_SUCCESS && event.GetResultRow())
    {
        if(event.GetEventType() == wxEVT_DATABASE_ADDCOMPANY)
        {
            m_staticTextStatus->SetLabel(_("Add Company Successfully"));
        }
        else
        {
            m_staticTextStatus->SetLabel(_("Update Company Info Successfully"));
        }

        m_textCtrl_companyname->SetValue(wxT(""));
        m_choice_companytype->SetSelection(0);
        m_id = NULL_ID;

        wxGetApp().GetMainFrame()->GetCompanyListctrl()->RefreshList();
    }
    else
    {
        if(event.GetEventType() == wxEVT_DATABASE_ADDCOMPANY)
        {
            m_staticTextStatus->SetLabel(_("Fail To Add Company"));
        }
        else
        {
            m_staticTextStatus->SetLabel(_("Fail To Update Company Info"));
        }
    }
}

//////////////////////////////////////////////////////////////////////////////

CompanyTypeDialog::CompanyTypeDialog(wxWindow* parent, size_t id):CompanyTypeDialogBase(parent)
{
    m_id = id;

    if(m_id != NULL_ID)
    {
        CompanyTypeInfo companytype_info = ((CompanyTypeController *)(wxGetApp().GetController(CONTROLLER_COMPANYTYPE)))->GetList()->Item(m_id);

        m_textCtrl_companytype->SetValue(companytype_info.m_name);
    }

    this->Connect(wxEVT_DATABASE_ADDCOMPANYTYPE, wxDatabaseEventHandler(CompanyTypeDialog::OnCompanyTypeInfoUpdate));
    this->Connect(wxEVT_DATABASE_UPDATECOMPANYTYPE, wxDatabaseEventHandler(CompanyTypeDialog::OnCompanyTypeInfoUpdate));
}

void CompanyTypeDialog::EnableDialog(bool flag)
{
    m_textCtrl_companytype->Enable(flag);
    m_button_save->Enable(flag);
    m_button_close->Enable(flag);
}

void CompanyTypeDialog::OnButtonSaveClick( wxCommandEvent& event )
{
    if(m_textCtrl_companytype->GetValue().IsEmpty())
    {
        m_staticTextStatus->SetLabel(_("Company Type Name Cannot Be Empty!"));
        return;
    }

    m_staticTextStatus->SetLabel(_("Saving Data......"));
    EnableDialog(false);

    wxJSONValue request_json;
    request_json[0] = m_textCtrl_companytype->GetValue();

    if(m_id != NULL_ID)
    {
        CompanyTypeInfo companytype_info = ((CompanyTypeController *)(wxGetApp().GetController(CONTROLLER_COMPANYTYPE)))->GetList()->Item(m_id);
        request_json[1] = companytype_info.m_id;
    }

    wxEventType event_type = wxEVT_DATABASE_ADDCOMPANYTYPE;
    if(m_id != NULL_ID) event_type = wxEVT_DATABASE_UPDATECOMPANYTYPE;

    wxEvtHandler *handler = wxGetApp().GetController(CONTROLLER_COMPANYTYPE);
    wxDatabaseEvent database_event(event_type, CONTROLLER_COMPANYTYPE);
    database_event.SetStatus(EVENTSTATUS_REQUEST);
    database_event.SetEventObject(this);
    database_event.SetJsonData(request_json);
    handler->AddPendingEvent(database_event);
}

void CompanyTypeDialog::OnCompanyTypeInfoUpdate( wxDatabaseEvent& event)
{
    EnableDialog(true);

    if(event.GetStatus() == EVENTSTATUS_SUCCESS && event.GetResultRow())
    {
        if(event.GetEventType() == wxEVT_DATABASE_ADDCOMPANYTYPE)
        {
            m_staticTextStatus->SetLabel(_("Add Company Type Successfully"));
        }
        else
        {
            m_staticTextStatus->SetLabel(_("Update Company Type Info Successfully"));
        }

        m_textCtrl_companytype->SetValue(wxT(""));
        m_id = NULL_ID;

        wxGetApp().GetMainFrame()->GetCompanyTypeListctrl()->RefreshList();
    }
    else
    {
        if(event.GetEventType() == wxEVT_DATABASE_ADDCOMPANYTYPE)
        {
            m_staticTextStatus->SetLabel(_("Fail To Add Company Type"));
        }
        else
        {
            m_staticTextStatus->SetLabel(_("Fail To Update Company Type Info"));
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////

ResourceDialog::ResourceDialog(wxWindow* parent, size_t id):ResourceDialogBase(parent)
{
    m_id = id;

    RefreshResourceTypeChoice();

    if(m_id != NULL_ID)
    {
        ResourceInfo resource_info = ((ResourceController *)(wxGetApp().GetController(CONTROLLER_RESOURCE)))->GetList()->Item(m_id);

        m_textCtrl_resourcename->SetValue(resource_info.m_name);

        for(size_t index = 0; index < m_choice_resourcetype->GetCount(); index++)
        {
            if(*(size_t *)(m_choice_resourcetype->GetClientData(index)) == resource_info.m_resourcetypeid)
                m_choice_resourcetype->SetSelection(index);
        }
    }
    else
    {
        m_choice_resourcetype->SetSelection(0);
    }

    this->Connect(wxEVT_DATABASE_ADDRESOURCE, wxDatabaseEventHandler(ResourceDialog::OnResourceInfoUpdate));
    this->Connect(wxEVT_DATABASE_UPDATERESOURCE, wxDatabaseEventHandler(ResourceDialog::OnResourceInfoUpdate));
}

void ResourceDialog::EnableDialog(bool flag)
{
    m_textCtrl_resourcename->Enable(flag);
    m_choice_resourcetype->Enable(flag);
    m_button_addresourcetype->Enable(flag);
    m_button_save->Enable(flag);
    m_button_close->Enable(flag);
}

void ResourceDialog::OnButtonSaveClick( wxCommandEvent& event )
{
    if(m_textCtrl_resourcename->GetValue().IsEmpty())
    {
        m_staticTextStatus->SetLabel(_("Resource Name Cannot Be Empty!"));
        return;
    }

    m_staticTextStatus->SetLabel(_("Saving Data......"));
    EnableDialog(false);

    wxJSONValue request_json;
    request_json[0] = m_textCtrl_resourcename->GetValue();
    request_json[1] = *(size_t *)(m_choice_resourcetype->GetClientData(m_choice_resourcetype->GetSelection()));
    request_json[2] = m_textCtrl_pattern->GetValue();
    request_json[3] = m_textCtrl_weight->GetValue();

    if(m_id != NULL_ID)
    {
        ResourceInfo resource_info = ((ResourceController *)(wxGetApp().GetController(CONTROLLER_RESOURCE)))->GetList()->Item(m_id);
        request_json[4] = resource_info.m_id;
    }

    wxEventType event_type = wxEVT_DATABASE_ADDRESOURCE;
    if(m_id != NULL_ID) event_type = wxEVT_DATABASE_UPDATERESOURCE;

    wxEvtHandler *handler = wxGetApp().GetController(CONTROLLER_RESOURCE);
    wxDatabaseEvent database_event(event_type, CONTROLLER_RESOURCE);
    database_event.SetStatus(EVENTSTATUS_REQUEST);
    database_event.SetEventObject(this);
    database_event.SetJsonData(request_json);
    handler->AddPendingEvent(database_event);
}

void ResourceDialog::OnButtonAddResourceTypeClick( wxCommandEvent& event )
{
    ResourceTypeDialog *dialog = new ResourceTypeDialog(this);
    dialog->ShowModal();

    delete dialog;
    RefreshResourceTypeChoice();
}

void ResourceDialog::RefreshResourceTypeChoice()
{
    m_choice_resourcetype->Clear();

    ResourceTypeInfoArray* resourcetype_array = ((ResourceTypeController *)(wxGetApp().GetController(CONTROLLER_RESOURCETYPE)))->GetList();
    for(size_t index = 0; index < resourcetype_array->GetCount(); index++)
    {
        m_choice_resourcetype->Append(resourcetype_array->Item(index).m_name, &(resourcetype_array->Item(index).m_id));
    }
}

void ResourceDialog::OnResourceInfoUpdate( wxDatabaseEvent& event)
{
    EnableDialog(true);

    if(event.GetStatus() == EVENTSTATUS_SUCCESS && event.GetResultRow())
    {
        if(event.GetEventType() == wxEVT_DATABASE_ADDRESOURCE)
        {
            m_staticTextStatus->SetLabel(_("Add Resource Successfully"));
        }
        else
        {
            m_staticTextStatus->SetLabel(_("Update Resource Info Successfully"));
        }

        m_textCtrl_resourcename->SetValue(wxT(""));
        m_choice_resourcetype->SetSelection(0);
        m_id = NULL_ID;

        wxGetApp().GetMainFrame()->GetResourceListctrl()->RefreshList();
    }
    else
    {
        if(event.GetEventType() == wxEVT_DATABASE_ADDRESOURCE)
        {
            m_staticTextStatus->SetLabel(_("Fail To Add Resource"));
        }
        else
        {
            m_staticTextStatus->SetLabel(_("Fail To Update Resource Info"));
        }
    }
}

////////////////////////////////////////////////////////////////////////////

ResourceTypeDialog::ResourceTypeDialog(wxWindow* parent, size_t id):ResourceTypeDialogBase(parent)
{
    m_id = id;

    if(m_id != NULL_ID)
    {
        ResourceTypeInfo resourcetype_info = ((ResourceTypeController *)(wxGetApp().GetController(CONTROLLER_RESOURCETYPE)))->GetList()->Item(m_id);

        m_textCtrl_resourcetype->SetValue(resourcetype_info.m_name);
    }

    this->Connect(wxEVT_DATABASE_ADDRESOURCETYPE, wxDatabaseEventHandler(ResourceTypeDialog::OnResourceTypeInfoUpdate));
    this->Connect(wxEVT_DATABASE_UPDATERESOURCETYPE, wxDatabaseEventHandler(ResourceTypeDialog::OnResourceTypeInfoUpdate));
}

void ResourceTypeDialog::EnableDialog(bool flag)
{
    m_textCtrl_resourcetype->Enable(flag);
    m_button_save->Enable(flag);
    m_button_close->Enable(flag);
}

void ResourceTypeDialog::OnButtonSaveClick( wxCommandEvent& event )
{
    if(m_textCtrl_resourcetype->GetValue().IsEmpty())
    {
        m_staticTextStatus->SetLabel(_("Resource Type Name Cannot Be Empty!"));
        return;
    }

    m_staticTextStatus->SetLabel(_("Saving Data......"));
    EnableDialog(false);

    wxJSONValue request_json;
    request_json[0] = m_textCtrl_resourcetype->GetValue();

    if(m_id != NULL_ID)
    {
        ResourceTypeInfo resourcetype_info = ((ResourceTypeController *)(wxGetApp().GetController(CONTROLLER_RESOURCETYPE)))->GetList()->Item(m_id);
        request_json[1] = resourcetype_info.m_id;
    }

    wxEventType event_type = wxEVT_DATABASE_ADDRESOURCETYPE;
    if(m_id != NULL_ID) event_type = wxEVT_DATABASE_UPDATERESOURCETYPE;

    wxEvtHandler *handler = wxGetApp().GetController(CONTROLLER_RESOURCETYPE);
    wxDatabaseEvent database_event(event_type, CONTROLLER_RESOURCETYPE);
    database_event.SetStatus(EVENTSTATUS_REQUEST);
    database_event.SetEventObject(this);
    database_event.SetJsonData(request_json);
    handler->AddPendingEvent(database_event);
}

void ResourceTypeDialog::OnResourceTypeInfoUpdate( wxDatabaseEvent& event)
{
    EnableDialog(true);

    if(event.GetStatus() == EVENTSTATUS_SUCCESS && event.GetResultRow())
    {
        if(event.GetEventType() == wxEVT_DATABASE_ADDRESOURCETYPE)
        {
            m_staticTextStatus->SetLabel(_("Add Resource Type Successfully"));
        }
        else
        {
            m_staticTextStatus->SetLabel(_("Update Resource Type Info Successfully"));
        }

        m_textCtrl_resourcetype->SetValue(wxT(""));
        m_id = NULL_ID;

        wxGetApp().GetMainFrame()->GetResourceTypeListctrl()->RefreshList();
    }
    else
    {
        if(event.GetEventType() == wxEVT_DATABASE_ADDRESOURCETYPE)
        {
            m_staticTextStatus->SetLabel(_("Fail To Add Resource Type"));
        }
        else
        {
            m_staticTextStatus->SetLabel(_("Fail To Update Resource Type Info"));
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////

ResourceStatusDialog::ResourceStatusDialog(wxWindow* parent, size_t id):ResourceStatusDialogBase(parent)
{
    m_id = id;

    if(m_id != NULL_ID)
    {
        ResourceStatusInfo resourcetype_info = ((ResourceStatusController *)(wxGetApp().GetController(CONTROLLER_RESOURCESTATUS)))->GetList()->Item(m_id);

        m_textCtrl_resourcetype->SetValue(resourcetype_info.m_name);
    }

    this->Connect(wxEVT_DATABASE_ADDRESOURCESTATUS, wxDatabaseEventHandler(ResourceStatusDialog::OnResourceStatusInfoUpdate));
    this->Connect(wxEVT_DATABASE_UPDATERESOURCESTATUS, wxDatabaseEventHandler(ResourceStatusDialog::OnResourceStatusInfoUpdate));
}

void ResourceStatusDialog::EnableDialog(bool flag)
{
    m_textCtrl_resourcetype->Enable(flag);
    m_button_save->Enable(flag);
    m_button_close->Enable(flag);
}

void ResourceStatusDialog::OnButtonSaveClick( wxCommandEvent& event )
{
    if(m_textCtrl_resourcetype->GetValue().IsEmpty())
    {
        m_staticTextStatus->SetLabel(_("Resource Status Name Cannot Be Empty!"));
        return;
    }

    m_staticTextStatus->SetLabel(_("Saving Data......"));
    EnableDialog(false);

    wxJSONValue request_json;
    request_json[0] = m_textCtrl_resourcetype->GetValue();

    if(m_id != NULL_ID)
    {
        ResourceStatusInfo resourcetype_info = ((ResourceStatusController *)(wxGetApp().GetController(CONTROLLER_RESOURCESTATUS)))->GetList()->Item(m_id);
        request_json[1] = resourcetype_info.m_id;
    }

    wxEventType event_type = wxEVT_DATABASE_ADDRESOURCESTATUS;
    if(m_id != NULL_ID) event_type = wxEVT_DATABASE_UPDATERESOURCESTATUS;

    wxEvtHandler *handler = wxGetApp().GetController(CONTROLLER_RESOURCESTATUS);
    wxDatabaseEvent database_event(event_type, CONTROLLER_RESOURCESTATUS);
    database_event.SetStatus(EVENTSTATUS_REQUEST);
    database_event.SetEventObject(this);
    database_event.SetJsonData(request_json);
    handler->AddPendingEvent(database_event);
}

void ResourceStatusDialog::OnResourceStatusInfoUpdate( wxDatabaseEvent& event)
{
    EnableDialog(true);

    if(event.GetStatus() == EVENTSTATUS_SUCCESS && event.GetResultRow())
    {
        if(event.GetEventType() == wxEVT_DATABASE_ADDRESOURCESTATUS)
        {
            m_staticTextStatus->SetLabel(_("Add Resource Status Successfully"));
        }
        else
        {
            m_staticTextStatus->SetLabel(_("Update Resource Status Info Successfully"));
        }

        m_textCtrl_resourcetype->SetValue(wxT(""));
        m_id = NULL_ID;

        wxGetApp().GetMainFrame()->GetResourceStatusListctrl()->RefreshList();
    }
    else
    {
        if(event.GetEventType() == wxEVT_DATABASE_ADDRESOURCESTATUS)
        {
            m_staticTextStatus->SetLabel(_("Fail To Add Resource Status"));
        }
        else
        {
            m_staticTextStatus->SetLabel(_("Fail To Update Resource Status Info"));
        }
    }
}

