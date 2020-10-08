#include <wx/wx.h>

class GridSizer : public wxFrame
{
public:
    GridSizer(const wxString& title);

    wxMenuBar *menubar;
    wxMenu *file;

    wxBoxSizer *sizer;
    wxGridSizer *gs;
    wxTextCtrl *display;
};