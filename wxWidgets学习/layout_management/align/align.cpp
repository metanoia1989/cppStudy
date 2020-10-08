#include "align.h"

Align::Align(const wxString& title) 
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(350, 250))
{
    auto *panel = new wxPanel(this, wxID_ANY);
    auto *vbox = new wxBoxSizer(wxVERTICAL);
    auto *hbox1 = new wxBoxSizer(wxHORIZONTAL);
    auto *hbox2 = new wxBoxSizer(wxHORIZONTAL);

    auto *ok = new wxButton(panel, wxID_ANY, wxT("OK"));
    auto *cancel = new wxButton(panel, wxID_ANY, wxT("Cancel"));

    hbox1->Add(new wxPanel(panel, wxID_ANY));
    vbox->Add(hbox1, 1, wxEXPAND);

    hbox2->Add(ok);
    hbox2->Add(cancel);

    vbox->Add(hbox2, 0, wxALIGN_RIGHT | wxRIGHT | wxBOTTOM, 10);
    panel->SetSizer(vbox);

    Centre();
}
