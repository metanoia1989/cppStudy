#include "veto.h"

Veto::Veto(const wxString& title) 
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(250, 130))
{

    Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(Veto::OnClose));
    Centre();
}

void Veto::OnClose(wxCloseEvent& event) 
{
    auto *dialog = new wxMessageDialog(nullptr, 
        wxT("Are you sure to quil?"), wxT("Question"),
        wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
    int ret = dialog->ShowModal();
    dialog->Destroy();
    if (ret == wxID_YES) {
        Destroy();
    } else {
        event.Veto(); // 拒绝关闭事件
    }
}

