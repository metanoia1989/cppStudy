#include <wx/wx.h>

class Line : public wxFrame
{
public:
    Line(const wxString& title);
    void OnPaint(wxPaintEvent& event);
};