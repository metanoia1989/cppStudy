#include <wx/wx.h>

class Regions : public wxFrame
{
public:
    Regions(const wxString& title);
    void OnPaint(wxPaintEvent& event);
};