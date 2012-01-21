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

    m_configdialog->ShowModal();
}

///////////////////////////////////////////////////////////////

DatabaseConfigDialog::DatabaseConfigDialog(wxFrame *frame) : DatabaseConfigDialogBase(frame)
{
    m_sqlitedialog = NULL;
    ManagerConfig *config = wxGetApp().GetConfig();
    //Database *database = wxGetApp().GetDatabase();
    //if(database)
    //{
    //    delete database;
    //    database = NULL;
    //}

    if(!config->ReadConfigData()) wxMessageBox(_("Can not read config file, please comfirm your access"), _("Error"), wxOK, this);

    m_panel_sqlite->Enable(false);
    m_panel_mysql->Enable(false);

    switch(config->GetDatabaseType())
    {
        case DATABASE_SQLITE:
            //database = DatabaseFactory::CreateDatabase(DATABASE_SQLITE);
            //database->InitDatabase(config);

            m_panel_sqlite->Enable(true);
            m_choice_databasetype->SetSelection(DATABASE_SQLITE);
            m_textCtrl_databasefile->SetValue(config->GetDatabaseFile());
            if(!config->GetDatabaseKey().IsEmpty()) m_textCtrl_databasekey->SetValue(wxT("******"));
            //m_checkBox_encrypteddatabase->SetValue(wxGetApp().GetConfig()->GetDatabaseEncrypted());
            break;

        default:
            break;
    }
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

void DatabaseConfigDialog::OnCreateDatabaseClick( wxHyperlinkEvent& event )
{
    if(!m_sqlitedialog) m_sqlitedialog = new SqliteCreateDialog(this);

    m_sqlitedialog->ShowModal();
}

void DatabaseConfigDialog::OnButtonTestClick( wxCommandEvent& event )
{

}

void DatabaseConfigDialog::OnButtonSaveClick( wxCommandEvent& event )
{
    ManagerConfig *config = wxGetApp().GetConfig();
    config ->SetDatabaseType(m_choice_databasetype->GetCurrentSelection());
    config ->SetDatabaseFile(m_textCtrl_databasefile->GetValue());
    config ->SetDatabaseKey(m_textCtrl_databasekey->GetValue());
    //wxGetApp().GetConfig()->SetDatabaseEncrypted(m_checkBox_encrypteddatabase->IsChecked());

    if(!wxGetApp().GetConfig()->WriteConfigData())
    {
        wxMessageBox(_("Can not save config file, please comfirm your access"), _("Error"), wxOK, this);
    }
    else
    {
        Close();
    }
}

void DatabaseConfigDialog::OnButtonCloseClick( wxCommandEvent& event )
{
    Close();
}

///////////////////////////////////////////////////////////////

SqliteCreateDialog::SqliteCreateDialog(wxDialog *dialog) : SqliteCreateDialogBase(dialog)
{
}

SqliteCreateDialog::~SqliteCreateDialog()
{
}

void SqliteCreateDialog::OnButtonBrowseClick( wxCommandEvent& event )
{
    wxFileDialog file_dialog(this, _("Save Database File As"), wxT(""), wxT(""), wxT("Database Files (*.db)|*.db"), wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

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
    m_textCtrl_databasefile->Enable(false);
    m_button_browse->Enable(false);
    m_checkBox_encrypteddatabase->Enable(false);
    m_textCtrl_databasekey->Enable(false);
    m_button_create->Enable(false);
    m_button_close->Enable(false);
}

void SqliteCreateDialog::OnButtonCloseClick( wxCommandEvent& event )
{
    Close();
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
