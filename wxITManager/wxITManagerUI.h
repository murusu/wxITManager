#ifndef WXITMANAGERUI_H_INCLUDED
#define WXITMANAGERUI_H_INCLUDED

#include "wxITManagerMain.h"

class DatabaseConfigDialog;
class SqliteCreateDialog;

//////////////////////////////////////////////////////////////////////////////////////

class LoginFrame : public LoginFrameBase
{
    protected:
        DatabaseConfigDialog *m_configdialog;

	public:
		LoginFrame(wxFrame *frame);
		~LoginFrame();

		void OnLogin( wxCommandEvent& event );
		void OnConfig( wxCommandEvent& event );

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
		void OnMenuDeploySelect( wxCommandEvent& event );

		void OnChoiceDeploySearchType( wxCommandEvent& event );
        void OnButtonDeploySearch( wxCommandEvent& event );
		void OnButtonDeployAdd( wxCommandEvent& event );
		void OnButtonDeployDelete( wxCommandEvent& event );

		void OnButtonSettingAdd( wxCommandEvent& event );
		void OnButtonSettingDelete( wxCommandEvent& event );
		void OnButtonSettingRefresh( wxCommandEvent& event );

        void OnSettingItemActivated( wxListEvent& event );

		void OnListSizeChange( wxSizeEvent& event );

		void DoListSize();

		inline UserListCtrl* GetUserListctrl(){return m_listCtrl_user;};
		inline UserGroupListCtrl* GetUserGroupListctrl(){return m_listCtrl_usergroup;};

		inline VcardListCtrl* GetVcardListctrl(){return m_listCtrl_vcard;};
		inline VcardGroupListCtrl* GetVcardGroupListctrl(){return m_listCtrl_vcardgroup;};
		inline CompanyListCtrl* GetCompanyListctrl(){return m_listCtrl_company;};
		inline CompanyTypeListCtrl* GetCompanyTypeListctrl(){return m_listCtrl_companytype;};
		inline LocationListCtrl* GetLocationListctrl(){return m_listCtrl_location;};

		inline ResourceListCtrl* GetResourceListctrl(){return m_listCtrl_resource;};
		inline ResourceTypeListCtrl* GetResourceTypeListctrl(){return m_listCtrl_resourcetype;};
		inline ResourceStatusListCtrl* GetResourceStatusListctrl(){return m_listCtrl_resourcestatus;};
		inline ResourceFeeTypeListCtrl* GetResourceFeeTypeListctrl(){return m_listCtrl_resourcefeetype;};

		inline ResourceDeployListCtrl* GetResourceDeployListctrl(){return m_listCtrl_resourcedeploy;};
};

class UserDialog : public UserDialogBase
{
    private:
        size_t          m_id;

	public:
		UserDialog(wxWindow* parent, size_t id = NULL_ID);

		void EnableDialog(bool flag);

		void OnButtonCloseClick( wxCommandEvent& event ){Close();};
		void OnButtonSaveClick( wxCommandEvent& event );
		void OnButtonAddUserGroupClick( wxCommandEvent& event );

		void RefreshUserGroupChoice();

		void OnUserInfoUpdate( wxDatabaseEvent& event);
};

class UserGroupDialog : public UserGroupDialogBase
{
    private:
        size_t          m_id;

	public:
		UserGroupDialog(wxWindow* parent, size_t id = NULL_ID);

		void EnableDialog(bool flag);

		void OnButtonCloseClick( wxCommandEvent& event ){Close();};
		void OnButtonSaveClick( wxCommandEvent& event );

		void OnUserGroupInfoUpdate( wxDatabaseEvent& event);
};

class VcardDialog : public VcardDialogBase
{
    private:
        size_t          m_id;

	public:
		VcardDialog(wxWindow* parent, size_t id = NULL_ID);

		void EnableDialog(bool flag);

		void OnButtonCloseClick( wxCommandEvent& event ){Close();};
		void OnButtonSaveClick( wxCommandEvent& event );

		void OnVcardInfoUpdate( wxDatabaseEvent& event);
};

class VcardGroupDialog : public VcardGroupDialogBase
{
    private:
        size_t          m_id;

	public:
		VcardGroupDialog(wxWindow* parent, size_t id = NULL_ID);

