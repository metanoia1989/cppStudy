#include "main.h"
#include "line.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{

    Line *line = new Line(wxT("Line"));
    line->Show(true);

    return true;
}