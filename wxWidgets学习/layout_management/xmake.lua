add_rules("mode.debug", "mode.release")

set_toolset("cc", "gcc")
set_toolset("cxx", "g++")
set_toolset("ld", "g++")
if is_plat("mingw") then
    add_includedirs(
        "D:/Program/msys64/mingw64/include",
        "D:/Program/msys64/mingw64/include/c++/10.2.0"
    )
    add_linkdirs(
        "D:/Program/msys64/mingw64/lib"
    )
    add_ldflags(
        "-DWXUSINGDLL",
        "-D__WXMSW__",
        "-lpthread",
        "-lwx_mswud_xrc-3.1",
        "-lwx_mswud_html-3.1",
        "-lwx_mswud_qa-3.1",
        "-lwx_mswud_core-3.1",
        "-lwx_baseud_xml-3.1",
        "-lwx_baseud_net-3.1",
        "-lwx_baseud-3.1",
        { force = true }
    )
elseif is_plat("linux") then
    add_includedirs(
        "/usr/local/lib/wx/include/gtk3-unicode-3.1",
        "/usr/local/include/wx-3.1"
    )
    add_defines("WXUSINGDLL", "__WXGTK3__", "__WXGTK__")
    add_ldflags(
        "-L/usr/local/lib", 
        "-pthread", 
        "-lwx_gtk3u_xrc-3.1", 
        "-lwx_gtk3u_html-3.1",  
        "-lwx_gtk3u_qa-3.1",  
        "-lwx_gtk3u_core-3.1",  
        "-lwx_baseu_xml-3.1",  
        "-lwx_baseu_net-3.1",  
        "-lwx_baseu-3.1"         
    )
end

add_cxxflags("-Wall")

target("absolute")
    set_kind("binary")
    add_files("absolute/*.cpp")

target("sizer")
    set_kind("binary")
    add_files("sizer/*.cpp")

target("boxsizer")
    set_kind("binary")
    add_files("boxsizer/*.cpp")

target("align")
    set_kind("binary")
    add_files("align/*.cpp")

target("gotoclass")
    set_kind("binary")
    add_files("gotoclass/*.cpp")

target("gridsizer")
    set_kind("binary")
    add_files("gridsizer/*.cpp")

target("flexgridsizer")
    set_kind("binary")
    add_files("flexgridsizer/*.cpp")