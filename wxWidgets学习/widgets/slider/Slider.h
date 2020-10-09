#include <wx/wx.h>
#include <wx/slider.h>

class MyPanel : public wxPanel
{
public:
    MyPanel(wxFrame *parent);
    
    void OnPaint(wxPaintEvent& event);
    void OnScroll(wxScrollEvent& event);
    
    wxSlider *slider;
    int fill;
};

class Slider : public wxFrame
{
public:
    Slider(const wxString& title);

    MyPanel *panel;
};

enum {
    ID_SLIDER = 100
};