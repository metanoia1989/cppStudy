#include "main.h"
#include "Listbox.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{

    Listbox *listbox = new Listbox(wxT("Listbox"));
    listbox->Show(true);

    return true;
}