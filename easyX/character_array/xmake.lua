add_rules("mode.debug", "mode.release")

option("company")
    set_default(false)
    set_showmenu(true)
    set_description("公司的easyX配置")
    add_includedirs(
        "D:/Program/VistualStudio/IDE/VC/Auxiliary/VS/include",
        "D:/Program/VistualStudio/IDE/VC/Tools/MSVC/14.27.29110/include",
        "D:/Windows Kits/10/Include/10.0.18362.0/shared",
        "D:/Windows Kits/10/Include/10.0.18362.0/ucrt",
        "D:/Windows Kits/10/Include/10.0.18362.0/um"
    )
    add_linkdirs(
        "D:/Program/VistualStudio/IDE/VC/Auxiliary/VS/lib/x64", 
        "D:/Windows Kits/10/Lib/10.0.18362.0/um/x64",
        "D:/Windows Kits/10/Lib/10.0.18362.0/ucrt/x64"
    )
option_end()

option("home")
    set_default(true)
    set_showmenu(true)
    set_description("家里的easyX配置")
    add_includedirs(
        "D:/Program/VisualStudioCommunity2019/IDE/VC/Auxiliary/VS/include",
        "D:/Program/VisualStudioCommunity2019/IDE/VC/Tools/MSVC/14.27.29110/include",
        "C:/Program Files (x86)/Windows Kits/10/Include/10.0.18362.0/shared",
        "C:/Program Files (x86)/Windows Kits/10/Include/10.0.18362.0/ucrt",
        "C:/Program Files (x86)/Windows Kits/10/Include/10.0.18362.0/um"
    )
    add_linkdirs(
        "D:/Program/VisualStudioCommunity2019/IDE/VC/Auxiliary/VS/lib/x64", 
        "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.18362.0/um/x64",
        "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.18362.0/ucrt/x64"
    )
option_end()

if has_config("company") then
    add_options("company")
elseif has_config("home") then
    add_options("home")
end

-- add_defines("UNICODE")
-- add_links("EasyXw")
add_links("EasyXa")
add_links("Gdi32", "User32", "shell32", "Ole32")

target("draw_circle")
    set_kind("binary")
    add_files("src/draw_circle.cpp")

target("character_array")
    set_kind("binary")
    add_files("src/character_array.cpp")
