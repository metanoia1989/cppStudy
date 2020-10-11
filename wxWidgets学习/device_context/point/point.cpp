#include "point.h"
#include <cstdlib>
#include <ctime>

Points::Points(const wxString& title) 
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(280, 180))
{
    Connect(wxEVT_PAINT, wxPaintEventHandler(Points::OnPaint));
    Centre();

    srand(time(nullptr));
}

void Points::OnPaint(wxPaintEvent& event) 
{
    wxPaintDC dc(this);
    wxCoord x = 0;
    wxCoord y = 0;
    wxSize size = GetSize();
    for (int i = 0; i < 1000; i++) {
        x = rand() % size.x + 1;
        y = rand() % size.y + 1;
        dc.DrawPoint(x, y); // 哇，这个绘制随机点太棒了
    }
}
