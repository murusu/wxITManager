#ifndef WXITMANAGERMISC_H_INCLUDED
#define WXITMANAGERMISC_H_INCLUDED

#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1

#include "wxITManagerMain.h"

class MiscFunction
{
    public:
        static wxString MD5(wxString plain_text);
};

#endif // WXITMANAGERMISC_H_INCLUDED
