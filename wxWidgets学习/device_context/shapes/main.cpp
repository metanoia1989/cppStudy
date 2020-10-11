#include "main.h"
#include "shapes.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{

    Shapes *shapes = new Shapes(wxT("Shapes"));
    shapes->Show(true);

    return true;
}