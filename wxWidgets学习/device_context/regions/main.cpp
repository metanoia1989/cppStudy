#include "main.h"
#include "Regions.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
  Regions *regions = new Regions(wxT("Regions"));
  regions->Show(true);

  return true;
}