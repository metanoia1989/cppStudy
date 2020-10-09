#include "fontdialog.h"
#include <wx/fontdlg.h>

enum {
    ID_FONTDIALOG = 1
};

ChangeFont::ChangeFont(const wxString& title) 
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(300, 200))
{
    wxPanel *panel = new wxPanel(this, wxID_ANY); 

    wxMenuBar *menubar = new wxMenuBar;
    wxMenu *file = new wxMenu;
    file->Append(ID_FONTDIALOG, wxT("&Change font"));
    menubar->Append(file, wxT("&File"));
    SetMenuBar(menubar);
    
    Connect(ID_FONTDIALOG, wxEVT_COMMAND_MENU_SELECTED,
        wxCommandEventHandler(ChangeFont::OnOpen));
    
    st = new wxStaticText(panel, wxID_ANY, wxT("The Agoge"),
        wxPoint(20, 20));
    
    Centre();
}

void ChangeFont::OnOpen(wxCommandEvent& WXUNUSED(event)) 
{
    auto fontDialog = new wxFontDialog(this);
    if (fontDialog->ShowModal() == wxID_OK) {
        st->SetFont(fontDialog->GetFontData().GetChosenFont());
    }
}
