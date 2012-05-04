///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version May  4 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __wxITManagerUIBase__
#define __wxITManagerUIBase__

#include <wx/intl.h>

class CompanyListCtrl;
class CompanyTypeListCtrl;
class LocationListCtrl;
class ResourceDeployListCtrl;
class ResourceFeeTypeListCtrl;
class ResourceListCtrl;
class ResourceStatusListCtrl;
class ResourceTypeListCtrl;
class UserGroupListCtrl;
class UserListCtrl;
class VcardGroupListCtrl;
class VcardListCtrl;

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
#include <wx/statline.h>
#include <wx/listctrl.h>
#include <wx/notebook.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>

///////////////////////////////////////////////////////////////////////////

#define wxID_BUTTON_LOGIN 1000
#define wxID_BUTTON_CONFIG 1001
#define wxID_BUTTON_TEST 1002
#define wxID_BUTTON_SAVE 1003
#define wxID_BUTTON_CANCEL 1004
#define wxID_MENUITEM_LOGOUT 1005
#define wxID_MENUITEM_EXIT 1006
#define wxID_MENUITEM_DEPLOYMANAGEMENT 1007
#define wxID_MENUITEM_USER 1008
#define wxID_MENUITEM_USERGROUP 1009
#define wxID_MENUITEM_VCARD 1010
#define wxID_MENUITEM_VCARDGROUP 1011
#define wxID_MENUITEM_COMPANY 1012
#define wxID_MENUITEM_COMPANYTYPE 1013
#define wxID_MENUITEM_LOCATION 1014
#define wxID_MENUITEM_RESOURCE 1015
#define wxID_MENUITEM_RESOURCETYPE 1016
#define wxID_MENUITEM_RESOURCESTATUS 1017
#define wxID_MENUITEM_RESOURCEFEETYPE 1018
#define wxID_MENUITEM_IMPORTDATA 1019
#define wxID_MENUITEM_EXPORTDATA 1020
#define wxID_MENUITEM_ABOUT 1021

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
		virtual void OnLogin( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnConfig( wxCommandEvent& event ) { event.Skip(); }
		
	
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
		wxStatusBar* m_statusBar;
		wxMenuBar* m_menubar;
		wxMenu* m_menu1;
		wxMenu* m_menu6;
		wxMenu* m_menu3;
		wxMenu* m_menu7;
		wxMenu* m_menu4;
		wxMenu* m_menu2;
		wxPanel* m_panel_deploy;
		wxPanel* m_panel_deploymanagementbutton;
		wxChoice* m_choice_serachtype;
		wxChoice* m_choice_serachparam;
		wxTextCtrl* m_textCtrl_searchparam;
		wxButton* m_button_deploysearch;
		wxStaticLine* m_staticline1;
		wxButton* m_button_deployadd;
		wxButton* m_button_deploydelete;
		wxPanel* m_panel_deploylist;
		wxPanel* m_panel_resourcedeploymanagement;
		ResourceDeployListCtrl* m_listCtrl_resourcedeploy;
		wxPanel* m_panel_setting;
		wxPanel* m_panel_settingbutton;
		wxButton* m_button_settingadd;
		wxButton* m_button_settingdelete;
		wxButton* m_button_settingrefresh;
		wxPanel* m_panel_settinglist;
		wxPanel* m_panel_user;
		UserListCtrl* m_listCtrl_user;
		wxPanel* m_panel_usergroup;
		UserGroupListCtrl* m_listCtrl_usergroup;
		wxPanel* m_panel_vcard;
		VcardListCtrl* m_listCtrl_vcard;
		wxPanel* m_panel_vcardgroup;
		VcardGroupListCtrl* m_listCtrl_vcardgroup;
		wxPanel* m_panel_company;
		CompanyListCtrl* m_listCtrl_company;
		wxPanel* m_panel_companytype;
		CompanyTypeListCtrl* m_listCtrl_companytype;
		wxPanel* m_panel_location;
		LocationListCtrl* m_listCtrl_location;
		wxPanel* m_panel_resource;
		ResourceListCtrl* m_listCtrl_resource;
		wxPanel* m_panel_resourcetype;
		ResourceTypeListCtrl* m_listCtrl_resourcetype;
		wxPanel* m_panel_resourcestatus;
		ResourceStatusListCtrl* m_listCtrl_resourcestatus;
		wxPanel* m_panel_resourcefeetype;
		ResourceFeeTypeListCtrl* m_listCtrl_resourcefeetype;
		wxPanel* m_panel_report;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnMainFrameClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnMenuLogoutSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuExitSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuDeploySelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuSettingSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuImportdataSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuExportdataSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuAboutSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnChoiceDeploySearchType( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonDeploySearch( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonDeployAdd( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonDeployDelete( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDeployItemActivated( wxListEvent& event ) { event.Skip(); }
		virtual void OnListSizeChange( wxSizeEvent& event ) { event.Skip(); }
		virtual void OnButtonSettingAdd( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonSettingDelete( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonSettingRefresh( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnListKeyDown( wxKeyEvent& event ) { event.Skip(); }
		virtual void SortUserList( wxListEvent& event ) { event.Skip(); }
		virtual void ShowPopupMenu( wxListEvent& event ) { event.Skip(); }
		virtual void OnSettingItemActivated( wxListEvent& event ) { event.Skip(); }
		virtual void SortUserGroupList( wxListEvent& event ) { event.Skip(); }
		
	
	public:
		
		MainFrameBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("wxITManager - Main"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 750,550 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~MainFrameBase();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class UserGroupDialogBase
///////////////////////////////////////////////////////////////////////////////
class UserGroupDialogBase : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText19;
		wxTextCtrl* m_textCtrl_groupname;
		wxStaticText* m_staticTextStatus;
		wxButton* m_button_save;
		wxButton* m_button_close;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnButtonSaveClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonCloseClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		UserGroupDialogBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("wxITManager - User Group"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 415,110 ), long style = wxDEFAULT_DIALOG_STYLE );
		~UserGroupDialogBase();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class UserDialogBase
///////////////////////////////////////////////////////////////////////////////
class UserDialogBase : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText23;
		wxTextCtrl* m_textCtrl_username;
		wxStaticText* m_staticText24;
		wxTextCtrl* m_textCtrl_userpassword;
		wxStaticText* m_staticText25;
		wxChoice* m_choice_usergroup;
		wxButton* m_button_addusergroup;
		wxStaticText* m_staticTextStatus;
		wxButton* m_button_save;
		wxButton* m_button_close;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnButtonAddUserGroupClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonSaveClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonCloseClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		UserDialogBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("wxITManager - User"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 415,160 ), long style = wxDEFAULT_DIALOG_STYLE );
		~UserDialogBase();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class VcardDialogBase
///////////////////////////////////////////////////////////////////////////////
class VcardDialogBase : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText28;
		wxTextCtrl* m_textCtrl_fullname;
		wxStaticText* m_staticText29;
		wxTextCtrl* m_textCtrl_nickname;
		wxStaticText* m_staticText30;
		wxTextCtrl* m_textCtrl_workphone;
		wxStaticText* m_staticText31;
		wxTextCtrl* m_textCtrl_mobiephone;
		wxStaticText* m_staticText33;
		wxTextCtrl* m_textCtrl_email;
		wxStaticText* m_staticText32;
		wxTextCtrl* m_textCtrl_title;
		wxStaticText* m_staticText34;
		wxTextCtrl* m_textCtrl_company;
		wxStaticText* m_staticTextStatus;
		wxButton* m_button_save;
		wxButton* m_button_close;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnButtonSaveClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonCloseClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		VcardDialogBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("wxITManager - Vcard"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 415,300 ), long style = wxDEFAULT_DIALOG_STYLE );
		~VcardDialogBase();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class VcardGroupDialogBase
///////////////////////////////////////////////////////////////////////////////
class VcardGroupDialogBase : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText19;
		wxTextCtrl* m_textCtrl_groupname;
		wxStaticText* m_staticTextStatus;
		wxButton* m_button_save;
		wxButton* m_button_close;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnButtonSaveClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonCloseClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		VcardGroupDialogBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("wxITManager - Vcard Group"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 415,110 ), long style = wxDEFAULT_DIALOG_STYLE );
		~VcardGroupDialogBase();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CompanyDialogBase
///////////////////////////////////////////////////////////////////////////////
class CompanyDialogBase : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText23;
		wxTextCtrl* m_textCtrl_companyname;
		wxStaticText* m_staticText25;
		wxChoice* m_choice_companytype;
		wxButton* m_button_addcompanytype;
		wxStaticText* m_staticTextStatus;
		wxButton* m_button_save;
		wxButton* m_button_close;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnButtonAddCompanyTypeClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonSaveClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonCloseClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		CompanyDialogBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("wxITManager - Company"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 415,143 ), long style = wxDEFAULT_DIALOG_STYLE );
		~CompanyDialogBase();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CompanyTypeDialogBase
///////////////////////////////////////////////////////////////////////////////
class CompanyTypeDialogBase : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText19;
		wxTextCtrl* m_textCtrl_companytype;
		wxStaticText* m_staticTextStatus;
		wxButton* m_button_save;
		wxButton* m_button_close;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnButtonSaveClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonCloseClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		CompanyTypeDialogBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("wxITManager - Company Type"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 415,110 ), long style = wxDEFAULT_DIALOG_STYLE );
		~CompanyTypeDialogBase();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class LocationDialogBase
///////////////////////////////////////////////////////////////////////////////
class LocationDialogBase : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText19;
		wxTextCtrl* m_textCtrl_location;
		wxStaticText* m_staticTextStatus;
		wxButton* m_button_save;
		wxButton* m_button_close;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnButtonSaveClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonCloseClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		LocationDialogBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("wxITManager - Location"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 415,110 ), long style = wxDEFAULT_DIALOG_STYLE );
		~LocationDialogBase();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ResourceDialogBase
///////////////////////////////////////////////////////////////////////////////
class ResourceDialogBase : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText_resourcename;
		wxTextCtrl* m_textCtrl_resourcename;
		wxStaticText* m_staticText25;
		wxChoice* m_choice_resourcetype;
		wxButton* m_button_addresourcetype;
		wxStaticText* m_staticText24;
		wxTextCtrl* m_textCtrl_pattern;
		wxStaticText* m_staticText55;
		wxTextCtrl* m_textCtrl_weight;
		wxStaticText* m_staticTextStatus;
		wxButton* m_button_save;
		wxButton* m_button_close;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnButtonAddResourceTypeClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonSaveClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonCloseClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		ResourceDialogBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("wxITManager - Resource"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 415,190 ), long style = wxDEFAULT_DIALOG_STYLE );
		~ResourceDialogBase();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ResourceTypeDialogBase
///////////////////////////////////////////////////////////////////////////////
class ResourceTypeDialogBase : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText23;
		wxTextCtrl* m_textCtrl_typename;
		wxStaticText* m_staticTextStatus;
		wxButton* m_button_save;
		wxButton* m_button_close;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnButtonSaveClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonCloseClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		ResourceTypeDialogBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("wxITManager - Resource Type"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 415,110 ), long style = wxDEFAULT_DIALOG_STYLE );
		~ResourceTypeDialogBase();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ResourceStatusDialogBase
