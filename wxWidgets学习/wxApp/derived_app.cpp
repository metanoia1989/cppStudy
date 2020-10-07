#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/help.h>

class DerivedApp : public wxApp
{
public:
    virtual bool OnInit();
private:
    void OnExit(wxCommandEvent& event);

    wxHelpController *helpCtrl;
};

enum {
    ID_MYFRAME = 1
};

wxIMPLEMENT_APP(DerivedApp);

bool DerivedApp::OnInit()
{
    helpCtrl = new wxHelpController;
    auto *frame = new wxFrame(nullptr, ID_MYFRAME, argv[0]);
    frame->Show(true);
    return true;
}


void DerivedApp::OnExit(wxCommandEvent& event)
{
    delete helpCtrl;
}