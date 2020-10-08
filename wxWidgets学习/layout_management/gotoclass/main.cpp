#include "main.h"
#include "gotoclass.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
 GotoClass *gotoclass = new GotoClass(wxT("GotoClass"));
 gotoclass->Show(true);

 return true;
}