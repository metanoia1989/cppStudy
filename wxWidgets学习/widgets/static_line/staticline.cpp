#include "staticline.h"
#include <wx/stattext.h>
#include <wx/statline.h>

Staticline::Staticline(const wxString& title) 
    : wxDialog(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(360, 350))
{
    wxFont font(10, wxDEFAULT, wxNORMAL, wxBOLD); 
    wxStaticText *heading = new wxStaticText(this, wxID_ANY, 
        wxT("The Central Europe"), wxPoint(30, 15));
    heading->SetFont(font);
    
    wxStaticLine *sl1 = new wxStaticLine(this, wxID_ANY, 
        wxPoint(25, 50), wxSize(300, 1));
    
    wxStaticText *st1 = new wxStaticText(this, wxID_ANY, wxT("Slovakia"),
        wxPoint(25, 80));
    wxStaticText *st2 = new wxStaticText(this, wxID_ANY, wxT("Hungary"),
        wxPoint(25, 100));
    wxStaticText *st3 = new wxStaticText(this, wxID_ANY, wxT("Poland"),
        wxPoint(25, 120));
    wxStaticText *st4 = new wxStaticText(this, wxID_ANY, wxT("Czech Republic"),
        wxPoint(25, 140));
    wxStaticText *st5 = new wxStaticText(this, wxID_ANY, wxT("Germany"),
        wxPoint(25, 160));
    wxStaticText *st6 = new wxStaticText(this, wxID_ANY, wxT("Slovenia"),
        wxPoint(25, 180));
    wxStaticText *st7 = new wxStaticText(this, wxID_ANY, wxT("Austria"),
        wxPoint(25, 200));
    wxStaticText *st8 = new wxStaticText(this, wxID_ANY, wxT("Switzerlan"),
        wxPoint(25, 220));

    wxStaticLine *sl2 = new wxStaticLine(this, wxID_ANY, 
        wxPoint(25, 260), wxSize(300, 1));
    
    wxStaticText *sum = new wxStaticText(this, wxID_ANY, wxT("164 102 000"), 
        wxPoint(220, 280));
    wxFont sum_font = sum->GetFont();
    sum_font.SetWeight(wxBOLD);
    sum->SetFont(sum_font);
    
    Centre();
}
