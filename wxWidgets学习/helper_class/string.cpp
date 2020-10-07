#define wxUSE_UNICODE 1
#include <wx/string.h>
#include <wx/crt.h>
#include <iostream>

int main(int argc, char const *argv[])
{
    /**
     * 测试字符串
     */ 
    // 字符串输出
    std::cout << wxString("输出中文测试").c_str() << std::endl;
    wxPuts(wxT("Widgets Consule Aplication"));

    // 字符串拼接
    wxString str1 = wxT("Linux");
    wxString str2 = wxT("Operating");
    wxString str3 = wxT("System");
    auto str = str1 + wxT(" ") + str2 + wxT(" ") + str3;
    wxPuts(str);

    // 字符串格式化
    wxString str_d;
    str_d.Printf(wxT("There are %d red ross."), 21);
    wxPuts(str_d);

    // 字符串包含检测
    wxString str_c = wxT("The history of my life一");
    if (str_c.Contains(wxT("history"))) {
        wxPuts(wxT("Contains history!"));
    }
    if (str_c.Contains(wxT("一"))) {
        wxPuts(wxT("Contains 1!"));
    }
    if (!str.Contains(wxT("plain"))) {
        wxPuts(wxT("Does not contains plain!"));
    }

    // 宽度检测 
    wxString str_le = wxT("English string length");
    wxString str_lz = wxT("中文字符串长度");
    wxPrintf(wxT("english string length is %zu, chinese string length is %zu\n"), 
        str_le.Len(), str_lz.Len());

    // 大小写转换
    wxString str_p = wxT("The is sample string");
    wxPuts(str_p.MakeLower());
    wxPuts(str_p.MakeUpper());


    return 0;
}
