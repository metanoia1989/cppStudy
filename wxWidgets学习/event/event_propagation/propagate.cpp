#include "propagate.h"
#include <iostream>

enum {
    ID_BUTTON = 1
};

Propagate::Propagate(const wxString& title) 
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(250, 130))
{
    MyPanel *panel = new MyPanel(this, wxID_ANY);
    new MyButton(panel, ID_BUTTON, wxT("OK"));

    Connect(ID_BUTTON, wxEVT_COMMAND_BUTTON_CLICKED,
        wxCommandEventHandler(Propagate::OnClick));
    
    Centre();
}

void Propagate::OnClick(wxCommandEvent& event) 
{
    std::cout << "event reached frame class" << std::endl; 
    event.Skip(); // 继续向父级冒泡
}


MyPanel::MyPanel(wxFrame *frame, int id) 
    : wxPanel(frame, id)
{
    Connect(ID_BUTTON, wxEVT_COMMAND_BUTTON_CLICKED,
        wxCommandEventHandler(MyPanel::OnClick));    
}

void MyPanel::OnClick(wxCommandEvent& event) 
{
    std::cout << "event reached panel class" << std::endl;     
    event.Skip();
}


MyButton::MyButton(MyPanel *panel, int id, const wxString& label) 
    : wxButton(panel, id, label, wxPoint(15, 15))
{
    Connect(ID_BUTTON, wxEVT_COMMAND_BUTTON_CLICKED,
        wxCommandEventHandler(MyButton::OnClick));    
}

void MyButton::OnClick(wxCommandEvent& event) 
{
    std::cout << "event reached button class" << std::endl;     
    event.Skip();
}
