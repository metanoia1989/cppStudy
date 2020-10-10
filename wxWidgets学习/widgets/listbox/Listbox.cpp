#include "Listbox.h"

MyPanel::MyPanel(wxPanel *parent) 
    : wxPanel(parent, wxID_ANY)
{
    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL); 
    Listbox *lb = static_cast<Listbox *>(parent->GetParent());
    m_lb = lb->listbox;
    
    m_newb = new wxButton(this, wxID_NEW, wxT("New")); 
    m_renameb = new wxButton(this, ID_RENAME, wxT("Rename")); 
    m_deleteb = new wxButton(this, wxID_DELETE, wxT("Delete")); 
    m_clearb = new wxButton(this, wxID_CLEAR, wxT("Clear")); 
    vbox->Add(-1, 20);
    vbox->Add(m_newb);
    vbox->Add(m_renameb, 0, wxTOP, 5);
    vbox->Add(m_deleteb, 0, wxTOP, 5);
    vbox->Add(m_clearb, 0, wxTOP, 5);
    
    SetSizer(vbox);
    
    Connect(wxID_NEW, wxEVT_COMMAND_BUTTON_CLICKED, 
        wxCommandEventHandler(MyPanel::OnNew));
    Connect(ID_RENAME, wxEVT_COMMAND_BUTTON_CLICKED, 
        wxCommandEventHandler(MyPanel::OnRename));
    Connect(wxID_CLEAR, wxEVT_COMMAND_BUTTON_CLICKED, 
        wxCommandEventHandler(MyPanel::OnClear));
    Connect(wxID_DELETE, wxEVT_COMMAND_BUTTON_CLICKED, 
        wxCommandEventHandler(MyPanel::OnDelete));
}

void MyPanel::OnNew(wxCommandEvent& event) 
{
    wxString str = wxGetTextFromUser(wxT('Add new item')); 
    if (str.Len() > 0) 
        m_lb->Append(str);
}

void MyPanel::OnRename(wxCommandEvent& event) 
{
    wxString text;
    wxString renamed;

    int sel = m_lb->GetSelection();
    if (sel != -1) {
        text = m_lb->GetString(sel);     
        renamed = wxGetTextFromUser(wxT("Rename item"),
            wxT("Rename dialog"), text);
    }
    if (!renamed.IsEmpty()) {
        m_lb->Delete(sel);
        m_lb->Insert(renamed, sel);
    }
}

void MyPanel::OnClear(wxCommandEvent& event) 
{
    m_lb->Clear();    
}

void MyPanel::OnDelete(wxCommandEvent& event) 
{
    int sel = m_lb->GetSelection();    
    if (sel != -1) {
        m_lb->Delete(sel);
    }
}

Listbox::Listbox(const wxString& title) 
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(270, 200))
{
    wxPanel *panel = new wxPanel(this, wxID_ANY); 

    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);
    listbox = new wxListBox(panel, ID_LISTBOX, 
        wxPoint(-1, -1), wxSize(-1, -1));
    btnPanel = new MyPanel(panel);
    hbox->Add(listbox, 3, wxEXPAND | wxALL, 20);
    hbox->Add(btnPanel, 2, wxEXPAND | wxRIGHT, 10);
    
    panel->SetSizer(hbox);
    Center();
    
    Connect(wxEVT_COMMAND_LISTBOX_DOUBLECLICKED,
        wxCommandEventHandler(Listbox::OnDblClick));
}

void Listbox::OnDblClick(wxCommandEvent& event) 
{
    wxString text;
    wxString renamed;

    int sel = listbox->GetSelection();
    if (sel != -1) {
        text = listbox->GetString(sel);     
        renamed = wxGetTextFromUser(wxT("Rename item"),
            wxT("Rename dialog"), text);
    }
    if (!renamed.IsEmpty()) {
        listbox->Delete(sel);
        listbox->Insert(renamed, sel);
    }
}
