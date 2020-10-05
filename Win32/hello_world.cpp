#include <windows.h>

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)   
{
    return MessageBox(nullptr, "hello world", "caption", 0);
}