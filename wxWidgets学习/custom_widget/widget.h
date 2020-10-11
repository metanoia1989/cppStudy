#if !defined(WIDGET_H)
#define WIDGET_H

#include <wx/wx.h>

class Widget : public wxPanel
{
public:
    Widget(wxPanel *parent, int id);

    void OnSize(wxSizeEvent& event);
    void OnPaint(wxPaintEvent& event);

    wxPanel *m_parent;
};

#endif // WIDGET_H
