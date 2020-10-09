#include "Messages.h"

Messages::Messages(const wxString& title) 
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(210, 100))
{
    wxPanel *panel = new wxPanel(this, wxID_ANY);    
    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);
    wxGridSizer *gs = new wxGridSizer(2, 2, 10, 10);
    
    wxButton *btn1 = new wxButton(panel, ID_INFO, wxT("Info"));
    wxButton *btn2 = new wxButton(panel, ID_ERROR, wxT("Error"));
    wxButton *btn3 = new wxButton(panel, ID_QUESTION, wxT("Question"));
    wxButton *btn4 = new wxButton(panel, ID_ALERT, wxT("Alter"));
    
    gs->Add(btn1, 1);
    gs->Add(btn2, 1);
    gs->Add(btn3, 1);
    gs->Add(btn4, 1);
    
    hbox->Add(gs, 0, wxALL, 15);
    panel->SetSizer(hbox);
    
    Connect(ID_INFO, wxEVT_COMMAND_BUTTON_CLICKED,
        wxCommandEventHandler(Messages::ShowMessage1));
    Connect(ID_ERROR, wxEVT_COMMAND_BUTTON_CLICKED,
        wxCommandEventHandler(Messages::ShowMessage2));
    Connect(ID_QUESTION, wxEVT_COMMAND_BUTTON_CLICKED,
        wxCommandEventHandler(Messages::ShowMessage3));
    Connect(ID_ALERT, wxEVT_COMMAND_BUTTON_CLICKED,
        wxCommandEventHandler(Messages::ShowMessage4));
    
    Centre();
}

void Messages::ShowMessage1(wxCommandEvent& event) 
{
    auto *dial = new wxMessageDialog(nullptr, wxT("Download complete"),
        wxT("Info"), wxOK);
    dial->ShowModal();
}

void Messages::ShowMessage2(wxCommandEvent& event) 
{
    auto *dial = new wxMessageDialog(nullptr, wxT("Error loading file"),
        wxT("Error"), wxOK | wxICON_ERROR);
    dial->ShowModal();
}

void Messages::ShowMessage3(wxCommandEvent& event) 
{
    auto *dial = new wxMessageDialog(nullptr, wxT("Are you sure to quit"),
        wxT("Question"), wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
    dial->ShowModal();
}

void Messages::ShowMessage4(wxCommandEvent& event) 
{
    auto *dial = new wxMessageDialog(nullptr, wxT("Unallowed operation"),
        wxT("Exclamation"), wxOK | wxICON_EXCLAMATION);
    dial->ShowModal();
}