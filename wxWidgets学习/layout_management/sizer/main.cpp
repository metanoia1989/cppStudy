#include "main.h"
#include "sizer.h"

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() 
{
    auto *sizer = new Sizer(wxT("Sizer")); 
    sizer->Show(true);
    
    return true;
}
