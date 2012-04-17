#ifndef WXITMANAGERUIEXTEND_H_INCLUDED
#define WXITMANAGERUIEXTEND_H_INCLUDED

#include "wxITManagerMain.h"

class UserListCtrl : public wxListCtrl
{
    public:
        UserListCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style);

        void OnListChange( wxDatabaseEvent& event);
        void OnRefreshList( wxDatabaseEvent& event);
        void RefreshList();
        wxString OnGetItemText(long item, long column) const;
};

class UserGroupListCtrl : public wxListCtrl
{
    public:
        UserGroupListCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style);

        void OnListChange( wxDatabaseEvent& event);
        void OnRefreshList( wxDatabaseEvent& event);
        void RefreshList();
        wxString OnGetItemText(long item, long column) const;
};

class VcardListCtrl : public wxListCtrl
{
    public:
        VcardListCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style);

        void OnListChange( wxDatabaseEvent& event);
        void OnRefreshList( wxDatabaseEvent& event);
        void RefreshList();
        wxString OnGetItemText(long item, long column) const;
};

class VcardGroupListCtrl : public wxListCtrl
{
    public:
        VcardGroupListCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style);

        void OnListChange( wxDatabaseEvent& event);
        void OnRefreshList( wxDatabaseEvent& event);
        void RefreshList();
        wxString OnGetItemText(long item, long column) const;
};

class CompanyListCtrl : public wxListCtrl
{
    public:
        CompanyListCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style);

        void OnListChange( wxDatabaseEvent& event);
        void OnRefreshList( wxDatabaseEvent& event);
        void RefreshList();
        wxString OnGetItemText(long item, long column) const;
};

class CompanyTypeListCtrl : public wxListCtrl
{
    public:
        CompanyTypeListCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style);

        void OnListChange( wxDatabaseEvent& event);
        void OnRefreshList( wxDatabaseEvent& event);
        void RefreshList();
        wxString OnGetItemText(long item, long column) const;
};

class LocationListCtrl : public wxListCtrl
{
    public:
        LocationListCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style);

        void OnListChange( wxDatabaseEvent& event);
        void OnRefreshList( wxDatabaseEvent& event);
        void RefreshList();
        wxString OnGetItemText(long item, long column) const;
};

class ResourceListCtrl : public wxListCtrl
{
    public:
        ResourceListCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style);

        void OnListChange( wxDatabaseEvent& event);
        void OnRefreshList( wxDatabaseEvent& event);
        void RefreshList();
        wxString OnGetItemText(long item, long column) const;
};

class ResourceTypeListCtrl : public wxListCtrl
{
    public:
        ResourceTypeListCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style);

        void OnListChange( wxDatabaseEvent& event);
        void OnRefreshList( wxDatabaseEvent& event);
        void RefreshList();
        wxString OnGetItemText(long item, long column) const;
};

class ResourceStatusListCtrl : public wxListCtrl
{
    public:
        ResourceStatusListCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style);

        void OnListChange( wxDatabaseEvent& event);
        void OnRefreshList( wxDatabaseEvent& event);
        void RefreshList();
        wxString OnGetItemText(long item, long column) const;
};

class ResourceFeeTypeListCtrl : public wxListCtrl
{
    public:
        ResourceFeeTypeListCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style);

        void OnListChange( wxDatabaseEvent& event);
        void OnRefreshList( wxDatabaseEvent& event);
        void RefreshList();
        wxString OnGetItemText(long item, long column) const;
};

#endif // WXITMANAGERUIEXTEND_H_INCLUDED
