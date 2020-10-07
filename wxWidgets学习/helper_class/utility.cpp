#include <wx/utils.h>
#include <wx/crt.h>
#include <wx/string.h>
#include <wx/app.h>

int main(int argc, char const *argv[])
{
    wxInitialize(); 

    // 执行命令
    wxShell(wxT("ls -l"));

    // 获取有关目录信息
    wxPuts(wxGetHomeDir());
    wxPuts(wxGetOsDescription());
    wxPuts(wxGetUserName());
    wxPuts(wxGetFullHostName());

    // toLong 会丢失精度，会报错，=_= 好坑爹啊  
    auto mem = wxGetFreeMemory().ToString();
    wxPrintf(wxT("Memory: %s\n"), mem);

    return 0;
}

