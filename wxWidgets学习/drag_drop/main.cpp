#include "main.h"
#include "textdrop.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{

    TextDrop *td = new TextDrop(wxT("TextDrop"));
    td->Show(true);

    return true;
}