#include "main.h"
#include "align.h"

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() 
{
    auto *align = new Align(wxT("Align")); 
    align->Show(true);
    
    return true;
}
