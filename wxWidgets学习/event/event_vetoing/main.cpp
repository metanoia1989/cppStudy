#include "main.h"
#include "veto.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    Veto *veto = new Veto(wxT("Veto"));
    veto->Show(true);

    return true;
}