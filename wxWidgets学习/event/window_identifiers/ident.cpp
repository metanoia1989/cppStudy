#include "ident.h"

Ident::Ident(const wxString& title) 
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(200, 150))
{
    wxPanel *panel = new wxPanel(this, wxID_ANY);    

    wxGridSizer *grid = new wxGridSizer(2, 3, 1, 1);
    grid->Add(new wxButton(panel, wxID_CANCEL), 0, wxTOP | wxLEFT, 9);
    grid->Add(new wxButton(panel, wxID_DELETE), 0, wxTOP, 9);
    grid->Add(new wxButton(panel, wxID_SAVE), 0, wxLEFT, 9);
    grid->Add(new wxButton(panel, wxID_EXIT));
    grid->Add(new wxButton(panel, wxID_STOP), 0, wxLEFT, 9);
    grid->Add(new wxButton(panel, wxID_NEW));

    panel->SetSizer(grid);
    Centre();
}
