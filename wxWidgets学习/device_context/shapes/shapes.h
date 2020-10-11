#include <wx/wx.h>

class Shapes : public wxFrame
{
public:
    Shapes(const wxString& title);
    void OnPaint(wxPaintEvent& event);
};