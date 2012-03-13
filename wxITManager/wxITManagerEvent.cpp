#include "wxITManagerEvent.h"

wxDatabaseEvent::wxDatabaseEvent(wxEventType commandType, wxEvtHandler *sender, int id):wxNotifyEvent(commandType, id)
{
    m_sender = sender;
};
