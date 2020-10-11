#include "main.h"
#include "gradient.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
  Gradient *grad = new Gradient(wxT("Gradient"));
  grad->Show(true);

  return true;
}