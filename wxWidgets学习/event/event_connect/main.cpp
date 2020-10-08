#include "main.h"
#include "move.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    Move *move = new Move(wxT("Move event"));
    move->Show(true);

    return true;
}