#ifndef WXITMANAGERUI_H_INCLUDED
#define WXITMANAGERUI_H_INCLUDED

#include "wxITManagerMain.h"
#include "wxITManagerUIBase.h"

class DatabaseConfigDialog;
class SqliteCreateDialog;

class UserListCtrl : public wxListCtrl
{
    public:
        UserListCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style);

        void OnReflashList( wxDatabaseEvent& event);
        wxString OnGetItemText(long item, long column) const;
};

class UserGroupListCtrl : public wxListCtrl
{
    public:
        UserGroupListCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style);

        void OnReflashList( wxDatabaseEvent& event);
        wxString OnGetItemText(long item, long column) const;
};

class LoginFrame : public LoginFrameBase
{
    protected:
        DatabaseConfigDialog *m_configdialog;

	public:
		LoginFrame(wxFrame *frame);
		~LoginFrame();

		void OnButtonLoginClick( wxCommandEvent& event );
		void OnButtonConfigClick( wxCommandEvent& event );

        void OnLoginRespone(wxDatabaseEvent& event);
		void EnableFrame(bool flag);
};

class DatabaseConfigDialog : public DatabaseConfigDialogBase
{
    protected:
        SqliteCreateDialog  *m_sqlitedialog;

	public:
		DatabaseConfigDialog(wxFrame *frame);
		~DatabaseConfigDialog();

        void OnChoiceDatabaseType( wxCommandEvent& event );
		void OnButtonSqliteBrowse( wxCommandEvent& event );
		void OnCheckBoxEncryptedClick( wxCommandEvent& event );
		void OnCreateDatabaseClick( wxHyperlinkEvent& event );
		void OnButtonTestClick( wxCommandEvent& event );
		void OnButtonSaveClick( wxCommandEvent& event );
		void OnButtonCloseClick( wxCommandEvent& event );

		void OnDatabaseTest( wxDatabaseEvent& event );

        void LoadConfig();
        void EnableDialog(bool flag);
		void ClearContent();
};

class SqliteCreateDialog : public SqliteCreateDialogBase
{
	public:
		SqliteCreateDialog(wxDialog *dialog);
		~SqliteCreateDialog();

        void OnButtonBrowseClick( wxCommandEvent& event );
		void OnCheckBoxEncryptedClick( wxCommandEvent& event );
		void OnButtonCreateClick( wxCommandEvent& event );
		void OnButtonCloseClick( wxCommandEvent& event );

		void OnDatabaseUpdate( wxDatabaseEvent& event);

		void EnableDialog(bool flag);
		void ClearContent();
};

class MainFrame : public MainFrameBase
{
	public:
		MainFrame(wxFrame *frame);
		~MainFrame();

        void OnMainFrameClose( wxCloseEvent& event );
		void OnMenuLogoutSelection( wxCommandEvent& event );
		void OnMenuExitSelection( wxCommandEvent& event );
		void OnMenuSettingSelect( wxCommandEvent& event );

		void OnButtonSettingAdd( wxCommandEvent& event );
		void OnButtonSettingDelete( wxCommandEvent& event );
		void OnButtonSettingReflash( wxCommandEvent& event );

		void OnListSizeChange( wxSizeEvent& event );

		void DoListSize();
};

class UserDialog : public UserDialogBase
{
	public:
		UserDialog(wxWindow* parent):UserDialogBase(parent){};

		void OnButtonCloseClick( wxCommandEvent& event ){Close();};

		void OnButtonAddUserGroupClick( wxCommandEvent& event );
};

class UserGroupDialog : public UserGroupDialogBase
{
	public:
		UserGroupDialog(wxWindow* parent):UserGroupDialogBase(parent){};

		void OnButtonCloseClick( wxCommandEvent& event ){Close();};
};

#endif // WXITMANAGERUI_H_INCLUDED
