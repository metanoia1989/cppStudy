#include <wx/wx.h>

class Veto : public wxFrame
{
public:
    Veto(const wxString& title);

    void OnClose(wxCloseEvent& event);
};

