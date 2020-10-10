#include "scrolled_window.h"

ScrWindow::ScrWindow(const wxString& title) 
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(300, 200))
{
    wxImage::AddHandler(new wxJPEGHandler); 
    wxScrolledWindow *sw = new wxScrolledWindow(this);
    wxBitmap bmp(wxT("castle.jpg"), wxBITMAP_TYPE_JPEG);
    wxStaticBitmap *sb = new wxStaticBitmap(sw, wxID_ANY, bmp);
    
    int width = bmp.GetWidth();
    int height = bmp.GetHeight();
    
    sw->SetScrollbars(10, 10, width / 10, height / 10);
    sw->Scroll(50, 10);
    
    Center();
}
