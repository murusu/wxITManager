#include "wxITManagerUI.h"
/*
DEFINE_EVENT_TYPE(wxEVT_DATABASE_CREATE)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_CREATE_SUCCESS)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_CREATE_ERROR)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_UPDATE)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_UPDATE_SUCCESS)
DEFINE_EVENT_TYPE(wxEVT_DATABASE_UPDATE_ERROR)
IMPLEMENT_DYNAMIC_CLASS(wxDatabaseEvent, wxNotifyEvent)
*/
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
        //wxMessageBox(_("Can not save config file, please comfirm your access"), _("Error"), wxOK, this);
        m_staticTextStatus->SetLabel(_("Fail To Save Config File"));
    }
    else
    {
        //Close();
        m_staticTextStatus->SetLabel(_("Config File Saved"));
    }
}

void DatabaseConfigDialog::OnButtonCloseClick( wxCommandEvent& event )
{
    Close();
}

///////////////////////////////////////////////////////////////

SqliteCreateDialog::SqliteCreateDialog(wxDialog *dialog) : SqliteCreateDialogBase(dialog)
{
    //m_resultrow = 0;
    //m_resultstr = wxT("");
    m_config = NULL;
    m_database = NULL;

    this->Connect(wxEVT_DATABASE_UPDATE_SUCCESS, wxDatabaseEventHandler(SqliteCreateDialog::OnDatabaseUpdate));
    this->Connect(wxEVT_DATABASE_UPDATE_ERROR, wxDatabaseEventHandler(SqliteCreateDialog::OnDatabaseUpdate));
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
    EnableDialog(false);
    m_staticTextStatus->SetLabel(_("Creating New Database"));

    ManagerConfig *config = ((DatabaseController *)(wxGetApp().GetController(CONTROLLER_DATABASE)))->GetConfig();

    config->SetDatabaseType(DATABASE_SQLITE);
    config->SetDatabaseFile(m_textCtrl_databasefile->GetValue());
    config->SetDatabaseKey(m_textCtrl_databasekey->GetValue());

    wxDatabaseEvent database_event(wxEVT_DATABASE_CREATE, CONTROLLER_DATABASE);
    //database_event.SetEventObject(this);
    wxGetApp().GetController(CONTROLLER_DATABASE)->AddPendingEvent(database_event);
    /*
    if(m_config) delete m_config;
    if(m_database) delete m_database;

    m_config = new ManagerConfig();
    m_config->SetDatabaseType(DATABASE_SQLITE);
    m_config->SetDatabaseFile(m_textCtrl_databasefile->GetValue());
    m_config->SetDatabaseKey(m_textCtrl_databasekey->GetValue());

    m_database = DatabaseFactory::CreateDatabase(DATABASE_SQLITE);
    m_database->InitDBByConfig(m_config);
    m_database->InitDBTable();
    */

/*
    wxSQLite3Database::InitializeSQLite();
    wxSQLite3Database db;
    if(m_checkBox_encrypteddatabase->IsChecked())
    {
       db.Open(m_textCtrl_databasefile->GetValue(), m_textCtrl_databasekey->GetValue());
    }
    else
    {
       db.Open(m_textCtrl_databasefile->GetValue(), wxT("create table emp(empno integer primary key, empname char(20), salary double);"));
    }

    wxString sqlstr = wxT("");

    DatabaseUpdateThread *database_thread = new DatabaseUpdateThread(this, &db, sqlstr, &m_resultrow, &m_resultstr);

    if ( database_thread->Create() != wxTHREAD_NO_ERROR )
    {
    }
    else
    {
        database_thread->Run();
    }
*/
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

    if(event.GetEventType() == wxEVT_DATABASE_UPDATE_SUCCESS)
    {
        m_staticTextStatus->SetLabel(_("New Database Created"));
    }
    else
    {
        m_staticTextStatus->SetLabel(_("Fail To Create Database"));
    }
}

void SqliteCreateDialog::EnableDialog(bool flag)
{
    if(flag)
    {
        m_textCtrl_databasefile->Enable(true);
        m_button_browse->Enable(true);
        m_checkBox_encrypteddatabase->Enable(true);
        m_textCtrl_databasekey->Enable(true);
        m_button_create->Enable(true);
        m_button_close->Enable(true);
    }
    else
    {
        m_textCtrl_databasefile->Enable(false);
        m_button_browse->Enable(false);
        m_checkBox_encrypteddatabase->Enable(false);
        m_textCtrl_databasekey->Enable(false);
        m_button_create->Enable(false);
        m_button_close->Enable(false);
    }
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
