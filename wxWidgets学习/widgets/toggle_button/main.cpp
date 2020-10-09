#include "main.h"
#include "toggle_button.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{

    ToggleButton *button = new ToggleButton(wxT("ToggleButton"));

    button->Centre();
    button->Show(true);

    return true;
}