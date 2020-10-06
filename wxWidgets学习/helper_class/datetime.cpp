#include <wx/crt.h>
#include <wx/string.h>
#include <wx/app.h>
#include <wx/datetime.h>


int main(int argc, char const *argv[])
{
    wxInitialize(); 

    wxDateTime now = wxDateTime::Now();

    // 输出日期时间
    wxString date1 = now.Format();
    wxString date2 = now.Format(wxT("%X"));
    wxString date3 = now.Format(wxT("%x"));
    auto date_str = date1 + wxT("\n") + date2 + wxT("\n") + date3;
    wxPuts(date_str);

    // 输出不同时区的日期时间 =_= 全部报错，我醉了，运行时才检测搞毛线
    // wxPrintf(wxT("   Tokyo: %s\n"), now.Format(wxT("%a %T"), wxDateTime::GMT9).c_str());
    // wxPrintf(wxT("   Moscow: %s\n"), now.Format(wxT("%a %T"), wxDateTime::MSD).c_str());
    // wxPrintf(wxT("   Budapest: %s\n"), now.Format(wxT("%a %T"), wxDateTime::CEST).c_str());
    // wxPrintf(wxT("   London: %s\n"), now.Format(wxT("%a %T"), wxDateTime::WEST).c_str());
    // wxPrintf(wxT("   New York: %s\n"), now.Format(wxT("%a %T"), wxDateTime::EDT).c_str());

    wxString a_date = now.Format(wxT("%B %d %Y"));
    wxPuts(a_date);

    wxDateSpan span(0, 1);
    wxDateTime then = now.Add(span); // 添加一个月
    wxString b_date = now.Format(wxT("%B %d %Y"));
    wxPuts(b_date);
}