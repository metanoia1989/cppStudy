#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class MyButton : public wxFrame
{
public:
    MyButton(const wxString& title);
    void OnQuit(wxCommandEvent& event);
private:
    wxDECLARE_EVENT_TABLE();
};