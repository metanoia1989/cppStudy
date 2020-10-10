#include <wx/wx.h>
#include <wx/listbox.h>

class MyPanel : public wxPanel
{
public:
    MyPanel(wxPanel *parent);
    
    void OnNew(wxCommandEvent& event);
    void OnRename(wxCommandEvent& event);
    void OnClear(wxCommandEvent& event);
    void OnDelete(wxCommandEvent& event);
    
    wxListBox *m_lb;
    wxButton *m_newb;
    wxButton *m_renameb;
    wxButton *m_clearb;
    wxButton *m_deleteb;
};

class Listbox : public wxFrame
{
public:
    Listbox(const wxString& title);
    
    void OnDblClick(wxCommandEvent& event);
    
    wxListBox *listbox;
    MyPanel *btnPanel;
};

enum {
    ID_RENAME = 1,
    ID_LISTBOX = 5
};