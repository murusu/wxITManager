///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version May  4 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxITManagerUIExtend.h"

#include "wxITManagerUIBase.h"

///////////////////////////////////////////////////////////////////////////

LoginFrameBase::LoginFrameBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_ACTIVEBORDER ) );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, _("IT Management System"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	m_staticText1->SetFont( wxFont( 20, 72, 90, 92, false, wxEmptyString ) );
	
	bSizer2->Add( m_staticText1, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer1->Add( bSizer2, 1, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, _("User Name:"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText3->Wrap( -1 );
	bSizer4->Add( m_staticText3, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_comboBox_username = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 150,-1 ), 0, NULL, 0 ); 
	bSizer4->Add( m_comboBox_username, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer3->Add( bSizer4, 1, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, _("Password:"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText2->Wrap( -1 );
	bSizer5->Add( m_staticText2, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl_password = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 150,-1 ), wxTE_PASSWORD );
	bSizer5->Add( m_textCtrl_password, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer3->Add( bSizer5, 1, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText_Status = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE|wxST_NO_AUTORESIZE );
	m_staticText_Status->Wrap( -1 );
	bSizer33->Add( m_staticText_Status, 0, wxALL|wxEXPAND, 5 );
	
	bSizer3->Add( bSizer33, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button_login = new wxButton( this, wxID_BUTTON_LOGIN, _("Login"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_button_login, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_button_config = new wxButton( this, wxID_BUTTON_CONFIG, _("Database Config"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_button_config, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer3->Add( bSizer6, 1, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer1->Add( bSizer3, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button_login->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoginFrameBase::OnButtonLoginClick ), NULL, this );
	m_button_config->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoginFrameBase::OnButtonConfigClick ), NULL, this );
}

LoginFrameBase::~LoginFrameBase()
{
	// Disconnect Events
	m_button_login->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoginFrameBase::OnButtonLoginClick ), NULL, this );
	m_button_config->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoginFrameBase::OnButtonConfigClick ), NULL, this );
	
}

DatabaseConfigDialogBase::DatabaseConfigDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, _("Database Type:"), wxDefaultPosition, wxSize( 120,-1 ), 0 );
	m_staticText4->Wrap( -1 );
	bSizer8->Add( m_staticText4, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString m_choice_databasetypeChoices[] = { _("Sqlite") };
	int m_choice_databasetypeNChoices = sizeof( m_choice_databasetypeChoices ) / sizeof( wxString );
	m_choice_databasetype = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 150,-1 ), m_choice_databasetypeNChoices, m_choice_databasetypeChoices, 0 );
	m_choice_databasetype->SetSelection( 0 );
	bSizer8->Add( m_choice_databasetype, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer7->Add( bSizer8, 0, 0, 5 );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	m_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( m_panel1, wxID_ANY, _("Database Setting") ), wxVERTICAL );
	
	m_panel_sqlite = new wxPanel( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText6 = new wxStaticText( m_panel_sqlite, wxID_ANY, _("Database File:"), wxDefaultPosition, wxSize( 115,-1 ), 0 );
	m_staticText6->Wrap( -1 );
	bSizer13->Add( m_staticText6, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl_databasefile = new wxTextCtrl( m_panel_sqlite, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 180,-1 ), wxTE_READONLY );
	bSizer13->Add( m_textCtrl_databasefile, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_button_databasefile = new wxButton( m_panel_sqlite, wxID_ANY, _("Browse"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_button_databasefile, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer12->Add( bSizer13, 0, wxALIGN_LEFT, 5 );
	
	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxHORIZONTAL );
	
	m_checkBox_encrypteddatabase = new wxCheckBox( m_panel_sqlite, wxID_ANY, _("Encrypted Database"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer31->Add( m_checkBox_encrypteddatabase, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer12->Add( bSizer31, 0, wxALIGN_LEFT, 5 );
	
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText13 = new wxStaticText( m_panel_sqlite, wxID_ANY, _("Database Key:"), wxDefaultPosition, wxSize( 115,-1 ), 0 );
	m_staticText13->Wrap( -1 );
	bSizer14->Add( m_staticText13, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl_databasekey = new wxTextCtrl( m_panel_sqlite, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 180,-1 ), wxTE_PASSWORD );
	m_textCtrl_databasekey->Enable( false );
	
	bSizer14->Add( m_textCtrl_databasekey, 0, wxALL, 5 );
	
	bSizer12->Add( bSizer14, 0, wxALIGN_LEFT, 5 );
	
	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText111 = new wxStaticText( m_panel_sqlite, wxID_ANY, _("No Database?"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText111->Wrap( -1 );
	bSizer22->Add( m_staticText111, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_hyperlink_createdatabase = new wxHyperlinkCtrl( m_panel_sqlite, wxID_ANY, _("Create New One"), wxEmptyString, wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	bSizer22->Add( m_hyperlink_createdatabase, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer12->Add( bSizer22, 0, wxALIGN_LEFT, 5 );
	
	m_panel_sqlite->SetSizer( bSizer12 );
	m_panel_sqlite->Layout();
	bSizer12->Fit( m_panel_sqlite );
	sbSizer1->Add( m_panel_sqlite, 1, wxEXPAND | wxALL, 0 );
	
	m_panel_mysql = new wxPanel( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel_mysql->Hide();
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText8 = new wxStaticText( m_panel_mysql, wxID_ANY, _("IP Address:"), wxDefaultPosition, wxSize( 115,-1 ), 0 );
	m_staticText8->Wrap( -1 );
	bSizer16->Add( m_staticText8, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl4 = new wxTextCtrl( m_panel_mysql, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 180,-1 ), 0 );
	bSizer16->Add( m_textCtrl4, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer15->Add( bSizer16, 0, wxALIGN_LEFT, 5 );
	
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText9 = new wxStaticText( m_panel_mysql, wxID_ANY, _("Database Name:"), wxDefaultPosition, wxSize( 115,-1 ), 0 );
	m_staticText9->Wrap( -1 );
	bSizer17->Add( m_staticText9, 0, wxALL, 5 );
	
	m_textCtrl5 = new wxTextCtrl( m_panel_mysql, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 180,-1 ), 0 );
	bSizer17->Add( m_textCtrl5, 0, wxALL, 5 );
	
	bSizer15->Add( bSizer17, 0, wxALIGN_LEFT, 5 );
	
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText10 = new wxStaticText( m_panel_mysql, wxID_ANY, _("User Name:"), wxDefaultPosition, wxSize( 115,-1 ), 0 );
	m_staticText10->Wrap( -1 );
	bSizer18->Add( m_staticText10, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl6 = new wxTextCtrl( m_panel_mysql, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 180,-1 ), 0 );
	bSizer18->Add( m_textCtrl6, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer15->Add( bSizer18, 0, wxALIGN_LEFT, 5 );
	
	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText11 = new wxStaticText( m_panel_mysql, wxID_ANY, _("Password:"), wxDefaultPosition, wxSize( 115,-1 ), 0 );
	m_staticText11->Wrap( -1 );
	bSizer19->Add( m_staticText11, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl7 = new wxTextCtrl( m_panel_mysql, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 180,-1 ), 0 );
	bSizer19->Add( m_textCtrl7, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer15->Add( bSizer19, 0, wxALIGN_LEFT, 5 );
	
	m_panel_mysql->SetSizer( bSizer15 );
	m_panel_mysql->Layout();
	bSizer15->Fit( m_panel_mysql );
	sbSizer1->Add( m_panel_mysql, 1, wxEXPAND | wxALL, 0 );
	
	bSizer11->Add( sbSizer1, 1, wxEXPAND, 5 );
	
	m_panel1->SetSizer( bSizer11 );
	m_panel1->Layout();
	bSizer11->Fit( m_panel1 );
	bSizer9->Add( m_panel1, 1, wxEXPAND | wxALL, 0 );
	
	bSizer7->Add( bSizer9, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextStatus = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextStatus->Wrap( -1 );
	bSizer33->Add( m_staticTextStatus, 0, wxALL, 5 );
	
	bSizer32->Add( bSizer33, 1, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT, 5 );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button_test = new wxButton( this, wxID_BUTTON_TEST, _("Test Connection"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_button_test, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_button_save = new wxButton( this, wxID_BUTTON_SAVE, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_button_save, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_button_cancel = new wxButton( this, wxID_BUTTON_CANCEL, _("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_button_cancel, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer32->Add( bSizer10, 0, wxALIGN_RIGHT, 5 );
	
	bSizer7->Add( bSizer32, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizer7 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_choice_databasetype->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( DatabaseConfigDialogBase::OnChoiceDatabaseType ), NULL, this );
	m_button_databasefile->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DatabaseConfigDialogBase::OnButtonSqliteBrowse ), NULL, this );
	m_checkBox_encrypteddatabase->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DatabaseConfigDialogBase::OnCheckBoxEncryptedClick ), NULL, this );
	m_hyperlink_createdatabase->Connect( wxEVT_COMMAND_HYPERLINK, wxHyperlinkEventHandler( DatabaseConfigDialogBase::OnCreateDatabaseClick ), NULL, this );
	m_button_test->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DatabaseConfigDialogBase::OnButtonTestClick ), NULL, this );
	m_button_save->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DatabaseConfigDialogBase::OnButtonSaveClick ), NULL, this );
	m_button_cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DatabaseConfigDialogBase::OnButtonCloseClick ), NULL, this );
}

DatabaseConfigDialogBase::~DatabaseConfigDialogBase()
{
	// Disconnect Events
	m_choice_databasetype->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( DatabaseConfigDialogBase::OnChoiceDatabaseType ), NULL, this );
	m_button_databasefile->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DatabaseConfigDialogBase::OnButtonSqliteBrowse ), NULL, this );
	m_checkBox_encrypteddatabase->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DatabaseConfigDialogBase::OnCheckBoxEncryptedClick ), NULL, this );
	m_hyperlink_createdatabase->Disconnect( wxEVT_COMMAND_HYPERLINK, wxHyperlinkEventHandler( DatabaseConfigDialogBase::OnCreateDatabaseClick ), NULL, this );
	m_button_test->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DatabaseConfigDialogBase::OnButtonTestClick ), NULL, this );
	m_button_save->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DatabaseConfigDialogBase::OnButtonSaveClick ), NULL, this );
	m_button_cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DatabaseConfigDialogBase::OnButtonCloseClick ), NULL, this );
	
}

