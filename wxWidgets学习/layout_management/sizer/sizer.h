#include <wx/wx.h>
#include <wx/menu.h>

class Sizer : public wxFrame
{
public:
    Sizer(const wxString& title);
    
    wxMenuBar *menuBar;
    wxMenu *file;
    wxMenu *edit;
    wxMenu *help;
    wxTextCtrl *textCtrl;
};