#include "wxITManagerUI.h"

DECLARE_APP(wxITManagerApp)

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

    m_listCtrl_companytype->InsertColumn(0,_("Name"),wxLIST_FORMAT_LEFT,200);

    m_listCtrl_location->InsertColumn(0,_("Name"),wxLIST_FORMAT_LEFT,200);

    m_listCtrl_resource->InsertColumn(0,_("Name"),wxLIST_FORMAT_LEFT,200);
    m_listCtrl_resource->InsertColumn(1,_("Resource Type"),wxLIST_FORMAT_LEFT,200);
    m_listCtrl_resource->InsertColumn(2,_("Pattern"),wxLIST_FORMAT_LEFT,200);
    m_listCtrl_resource->InsertColumn(3,_("Weight"),wxLIST_FORMAT_LEFT,200);

    m_listCtrl_resourcetype->InsertColumn(0,_("Name"),wxLIST_FORMAT_LEFT,200);

    m_listCtrl_resourcestatus->InsertColumn(0,_("Name"),wxLIST_FORMAT_LEFT,200);
    m_listCtrl_resourcestatus->InsertColumn(1,_("Available Status"),wxLIST_FORMAT_LEFT,200);

    m_listCtrl_resourcefeetype->InsertColumn(0,_("Name"),wxLIST_FORMAT_LEFT,200);
    m_listCtrl_resourcefeetype->InsertColumn(1,_("Have Expiration"),wxLIST_FORMAT_LEFT,200);

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
    m_panel_location->Show(false);

    m_panel_resource->Show(false);
    m_panel_resourcetype->Show(false);
    m_panel_resourcestatus->Show(false);
    m_panel_resourcefeetype->Show(false);

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

        case wxID_MENUITEM_LOCATION:
            select_panel = m_panel_location;
            break;

        case wxID_MENUITEM_RESOURCE:
            select_panel = m_panel_resource;
            break;

        case wxID_MENUITEM_RESOURCETYPE:
            select_panel = m_panel_resourcetype;
            break;

        case wxID_MENUITEM_RESOURCESTATUS:
            select_panel = m_panel_resourcestatus;
            break;

        case wxID_MENUITEM_RESOURCEFEETYPE:
            select_panel = m_panel_resourcefeetype;
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

    if(m_panel_location->IsShown())
    {
        dialog   = new LocationDialog(this);
        listctrl = m_listCtrl_location;
    }

    if(m_panel_resource->IsShown())
    {
        dialog   = new ResourceDialog(this);
        listctrl = m_listCtrl_resource;
    }

    if(m_panel_resourcetype->IsShown())
    {
        dialog   = new ResourceTypeDialog(this);
        listctrl = m_listCtrl_resourcetype;
    }

    if(m_panel_resourcestatus->IsShown())
    {
        dialog   = new ResourceStatusDialog(this);
        listctrl = m_listCtrl_resourcestatus;
    }

    if(m_panel_resourcefeetype->IsShown())
    {
        dialog   = new ResourceFeeTypeDialog(this);
        listctrl = m_listCtrl_resourcefeetype;
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

    if(m_panel_location->IsShown())
    {
        controller_id = CONTROLLER_LOCATION;
        listctrl = m_listCtrl_location;
        event_type = wxEVT_DATABASE_DELETELOCATION;
    }

    if(m_panel_resource->IsShown())
    {
        controller_id = CONTROLLER_RESOURCE;
        listctrl = m_listCtrl_resource;
        event_type = wxEVT_DATABASE_DELETERESOURCE;
    }

    if(m_panel_resourcetype->IsShown())
    {
        controller_id = CONTROLLER_RESOURCETYPE;
        listctrl = m_listCtrl_resourcetype;
        event_type = wxEVT_DATABASE_DELETERESOURCETYPE;
    }

    if(m_panel_resourcestatus->IsShown())
    {
        controller_id = CONTROLLER_RESOURCESTATUS;
        listctrl = m_listCtrl_resourcestatus;
        event_type = wxEVT_DATABASE_DELETERESOURCESTATUS;
    }

    if(m_panel_resourcefeetype->IsShown())
    {
        controller_id = CONTROLLER_RESOURCEFEETYPE;
        listctrl = m_listCtrl_resourcefeetype;
        event_type = wxEVT_DATABASE_DELETERESOURCEFEETYPE;
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
        if(m_panel_location->IsShown()) delete_json[index] = ((LocationController *)(wxGetApp().GetController(controller_id)))->GetList()->Item(item).m_id;

        if(m_panel_resource->IsShown()) delete_json[index] = ((ResourceController *)(wxGetApp().GetController(controller_id)))->GetList()->Item(item).m_id;
        if(m_panel_resourcetype->IsShown()) delete_json[index] = ((ResourceTypeController *)(wxGetApp().GetController(controller_id)))->GetList()->Item(item).m_id;
        if(m_panel_resourcestatus->IsShown()) delete_json[index] = ((ResourceStatusController *)(wxGetApp().GetController(controller_id)))->GetList()->Item(item).m_id;
        if(m_panel_resourcefeetype->IsShown()) delete_json[index] = ((ResourceFeeTypeController *)(wxGetApp().GetController(controller_id)))->GetList()->Item(item).m_id;

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
    if(m_panel_location->IsShown()) m_listCtrl_location->RefreshList();

    if(m_panel_resource->IsShown()) m_listCtrl_resource->RefreshList();
    if(m_panel_resourcetype->IsShown()) m_listCtrl_resourcetype->RefreshList();
    if(m_panel_resourcestatus->IsShown()) m_listCtrl_resourcestatus->RefreshList();
    if(m_panel_resourcefeetype->IsShown()) m_listCtrl_resourcefeetype->RefreshList();
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

    if(m_panel_location->IsShown())
    {
        dialog = new LocationDialog(this, event.GetIndex());
        listctrl = m_listCtrl_location;
    }

    if(m_panel_resource->IsShown())
    {
        dialog = new ResourceDialog(this, event.GetIndex());
        listctrl = m_listCtrl_resource;
    }
    if(m_panel_resourcetype->IsShown())
    {
        dialog = new ResourceTypeDialog(this, event.GetIndex());
        listctrl = m_listCtrl_resourcetype;
    }
    if(m_panel_resourcestatus->IsShown())
    {
        dialog = new ResourceStatusDialog(this, event.GetIndex());
        listctrl = m_listCtrl_resourcestatus;
    }
    if(m_panel_resourcefeetype->IsShown())
    {
        dialog = new ResourceFeeTypeDialog(this, event.GetIndex());
        listctrl = m_listCtrl_resourcefeetype;
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
    m_listCtrl_location->SetSize(0, 0, size.x - 5, size.y - (m_panel_settingbutton->GetSize()).GetHeight());

    m_listCtrl_resource->SetSize(0, 0, size.x - 5, size.y - (m_panel_settingbutton->GetSize()).GetHeight());
    m_listCtrl_resourcetype->SetSize(0, 0, size.x - 5, size.y - (m_panel_settingbutton->GetSize()).GetHeight());
    m_listCtrl_resourcestatus->SetSize(0, 0, size.x - 5, size.y - (m_panel_settingbutton->GetSize()).GetHeight());
    m_listCtrl_resourcefeetype->SetSize(0, 0, size.x - 5, size.y - (m_panel_settingbutton->GetSize()).GetHeight());
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
    m_choice_usergroup->SetSelection(0);
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
    m_choice_companytype->SetSelection(0);
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

LocationDialog::LocationDialog(wxWindow* parent, size_t id):LocationDialogBase(parent)
{
    m_id = id;

    if(m_id != NULL_ID)
    {
        LocationInfo location_info = ((LocationController *)(wxGetApp().GetController(CONTROLLER_LOCATION)))->GetList()->Item(m_id);

        m_textCtrl_location->SetValue(location_info.m_name);
    }

    this->Connect(wxEVT_DATABASE_ADDLOCATION, wxDatabaseEventHandler(LocationDialog::OnLocationInfoUpdate));
    this->Connect(wxEVT_DATABASE_UPDATELOCATION, wxDatabaseEventHandler(LocationDialog::OnLocationInfoUpdate));
}

void LocationDialog::EnableDialog(bool flag)
{
    m_textCtrl_location->Enable(flag);
    m_button_save->Enable(flag);
    m_button_close->Enable(flag);
}

void LocationDialog::OnButtonSaveClick( wxCommandEvent& event )
{
    if(m_textCtrl_location->GetValue().IsEmpty())
    {
        m_staticTextStatus->SetLabel(_("Location Name Cannot Be Empty!"));
        return;
    }

    m_staticTextStatus->SetLabel(_("Saving Data......"));
    EnableDialog(false);

    wxJSONValue request_json;
    request_json[0] = m_textCtrl_location->GetValue();

    if(m_id != NULL_ID)
    {
        LocationInfo location_info = ((LocationController *)(wxGetApp().GetController(CONTROLLER_LOCATION)))->GetList()->Item(m_id);
        request_json[1] = location_info.m_id;
    }

    wxEventType event_type = wxEVT_DATABASE_ADDLOCATION;
    if(m_id != NULL_ID) event_type = wxEVT_DATABASE_UPDATELOCATION;

    wxEvtHandler *handler = wxGetApp().GetController(CONTROLLER_LOCATION);
    wxDatabaseEvent database_event(event_type, CONTROLLER_LOCATION);
    database_event.SetStatus(EVENTSTATUS_REQUEST);
    database_event.SetEventObject(this);
    database_event.SetJsonData(request_json);
    handler->AddPendingEvent(database_event);
}

void LocationDialog::OnLocationInfoUpdate( wxDatabaseEvent& event)
{
    EnableDialog(true);

    if(event.GetStatus() == EVENTSTATUS_SUCCESS && event.GetResultRow())
    {
        if(event.GetEventType() == wxEVT_DATABASE_ADDLOCATION)
        {
            m_staticTextStatus->SetLabel(_("Add Location Successfully"));
        }
        else
        {
            m_staticTextStatus->SetLabel(_("Update Location Info Successfully"));
        }

        m_textCtrl_location->SetValue(wxT(""));
        m_id = NULL_ID;

        wxGetApp().GetMainFrame()->GetLocationListctrl()->RefreshList();
    }
    else
    {
        if(event.GetEventType() == wxEVT_DATABASE_ADDLOCATION)
        {
            m_staticTextStatus->SetLabel(_("Fail To Add Location"));
        }
        else
        {
            m_staticTextStatus->SetLabel(_("Fail To Update Location Info"));
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
        m_textCtrl_pattern->SetValue(resource_info.m_pattern);
        m_textCtrl_weight->SetValue(wxString::Format(wxT("%d"),resource_info.m_weight));

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
    m_choice_resourcetype->SetSelection(0);
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
        m_textCtrl_pattern->SetValue(wxT(""));
        m_textCtrl_weight->SetValue(wxT(""));
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

        m_textCtrl_typename->SetValue(resourcetype_info.m_name);
    }

    this->Connect(wxEVT_DATABASE_ADDRESOURCETYPE, wxDatabaseEventHandler(ResourceTypeDialog::OnResourceTypeInfoUpdate));
    this->Connect(wxEVT_DATABASE_UPDATERESOURCETYPE, wxDatabaseEventHandler(ResourceTypeDialog::OnResourceTypeInfoUpdate));
}

void ResourceTypeDialog::EnableDialog(bool flag)
{
    m_textCtrl_typename->Enable(flag);
    m_button_save->Enable(flag);
    m_button_close->Enable(flag);
}

void ResourceTypeDialog::OnButtonSaveClick( wxCommandEvent& event )
{
    if(m_textCtrl_typename->GetValue().IsEmpty())
    {
        m_staticTextStatus->SetLabel(_("Resource Type Name Cannot Be Empty!"));
        return;
    }

    m_staticTextStatus->SetLabel(_("Saving Data......"));
    EnableDialog(false);

    wxJSONValue request_json;
    request_json[0] = m_textCtrl_typename->GetValue();

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

        m_textCtrl_typename->SetValue(wxT(""));
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
        ResourceStatusInfo resourcestatus_info = ((ResourceStatusController *)(wxGetApp().GetController(CONTROLLER_RESOURCESTATUS)))->GetList()->Item(m_id);

        m_textCtrl_resourcestatus->SetValue(resourcestatus_info.m_name);
        m_checkBox_available->SetValue(resourcestatus_info.m_available);
    }

    this->Connect(wxEVT_DATABASE_ADDRESOURCESTATUS, wxDatabaseEventHandler(ResourceStatusDialog::OnResourceStatusInfoUpdate));
    this->Connect(wxEVT_DATABASE_UPDATERESOURCESTATUS, wxDatabaseEventHandler(ResourceStatusDialog::OnResourceStatusInfoUpdate));
}

void ResourceStatusDialog::EnableDialog(bool flag)
{
    m_textCtrl_resourcestatus->Enable(flag);
    m_button_save->Enable(flag);
    m_button_close->Enable(flag);
}

void ResourceStatusDialog::OnButtonSaveClick( wxCommandEvent& event )
{
    if(m_textCtrl_resourcestatus->GetValue().IsEmpty())
    {
        m_staticTextStatus->SetLabel(_("Resource Status Name Cannot Be Empty!"));
        return;
    }

    m_staticTextStatus->SetLabel(_("Saving Data......"));
    EnableDialog(false);

    wxJSONValue request_json;
    request_json[0] = m_textCtrl_resourcestatus->GetValue();
    request_json[1] = m_checkBox_available->GetValue()?1:0;

    if(m_id != NULL_ID)
    {
        ResourceStatusInfo resourcestatus_info = ((ResourceStatusController *)(wxGetApp().GetController(CONTROLLER_RESOURCESTATUS)))->GetList()->Item(m_id);
        request_json[2] = resourcestatus_info.m_id;
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

        m_textCtrl_resourcestatus->SetValue(wxT(""));
        m_checkBox_available->SetValue(true);
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

///////////////////////////////////////////////////////////////////////////////////

ResourceFeeTypeDialog::ResourceFeeTypeDialog(wxWindow* parent, size_t id):ResourceFeeTypeDialogBase(parent)
{
    m_id = id;

    if(m_id != NULL_ID)
    {
        ResourceFeeTypeInfo resourcefeetype_info = ((ResourceFeeTypeController *)(wxGetApp().GetController(CONTROLLER_RESOURCEFEETYPE)))->GetList()->Item(m_id);

        m_textCtrl_feetype->SetValue(resourcefeetype_info.m_name);
        m_checkBox_expire->SetValue(resourcefeetype_info.m_haveexpiration);
    }

    this->Connect(wxEVT_DATABASE_ADDRESOURCEFEETYPE, wxDatabaseEventHandler(ResourceFeeTypeDialog::OnResourceFeeTypeInfoUpdate));
    this->Connect(wxEVT_DATABASE_UPDATERESOURCEFEETYPE, wxDatabaseEventHandler(ResourceFeeTypeDialog::OnResourceFeeTypeInfoUpdate));
}

void ResourceFeeTypeDialog::EnableDialog(bool flag)
{
    m_textCtrl_feetype->Enable(flag);
    m_button_save->Enable(flag);
    m_button_close->Enable(flag);
}

void ResourceFeeTypeDialog::OnButtonSaveClick( wxCommandEvent& event )
{
    if(m_textCtrl_feetype->GetValue().IsEmpty())
    {
        m_staticTextStatus->SetLabel(_("Resource Fee Type Name Cannot Be Empty!"));
        return;
    }

    m_staticTextStatus->SetLabel(_("Saving Data......"));
    EnableDialog(false);

    wxJSONValue request_json;
    request_json[0] = m_textCtrl_feetype->GetValue();
    request_json[1] = m_checkBox_expire->GetValue()?1:0;

    if(m_id != NULL_ID)
    {
        ResourceFeeTypeInfo resourcefeetype_info = ((ResourceFeeTypeController *)(wxGetApp().GetController(CONTROLLER_RESOURCEFEETYPE)))->GetList()->Item(m_id);
        request_json[2] = resourcefeetype_info.m_id;
    }

    wxEventType event_type = wxEVT_DATABASE_ADDRESOURCEFEETYPE;
    if(m_id != NULL_ID) event_type = wxEVT_DATABASE_UPDATERESOURCEFEETYPE;

    wxEvtHandler *handler = wxGetApp().GetController(CONTROLLER_RESOURCEFEETYPE);
    wxDatabaseEvent database_event(event_type, CONTROLLER_RESOURCEFEETYPE);
    database_event.SetStatus(EVENTSTATUS_REQUEST);
    database_event.SetEventObject(this);
    database_event.SetJsonData(request_json);
    handler->AddPendingEvent(database_event);
}

void ResourceFeeTypeDialog::OnResourceFeeTypeInfoUpdate( wxDatabaseEvent& event)
{
    EnableDialog(true);

    if(event.GetStatus() == EVENTSTATUS_SUCCESS && event.GetResultRow())
    {
        if(event.GetEventType() == wxEVT_DATABASE_ADDRESOURCEFEETYPE)
        {
            m_staticTextStatus->SetLabel(_("Add Resource Fee Type Successfully"));
        }
        else
        {
            m_staticTextStatus->SetLabel(_("Update Resource Status Info Successfully"));
        }

        m_textCtrl_feetype->SetValue(wxT(""));
        m_checkBox_expire->SetValue(false);
        m_id = NULL_ID;

        wxGetApp().GetMainFrame()->GetResourceFeeTypeListctrl()->RefreshList();
    }
    else
    {
        if(event.GetEventType() == wxEVT_DATABASE_ADDRESOURCEFEETYPE)
        {
            m_staticTextStatus->SetLabel(_("Fail To Add Resource Fee Type"));
        }
        else
        {
            m_staticTextStatus->SetLabel(_("Fail To Update Resource Fee Type Info"));
        }
    }
}
