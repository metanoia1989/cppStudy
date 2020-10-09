#include "main.h"
#include "customdialog.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{

    CustomDialog *custom = new CustomDialog(wxT("CustomDialog"));
    custom->Show(true);

    return true;
}