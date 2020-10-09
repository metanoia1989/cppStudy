#include "main.h"
#include "bitmapbutton.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{

    BitmapButton *bb = new BitmapButton(wxT("BitmapButton"));
    bb->Show(true);

    return true;
}