#include "menu.h"

SubMenu::SubMenu(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(280, 180))
{
    menuBar = new wxMenuBar;

    fileMenu = new wxMenu;
    fileMenu->Append(wxID_EXIT, wxT("&Quit"));
    fileMenu->Append(wxID_EXIT, wxT("&Open"));
    fileMenu->Append(wxID_EXIT, wxT("&Save"));
    fileMenu->AppendSeparator();

    impMenu = new wxMenu;
    impMenu->Append(wxID_ANY, wxT("Import newsfeed list..."));
    impMenu->Append(wxID_ANY, wxT("Import bookmarks..."));
    impMenu->Append(wxID_ANY, wxT("Import mail..."));

    fileMenu->AppendSubMenu(impMenu, wxT("I&mport"));

    quit = new wxMenuItem(fileMenu, wxID_EXIT, wxT("&Quit\tCtrl+W"));
    fileMenu->Append(quit);

    menuBar->Append(fileMenu, wxT("&File"));
    SetMenuBar(menuBar);

    Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED,
        wxCommandEventHandler(SubMenu::OnQuit)); // 退出菜单项，连接方法
    Centre();
}

void SubMenu::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);
}