#include "main.h"
#include "pen.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
  Pen *pen = new Pen(wxT("Pen"));
  pen->Show(true);

  return true;
}