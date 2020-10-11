#include <wx/wx.h>
#include <wx/dnd.h>
#include <wx/listctrl.h>
#include <wx/dirctrl.h>

class TextDrop : public wxFrame
{
public:
    TextDrop(const wxString& title);
    
    void OnSelect(wxCommandEvent& event);
    void OnDragInit(wxListEvent& event);
    
    wxGenericDirCtrl *m_gdir;
    wxListCtrl *m_lc1;
    wxListCtrl *m_lc2;
};

class MyTextDropTarget : public wxTextDropTarget
{
public:
    MyTextDropTarget(wxListCtrl *owner);

    virtual bool OnDropText(wxCoord x, wxCoord y,
        const wxString& data);
    
    wxListCtrl *m_owner;
};