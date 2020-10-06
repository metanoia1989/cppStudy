#include "menu.h"

SimpleMenu::SimpleMenu(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(280, 180))
{
    menuBar = new wxMenuBar;
    fileMenu = new wxMenu;
    fileMenu->Append(wxID_EXIT, wxT("&Quit"));
    menuBar->Append(fileMenu, wxT("&File"));
    SetMenuBar(menuBar);

    Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED,
        wxCommandEventHandler(SimpleMenu::OnQuit)); // 退出菜单项，连接方法
    Centre();
}

void SimpleMenu::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);
}