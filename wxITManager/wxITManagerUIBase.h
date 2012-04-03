///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version May  4 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __wxITManagerUIBase__
#define __wxITManagerUIBase__

#include <wx/intl.h>

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/combobox.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/choice.h>
#include <wx/checkbox.h>
#include <wx/hyperlink.h>
#include <wx/panel.h>
#include <wx/statbox.h>
#include <wx/dialog.h>
#include <wx/statusbr.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>

///////////////////////////////////////////////////////////////////////////

#define wxID_BUTTON_LOGIN 1000
#define wxID_BUTTON_CONFIG 1001
#define wxID_BUTTON_TEST 1002
#define wxID_BUTTON_SAVE 1003
#define wxID_BUTTON_CANCEL 1004
#define wxID_MENUITEM_LOGOUT 1005
#define wxID_MENUITEM_EXIT 1006
#define wxID_MENUITEM_IMPORTDATA 1007
#define wxID_MENUITEM_EXPORTDATA 1008
#define wxID_MENUITEM_ABOUT 1009

///////////////////////////////////////////////////////////////////////////////
/// Class LoginFrameBase
///////////////////////////////////////////////////////////////////////////////
class LoginFrameBase : public wxFrame 
{
	private:
	
	protected:
		wxStaticText* m_staticText1;
		wxStaticText* m_staticText3;
		wxComboBox* m_comboBox_username;
		wxStaticText* m_staticText2;
		wxTextCtrl* m_textCtrl_password;
		wxStaticText* m_staticText_Status;
		wxButton* m_button_login;
		wxButton* m_button_config;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnButtonLoginClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonConfigClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		LoginFrameBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("wxITManager - Login"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 486,379 ), long style = wxCAPTION|wxCLOSE_BOX|wxSYSTEM_MENU|wxTAB_TRAVERSAL );
		~LoginFrameBase();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class DatabaseConfigDialogBase
///////////////////////////////////////////////////////////////////////////////
class DatabaseConfigDialogBase : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText4;
		wxChoice* m_choice_databasetype;
		wxPanel* m_panel1;
		wxPanel* m_panel_sqlite;
		wxStaticText* m_staticText6;
		wxTextCtrl* m_textCtrl_databasefile;
		wxButton* m_button_databasefile;
		wxCheckBox* m_checkBox_encrypteddatabase;
		wxStaticText* m_staticText13;
		wxTextCtrl* m_textCtrl_databasekey;
		wxStaticText* m_staticText111;
		wxHyperlinkCtrl* m_hyperlink_createdatabase;
		wxPanel* m_panel_mysql;
		wxStaticText* m_staticText8;
		wxTextCtrl* m_textCtrl4;
		wxStaticText* m_staticText9;
		wxTextCtrl* m_textCtrl5;
		wxStaticText* m_staticText10;
		wxTextCtrl* m_textCtrl6;
		wxStaticText* m_staticText11;
		wxTextCtrl* m_textCtrl7;
		wxStaticText* m_staticTextStatus;
		wxButton* m_button_test;
		wxButton* m_button_save;
		wxButton* m_button_cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnChoiceDatabaseType( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonSqliteBrowse( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCheckBoxEncryptedClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCreateDatabaseClick( wxHyperlinkEvent& event ) { event.Skip(); }
		virtual void OnButtonTestClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonSaveClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonCloseClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		DatabaseConfigDialogBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("wxITManager - Database Config"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 475,275 ), long style = wxDEFAULT_DIALOG_STYLE );
		~DatabaseConfigDialogBase();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class SqliteCreateDialogBase
///////////////////////////////////////////////////////////////////////////////
class SqliteCreateDialogBase : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText12;
		wxTextCtrl* m_textCtrl_databasefile;
		wxButton* m_button_browse;
		wxCheckBox* m_checkBox_encrypteddatabase;
		wxStaticText* m_staticText13;
		wxTextCtrl* m_textCtrl_databasekey;
		wxStaticText* m_staticTextStatus;
		wxButton* m_button_create;
		wxButton* m_button_close;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnButtonBrowseClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCheckBoxEncryptedClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonCreateClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonCloseClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		SqliteCreateDialogBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("wxITManager - Database Create"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 408,172 ), long style = wxDEFAULT_DIALOG_STYLE );
		~SqliteCreateDialogBase();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MainFrameBase
///////////////////////////////////////////////////////////////////////////////
class MainFrameBase : public wxFrame 
{
	private:
	
	protected:
		wxStatusBar* m_statusBar1;
		wxMenuBar* m_menubar;
		wxMenu* m_menu1;
		wxMenu* m_menu3;
		wxMenu* m_menu4;
		wxMenu* m_menu2;
		wxPanel* m_panel4;
		wxPanel* m_panel5;
		wxPanel* m_panel6;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnMainFrameClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnMenuLogoutSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuExitSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuImportdataSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuExportdataSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuAboutSelection( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MainFrameBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("wxITManager - Main"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 590,494 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~MainFrameBase();
	
};

#endif //__wxITManagerUIBase__