SqliteCreateDialogBase::SqliteCreateDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText12 = new wxStaticText( this, wxID_ANY, _("Database File:"), wxDefaultPosition, wxSize( 115,-1 ), 0 );
	m_staticText12->Wrap( -1 );
	bSizer24->Add( m_staticText12, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl_databasefile = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 180,-1 ), wxTE_READONLY );
	bSizer24->Add( m_textCtrl_databasefile, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_button_browse = new wxButton( this, wxID_ANY, _("Browse"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer24->Add( m_button_browse, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer23->Add( bSizer24, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxHORIZONTAL );
	
	m_checkBox_encrypteddatabase = new wxCheckBox( this, wxID_ANY, _("Encrypted Database"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer25->Add( m_checkBox_encrypteddatabase, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer23->Add( bSizer25, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer27;
	bSizer27 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText13 = new wxStaticText( this, wxID_ANY, _("Database Key:"), wxDefaultPosition, wxSize( 115,-1 ), 0 );
	m_staticText13->Wrap( -1 );
	bSizer27->Add( m_staticText13, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl_databasekey = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 180,-1 ), wxTE_PASSWORD );
	m_textCtrl_databasekey->Enable( false );
	
	bSizer27->Add( m_textCtrl_databasekey, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer23->Add( bSizer27, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextStatus = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextStatus->Wrap( -1 );
	bSizer29->Add( m_staticTextStatus, 0, wxALIGN_CENTER|wxALL, 5 );
	
	bSizer28->Add( bSizer29, 1, wxALIGN_LEFT|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button_create = new wxButton( this, wxID_ANY, _("Create"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button_create, 0, wxALL, 5 );
	
	m_button_close = new wxButton( this, wxID_ANY, _("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button_close, 0, wxALL, 5 );
	
	bSizer28->Add( bSizer26, 0, wxALIGN_RIGHT, 5 );
	
	bSizer23->Add( bSizer28, 0, wxEXPAND|wxTOP, 15 );
	
	this->SetSizer( bSizer23 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button_browse->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SqliteCreateDialogBase::OnButtonBrowseClick ), NULL, this );
	m_checkBox_encrypteddatabase->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SqliteCreateDialogBase::OnCheckBoxEncryptedClick ), NULL, this );
	m_button_create->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SqliteCreateDialogBase::OnButtonCreateClick ), NULL, this );
	m_button_close->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SqliteCreateDialogBase::OnButtonCloseClick ), NULL, this );
}

SqliteCreateDialogBase::~SqliteCreateDialogBase()
{
	// Disconnect Events
	m_button_browse->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SqliteCreateDialogBase::OnButtonBrowseClick ), NULL, this );
	m_checkBox_encrypteddatabase->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SqliteCreateDialogBase::OnCheckBoxEncryptedClick ), NULL, this );
	m_button_create->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SqliteCreateDialogBase::OnButtonCreateClick ), NULL, this );
	m_button_close->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SqliteCreateDialogBase::OnButtonCloseClick ), NULL, this );
	
}

