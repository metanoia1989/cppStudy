#include "burning.h"

enum {
    ID_SLIDER = 1
};

Burning::Burning(const wxString& title) 
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(350, 200))
{
    cur_width = 75; 
    wxPanel *panel = new wxPanel(this, wxID_ANY);
    wxPanel *centerPanel = new wxPanel(panel, wxID_ANY);
    
    m_slider = new wxSlider(centerPanel, ID_SLIDER, 75, 0, 750, wxPoint(-1, -1),
        wxSize(150, -1), wxSL_LABELS);
    
    auto *vbox = new wxBoxSizer(wxVERTICAL);
    auto *hbox = new wxBoxSizer(wxHORIZONTAL);
    auto *hbox2 = new wxBoxSizer(wxHORIZONTAL);
    auto *hbox3 = new wxBoxSizer(wxHORIZONTAL);
    
    m_wid = new Widget(panel, wxID_ANY);
    hbox->Add(m_wid, 1, wxEXPAND);
    hbox2->Add(centerPanel, 1, wxEXPAND);
    hbox3->Add(m_slider, 0, wxTOP|wxLEFT, 35);
    centerPanel->SetSizer(hbox3);
    vbox->Add(hbox2, 1, wxEXPAND);
    vbox->Add(hbox, 0, wxEXPAND);
    
    panel->SetSizer(vbox);
    m_slider->SetFocus();
    
    Centre();
    
    Connect(ID_SLIDER, wxEVT_COMMAND_SLIDER_UPDATED,
        wxScrollEventHandler(Burning::OnScroll));
}

void Burning::OnScroll(wxScrollEvent& event) 
{
    cur_width = m_slider->GetValue();
    m_wid->Refresh();
}

int Burning::GetCurWidth() 
{
    return cur_width;
}
