#include <wx/wx.h>
#include <wx/menu.h>
    
class SubMenu : public wxFrame
{
public:
    SubMenu(const wxString& title);
    void OnQuit(wxCommandEvent& event);

    wxMenuBar *menuBar;
    wxMenu *fileMenu;
    wxMenu* impMenu;
    wxMenuItem* quit;
};