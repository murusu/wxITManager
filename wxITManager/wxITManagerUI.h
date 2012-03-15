#ifndef WXITMANAGERUI_H_INCLUDED
#define WXITMANAGERUI_H_INCLUDED

#include "wxITManagerMain.h"
#include "wxITManagerUIBase.h"
//#include "wxITManagerConfig.h"
//#include "wxITManagerDatabase.h"
//#include "wxITManagerController.h"
//#include "wxITManagerEvent.h"

class DatabaseConfigDialog;
class SqliteCreateDialog;
//class Database;

class LoginFrame : public LoginFrameBase
{
    protected:
        DatabaseConfigDialog *m_configdialog;

	public:
		LoginFrame(wxFrame *frame);
		~LoginFrame();

		void OnButtonLoginClick( wxCommandEvent& event );
		void OnButtonConfigClick( wxCommandEvent& event );
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

		void OnDatabaseTest( wxDatabaseEvent& event);

        void LoadConfig();
        void EnableDialog(bool flag);
		void ClearContent();
};

class SqliteCreateDialog : public SqliteCreateDialogBase
{
    //private:
        //ManagerConfig   *m_config;
        //Database        *m_database;

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
};

#endif // WXITMANAGERUI_H_INCLUDED
