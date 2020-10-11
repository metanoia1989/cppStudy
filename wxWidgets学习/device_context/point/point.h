#include <wx/wx.h>

class Points : public wxFrame
{
public:
    Points(const wxString& ttile);
    void OnPaint(wxPaintEvent& event);
};