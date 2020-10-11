#include "main.h"
#include "text.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{

    Text *text = new Text(wxT("Text"));
    text->Show(true);

    return true;
}