#include "main.h"
#include "propagate.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{

    Propagate *prop = new Propagate(wxT("Propagate"));
    prop->Show(true);

    return true;
}