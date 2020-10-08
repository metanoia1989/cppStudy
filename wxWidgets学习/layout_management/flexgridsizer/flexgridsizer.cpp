#include "flexgridsizer.h"

FlexGridSizer::FlexGridSizer(const wxString& title) 
    : wxFrame(nullptr, wxID_ANY, title, wxPoint(-1, -1), wxSize(270, 220))
{
    wxPanel *panel = new wxPanel(this, wxID_ANY); 
    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);
    wxFlexGridSizer *fgs = new wxFlexGridSizer(3, 2, 9, 25);

    auto *theTitle = new wxStaticText(panel, wxID_ANY, wxT("标题"));
    auto *author = new wxStaticText(panel, wxID_ANY, wxT("作者"));
    auto *review = new wxStaticText(panel, wxID_ANY, wxT("评论"));
    auto *tc1 = new wxTextCtrl(panel, wxID_ANY);
    auto *tc2 = new wxTextCtrl(panel, wxID_ANY);
    auto *tc3 = new wxTextCtrl(panel, wxID_ANY, wxT(""), 
        wxPoint(-1, -1), wxSize(-1, -1), wxTE_MULTILINE);
    fgs->Add(theTitle);
    fgs->Add(tc1, 1, wxEXPAND);
    fgs->Add(author);
    fgs->Add(tc2, 1, wxEXPAND);
    fgs->Add(review);
    fgs->Add(tc3, 1, wxEXPAND);
    fgs->AddGrowableRow(2, 1);
    fgs->AddGrowableCol(1, 1);

    hbox->Add(fgs, 1, wxALL|wxEXPAND, 15);
    panel->SetSizer(hbox);
    
    Centre();
}
