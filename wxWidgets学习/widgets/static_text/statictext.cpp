#include "statictext.h"

StaticText::StaticText(const wxString& title) 
    : wxFrame(nullptr, wxID_ANY, title)
{
    wxPanel *panel = new wxPanel(this, wxID_ANY);  
    wxString text = wxT(R"(Cause sometimes you feel tired,
feel weak, and when you feel weak,
you feel like you wanna just give up.
But you gotta search within you,
you gotta find that inner strength
and just pull that shit out of you
and get that motivation to not give up
and not be a quitter,
no matter how bad you wanna just fall flat on your face and collapse.)");
    wxStaticText *st = new wxStaticText(panel, wxID_ANY, text,
        wxPoint(10, 10), wxDefaultSize, wxALIGN_CENTER);

    SetSize(600, 110);
    Centre();
}
