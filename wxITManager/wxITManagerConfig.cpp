#include "wxITManagerConfig.h"

ManagerConfig::ManagerConfig()
{
    m_databasetype  = DATABASE_SQLITE;
    m_databasefile  = wxT("");
    m_databasekey   = wxT("");
}

ManagerConfig::~ManagerConfig()
{
}

bool ManagerConfig::ReadConfigData()
{
    wxXmlDocument configdoc;

    if(!wxFileExists(wxString(CONFIGFILE_NAME, wxConvUTF8))) return true;
    if(!configdoc.Load(wxString(CONFIGFILE_NAME, wxConvUTF8))) return false;

    wxXmlNode *childnode = configdoc.GetRoot()->GetChildren();
    while (childnode)
    {
        if (childnode->GetName() == wxString(DATABASE_TYPE, wxConvUTF8))
        {
            m_databasetype = wxAtoi(childnode->GetPropVal(wxString(DATABASE_PROPERTY, wxConvUTF8), wxString::Format(wxT("%i"), DATABASE_SQLITE)));
        }

        if (childnode->GetName() == wxString(DATABASE_FILENAME, wxConvUTF8))
        {
            m_databasefile = childnode->GetPropVal(wxString(DATABASE_PROPERTY, wxConvUTF8), wxT(""));
        }

        if (childnode->GetName() == wxString(DATABASE_KEY, wxConvUTF8))
        {
            m_databasekey = childnode->GetPropVal(wxString(DATABASE_PROPERTY, wxConvUTF8), wxT(""));
        }

        childnode = childnode->GetNext();
    }

    return true;
}

bool ManagerConfig::WriteConfigData()
{
    wxXmlDocument configdoc;

    configdoc.SetFileEncoding(wxT("UTF-8"));
    configdoc.SetVersion(wxT("1.0"));

    wxXmlNode* root = new wxXmlNode(wxXML_ELEMENT_NODE, wxString(CONFIGFILE_ROOTNAME, wxConvUTF8));

    wxXmlNode* type = new wxXmlNode(NULL, wxXML_ELEMENT_NODE, wxString(DATABASE_TYPE, wxConvUTF8));
    type->AddProperty(wxString(DATABASE_PROPERTY, wxConvUTF8), wxString::Format(wxT("%i"),m_databasetype));

    wxXmlNode* file = new wxXmlNode(wxXML_ELEMENT_NODE, wxString(DATABASE_FILENAME, wxConvUTF8));
    file->AddProperty(wxString(DATABASE_PROPERTY, wxConvUTF8), m_databasefile);

    wxXmlNode* key = new wxXmlNode(wxXML_ELEMENT_NODE, wxString(DATABASE_KEY, wxConvUTF8));
    key->AddProperty(wxString(DATABASE_PROPERTY, wxConvUTF8), m_databasekey);

    root->AddChild(type);
    root->AddChild(file);
    root->AddChild(key);

    configdoc.SetRoot(root);

    if(!configdoc.Save(wxString(CONFIGFILE_NAME, wxConvUTF8))) return false;

    return true;
}