MainFrameBase::MainFrameBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_ACTIVEBORDER ) );
	
	m_statusBar = this->CreateStatusBar( 3, wxST_SIZEGRIP, wxID_ANY );
	m_menubar = new wxMenuBar( 0 );
	m_menu1 = new wxMenu();
	wxMenuItem* m_menuItem_logout;
	m_menuItem_logout = new wxMenuItem( m_menu1, wxID_MENUITEM_LOGOUT, wxString( _("Logout") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem_logout );
	
	wxMenuItem* m_menuItem_exit;
	m_menuItem_exit = new wxMenuItem( m_menu1, wxID_MENUITEM_EXIT, wxString( _("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem_exit );
	
	m_menubar->Append( m_menu1, _("System") ); 
	
	m_menu6 = new wxMenu();
	wxMenuItem* m_menuItem18;
	m_menuItem18 = new wxMenuItem( m_menu6, wxID_ANY, wxString( _("Management") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu6->Append( m_menuItem18 );
	
	wxMenuItem* m_menuItem19;
	m_menuItem19 = new wxMenuItem( m_menu6, wxID_ANY, wxString( _("Log") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu6->Append( m_menuItem19 );
	
	m_menubar->Append( m_menu6, _("Depoly") ); 
	
	m_menu3 = new wxMenu();
	wxMenuItem* m_menuItem4;
	m_menuItem4 = new wxMenuItem( m_menu3, wxID_MENUITEM_USER, wxString( _("User") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem4 );
	
	wxMenuItem* m_menuItem5;
	m_menuItem5 = new wxMenuItem( m_menu3, wxID_MENUITEM_USERGROUP, wxString( _("UserGroup") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem5 );
	
	wxMenuItem* m_separator2;
	m_separator2 = m_menu3->AppendSeparator();
	
	wxMenuItem* m_menuItem6;
	m_menuItem6 = new wxMenuItem( m_menu3, wxID_MENUITEM_VCARD, wxString( _("Vcard") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem6 );
	
	wxMenuItem* m_menuItem8;
	m_menuItem8 = new wxMenuItem( m_menu3, wxID_MENUITEM_VCARDGROUP, wxString( _("Vcard Group") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem8 );
	
	wxMenuItem* m_menuItem7;
	m_menuItem7 = new wxMenuItem( m_menu3, wxID_MENUITEM_COMPANY, wxString( _("Company") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem7 );
	
	wxMenuItem* m_menuItem11;
	m_menuItem11 = new wxMenuItem( m_menu3, wxID_MENUITEM_COMPANYTYPE, wxString( _("Company Type") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem11 );
	
	wxMenuItem* m_menuItem201;
	m_menuItem201 = new wxMenuItem( m_menu3, wxID_MENUITEM_LOCATION, wxString( _("Location") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem201 );
	
	wxMenuItem* m_separator3;
	m_separator3 = m_menu3->AppendSeparator();
	
	wxMenuItem* m_menuItem17;
	m_menuItem17 = new wxMenuItem( m_menu3, wxID_MENUITEM_RESOURCE, wxString( _("Resource") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem17 );
	
	wxMenuItem* m_menuItem10;
	m_menuItem10 = new wxMenuItem( m_menu3, wxID_MENUITEM_RESOURCETYPE, wxString( _("Resource Type") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem10 );
	
	wxMenuItem* m_menuItem14;
	m_menuItem14 = new wxMenuItem( m_menu3, wxID_MENUITEM_RESOURCESTATUS, wxString( _("Resource Status") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem14 );
	
	wxMenuItem* m_menuItem15;
	m_menuItem15 = new wxMenuItem( m_menu3, wxID_MENUITEM_RESOURCEFEETYPE, wxString( _("Resource Fee Type") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem15 );
	
	m_menubar->Append( m_menu3, _("Settings") ); 
	
	m_menu7 = new wxMenu();
	wxMenuItem* m_menuItem21;
	m_menuItem21 = new wxMenuItem( m_menu7, wxID_ANY, wxString( _("Deploy Report") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu7->Append( m_menuItem21 );
	
	wxMenuItem* m_menuItem20;
	m_menuItem20 = new wxMenuItem( m_menu7, wxID_ANY, wxString( _("Fee Report") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu7->Append( m_menuItem20 );
	
	m_menubar->Append( m_menu7, _("Report") ); 
	
	m_menu4 = new wxMenu();
	wxMenuItem* m_menuItem12;
	m_menuItem12 = new wxMenuItem( m_menu4, wxID_MENUITEM_IMPORTDATA, wxString( _("ImportData") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu4->Append( m_menuItem12 );
	
	wxMenuItem* m_menuItem13;
	m_menuItem13 = new wxMenuItem( m_menu4, wxID_MENUITEM_EXPORTDATA, wxString( _("ExportData") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu4->Append( m_menuItem13 );
	
	m_menubar->Append( m_menu4, _("Database") ); 
	
	m_menu2 = new wxMenu();
	wxMenuItem* m_menuItem3;
	m_menuItem3 = new wxMenuItem( m_menu2, wxID_MENUITEM_ABOUT, wxString( _("About wxITManagement") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItem3 );
	
	m_menubar->Append( m_menu2, _("Help") ); 
	
	this->SetMenuBar( m_menubar );
	
	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxVERTICAL );
	
	m_panel_depoly = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer141;
	bSizer141 = new wxBoxSizer( wxVERTICAL );
	
	m_panel_depolymanagementbutton = new wxPanel( m_panel_depoly, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer144;
	bSizer144 = new wxBoxSizer( wxHORIZONTAL );
	
	wxString m_choice_serachtypeChoices[] = { _("All"), _("System Code"), _("Code"), _("Resource Name"), _("Resource Type"), _("Location"), _("Owner"), _("Status") };
	int m_choice_serachtypeNChoices = sizeof( m_choice_serachtypeChoices ) / sizeof( wxString );
	m_choice_serachtype = new wxChoice( m_panel_depolymanagementbutton, wxID_ANY, wxDefaultPosition, wxSize( 150,-1 ), m_choice_serachtypeNChoices, m_choice_serachtypeChoices, 0 );
	m_choice_serachtype->SetSelection( 0 );
	bSizer144->Add( m_choice_serachtype, 0, wxALL, 5 );
	
	wxArrayString m_choice_serachparamChoices;
	m_choice_serachparam = new wxChoice( m_panel_depolymanagementbutton, wxID_ANY, wxDefaultPosition, wxSize( 150,-1 ), m_choice_serachparamChoices, 0 );
	m_choice_serachparam->SetSelection( 0 );
	bSizer144->Add( m_choice_serachparam, 0, wxALL, 5 );
	
	m_textCtrl_searchparam = new wxTextCtrl( m_panel_depolymanagementbutton, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 150,-1 ), 0 );
	m_textCtrl_searchparam->Hide();
	
	bSizer144->Add( m_textCtrl_searchparam, 0, wxALL, 5 );
	
	m_button_depolysearch = new wxButton( m_panel_depolymanagementbutton, wxID_ANY, _("Search"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer144->Add( m_button_depolysearch, 0, wxALL, 5 );
	
	m_staticline1 = new wxStaticLine( m_panel_depolymanagementbutton, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxLI_HORIZONTAL );
	bSizer144->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );
	
	m_button_depolyadd = new wxButton( m_panel_depolymanagementbutton, wxID_ANY, _("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer144->Add( m_button_depolyadd, 0, wxALL, 5 );
	
	m_button_depolydelete = new wxButton( m_panel_depolymanagementbutton, wxID_ANY, _("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer144->Add( m_button_depolydelete, 0, wxALL, 5 );
	
	m_panel_depolymanagementbutton->SetSizer( bSizer144 );
	m_panel_depolymanagementbutton->Layout();
	bSizer144->Fit( m_panel_depolymanagementbutton );
	bSizer141->Add( m_panel_depolymanagementbutton, 0, wxEXPAND, 5 );
	
	m_panel25 = new wxPanel( m_panel_depoly, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer147;
	bSizer147 = new wxBoxSizer( wxVERTICAL );
	
	m_listCtrl_resourcedepoly = new ResourceDepolyListCtrl( m_panel25, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_REPORT|wxLC_VIRTUAL|wxLC_VRULES );
	bSizer147->Add( m_listCtrl_resourcedepoly, 1, wxALL|wxEXPAND, 5 );
	
	m_panel25->SetSizer( bSizer147 );
	m_panel25->Layout();
	bSizer147->Fit( m_panel25 );
	bSizer141->Add( m_panel25, 1, wxEXPAND, 5 );
	
	m_panel_depoly->SetSizer( bSizer141 );
	m_panel_depoly->Layout();
	bSizer141->Fit( m_panel_depoly );
	bSizer20->Add( m_panel_depoly, 1, wxEXPAND, 0 );
	
	m_panel_setting = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel_setting->Hide();
	
	wxBoxSizer* bSizer129;
	bSizer129 = new wxBoxSizer( wxVERTICAL );
	
	m_panel_settingbutton = new wxPanel( m_panel_setting, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer132;
	bSizer132 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button_settingadd = new wxButton( m_panel_settingbutton, wxID_ANY, _("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer132->Add( m_button_settingadd, 0, wxALL, 5 );
	
	m_button_settingdelete = new wxButton( m_panel_settingbutton, wxID_ANY, _("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer132->Add( m_button_settingdelete, 0, wxALL, 5 );
	
	m_button_settingrefresh = new wxButton( m_panel_settingbutton, wxID_ANY, _("Refresh"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer132->Add( m_button_settingrefresh, 0, wxALL, 5 );
	
	m_panel_settingbutton->SetSizer( bSizer132 );
	m_panel_settingbutton->Layout();
	bSizer132->Fit( m_panel_settingbutton );
	bSizer129->Add( m_panel_settingbutton, 0, wxALIGN_RIGHT, 5 );
	
	m_panel_settinglist = new wxPanel( m_panel_setting, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxVERTICAL );
	
	m_panel_user = new wxPanel( m_panel_settinglist, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer201;
	bSizer201 = new wxBoxSizer( wxVERTICAL );
	
	m_listCtrl_user = new UserListCtrl( m_panel_user, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_REPORT|wxLC_VIRTUAL|wxLC_VRULES );
	m_listCtrl_user->SetFont( wxFont( 11, 70, 90, 90, false, wxT("Arial") ) );
	
	bSizer201->Add( m_listCtrl_user, 0, wxALL|wxEXPAND, 5 );
	
	m_panel_user->SetSizer( bSizer201 );
	m_panel_user->Layout();
	bSizer201->Fit( m_panel_user );
	bSizer21->Add( m_panel_user, 1, wxEXPAND, 0 );
	
	m_panel_usergroup = new wxPanel( m_panel_settinglist, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel_usergroup->Hide();
	
	wxBoxSizer* bSizer204;
	bSizer204 = new wxBoxSizer( wxVERTICAL );
	
	m_listCtrl_usergroup = new UserGroupListCtrl( m_panel_usergroup, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_REPORT|wxLC_VIRTUAL|wxLC_VRULES );
	m_listCtrl_usergroup->SetFont( wxFont( 11, 70, 90, 90, false, wxT("Arial") ) );
	
	bSizer204->Add( m_listCtrl_usergroup, 0, wxALL|wxEXPAND, 5 );
	
	m_panel_usergroup->SetSizer( bSizer204 );
	m_panel_usergroup->Layout();
	bSizer204->Fit( m_panel_usergroup );
	bSizer21->Add( m_panel_usergroup, 1, wxEXPAND, 0 );
	
	m_panel_vcard = new wxPanel( m_panel_settinglist, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel_vcard->Hide();
	
	wxBoxSizer* bSizer127;
	bSizer127 = new wxBoxSizer( wxVERTICAL );
	
	m_listCtrl_vcard = new VcardListCtrl( m_panel_vcard, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_REPORT|wxLC_VIRTUAL|wxLC_VRULES );
	m_listCtrl_vcard->SetFont( wxFont( 11, 70, 90, 90, false, wxT("Arial") ) );
	
	bSizer127->Add( m_listCtrl_vcard, 0, wxALL|wxEXPAND, 5 );
	
	m_panel_vcard->SetSizer( bSizer127 );
	m_panel_vcard->Layout();
	bSizer127->Fit( m_panel_vcard );
	bSizer21->Add( m_panel_vcard, 1, wxEXPAND, 5 );
	
	m_panel_vcardgroup = new wxPanel( m_panel_settinglist, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel_vcardgroup->Hide();
	
	wxBoxSizer* bSizer128;
	bSizer128 = new wxBoxSizer( wxVERTICAL );
	
	m_listCtrl_vcardgroup = new VcardGroupListCtrl( m_panel_vcardgroup, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_REPORT|wxLC_VIRTUAL|wxLC_VRULES );
	m_listCtrl_vcardgroup->SetFont( wxFont( 11, 70, 90, 90, false, wxT("Arial") ) );
	
	bSizer128->Add( m_listCtrl_vcardgroup, 0, wxALL|wxEXPAND, 5 );
	
	m_panel_vcardgroup->SetSizer( bSizer128 );
	m_panel_vcardgroup->Layout();
	bSizer128->Fit( m_panel_vcardgroup );
	bSizer21->Add( m_panel_vcardgroup, 1, wxEXPAND, 5 );
	
	m_panel_company = new wxPanel( m_panel_settinglist, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel_company->Hide();
	
	wxBoxSizer* bSizer1291;
	bSizer1291 = new wxBoxSizer( wxVERTICAL );
	
	m_listCtrl_company = new CompanyListCtrl( m_panel_company, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_REPORT|wxLC_VIRTUAL|wxLC_VRULES );
	m_listCtrl_company->SetFont( wxFont( 11, 70, 90, 90, false, wxT("Arial") ) );
	
	bSizer1291->Add( m_listCtrl_company, 0, wxALL|wxEXPAND, 5 );
	
	m_panel_company->SetSizer( bSizer1291 );
	m_panel_company->Layout();
	bSizer1291->Fit( m_panel_company );
	bSizer21->Add( m_panel_company, 1, wxEXPAND, 5 );
	
	m_panel_companytype = new wxPanel( m_panel_settinglist, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel_companytype->Hide();
	
	wxBoxSizer* bSizer130;
	bSizer130 = new wxBoxSizer( wxVERTICAL );
	
	m_listCtrl_companytype = new CompanyTypeListCtrl( m_panel_companytype, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_REPORT|wxLC_VIRTUAL|wxLC_VRULES );
	m_listCtrl_companytype->SetFont( wxFont( 11, 70, 90, 90, false, wxT("Arial") ) );
	
	bSizer130->Add( m_listCtrl_companytype, 0, wxALL|wxEXPAND, 5 );
	
	m_panel_companytype->SetSizer( bSizer130 );
	m_panel_companytype->Layout();
	bSizer130->Fit( m_panel_companytype );
	bSizer21->Add( m_panel_companytype, 1, wxEXPAND, 5 );
	
	m_panel_location = new wxPanel( m_panel_settinglist, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel_location->Hide();
	
	wxBoxSizer* bSizer140;
	bSizer140 = new wxBoxSizer( wxVERTICAL );
	
	m_listCtrl_location = new LocationListCtrl( m_panel_location, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_REPORT|wxLC_VIRTUAL|wxLC_VRULES );
	m_listCtrl_location->SetFont( wxFont( 11, 70, 90, 90, false, wxT("Arial") ) );
	
	bSizer140->Add( m_listCtrl_location, 0, wxALL|wxEXPAND, 5 );
	
	m_panel_location->SetSizer( bSizer140 );
	m_panel_location->Layout();
	bSizer140->Fit( m_panel_location );
	bSizer21->Add( m_panel_location, 1, wxEXPAND, 5 );
	
	m_panel_resource = new wxPanel( m_panel_settinglist, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel_resource->Hide();
	
	wxBoxSizer* bSizer136;
	bSizer136 = new wxBoxSizer( wxVERTICAL );
	
	m_listCtrl_resource = new ResourceListCtrl( m_panel_resource, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_REPORT|wxLC_VIRTUAL|wxLC_VRULES );
	m_listCtrl_resource->SetFont( wxFont( 11, 70, 90, 90, false, wxT("Arial") ) );
	
	bSizer136->Add( m_listCtrl_resource, 0, wxALL|wxEXPAND, 5 );
	
	m_panel_resource->SetSizer( bSizer136 );
	m_panel_resource->Layout();
	bSizer136->Fit( m_panel_resource );
	bSizer21->Add( m_panel_resource, 1, wxEXPAND, 5 );
	
	m_panel_resourcetype = new wxPanel( m_panel_settinglist, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel_resourcetype->Hide();
	
	wxBoxSizer* bSizer137;
	bSizer137 = new wxBoxSizer( wxVERTICAL );
	
	m_listCtrl_resourcetype = new ResourceTypeListCtrl( m_panel_resourcetype, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_REPORT|wxLC_VIRTUAL|wxLC_VRULES );
	m_listCtrl_resourcetype->SetFont( wxFont( 11, 70, 90, 90, false, wxT("Arial") ) );
	
	bSizer137->Add( m_listCtrl_resourcetype, 0, wxALL|wxEXPAND, 5 );
	
	m_panel_resourcetype->SetSizer( bSizer137 );
	m_panel_resourcetype->Layout();
	bSizer137->Fit( m_panel_resourcetype );
	bSizer21->Add( m_panel_resourcetype, 1, wxEXPAND, 5 );
	
	m_panel_resourcestatus = new wxPanel( m_panel_settinglist, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel_resourcestatus->SetFont( wxFont( 11, 70, 90, 90, false, wxT("Arial") ) );
	m_panel_resourcestatus->Hide();
	
	wxBoxSizer* bSizer138;
	bSizer138 = new wxBoxSizer( wxVERTICAL );
	
	m_listCtrl_resourcestatus = new ResourceStatusListCtrl( m_panel_resourcestatus, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_REPORT|wxLC_VIRTUAL|wxLC_VRULES );
	m_listCtrl_resourcestatus->SetFont( wxFont( 11, 70, 90, 90, false, wxT("Arial") ) );
	
	bSizer138->Add( m_listCtrl_resourcestatus, 0, wxALL|wxEXPAND, 5 );
	
	m_panel_resourcestatus->SetSizer( bSizer138 );
	m_panel_resourcestatus->Layout();
	bSizer138->Fit( m_panel_resourcestatus );
	bSizer21->Add( m_panel_resourcestatus, 1, wxEXPAND, 5 );
	
	m_panel_resourcefeetype = new wxPanel( m_panel_settinglist, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel_resourcefeetype->Hide();
	
	wxBoxSizer* bSizer139;
	bSizer139 = new wxBoxSizer( wxVERTICAL );
	
	m_listCtrl_resourcefeetype = new ResourceFeeTypeListCtrl( m_panel_resourcefeetype, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_REPORT|wxLC_VIRTUAL|wxLC_VRULES );
	m_listCtrl_resourcefeetype->SetFont( wxFont( 11, 70, 90, 90, false, wxT("Arial") ) );
	
	bSizer139->Add( m_listCtrl_resourcefeetype, 0, wxALL|wxEXPAND, 5 );
	
	m_panel_resourcefeetype->SetSizer( bSizer139 );
	m_panel_resourcefeetype->Layout();
	bSizer139->Fit( m_panel_resourcefeetype );
	bSizer21->Add( m_panel_resourcefeetype, 1, wxEXPAND, 5 );
	
	m_panel_settinglist->SetSizer( bSizer21 );
	m_panel_settinglist->Layout();
	bSizer21->Fit( m_panel_settinglist );
	bSizer129->Add( m_panel_settinglist, 1, wxEXPAND, 5 );
	
	m_panel_setting->SetSizer( bSizer129 );
	m_panel_setting->Layout();
	bSizer129->Fit( m_panel_setting );
	bSizer20->Add( m_panel_setting, 1, wxEXPAND, 0 );
	
	m_panel_report = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel_report->Hide();
	
	bSizer20->Add( m_panel_report, 1, wxEXPAND, 0 );
	
	this->SetSizer( bSizer20 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrameBase::OnMainFrameClose ) );
	this->Connect( wxID_MENUITEM_LOGOUT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuLogoutSelection ) );
	this->Connect( wxID_MENUITEM_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuExitSelection ) );
	this->Connect( wxID_MENUITEM_USER, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuSettingSelect ) );
	this->Connect( wxID_MENUITEM_USERGROUP, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuSettingSelect ) );
	this->Connect( wxID_MENUITEM_VCARD, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuSettingSelect ) );
	this->Connect( wxID_MENUITEM_VCARDGROUP, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuSettingSelect ) );
	this->Connect( wxID_MENUITEM_COMPANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuSettingSelect ) );
	this->Connect( wxID_MENUITEM_COMPANYTYPE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuSettingSelect ) );
	this->Connect( wxID_MENUITEM_LOCATION, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuSettingSelect ) );
	this->Connect( wxID_MENUITEM_RESOURCE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuSettingSelect ) );
	this->Connect( wxID_MENUITEM_RESOURCETYPE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuSettingSelect ) );
	this->Connect( wxID_MENUITEM_RESOURCESTATUS, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuSettingSelect ) );
	this->Connect( wxID_MENUITEM_RESOURCEFEETYPE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuSettingSelect ) );
	this->Connect( wxID_MENUITEM_IMPORTDATA, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuImportdataSelection ) );
	this->Connect( wxID_MENUITEM_EXPORTDATA, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuExportdataSelection ) );
	this->Connect( wxID_MENUITEM_ABOUT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuAboutSelection ) );
	m_listCtrl_resourcedepoly->Connect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( MainFrameBase::OnDepolyItemActivated ), NULL, this );
	m_listCtrl_resourcedepoly->Connect( wxEVT_SIZE, wxSizeEventHandler( MainFrameBase::OnListSizeChange ), NULL, this );
	m_button_settingadd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonSettingAdd ), NULL, this );
	m_button_settingdelete->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonSettingDelete ), NULL, this );
	m_button_settingrefresh->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonSettingRefresh ), NULL, this );
	m_listCtrl_user->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( MainFrameBase::OnListKeyDown ), NULL, this );
	m_listCtrl_user->Connect( wxEVT_COMMAND_LIST_COL_CLICK, wxListEventHandler( MainFrameBase::SortUserList ), NULL, this );
	m_listCtrl_user->Connect( wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK, wxListEventHandler( MainFrameBase::ShowPopupMenu ), NULL, this );
	m_listCtrl_user->Connect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( MainFrameBase::OnSettingItemActivated ), NULL, this );
	m_listCtrl_user->Connect( wxEVT_SIZE, wxSizeEventHandler( MainFrameBase::OnListSizeChange ), NULL, this );
	m_listCtrl_usergroup->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( MainFrameBase::OnListKeyDown ), NULL, this );
	m_listCtrl_usergroup->Connect( wxEVT_COMMAND_LIST_COL_CLICK, wxListEventHandler( MainFrameBase::SortUserGroupList ), NULL, this );
	m_listCtrl_usergroup->Connect( wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK, wxListEventHandler( MainFrameBase::ShowPopupMenu ), NULL, this );
	m_listCtrl_usergroup->Connect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( MainFrameBase::OnSettingItemActivated ), NULL, this );
	m_listCtrl_usergroup->Connect( wxEVT_SIZE, wxSizeEventHandler( MainFrameBase::OnListSizeChange ), NULL, this );
	m_listCtrl_vcard->Connect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( MainFrameBase::OnSettingItemActivated ), NULL, this );
	m_listCtrl_vcard->Connect( wxEVT_SIZE, wxSizeEventHandler( MainFrameBase::OnListSizeChange ), NULL, this );
	m_listCtrl_vcardgroup->Connect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( MainFrameBase::OnSettingItemActivated ), NULL, this );
	m_listCtrl_vcardgroup->Connect( wxEVT_SIZE, wxSizeEventHandler( MainFrameBase::OnListSizeChange ), NULL, this );
	m_listCtrl_company->Connect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( MainFrameBase::OnSettingItemActivated ), NULL, this );
	m_listCtrl_company->Connect( wxEVT_SIZE, wxSizeEventHandler( MainFrameBase::OnListSizeChange ), NULL, this );
	m_listCtrl_companytype->Connect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( MainFrameBase::OnSettingItemActivated ), NULL, this );
	m_listCtrl_companytype->Connect( wxEVT_SIZE, wxSizeEventHandler( MainFrameBase::OnListSizeChange ), NULL, this );
	m_listCtrl_location->Connect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( MainFrameBase::OnSettingItemActivated ), NULL, this );
	m_listCtrl_location->Connect( wxEVT_SIZE, wxSizeEventHandler( MainFrameBase::OnListSizeChange ), NULL, this );
	m_listCtrl_resource->Connect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( MainFrameBase::OnSettingItemActivated ), NULL, this );
	m_listCtrl_resource->Connect( wxEVT_SIZE, wxSizeEventHandler( MainFrameBase::OnListSizeChange ), NULL, this );
	m_listCtrl_resourcetype->Connect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( MainFrameBase::OnSettingItemActivated ), NULL, this );
	m_listCtrl_resourcetype->Connect( wxEVT_SIZE, wxSizeEventHandler( MainFrameBase::OnListSizeChange ), NULL, this );
	m_listCtrl_resourcestatus->Connect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( MainFrameBase::OnSettingItemActivated ), NULL, this );
	m_listCtrl_resourcestatus->Connect( wxEVT_SIZE, wxSizeEventHandler( MainFrameBase::OnListSizeChange ), NULL, this );
	m_listCtrl_resourcefeetype->Connect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( MainFrameBase::OnSettingItemActivated ), NULL, this );
	m_listCtrl_resourcefeetype->Connect( wxEVT_SIZE, wxSizeEventHandler( MainFrameBase::OnListSizeChange ), NULL, this );
}

MainFrameBase::~MainFrameBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrameBase::OnMainFrameClose ) );
	this->Disconnect( wxID_MENUITEM_LOGOUT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuLogoutSelection ) );
	this->Disconnect( wxID_MENUITEM_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuExitSelection ) );
	this->Disconnect( wxID_MENUITEM_USER, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuSettingSelect ) );
	this->Disconnect( wxID_MENUITEM_USERGROUP, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuSettingSelect ) );
	this->Disconnect( wxID_MENUITEM_VCARD, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuSettingSelect ) );
	this->Disconnect( wxID_MENUITEM_VCARDGROUP, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuSettingSelect ) );
	this->Disconnect( wxID_MENUITEM_COMPANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuSettingSelect ) );
	this->Disconnect( wxID_MENUITEM_COMPANYTYPE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuSettingSelect ) );
	this->Disconnect( wxID_MENUITEM_LOCATION, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuSettingSelect ) );
	this->Disconnect( wxID_MENUITEM_RESOURCE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuSettingSelect ) );
	this->Disconnect( wxID_MENUITEM_RESOURCETYPE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuSettingSelect ) );
	this->Disconnect( wxID_MENUITEM_RESOURCESTATUS, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuSettingSelect ) );
	this->Disconnect( wxID_MENUITEM_RESOURCEFEETYPE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuSettingSelect ) );
	this->Disconnect( wxID_MENUITEM_IMPORTDATA, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuImportdataSelection ) );
	this->Disconnect( wxID_MENUITEM_EXPORTDATA, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuExportdataSelection ) );
	this->Disconnect( wxID_MENUITEM_ABOUT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuAboutSelection ) );
	m_listCtrl_resourcedepoly->Disconnect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( MainFrameBase::OnDepolyItemActivated ), NULL, this );
	m_listCtrl_resourcedepoly->Disconnect( wxEVT_SIZE, wxSizeEventHandler( MainFrameBase::OnListSizeChange ), NULL, this );
	m_button_settingadd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonSettingAdd ), NULL, this );
	m_button_settingdelete->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonSettingDelete ), NULL, this );
	m_button_settingrefresh->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonSettingRefresh ), NULL, this );
	m_listCtrl_user->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( MainFrameBase::OnListKeyDown ), NULL, this );
	m_listCtrl_user->Disconnect( wxEVT_COMMAND_LIST_COL_CLICK, wxListEventHandler( MainFrameBase::SortUserList ), NULL, this );
	m_listCtrl_user->Disconnect( wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK, wxListEventHandler( MainFrameBase::ShowPopupMenu ), NULL, this );
	m_listCtrl_user->Disconnect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( MainFrameBase::OnSettingItemActivated ), NULL, this );
	m_listCtrl_user->Disconnect( wxEVT_SIZE, wxSizeEventHandler( MainFrameBase::OnListSizeChange ), NULL, this );
	m_listCtrl_usergroup->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( MainFrameBase::OnListKeyDown ), NULL, this );
	m_listCtrl_usergroup->Disconnect( wxEVT_COMMAND_LIST_COL_CLICK, wxListEventHandler( MainFrameBase::SortUserGroupList ), NULL, this );
	m_listCtrl_usergroup->Disconnect( wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK, wxListEventHandler( MainFrameBase::ShowPopupMenu ), NULL, this );
	m_listCtrl_usergroup->Disconnect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( MainFrameBase::OnSettingItemActivated ), NULL, this );
	m_listCtrl_usergroup->Disconnect( wxEVT_SIZE, wxSizeEventHandler( MainFrameBase::OnListSizeChange ), NULL, this );
	m_listCtrl_vcard->Disconnect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( MainFrameBase::OnSettingItemActivated ), NULL, this );
	m_listCtrl_vcard->Disconnect( wxEVT_SIZE, wxSizeEventHandler( MainFrameBase::OnListSizeChange ), NULL, this );
	m_listCtrl_vcardgroup->Disconnect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( MainFrameBase::OnSettingItemActivated ), NULL, this );
	m_listCtrl_vcardgroup->Disconnect( wxEVT_SIZE, wxSizeEventHandler( MainFrameBase::OnListSizeChange ), NULL, this );
	m_listCtrl_company->Disconnect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( MainFrameBase::OnSettingItemActivated ), NULL, this );
	m_listCtrl_company->Disconnect( wxEVT_SIZE, wxSizeEventHandler( MainFrameBase::OnListSizeChange ), NULL, this );
	m_listCtrl_companytype->Disconnect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( MainFrameBase::OnSettingItemActivated ), NULL, this );
	m_listCtrl_companytype->Disconnect( wxEVT_SIZE, wxSizeEventHandler( MainFrameBase::OnListSizeChange ), NULL, this );
	m_listCtrl_location->Disconnect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( MainFrameBase::OnSettingItemActivated ), NULL, this );
	m_listCtrl_location->Disconnect( wxEVT_SIZE, wxSizeEventHandler( MainFrameBase::OnListSizeChange ), NULL, this );
	m_listCtrl_resource->Disconnect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( MainFrameBase::OnSettingItemActivated ), NULL, this );
	m_listCtrl_resource->Disconnect( wxEVT_SIZE, wxSizeEventHandler( MainFrameBase::OnListSizeChange ), NULL, this );
	m_listCtrl_resourcetype->Disconnect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( MainFrameBase::OnSettingItemActivated ), NULL, this );
	m_listCtrl_resourcetype->Disconnect( wxEVT_SIZE, wxSizeEventHandler( MainFrameBase::OnListSizeChange ), NULL, this );
	m_listCtrl_resourcestatus->Disconnect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( MainFrameBase::OnSettingItemActivated ), NULL, this );
	m_listCtrl_resourcestatus->Disconnect( wxEVT_SIZE, wxSizeEventHandler( MainFrameBase::OnListSizeChange ), NULL, this );
	m_listCtrl_resourcefeetype->Disconnect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( MainFrameBase::OnSettingItemActivated ), NULL, this );
	m_listCtrl_resourcefeetype->Disconnect( wxEVT_SIZE, wxSizeEventHandler( MainFrameBase::OnListSizeChange ), NULL, this );
	
}

