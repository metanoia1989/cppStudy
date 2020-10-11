#include "text.h"

Text::Text(const wxString& title) 
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(250, 150))
{
    Connect(wxEVT_PAINT, wxPaintEventHandler(Text::OnPaint));
    Centre();
}

void Text::OnPaint(wxPaintEvent& event) 
{
    wxPaintDC dc(this); 
    dc.DrawText(wxT("金刚葫芦娃，呜啦啦啦啦"), 40, 60);
    dc.DrawText(wxT("齐天大圣孙悟空"), 70, 80);
}
