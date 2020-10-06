#include "main.h"
#include "menu.h"

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	SimpleMenu* menu = new SimpleMenu(wxT("简单菜单"));
	menu->Show(true);
	return true;
}