#include "toolbar.h"

Toolbar::Toolbar(const wxString& title) 
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(300, 250))
{
    wxImage::AddHandler(new wxPNGHandler);
    wxBitmap exit(wxT("exit.png"), wxBIT)
}

void Toolbar::OnQuit(wxCommandEvent& WXUNUSED(event)) 
{
    Close(true); 
}
