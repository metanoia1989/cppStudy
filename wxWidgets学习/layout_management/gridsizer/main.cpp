#include "main.h"
#include "gridsizer.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{

    GridSizer *gs = new GridSizer(wxT("GridSizer"));
    gs->Show(true);

    return true;
}