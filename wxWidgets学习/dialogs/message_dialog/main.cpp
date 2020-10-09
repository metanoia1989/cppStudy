#include "main.h"
#include "Messages.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{

  Messages *msgs = new Messages(wxT("Messages"));
  msgs->Show(true);

  return true;
}