UserGroupDialogBase::UserGroupDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer42;
	bSizer42 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText19 = new wxStaticText( this, wxID_ANY, _("User Group Name:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText19->Wrap( -1 );
	bSizer42->Add( m_staticText19, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl_groupname = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	bSizer42->Add( m_textCtrl_groupname, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer34->Add( bSizer42, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextStatus = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextStatus->Wrap( -1 );
	bSizer29->Add( m_staticTextStatus, 0, wxALIGN_CENTER|wxALL, 5 );
	
	bSizer28->Add( bSizer29, 1, wxALIGN_LEFT|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button_save = new wxButton( this, wxID_ANY, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button_save, 0, wxALL, 5 );
	
	m_button_close = new wxButton( this, wxID_ANY, _("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button_close, 0, wxALL, 5 );
	
	bSizer28->Add( bSizer26, 0, wxALIGN_RIGHT, 5 );
	
	bSizer34->Add( bSizer28, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizer34 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button_save->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UserGroupDialogBase::OnButtonSaveClick ), NULL, this );
	m_button_close->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UserGroupDialogBase::OnButtonCloseClick ), NULL, this );
}

UserGroupDialogBase::~UserGroupDialogBase()
{
	// Disconnect Events
	m_button_save->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UserGroupDialogBase::OnButtonSaveClick ), NULL, this );
	m_button_close->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UserGroupDialogBase::OnButtonCloseClick ), NULL, this );
	
}

