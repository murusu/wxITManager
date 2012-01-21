///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version May  4 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

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
	
	m_comboBox1 = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 150,-1 ), 0, NULL, 0 ); 
	bSizer4->Add( m_comboBox1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer3->Add( bSizer4, 1, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, _("Password:"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_staticText2->Wrap( -1 );
	bSizer5->Add( m_staticText2, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 150,-1 ), wxTE_PASSWORD );
	bSizer5->Add( m_textCtrl1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer3->Add( bSizer5, 1, wxALIGN_CENTER_HORIZONTAL, 5 );
	
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
	
	m_button6 = new wxButton( m_panel_sqlite, wxID_ANY, _("Browse"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_button6, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer12->Add( bSizer13, 0, wxALIGN_LEFT, 5 );
	
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText13 = new wxStaticText( m_panel_sqlite, wxID_ANY, _("Database Key:"), wxDefaultPosition, wxSize( 115,-1 ), 0 );
	m_staticText13->Wrap( -1 );
	bSizer14->Add( m_staticText13, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl_databasekey = new wxTextCtrl( m_panel_sqlite, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 180,-1 ), wxTE_PASSWORD );
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
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button_test = new wxButton( this, wxID_BUTTON_TEST, _("Test Connection"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_button_test, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_button_save = new wxButton( this, wxID_BUTTON_SAVE, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_button_save, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_button_cancel = new wxButton( this, wxID_BUTTON_CANCEL, _("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_button_cancel, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer7->Add( bSizer10, 0, wxALIGN_RIGHT, 5 );
	
	this->SetSizer( bSizer7 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_choice_databasetype->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( DatabaseConfigDialogBase::OnChoiceDatabaseType ), NULL, this );
	m_button6->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DatabaseConfigDialogBase::OnButtonSqliteBrowse ), NULL, this );
	m_hyperlink_createdatabase->Connect( wxEVT_COMMAND_HYPERLINK, wxHyperlinkEventHandler( DatabaseConfigDialogBase::OnCreateDatabaseClick ), NULL, this );
	m_button_test->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DatabaseConfigDialogBase::OnButtonTestClick ), NULL, this );
	m_button_save->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DatabaseConfigDialogBase::OnButtonSaveClick ), NULL, this );
	m_button_cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DatabaseConfigDialogBase::OnButtonCloseClick ), NULL, this );
}

DatabaseConfigDialogBase::~DatabaseConfigDialogBase()
{
	// Disconnect Events
	m_choice_databasetype->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( DatabaseConfigDialogBase::OnChoiceDatabaseType ), NULL, this );
	m_button6->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DatabaseConfigDialogBase::OnButtonSqliteBrowse ), NULL, this );
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
	bSizer28 = new wxBoxSizer( wxVERTICAL );
	
	m_gauge_create = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxSize( 390,10 ), wxGA_HORIZONTAL );
	bSizer28->Add( m_gauge_create, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer23->Add( bSizer28, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button_create = new wxButton( this, wxID_ANY, _("Create"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button_create, 0, wxALL, 5 );
	
	m_button_close = new wxButton( this, wxID_ANY, _("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button_close, 0, wxALL, 5 );
	
	bSizer23->Add( bSizer26, 0, wxALIGN_RIGHT, 5 );
	
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
	
	m_statusBar1 = this->CreateStatusBar( 2, wxST_SIZEGRIP, wxID_ANY );
	m_menubar = new wxMenuBar( 0 );
	m_menu1 = new wxMenu();
	wxMenuItem* m_menuItem_logout;
	m_menuItem_logout = new wxMenuItem( m_menu1, wxID_MENUITEM_LOGOUT, wxString( _("Logout") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem_logout );
	
	wxMenuItem* m_menuItem_exit;
	m_menuItem_exit = new wxMenuItem( m_menu1, wxID_MENUITEM_EXIT, wxString( _("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem_exit );
	
	m_menubar->Append( m_menu1, _("System") ); 
	
	m_menu3 = new wxMenu();
	wxMenuItem* m_menuItem4;
	m_menuItem4 = new wxMenuItem( m_menu3, wxID_ANY, wxString( _("User") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem4 );
	
	wxMenuItem* m_menuItem5;
	m_menuItem5 = new wxMenuItem( m_menu3, wxID_ANY, wxString( _("Brand") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem5 );
	
	wxMenuItem* m_menuItem6;
	m_menuItem6 = new wxMenuItem( m_menu3, wxID_ANY, wxString( _("Suppliers") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem6 );
	
	wxMenuItem* m_menuItem11;
	m_menuItem11 = new wxMenuItem( m_menu3, wxID_ANY, wxString( _("Maintenance Company") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem11 );
	
	wxMenuItem* m_separator1;
	m_separator1 = m_menu3->AppendSeparator();
	
	wxMenuItem* m_menuItem7;
	m_menuItem7 = new wxMenuItem( m_menu3, wxID_ANY, wxString( _("Hardware Type") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem7 );
	
	wxMenuItem* m_menuItem8;
	m_menuItem8 = new wxMenuItem( m_menu3, wxID_ANY, wxString( _("Hardware") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem8 );
	
	wxMenuItem* m_separator2;
	m_separator2 = m_menu3->AppendSeparator();
	
	wxMenuItem* m_menuItem9;
	m_menuItem9 = new wxMenuItem( m_menu3, wxID_ANY, wxString( _("Software Type") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem9 );
	
	wxMenuItem* m_menuItem10;
	m_menuItem10 = new wxMenuItem( m_menu3, wxID_ANY, wxString( _("Software") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem10 );
	
	m_menubar->Append( m_menu3, _("Settings") ); 
	
	m_menu2 = new wxMenu();
	wxMenuItem* m_menuItem3;
	m_menuItem3 = new wxMenuItem( m_menu2, wxID_ANY, wxString( _("About wxITManagement") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItem3 );
	
	m_menubar->Append( m_menu2, _("Help") ); 
	
	this->SetMenuBar( m_menubar );
	
	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxVERTICAL );
	
	m_panel4 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxVERTICAL );
	
	m_panel5 = new wxPanel( m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	bSizer21->Add( m_panel5, 1, wxEXPAND | wxALL, 0 );
	
	m_panel6 = new wxPanel( m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel6->Hide();
	
	bSizer21->Add( m_panel6, 1, wxEXPAND | wxALL, 0 );
	
	m_panel4->SetSizer( bSizer21 );
	m_panel4->Layout();
	bSizer21->Fit( m_panel4 );
	bSizer20->Add( m_panel4, 1, wxEXPAND | wxALL, 0 );
	
	this->SetSizer( bSizer20 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrameBase::OnMainFrameClose ) );
	this->Connect( wxID_MENUITEM_LOGOUT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuLogoutSelection ) );
	this->Connect( wxID_MENUITEM_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuExitSelection ) );
}

MainFrameBase::~MainFrameBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrameBase::OnMainFrameClose ) );
	this->Disconnect( wxID_MENUITEM_LOGOUT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuLogoutSelection ) );
	this->Disconnect( wxID_MENUITEM_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuExitSelection ) );
	
}
