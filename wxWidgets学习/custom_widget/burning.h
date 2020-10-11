#if !defined(BRUNING_H)
#define BRUNING_H

#include <wx/wx.h>
#include "widget.h"

class Burning : public wxFrame
{
public:
    Burning(const wxString& title);
    void OnScroll(wxScrollEvent& event);
    int GetCurWidth();
    
    wxSlider *m_slider;
    Widget *m_wid;
    int cur_width;
};

#endif // BRUNING_H
