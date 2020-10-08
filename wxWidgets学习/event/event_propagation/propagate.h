#include <wx/wx.h>

class Propagate : public wxFrame
{
public:
    Propagate(const wxString& title);

    void OnClick(wxCommandEvent& event);
};


class MyPanel : public wxPanel
{
public:
    MyPanel(wxFrame *frame, int id);

    void OnClick(wxCommandEvent& event);
};

class MyButton : public wxButton
{
public:
    MyButton(MyPanel *panel, int id, const wxString& label);

    void OnClick(wxCommandEvent& event);
};