#include "main.h"
#include "flexgridsizer.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{

    FlexGridSizer *fgs = new FlexGridSizer(wxT("FlexGridSizer"));
    fgs->Show(true);

    return true;
}