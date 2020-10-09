#include "customdialog.h"

CustomDialog::CustomDialog(const wxString& title) 
    : wxDialog(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(250, 230))
{
    wxPanel *panel = new wxPanel(this, wxID_ANY); 
    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);
    
    wxStaticBox *st = new wxStaticBox(panel, wxID_ANY, wxT("Colors"), 
        wxPoint(5, 5), wxSize(240, 150));
    wxRadioButton *rb = new wxRadioButton(panel, wxID_ANY,
        wxT("256 Colors"), wxPoint(15, 30), wxDefaultSize, wxRB_GROUP);
    wxRadioButton *rb1 = new wxRadioButton(panel, wxID_ANY,
        wxT("16 Colors"), wxPoint(15, 55));
    wxRadioButton *rb2 = new wxRadioButton(panel, wxID_ANY,
        wxT("2 Colors"), wxPoint(15, 80));
    wxRadioButton *rb3 = new wxRadioButton(panel, wxID_ANY,
        wxT("Custom"), wxPoint(15, 105));
    wxTextCtrl *tc = new wxTextCtrl(panel, wxID_ANY, wxT(""),
        wxPoint(95, 105));

    wxButton *okButton = new wxButton(this, wxID_ANY, wxT("Ok"),
        wxDefaultPosition, wxSize(70, 30)); 
    wxButton *closeButton = new wxButton(this, wxID_ANY, wxT("Close"),
        wxDefaultPosition, wxSize(70, 30)); 

    hbox->Add(okButton, 1);
    hbox->Add(closeButton, 1, wxLEFT, 5);
    
    vbox->Add(panel, 1);
    vbox->Add(hbox, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 10);
    
    SetSizer(vbox);
    Centre();
}
