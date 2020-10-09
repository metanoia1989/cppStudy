#include <wx/wx.h>

class ChangeFont : public wxFrame
{
public:
    ChangeFont(const wxString& title);
    
    void OnOpen(wxCommandEvent& event);
    
    wxStaticText *st;
};
