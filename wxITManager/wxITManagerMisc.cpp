#include "wxITManagerMisc.h"

wxString MiscFunction::MD5(wxString plain_text)
{
    wxString hash_text = plain_text;
    /*
    Weak::MD5 md5;
    unsigned char md5_data[16];
    size_t len =  plain_text.Len();
    unsigned char message[len + 2];
    strcpy((char*)message, pass_str.mb_str());
    md5.CalculateDigest(md5_data, message, len);
    wxString md5_str = wxString::Format(wxT("%02x"), md5_data);
    */

    return hash_text;
}
