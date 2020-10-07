#include "sizer.h"

Sizer::Sizer(const wxString& title) 
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(350, 250))
{
    wxPanel *panel = new wxPanel(this, wxID_ANY); 
    
    menuBar = new wxMenuBar;
    file = new wxMenu;
    edit = new wxMenu;
    help = new wxMenu;
    menuBar->Append(file, wxT("&File"));
    menuBar->Append(edit, wxT("&Edit"));
    menuBar->Append(help, wxT("&Help"));
    
    SetMenuBar(menuBar);
    
    textCtrl = new wxTextCtrl(panel, wxID_ANY, wxT(""), wxDefaultPosition,
        wxSize(250, 150), wxTE_MULTILINE);
}
