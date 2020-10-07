#include "main.h"
#include "absolute.h"

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() 
{
    Absolute *absolute = new Absolute(wxT("Absolute")); 
    absolute->Show(true);
    
    return true;
}
