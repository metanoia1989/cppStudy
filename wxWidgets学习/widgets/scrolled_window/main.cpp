#include "main.h"
#include "scrolled_window.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{

    ScrWindow *sw = new ScrWindow(wxT("ScrolledWindow"));
    sw->Show(true);

    return true;
}