///////////////////////////////////////////////////////////////////////////////
class ResourceStatusDialogBase : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText19;
		wxTextCtrl* m_textCtrl_resourcestatus;
		wxCheckBox* m_checkBox_available;
		wxStaticText* m_staticTextStatus;
		wxButton* m_button_save;
		wxButton* m_button_close;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnButtonSaveClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonCloseClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		ResourceStatusDialogBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("wxITManager - Resource Status"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 415,125 ), long style = wxDEFAULT_DIALOG_STYLE );
		~ResourceStatusDialogBase();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ResourceDeployDialogBase
///////////////////////////////////////////////////////////////////////////////
class ResourceDeployDialogBase : public wxDialog 
{
	private:
	
	protected:
		wxNotebook* m_notebook;
		wxPanel* m_panel_base;
		
		wxStaticText* m_staticText66;
		wxStaticText* m_staticText_systemcode;
		wxStaticText* m_staticText28;
		wxTextCtrl* m_textCtrl_code;
		
		wxStaticText* m_staticText83;
		wxChoice* m_choice_resourcestatus;
		wxButton* m_button_addresourcestatus;
		wxStaticText* m_staticText29;
		wxChoice* m_choice_resourcetype;
		wxButton* m_button_addresourcetype;
		wxStaticText* m_staticText82;
		wxChoice* m_choice_resourcename;
		wxButton* m_button_addresource;
		wxStaticText* m_staticText30;
		wxChoice* m_choice_location;
		wxButton* m_button_addlocation;
		wxStaticText* m_staticText85;
		wxChoice* m_choice_owner;
		wxButton* m_button_addvcard;
		wxStaticText* m_staticText98;
		wxTextCtrl* m_textCtrl_remark;
		wxPanel* m_panel_sub;
		wxButton* m_button_addnewsub;
		wxButton* m_button_addexitsub;
		wxButton* m_button_deletesub;
		wxListCtrl* m_listCtrl_sub;
		wxPanel* m_panel_fee;
		wxButton* m_button_addfee;
		wxButton* m_button_deletefee;
		wxListCtrl* m_listCtrl_fee;
		wxPanel* m_panel_log;
		wxListCtrl* m_listCtrl_log;
		wxStaticText* m_staticTextStatus;
		wxButton* m_button_save;
		wxButton* m_button_close;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnButtonAddResourceStatusClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonAddResourceTypeClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonAddResourceClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonAddLocationClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonAddVcardClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonSaveClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonCloseClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		ResourceDeployDialogBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("wxITManager - Resource Deploy"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 738,360 ), long style = wxDEFAULT_DIALOG_STYLE );
		~ResourceDeployDialogBase();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ResourceFeeTypeDialogBase
