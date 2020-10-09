#include "main.h"
#include "statictext.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{

  StaticText *st = new StaticText(wxT("StaticText"));
  st->Show(true);

  return true;
}