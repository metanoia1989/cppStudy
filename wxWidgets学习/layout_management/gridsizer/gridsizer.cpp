#include "gridsizer.h"

GridSizer::GridSizer(const wxString& title) 
    : wxFrame(nullptr, wxID_ANY, title, wxPoint(-1, -1), wxSize(300, 250))
{
    menubar = new wxMenuBar;      
    file = new wxMenu;

    SetMenuBar(menubar);

    sizer = new wxBoxSizer(wxVERTICAL);
    display = new wxTextCtrl(this, -1, wxT(""), wxPoint(-1, -1),
        wxSize(-1, -1), wxTE_RIGHT);
    sizer->Add(display, 0, wxEXPAND|wxTOP|wxBOTTOM, 4);

    gs = new wxGridSizer(5, 4, 3, 3);
    std::string str[] = {
        "Cls", "Bck", "", "Close", 
        "7", "8", "9", "/", 
        "4", "5", "6", "*", 
        "1", "2", "3", "-", 
        "0", ".", "=", "+"
    };
    for (auto &item : str) {
        if (item.empty()) {
            gs->Add(new wxStaticText(this, wxID_ANY, wxT("")), 0, wxEXPAND);
            continue;
        }
        auto text = wxString(item.c_str(), wxConvUTF8);
        gs->Add(new wxButton(this, wxID_ANY, text), 0, wxEXPAND);
    }

    sizer->Add(gs, 1, wxEXPAND);
    SetSizer(sizer);
    SetMinSize(wxSize(270, 220));

    Centre();
}
