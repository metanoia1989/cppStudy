#include "main.h"
#include "staticline.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    Staticline *sl = new Staticline(wxT("The Central Europe"));
    sl->ShowModal();
    sl->Destroy();

    return true;
}