#include "main.h"
#include "fontdialog.h"

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{

    ChangeFont *change = new ChangeFont(wxT("Change font"));
    change->Show(true);

    return true;
}