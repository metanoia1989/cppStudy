#include "main.h"
#include "menu.h"

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	auto menu = new SubMenu(wxT("子菜单"));
	menu->Show(true);
	return true;
}