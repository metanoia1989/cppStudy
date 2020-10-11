#include <wx/wx.h>

class Gradient : public wxFrame
{
public:
    Gradient(const wxString& title);
    void OnPaint(wxPaintEvent& event);
};