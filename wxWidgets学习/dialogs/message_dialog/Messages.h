#include <wx/wx.h>

class Messages : public wxFrame
{
public:
    Messages(const wxString& title);
    
    void ShowMessage1(wxCommandEvent& event);
    void ShowMessage2(wxCommandEvent& event);
    void ShowMessage3(wxCommandEvent& event);
    void ShowMessage4(wxCommandEvent& event);
};

enum {
    ID_INFO = 1,
    ID_ERROR = 2,
    ID_QUESTION = 3,
    ID_ALERT = 4
};