		void EnableDialog(bool flag);

		void OnButtonCloseClick( wxCommandEvent& event ){Close();};
		void OnButtonSaveClick( wxCommandEvent& event );

		void OnVcardGroupInfoUpdate( wxDatabaseEvent& event);
};

class CompanyDialog : public CompanyDialogBase
{
    private:
        size_t          m_id;

	public:
		CompanyDialog(wxWindow* parent, size_t id = NULL_ID);

		void EnableDialog(bool flag);

		void OnButtonCloseClick( wxCommandEvent& event ){Close();};
		void OnButtonSaveClick( wxCommandEvent& event );
		void OnButtonAddCompanyTypeClick( wxCommandEvent& event );

		void RefreshCompanyTypeChoice();

		void OnCompanyInfoUpdate( wxDatabaseEvent& event);
};

class CompanyTypeDialog : public CompanyTypeDialogBase
{
    private:
        size_t          m_id;

	public:
		CompanyTypeDialog(wxWindow* parent, size_t id = NULL_ID);

		void EnableDialog(bool flag);

		void OnButtonCloseClick( wxCommandEvent& event ){Close();};
		void OnButtonSaveClick( wxCommandEvent& event );

		void OnCompanyTypeInfoUpdate( wxDatabaseEvent& event);
};

class LocationDialog : public LocationDialogBase
{
    private:
        size_t          m_id;

	public:
		LocationDialog(wxWindow* parent, size_t id = NULL_ID);

		void EnableDialog(bool flag);

		void OnButtonCloseClick( wxCommandEvent& event ){Close();};
		void OnButtonSaveClick( wxCommandEvent& event );

		void OnLocationInfoUpdate( wxDatabaseEvent& event);
};

class ResourceDialog : public ResourceDialogBase
{
    private:
        size_t          m_id;

	public:
		ResourceDialog(wxWindow* parent, size_t id = NULL_ID);

		void EnableDialog(bool flag);

		void OnButtonCloseClick( wxCommandEvent& event ){Close();};
		void OnButtonSaveClick( wxCommandEvent& event );
		void OnButtonAddResourceTypeClick( wxCommandEvent& event );

		void RefreshResourceTypeChoice();

		void OnResourceInfoUpdate( wxDatabaseEvent& event);
};

class ResourceTypeDialog : public ResourceTypeDialogBase
{
    private:
        size_t          m_id;

	public:
		ResourceTypeDialog(wxWindow* parent, size_t id = NULL_ID);

		void EnableDialog(bool flag);

		void OnButtonCloseClick( wxCommandEvent& event ){Close();};
		void OnButtonSaveClick( wxCommandEvent& event );

		void OnResourceTypeInfoUpdate( wxDatabaseEvent& event);
};

class ResourceStatusDialog : public ResourceStatusDialogBase
{
    private:
        size_t          m_id;

	public:
		ResourceStatusDialog(wxWindow* parent, size_t id = NULL_ID);

		void EnableDialog(bool flag);

		void OnButtonCloseClick( wxCommandEvent& event ){Close();};
		void OnButtonSaveClick( wxCommandEvent& event );

		void OnResourceStatusInfoUpdate( wxDatabaseEvent& event);
};

class ResourceFeeTypeDialog : public ResourceFeeTypeDialogBase
{
    private:
        size_t          m_id;

	public:
		ResourceFeeTypeDialog(wxWindow* parent, size_t id = NULL_ID);

		void EnableDialog(bool flag);

		void OnButtonCloseClick( wxCommandEvent& event ){Close();};
		void OnButtonSaveClick( wxCommandEvent& event );

		void OnResourceFeeTypeInfoUpdate( wxDatabaseEvent& event);
};

class ResourceDeployDialog : public ResourceDeployDialogBase
{
    private:
        size_t          m_id;

	public:
		ResourceDeployDialog(wxWindow* parent, size_t id = NULL_ID);

		void EnableDialog(bool flag);

		void OnButtonCloseClick( wxCommandEvent& event ){Close();};
		void OnButtonSaveClick( wxCommandEvent& event );

		void OnResourceDeployInfoUpdate( wxDatabaseEvent& event);
};

#endif // WXITMANAGERUI_H_INCLUDED
