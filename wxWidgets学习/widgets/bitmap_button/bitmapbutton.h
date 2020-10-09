#include <wx/wx.h>
#include <wx/slider.h>

class BitmapButton : public wxFrame
{
public:
    BitmapButton(const wxString& title);
    
    void OnScroll(wxScrollEvent& event);
    
    wxSlider *slider;
    wxBitmapButton *button;
    int pos;
};

enum {
    ID_SLIDER = 100
};