#include "main.h"
#include "ident.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{

    Ident *ident = new Ident(wxT("Identifiers"));
    ident->Show(true);

    return true;
}