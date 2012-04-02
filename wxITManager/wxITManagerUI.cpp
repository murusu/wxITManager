#include "wxITManagerUI.h"

DECLARE_APP(wxITManagerApp)

LoginFrame::LoginFrame(wxFrame *frame) : LoginFrameBase(frame)
{
    m_configdialog = NULL;
}

LoginFrame::~LoginFrame()
{
}

void LoginFrame::OnButtonLoginClick( wxCommandEvent& event )
{
    wxGetApp().DoLogin();
}

void LoginFrame::OnButtonConfigClick( wxCommandEvent& event )
{
    if(!m_configdialog) m_configdialog = new DatabaseConfigDialog(this);

    m_configdialog->ClearContent();
    m_configdialog->LoadConfig();
    m_configdialog->ShowModal();
}

///////////////////////////////////////////////////////////////

DatabaseConfigDialog::DatabaseConfigDialog(wxFrame *frame) : DatabaseConfigDialogBase(frame)
{
    m_sqlitedialog = NULL;
    LoadConfig();

    this->Connect(wxEVT_DATABASE_QUERYSUCCESS, wxDatabaseEventHandler(DatabaseConfigDialog::OnDatabaseTest));
    this->Connect(wxEVT_DATABASE_QUERYERROR, wxDatabaseEventHandler(DatabaseConfigDialog::OnDatabaseTest));
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

    if(event.GetEventType() == wxEVT_DATABASE_QUERYSUCCESS)
    {
        wxJSONValue result(event.GetResultJson());
        wxJSONWriter writer;
  wxString     jsonText;
  writer.Write( result, jsonText );

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

///////////////////////////////////////////////////////////////

SqliteCreateDialog::SqliteCreateDialog(wxDialog *dialog) : SqliteCreateDialogBase(dialog)
{
    this->Connect(wxEVT_DATABASE_UPDATESUCCESS, wxDatabaseEventHandler(SqliteCreateDialog::OnDatabaseUpdate));
    this->Connect(wxEVT_DATABASE_UPDATEERROR, wxDatabaseEventHandler(SqliteCreateDialog::OnDatabaseUpdate));
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

    if(event.GetEventType() == wxEVT_DATABASE_UPDATESUCCESS)
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

///////////////////////////////////////////////////////////////

MainFrame::MainFrame(wxFrame *frame) : MainFrameBase(frame)
{
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
