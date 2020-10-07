#include <wx/crt.h>
#include <wx/string.h>
#include <wx/app.h>
#include <wx/file.h>
#include <wx/textfile.h>
#include <wx/dir.h>
#include <wx/filefn.h>

int main(int argc, char const *argv[])
{
    wxInitialize(); 

    // 创建文件并添加内容
    wxString str = wxT("#include <stdio.h>\nint main() {\n\tprintf(\"测试\");\n}");

    wxFile file;
    file.Create(wxT("test.c"), true);
    if (file.IsOpened()) {
        wxPuts(wxT("the file is opened"));
    }
    file.Write(str);
    file.Close();
    if (!file.IsOpened()) {
        wxPuts(wxT("the file is not opened"));
    }

    // 读取文件
    wxTextFile filer(wxT("test.c"));
    filer.Open();
    wxPrintf(wxT("Number of lines: %zu\n"), filer.GetLineCount());
    wxPrintf(wxT("First line: %s\n"), filer.GetFirstLine().c_str());
    wxPrintf(wxT("Last line: %s\n"), filer.GetFirstLine().c_str());

    wxPuts(wxT("-----------------------------------------------"));
    for (wxString s = filer.GetFirstLine(); !filer.Eof(); s = filer.GetNextLine())
    {
        wxPuts(s);
    }
    filer.Close();

    // 读取目录，感觉不太好用
    wxPuts(wxT("dir file output: "));
    wxDir dir(wxGetCwd());
    wxString file_str;
    bool cont = dir.GetFirst(&file_str, wxEmptyString,
        wxDIR_FILES | wxDIR_DIRS);

    while (cont) {
        wxPuts(file_str);
        cont = dir.GetNext(&file_str);
    }
}