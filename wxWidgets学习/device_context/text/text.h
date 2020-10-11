#include <wx/wx.h>

class Text : public wxFrame
{
public:
    Text(const wxString& title);
    void OnPaint(wxPaintEvent& event);
};