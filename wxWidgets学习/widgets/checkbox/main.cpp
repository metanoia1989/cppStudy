#include "main.h"
#include "checkbox.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{

    CheckBox *cb = new CheckBox(wxT("CheckBox"));
    cb->Show(true);

    return true;
}