///////////////////////////////////////////////////////////////////////////////
class ResourceFeeTypeDialogBase : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText19;
		wxTextCtrl* m_textCtrl_feetype;
		wxCheckBox* m_checkBox_expire;
		wxStaticText* m_staticTextStatus;
		wxButton* m_button_save;
		wxButton* m_button_close;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnButtonSaveClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonCloseClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		ResourceFeeTypeDialogBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("wxITManager - Resource Fee Type"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 415,125 ), long style = wxDEFAULT_DIALOG_STYLE );
		~ResourceFeeTypeDialogBase();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ResourceFeeDialogBase
///////////////////////////////////////////////////////////////////////////////
class ResourceFeeDialogBase : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText_resourcename;
		wxChoice* m_choice_feetype;
		
		wxButton* m_button_addfeetype;
		wxStaticText* m_staticText25;
		wxChoice* m_choice_companytype;
		wxChoice* m_choice_company;
		wxButton* m_button_addcompany;
		wxStaticText* m_staticText24;
		wxTextCtrl* m_textCtrl_serial;
		wxStaticText* m_staticText55;
		wxTextCtrl* m_textCtrl_price;
		wxStaticText* m_staticText114;
		wxDatePickerCtrl* m_datePicker1;
		wxStaticText* m_staticText115;
		wxDatePickerCtrl* m_datePicker2;
		wxStaticText* m_staticTextStatus;
		wxButton* m_button_save;
		wxButton* m_button_close;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnButtonSaveClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonCloseClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		ResourceFeeDialogBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("wxITManager - Resource Fee"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 534,220 ), long style = wxDEFAULT_DIALOG_STYLE );
		~ResourceFeeDialogBase();
	
};

#endif //__wxITManagerUIBase__
