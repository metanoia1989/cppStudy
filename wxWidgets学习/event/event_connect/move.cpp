#include "move.h"

Move::Move(const wxString& title) 
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(250, 130))
{
    wxPanel *panel = new wxPanel(this, wxID_ANY);
    st1 = new wxStaticText(panel, wxID_ANY, wxT(""), wxPoint(10, 10));
    st2 = new wxStaticText(panel, wxID_ANY, wxT(""), wxPoint(10, 30));

    Connect(wxEVT_MOVE, wxMoveEventHandler(Move::OnMove));
}

void Move::OnMove(wxMoveEvent& event) 
{
    wxPoint size = event.GetPosition();
    st1->SetLabel(wxString::Format(wxT("x: %d"), size.x));
    st2->SetLabel(wxString::Format(wxT("y: %d"), size.y));
}
