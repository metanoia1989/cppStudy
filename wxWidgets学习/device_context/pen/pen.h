#include <wx/wx.h>

class Pen : public wxFrame
{
public:
    Pen(const wxString& title);
    void OnPaint(wxPaintEvent& event);
};