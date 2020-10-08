#include "button.h"

MyButton::MyButton(const wxString& title) 
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(270, 150))
{
    wxPanel *panel = new wxPanel(this, wxID_ANY); 
    wxButton *button = new wxButton(panel, wxID_EXIT, 
        wxT("Quit"), wxPoint(20, 20));
    Centre();
}

void MyButton::OnQuit(wxCommandEvent& WXUNUSED(event)) 
{
    Close(true); 
}

wxBEGIN_EVENT_TABLE(MyButton, wxFrame)
    EVT_BUTTON( wxID_EXIT, MyButton::OnQuit )
wxEND_EVENT_TABLE()