#include "main.h"
#include "boxsizer.h"

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() 
{
    auto *border = new Border(wxT("Border")); 
    border->Show(true);
    
    return true;
}
