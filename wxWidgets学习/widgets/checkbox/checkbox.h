#include <wx/wx.h>

class CheckBox : public wxFrame
{
public:
    CheckBox(const wxString& title);
    
    void OnToggle(wxCommandEvent& event);
    
    wxCheckBox *m_cb;
};

enum {
    ID_CHECKBOX = 100
};