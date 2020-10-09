#include "main.h"
#include "Slider.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{

    Slider *slider = new Slider(wxT("Slider"));
    slider->Show(true);

    return true;
}