UserDialogBase::UserDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer46;
	bSizer46 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer54;
	bSizer54 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText23 = new wxStaticText( this, wxID_ANY, _("User Name:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText23->Wrap( -1 );
	bSizer54->Add( m_staticText23, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl_username = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrl_username->SetMinSize( wxSize( 200,-1 ) );
	
	bSizer54->Add( m_textCtrl_username, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer46->Add( bSizer54, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer55;
	bSizer55 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText24 = new wxStaticText( this, wxID_ANY, _("Password:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText24->Wrap( -1 );
	bSizer55->Add( m_staticText24, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl_userpassword = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	bSizer55->Add( m_textCtrl_userpassword, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer46->Add( bSizer55, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer56;
	bSizer56 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText25 = new wxStaticText( this, wxID_ANY, _("User Group:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText25->Wrap( -1 );
	bSizer56->Add( m_staticText25, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxArrayString m_choice_usergroupChoices;
	m_choice_usergroup = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 200,-1 ), m_choice_usergroupChoices, 0 );
	m_choice_usergroup->SetSelection( 0 );
	bSizer56->Add( m_choice_usergroup, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_button_addusergroup = new wxButton( this, wxID_ANY, _("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer56->Add( m_button_addusergroup, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer46->Add( bSizer56, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextStatus = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextStatus->Wrap( -1 );
	bSizer29->Add( m_staticTextStatus, 0, wxALIGN_CENTER|wxALL, 5 );
	
	bSizer28->Add( bSizer29, 1, wxALIGN_LEFT|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button_save = new wxButton( this, wxID_ANY, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button_save, 0, wxALL, 5 );
	
	m_button_close = new wxButton( this, wxID_ANY, _("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button_close, 0, wxALL, 5 );
	
	bSizer28->Add( bSizer26, 0, wxALIGN_RIGHT, 5 );
	
	bSizer46->Add( bSizer28, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizer46 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button_addusergroup->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UserDialogBase::OnButtonAddUserGroupClick ), NULL, this );
	m_button_save->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UserDialogBase::OnButtonSaveClick ), NULL, this );
	m_button_close->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UserDialogBase::OnButtonCloseClick ), NULL, this );
}

UserDialogBase::~UserDialogBase()
{
	// Disconnect Events
	m_button_addusergroup->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UserDialogBase::OnButtonAddUserGroupClick ), NULL, this );
	m_button_save->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UserDialogBase::OnButtonSaveClick ), NULL, this );
	m_button_close->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UserDialogBase::OnButtonCloseClick ), NULL, this );
	
}

VcardDialogBase::VcardDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer57;
	bSizer57 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer65;
	bSizer65 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText28 = new wxStaticText( this, wxID_ANY, _("Full Name:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText28->Wrap( -1 );
	bSizer65->Add( m_staticText28, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl_fullname = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	bSizer65->Add( m_textCtrl_fullname, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer57->Add( bSizer65, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer66;
	bSizer66 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText29 = new wxStaticText( this, wxID_ANY, _("Nick Name:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText29->Wrap( -1 );
	bSizer66->Add( m_staticText29, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl_nickname = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	bSizer66->Add( m_textCtrl_nickname, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer57->Add( bSizer66, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer67;
	bSizer67 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText30 = new wxStaticText( this, wxID_ANY, _("Work Phone:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText30->Wrap( -1 );
	bSizer67->Add( m_staticText30, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl_workphone = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	bSizer67->Add( m_textCtrl_workphone, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer57->Add( bSizer67, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer68;
	bSizer68 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText31 = new wxStaticText( this, wxID_ANY, _("Mobie Phone:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText31->Wrap( -1 );
	bSizer68->Add( m_staticText31, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl_mobiephone = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	bSizer68->Add( m_textCtrl_mobiephone, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer57->Add( bSizer68, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer70;
	bSizer70 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText33 = new wxStaticText( this, wxID_ANY, _("E-Mail:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText33->Wrap( -1 );
	bSizer70->Add( m_staticText33, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl_email = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	bSizer70->Add( m_textCtrl_email, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer57->Add( bSizer70, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer69;
	bSizer69 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText32 = new wxStaticText( this, wxID_ANY, _("Title:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText32->Wrap( -1 );
	bSizer69->Add( m_staticText32, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl_title = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	bSizer69->Add( m_textCtrl_title, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer57->Add( bSizer69, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer71;
	bSizer71 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText34 = new wxStaticText( this, wxID_ANY, _("Company:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText34->Wrap( -1 );
	bSizer71->Add( m_staticText34, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl_company = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	bSizer71->Add( m_textCtrl_company, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer57->Add( bSizer71, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextStatus = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextStatus->Wrap( -1 );
	bSizer29->Add( m_staticTextStatus, 0, wxALIGN_CENTER|wxALL, 5 );
	
	bSizer28->Add( bSizer29, 1, wxALIGN_LEFT|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button_save = new wxButton( this, wxID_ANY, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button_save, 0, wxALL, 5 );
	
	m_button_close = new wxButton( this, wxID_ANY, _("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button_close, 0, wxALL, 5 );
	
	bSizer28->Add( bSizer26, 0, wxALIGN_RIGHT, 5 );
	
	bSizer57->Add( bSizer28, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizer57 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button_save->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VcardDialogBase::OnButtonSaveClick ), NULL, this );
	m_button_close->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VcardDialogBase::OnButtonCloseClick ), NULL, this );
}

VcardDialogBase::~VcardDialogBase()
{
	// Disconnect Events
	m_button_save->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VcardDialogBase::OnButtonSaveClick ), NULL, this );
	m_button_close->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VcardDialogBase::OnButtonCloseClick ), NULL, this );
	
}

VcardGroupDialogBase::VcardGroupDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer42;
	bSizer42 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText19 = new wxStaticText( this, wxID_ANY, _("User Group Name:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText19->Wrap( -1 );
	bSizer42->Add( m_staticText19, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl_groupname = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	bSizer42->Add( m_textCtrl_groupname, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer34->Add( bSizer42, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextStatus = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextStatus->Wrap( -1 );
	bSizer29->Add( m_staticTextStatus, 0, wxALIGN_CENTER|wxALL, 5 );
	
	bSizer28->Add( bSizer29, 1, wxALIGN_LEFT|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button_save = new wxButton( this, wxID_ANY, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button_save, 0, wxALL, 5 );
	
	m_button_close = new wxButton( this, wxID_ANY, _("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button_close, 0, wxALL, 5 );
	
	bSizer28->Add( bSizer26, 0, wxALIGN_RIGHT, 5 );
	
	bSizer34->Add( bSizer28, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizer34 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button_save->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VcardGroupDialogBase::OnButtonSaveClick ), NULL, this );
	m_button_close->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VcardGroupDialogBase::OnButtonCloseClick ), NULL, this );
}

VcardGroupDialogBase::~VcardGroupDialogBase()
{
	// Disconnect Events
	m_button_save->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VcardGroupDialogBase::OnButtonSaveClick ), NULL, this );
	m_button_close->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VcardGroupDialogBase::OnButtonCloseClick ), NULL, this );
	
}

CompanyDialogBase::CompanyDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer46;
	bSizer46 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer54;
	bSizer54 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText23 = new wxStaticText( this, wxID_ANY, _("Company Name:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText23->Wrap( -1 );
	bSizer54->Add( m_staticText23, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl_companyname = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrl_companyname->SetMinSize( wxSize( 200,-1 ) );
	
	bSizer54->Add( m_textCtrl_companyname, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer46->Add( bSizer54, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer56;
	bSizer56 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText25 = new wxStaticText( this, wxID_ANY, _("Company Type:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText25->Wrap( -1 );
	bSizer56->Add( m_staticText25, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxArrayString m_choice_companytypeChoices;
	m_choice_companytype = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 200,-1 ), m_choice_companytypeChoices, 0 );
	m_choice_companytype->SetSelection( 0 );
	bSizer56->Add( m_choice_companytype, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_button_addcompanytype = new wxButton( this, wxID_ANY, _("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer56->Add( m_button_addcompanytype, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer46->Add( bSizer56, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextStatus = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextStatus->Wrap( -1 );
	bSizer29->Add( m_staticTextStatus, 0, wxALIGN_CENTER|wxALL, 5 );
	
	bSizer28->Add( bSizer29, 1, wxALIGN_LEFT|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button_save = new wxButton( this, wxID_ANY, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button_save, 0, wxALL, 5 );
	
	m_button_close = new wxButton( this, wxID_ANY, _("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button_close, 0, wxALL, 5 );
	
	bSizer28->Add( bSizer26, 0, wxALIGN_RIGHT, 5 );
	
	bSizer46->Add( bSizer28, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizer46 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button_addcompanytype->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CompanyDialogBase::OnButtonAddCompanyTypeClick ), NULL, this );
	m_button_save->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CompanyDialogBase::OnButtonSaveClick ), NULL, this );
	m_button_close->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CompanyDialogBase::OnButtonCloseClick ), NULL, this );
}

CompanyDialogBase::~CompanyDialogBase()
{
	// Disconnect Events
	m_button_addcompanytype->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CompanyDialogBase::OnButtonAddCompanyTypeClick ), NULL, this );
	m_button_save->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CompanyDialogBase::OnButtonSaveClick ), NULL, this );
	m_button_close->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CompanyDialogBase::OnButtonCloseClick ), NULL, this );
	
}

CompanyTypeDialogBase::CompanyTypeDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer42;
	bSizer42 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText19 = new wxStaticText( this, wxID_ANY, _("Company Type:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText19->Wrap( -1 );
	bSizer42->Add( m_staticText19, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl_companytype = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	bSizer42->Add( m_textCtrl_companytype, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer34->Add( bSizer42, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextStatus = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextStatus->Wrap( -1 );
	bSizer29->Add( m_staticTextStatus, 0, wxALIGN_CENTER|wxALL, 5 );
	
	bSizer28->Add( bSizer29, 1, wxALIGN_LEFT|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button_save = new wxButton( this, wxID_ANY, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button_save, 0, wxALL, 5 );
	
	m_button_close = new wxButton( this, wxID_ANY, _("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button_close, 0, wxALL, 5 );
	
	bSizer28->Add( bSizer26, 0, wxALIGN_RIGHT, 5 );
	
	bSizer34->Add( bSizer28, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizer34 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button_save->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CompanyTypeDialogBase::OnButtonSaveClick ), NULL, this );
	m_button_close->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CompanyTypeDialogBase::OnButtonCloseClick ), NULL, this );
}

CompanyTypeDialogBase::~CompanyTypeDialogBase()
{
	// Disconnect Events
	m_button_save->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CompanyTypeDialogBase::OnButtonSaveClick ), NULL, this );
	m_button_close->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CompanyTypeDialogBase::OnButtonCloseClick ), NULL, this );
	
}

LocationDialogBase::LocationDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer42;
	bSizer42 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText19 = new wxStaticText( this, wxID_ANY, _("Location Name:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText19->Wrap( -1 );
	bSizer42->Add( m_staticText19, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl_location = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	bSizer42->Add( m_textCtrl_location, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer34->Add( bSizer42, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextStatus = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextStatus->Wrap( -1 );
	bSizer29->Add( m_staticTextStatus, 0, wxALIGN_CENTER|wxALL, 5 );
	
	bSizer28->Add( bSizer29, 1, wxALIGN_LEFT|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button_save = new wxButton( this, wxID_ANY, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button_save, 0, wxALL, 5 );
	
	m_button_close = new wxButton( this, wxID_ANY, _("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button_close, 0, wxALL, 5 );
	
	bSizer28->Add( bSizer26, 0, wxALIGN_RIGHT, 5 );
	
	bSizer34->Add( bSizer28, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizer34 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button_save->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LocationDialogBase::OnButtonSaveClick ), NULL, this );
	m_button_close->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LocationDialogBase::OnButtonCloseClick ), NULL, this );
}

LocationDialogBase::~LocationDialogBase()
{
	// Disconnect Events
	m_button_save->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LocationDialogBase::OnButtonSaveClick ), NULL, this );
	m_button_close->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LocationDialogBase::OnButtonCloseClick ), NULL, this );
	
}

ResourceDialogBase::ResourceDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer46;
	bSizer46 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer54;
	bSizer54 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText_resourcename = new wxStaticText( this, wxID_ANY, _("Resource Name:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText_resourcename->Wrap( -1 );
	bSizer54->Add( m_staticText_resourcename, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl_resourcename = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrl_resourcename->SetMinSize( wxSize( 200,-1 ) );
	
	bSizer54->Add( m_textCtrl_resourcename, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer46->Add( bSizer54, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer56;
	bSizer56 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText25 = new wxStaticText( this, wxID_ANY, _("Resource Type:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText25->Wrap( -1 );
	bSizer56->Add( m_staticText25, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxArrayString m_choice_resourcetypeChoices;
	m_choice_resourcetype = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 200,-1 ), m_choice_resourcetypeChoices, 0 );
	m_choice_resourcetype->SetSelection( 0 );
	bSizer56->Add( m_choice_resourcetype, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_button_addresourcetype = new wxButton( this, wxID_ANY, _("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer56->Add( m_button_addresourcetype, 0, wxALL, 5 );
	
	bSizer46->Add( bSizer56, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer55;
	bSizer55 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText24 = new wxStaticText( this, wxID_ANY, _("Pattern:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText24->Wrap( -1 );
	bSizer55->Add( m_staticText24, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl_pattern = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	bSizer55->Add( m_textCtrl_pattern, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer46->Add( bSizer55, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer105;
	bSizer105 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText55 = new wxStaticText( this, wxID_ANY, _("Weight:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText55->Wrap( -1 );
	bSizer105->Add( m_staticText55, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl_weight = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	bSizer105->Add( m_textCtrl_weight, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer46->Add( bSizer105, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextStatus = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextStatus->Wrap( -1 );
	bSizer29->Add( m_staticTextStatus, 0, wxALIGN_CENTER|wxALL, 5 );
	
	bSizer28->Add( bSizer29, 1, wxALIGN_LEFT|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button_save = new wxButton( this, wxID_ANY, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button_save, 0, wxALL, 5 );
	
	m_button_close = new wxButton( this, wxID_ANY, _("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button_close, 0, wxALL, 5 );
	
	bSizer28->Add( bSizer26, 0, wxALIGN_RIGHT, 5 );
	
	bSizer46->Add( bSizer28, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizer46 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button_addresourcetype->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ResourceDialogBase::OnButtonAddResourceTypeClick ), NULL, this );
	m_button_save->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ResourceDialogBase::OnButtonSaveClick ), NULL, this );
	m_button_close->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ResourceDialogBase::OnButtonCloseClick ), NULL, this );
}

ResourceDialogBase::~ResourceDialogBase()
{
	// Disconnect Events
	m_button_addresourcetype->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ResourceDialogBase::OnButtonAddResourceTypeClick ), NULL, this );
	m_button_save->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ResourceDialogBase::OnButtonSaveClick ), NULL, this );
	m_button_close->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ResourceDialogBase::OnButtonCloseClick ), NULL, this );
	
}

ResourceTypeDialogBase::ResourceTypeDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer46;
	bSizer46 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer54;
	bSizer54 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText23 = new wxStaticText( this, wxID_ANY, _("Type Name:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText23->Wrap( -1 );
	bSizer54->Add( m_staticText23, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl_typename = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrl_typename->SetMinSize( wxSize( 200,-1 ) );
	
	bSizer54->Add( m_textCtrl_typename, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer46->Add( bSizer54, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextStatus = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextStatus->Wrap( -1 );
	bSizer29->Add( m_staticTextStatus, 0, wxALIGN_CENTER|wxALL, 5 );
	
	bSizer28->Add( bSizer29, 1, wxALIGN_LEFT|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button_save = new wxButton( this, wxID_ANY, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button_save, 0, wxALL, 5 );
	
	m_button_close = new wxButton( this, wxID_ANY, _("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button_close, 0, wxALL, 5 );
	
	bSizer28->Add( bSizer26, 0, wxALIGN_RIGHT, 5 );
	
	bSizer46->Add( bSizer28, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizer46 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button_save->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ResourceTypeDialogBase::OnButtonSaveClick ), NULL, this );
	m_button_close->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ResourceTypeDialogBase::OnButtonCloseClick ), NULL, this );
}

ResourceTypeDialogBase::~ResourceTypeDialogBase()
{
	// Disconnect Events
	m_button_save->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ResourceTypeDialogBase::OnButtonSaveClick ), NULL, this );
	m_button_close->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ResourceTypeDialogBase::OnButtonCloseClick ), NULL, this );
	
}

ResourceStatusDialogBase::ResourceStatusDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer42;
	bSizer42 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText19 = new wxStaticText( this, wxID_ANY, _("Status Name:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText19->Wrap( -1 );
	bSizer42->Add( m_staticText19, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl_resourcestatus = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	bSizer42->Add( m_textCtrl_resourcestatus, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer34->Add( bSizer42, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer171;
	bSizer171 = new wxBoxSizer( wxHORIZONTAL );
	
	m_checkBox_available = new wxCheckBox( this, wxID_ANY, _("Available Status?"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox_available->SetValue(true); 
	bSizer171->Add( m_checkBox_available, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer34->Add( bSizer171, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextStatus = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextStatus->Wrap( -1 );
	bSizer29->Add( m_staticTextStatus, 0, wxALIGN_CENTER|wxALL, 5 );
	
	bSizer28->Add( bSizer29, 1, wxALIGN_LEFT|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button_save = new wxButton( this, wxID_ANY, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button_save, 0, wxALL, 5 );
	
	m_button_close = new wxButton( this, wxID_ANY, _("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button_close, 0, wxALL, 5 );
	
	bSizer28->Add( bSizer26, 0, wxALIGN_RIGHT, 5 );
	
	bSizer34->Add( bSizer28, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer34 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button_save->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ResourceStatusDialogBase::OnButtonSaveClick ), NULL, this );
	m_button_close->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ResourceStatusDialogBase::OnButtonCloseClick ), NULL, this );
}

ResourceStatusDialogBase::~ResourceStatusDialogBase()
{
	// Disconnect Events
	m_button_save->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ResourceStatusDialogBase::OnButtonSaveClick ), NULL, this );
	m_button_close->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ResourceStatusDialogBase::OnButtonCloseClick ), NULL, this );
	
}

ResourceDeployDialogBase::ResourceDeployDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer57;
	bSizer57 = new wxBoxSizer( wxVERTICAL );
	
	m_notebook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel_base = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer155;
	bSizer155 = new wxBoxSizer( wxVERTICAL );
	
	
	bSizer155->Add( 0, 0, 0, wxTOP, 10 );
	
	wxBoxSizer* bSizer142;
	bSizer142 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText66 = new wxStaticText( m_panel_base, wxID_ANY, _("System Code:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText66->Wrap( -1 );
	bSizer142->Add( m_staticText66, 0, wxALL, 5 );
	
	m_staticText_systemcode = new wxStaticText( m_panel_base, wxID_ANY, _("SF039413"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_systemcode->Wrap( -1 );
	bSizer142->Add( m_staticText_systemcode, 0, wxALL, 5 );
	
	bSizer155->Add( bSizer142, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer65;
	bSizer65 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText28 = new wxStaticText( m_panel_base, wxID_ANY, _("Code:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText28->Wrap( -1 );
	bSizer65->Add( m_staticText28, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl_code = new wxTextCtrl( m_panel_base, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 150,-1 ), 0 );
	bSizer65->Add( m_textCtrl_code, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText83 = new wxStaticText( m_panel_base, wxID_ANY, _("Resource Status:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText83->Wrap( -1 );
	bSizer65->Add( m_staticText83, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxArrayString m_choice_resourcestatusChoices;
	m_choice_resourcestatus = new wxChoice( m_panel_base, wxID_ANY, wxDefaultPosition, wxSize( 150,-1 ), m_choice_resourcestatusChoices, 0 );
	m_choice_resourcestatus->SetSelection( 0 );
	bSizer65->Add( m_choice_resourcestatus, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer155->Add( bSizer65, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer66;
	bSizer66 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText29 = new wxStaticText( m_panel_base, wxID_ANY, _("Resource Type:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText29->Wrap( -1 );
	bSizer66->Add( m_staticText29, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString m_choice_resourcetypeChoices[] = { _("All") };
	int m_choice_resourcetypeNChoices = sizeof( m_choice_resourcetypeChoices ) / sizeof( wxString );
	m_choice_resourcetype = new wxChoice( m_panel_base, wxID_ANY, wxDefaultPosition, wxSize( 150,-1 ), m_choice_resourcetypeNChoices, m_choice_resourcetypeChoices, 0 );
	m_choice_resourcetype->SetSelection( 0 );
	bSizer66->Add( m_choice_resourcetype, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText82 = new wxStaticText( m_panel_base, wxID_ANY, _("Resource Name:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText82->Wrap( -1 );
	bSizer66->Add( m_staticText82, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxArrayString m_choice_resourcenameChoices;
	m_choice_resourcename = new wxChoice( m_panel_base, wxID_ANY, wxDefaultPosition, wxSize( 150,-1 ), m_choice_resourcenameChoices, 0 );
	m_choice_resourcename->SetSelection( 0 );
	bSizer66->Add( m_choice_resourcename, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer155->Add( bSizer66, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer67;
	bSizer67 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText30 = new wxStaticText( m_panel_base, wxID_ANY, _("Location:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText30->Wrap( -1 );
	bSizer67->Add( m_staticText30, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString m_choice_locationChoices[] = { _("None") };
	int m_choice_locationNChoices = sizeof( m_choice_locationChoices ) / sizeof( wxString );
	m_choice_location = new wxChoice( m_panel_base, wxID_ANY, wxDefaultPosition, wxSize( 150,-1 ), m_choice_locationNChoices, m_choice_locationChoices, 0 );
	m_choice_location->SetSelection( 0 );
	bSizer67->Add( m_choice_location, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText85 = new wxStaticText( m_panel_base, wxID_ANY, _("Owner:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText85->Wrap( -1 );
	bSizer67->Add( m_staticText85, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString m_choice_ownerChoices[] = { _("None") };
	int m_choice_ownerNChoices = sizeof( m_choice_ownerChoices ) / sizeof( wxString );
	m_choice_owner = new wxChoice( m_panel_base, wxID_ANY, wxDefaultPosition, wxSize( 150,-1 ), m_choice_ownerNChoices, m_choice_ownerChoices, 0 );
	m_choice_owner->SetSelection( 0 );
	bSizer67->Add( m_choice_owner, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer155->Add( bSizer67, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer170;
	bSizer170 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText98 = new wxStaticText( m_panel_base, wxID_ANY, _("Remark:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText98->Wrap( -1 );
	bSizer170->Add( m_staticText98, 0, wxALL, 5 );
	
	m_textCtrl_remark = new wxTextCtrl( m_panel_base, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 530,90 ), 0 );
	bSizer170->Add( m_textCtrl_remark, 0, wxALL, 5 );
	
	bSizer155->Add( bSizer170, 1, wxEXPAND, 5 );
	
	m_panel_base->SetSizer( bSizer155 );
	m_panel_base->Layout();
	bSizer155->Fit( m_panel_base );
	m_notebook->AddPage( m_panel_base, _("Base Info"), true );
	m_panel_sub = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer157;
	bSizer157 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer158;
	bSizer158 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button_addnewsub = new wxButton( m_panel_sub, wxID_ANY, _("Add New Resource"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer158->Add( m_button_addnewsub, 0, wxALL, 5 );
	
	m_button_addexitsub = new wxButton( m_panel_sub, wxID_ANY, _("Add Deployed Resource"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer158->Add( m_button_addexitsub, 0, wxALL, 5 );
	
	m_button_deletesub = new wxButton( m_panel_sub, wxID_ANY, _("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer158->Add( m_button_deletesub, 0, wxALL, 5 );
	
	bSizer157->Add( bSizer158, 0, wxALIGN_RIGHT, 5 );
	
	wxBoxSizer* bSizer159;
	bSizer159 = new wxBoxSizer( wxVERTICAL );
	
	m_listCtrl_sub = new wxListCtrl( m_panel_sub, wxID_ANY, wxDefaultPosition, wxSize( 530,190 ), wxLC_HRULES|wxLC_REPORT|wxLC_VRULES );
	bSizer159->Add( m_listCtrl_sub, 0, wxALL, 5 );
	
	bSizer157->Add( bSizer159, 0, wxEXPAND, 5 );
	
	m_panel_sub->SetSizer( bSizer157 );
	m_panel_sub->Layout();
	bSizer157->Fit( m_panel_sub );
	m_notebook->AddPage( m_panel_sub, _("Sub Resource"), false );
	m_panel_fee = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer1571;
	bSizer1571 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer1581;
	bSizer1581 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button_addfee = new wxButton( m_panel_fee, wxID_ANY, _("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1581->Add( m_button_addfee, 0, wxALL, 5 );
	
	m_button_deletefee = new wxButton( m_panel_fee, wxID_ANY, _("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1581->Add( m_button_deletefee, 0, wxALL, 5 );
	
	bSizer1571->Add( bSizer1581, 0, wxALIGN_RIGHT, 5 );
	
	wxBoxSizer* bSizer1591;
	bSizer1591 = new wxBoxSizer( wxVERTICAL );
	
	m_listCtrl_fee = new wxListCtrl( m_panel_fee, wxID_ANY, wxDefaultPosition, wxSize( 530,190 ), wxLC_HRULES|wxLC_REPORT|wxLC_VRULES );
	bSizer1591->Add( m_listCtrl_fee, 0, wxALL, 5 );
	
	bSizer1571->Add( bSizer1591, 0, wxEXPAND, 5 );
	
	m_panel_fee->SetSizer( bSizer1571 );
	m_panel_fee->Layout();
	bSizer1571->Fit( m_panel_fee );
	m_notebook->AddPage( m_panel_fee, _("Fee"), false );
	m_panel_log = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer168;
	bSizer168 = new wxBoxSizer( wxVERTICAL );
	
	m_listCtrl_log = new wxListCtrl( m_panel_log, wxID_ANY, wxDefaultPosition, wxSize( 530,220 ), wxLC_HRULES|wxLC_REPORT|wxLC_VRULES );
	bSizer168->Add( m_listCtrl_log, 0, wxALL, 5 );
	
	m_panel_log->SetSizer( bSizer168 );
	m_panel_log->Layout();
	bSizer168->Fit( m_panel_log );
	m_notebook->AddPage( m_panel_log, _("Log"), false );
	
	bSizer57->Add( m_notebook, 1, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextStatus = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextStatus->Wrap( -1 );
	bSizer29->Add( m_staticTextStatus, 0, wxALIGN_CENTER|wxALL, 5 );
	
	bSizer28->Add( bSizer29, 1, wxALIGN_LEFT|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button_save = new wxButton( this, wxID_ANY, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button_save, 0, wxALL, 5 );
	
	m_button_close = new wxButton( this, wxID_ANY, _("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button_close, 0, wxALL, 5 );
	
	bSizer28->Add( bSizer26, 0, wxALIGN_RIGHT, 5 );
	
	bSizer57->Add( bSizer28, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizer57 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button_save->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ResourceDeployDialogBase::OnButtonSaveClick ), NULL, this );
	m_button_close->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ResourceDeployDialogBase::OnButtonCloseClick ), NULL, this );
}

ResourceDeployDialogBase::~ResourceDeployDialogBase()
{
	// Disconnect Events
	m_button_save->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ResourceDeployDialogBase::OnButtonSaveClick ), NULL, this );
	m_button_close->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ResourceDeployDialogBase::OnButtonCloseClick ), NULL, this );
	
}

ResourceFeeTypeDialogBase::ResourceFeeTypeDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer42;
	bSizer42 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText19 = new wxStaticText( this, wxID_ANY, _("Fee Type Name:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText19->Wrap( -1 );
	bSizer42->Add( m_staticText19, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl_feetype = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	bSizer42->Add( m_textCtrl_feetype, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer34->Add( bSizer42, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer171;
	bSizer171 = new wxBoxSizer( wxHORIZONTAL );
	
	m_checkBox_expire = new wxCheckBox( this, wxID_ANY, _("Have Expiration Date?"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer171->Add( m_checkBox_expire, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer34->Add( bSizer171, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextStatus = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextStatus->Wrap( -1 );
	bSizer29->Add( m_staticTextStatus, 0, wxALIGN_CENTER|wxALL, 5 );
	
	bSizer28->Add( bSizer29, 1, wxALIGN_LEFT|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button_save = new wxButton( this, wxID_ANY, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button_save, 0, wxALL, 5 );
	
	m_button_close = new wxButton( this, wxID_ANY, _("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button_close, 0, wxALL, 5 );
	
	bSizer28->Add( bSizer26, 0, wxALIGN_RIGHT, 5 );
	
	bSizer34->Add( bSizer28, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer34 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button_save->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ResourceFeeTypeDialogBase::OnButtonSaveClick ), NULL, this );
	m_button_close->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ResourceFeeTypeDialogBase::OnButtonCloseClick ), NULL, this );
}

ResourceFeeTypeDialogBase::~ResourceFeeTypeDialogBase()
{
	// Disconnect Events
	m_button_save->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ResourceFeeTypeDialogBase::OnButtonSaveClick ), NULL, this );
	m_button_close->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ResourceFeeTypeDialogBase::OnButtonCloseClick ), NULL, this );
	
}

ResourceFeeDialogBase::ResourceFeeDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer46;
	bSizer46 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer54;
	bSizer54 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText_resourcename = new wxStaticText( this, wxID_ANY, _("Fee Type:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText_resourcename->Wrap( -1 );
	bSizer54->Add( m_staticText_resourcename, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxArrayString m_choice_feetypeChoices;
	m_choice_feetype = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 150,-1 ), m_choice_feetypeChoices, 0 );
	m_choice_feetype->SetSelection( 0 );
	bSizer54->Add( m_choice_feetype, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizer54->Add( 0, 0, 0, wxLEFT, 160 );
	
	m_button_addfeetype = new wxButton( this, wxID_ANY, _("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer54->Add( m_button_addfeetype, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer46->Add( bSizer54, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer56;
	bSizer56 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText25 = new wxStaticText( this, wxID_ANY, _("Company:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText25->Wrap( -1 );
	bSizer56->Add( m_staticText25, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString m_choice_companytypeChoices[] = { _("All") };
	int m_choice_companytypeNChoices = sizeof( m_choice_companytypeChoices ) / sizeof( wxString );
	m_choice_companytype = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 150,-1 ), m_choice_companytypeNChoices, m_choice_companytypeChoices, 0 );
	m_choice_companytype->SetSelection( 0 );
	bSizer56->Add( m_choice_companytype, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxArrayString m_choice_companyChoices;
	m_choice_company = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 150,-1 ), m_choice_companyChoices, 0 );
	m_choice_company->SetSelection( 0 );
	bSizer56->Add( m_choice_company, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_button_addcompany = new wxButton( this, wxID_ANY, _("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer56->Add( m_button_addcompany, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer46->Add( bSizer56, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer55;
	bSizer55 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText24 = new wxStaticText( this, wxID_ANY, _("Serial Number:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText24->Wrap( -1 );
	bSizer55->Add( m_staticText24, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl_serial = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 150,-1 ), 0 );
	bSizer55->Add( m_textCtrl_serial, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer46->Add( bSizer55, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer105;
	bSizer105 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText55 = new wxStaticText( this, wxID_ANY, _("Price:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText55->Wrap( -1 );
	bSizer105->Add( m_staticText55, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl_price = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 150,-1 ), 0 );
	bSizer105->Add( m_textCtrl_price, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer46->Add( bSizer105, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer200;
	bSizer200 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText114 = new wxStaticText( this, wxID_ANY, _("Purchase Date:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText114->Wrap( -1 );
	bSizer200->Add( m_staticText114, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_datePicker1 = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxSize( 150,-1 ), wxDP_DROPDOWN );
	bSizer200->Add( m_datePicker1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText115 = new wxStaticText( this, wxID_ANY, _("Expiration Date:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText115->Wrap( -1 );
	bSizer200->Add( m_staticText115, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_datePicker2 = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxSize( 150,-1 ), wxDP_DROPDOWN );
	bSizer200->Add( m_datePicker2, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer46->Add( bSizer200, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextStatus = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextStatus->Wrap( -1 );
	bSizer29->Add( m_staticTextStatus, 0, wxALIGN_CENTER|wxALL, 5 );
	
	bSizer28->Add( bSizer29, 1, wxALIGN_LEFT|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button_save = new wxButton( this, wxID_ANY, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button_save, 0, wxALL, 5 );
	
	m_button_close = new wxButton( this, wxID_ANY, _("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button_close, 0, wxALL, 5 );
	
	bSizer28->Add( bSizer26, 0, wxALIGN_RIGHT, 5 );
	
	bSizer46->Add( bSizer28, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizer46 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button_save->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ResourceFeeDialogBase::OnButtonSaveClick ), NULL, this );
	m_button_close->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ResourceFeeDialogBase::OnButtonCloseClick ), NULL, this );
}

ResourceFeeDialogBase::~ResourceFeeDialogBase()
{
	// Disconnect Events
	m_button_save->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ResourceFeeDialogBase::OnButtonSaveClick ), NULL, this );
	m_button_close->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ResourceFeeDialogBase::OnButtonCloseClick ), NULL, this );
	
}
