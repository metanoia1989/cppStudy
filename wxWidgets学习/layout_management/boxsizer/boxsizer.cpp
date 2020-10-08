#include "boxsizer.h"

Border::Border(const wxString& title) 
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(350, 250))
{
    wxColour col1, col2;
    col1.Set(wxT("#4f5049"));
    col2.Set(wxT("#4f5049"));
    
    auto *panel = new wxPanel(this, wxID_ANY);
    panel->SetBackgroundColour(col1);
    auto *vbox = new wxBoxSizer(wxVERTICAL);

    auto *midPan = new wxPanel(panel, wxID_ANY);
    midPan->SetBackgroundColour(col2);

    vbox->Add(midPan, 1, wxEXPAND | wxALL, 20);
    panel->SetSizer(vbox);

    Centre();
}
