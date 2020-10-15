add_rules("mode.debug", "mode.release")
set_languages("c99", "c++17")

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
    set_default(false)
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

add_defines("UNICODE")
add_defines("_UNICODE")
add_links("EasyXw")
-- add_links("EasyXa")
add_links("Gdi32", "User32", "shell32", "Ole32")

if has_config("company") then
    add_options("company")
elseif has_config("home") then
    add_options("home")
end

target("load")
    set_kind("binary")
    add_files("load_image.cpp")
    after_build(function (target)
        local full_path = target:targetfile()
        local dir_path = string.gsub(full_path, "(.*[/|\\])(.*)", "%1")
        os.cp("$(projectdir)/*.jpg", dir_path)
    end)
    on_clean(function (target) 
        local full_path = target:targetfile()
        local dir_path = string.gsub(full_path, "(.*[/|\\])(.*)", "%1")
        os.rm(string.format("%s*.jpg", dir_path))
    end)

target("get")
    set_kind("binary")
    add_files("get_image.cpp")

target("trans_blt")
    set_kind("binary")
    add_files("transparent_blt.cpp")
    after_build(function (target)
        local full_path = target:targetfile()
        local dir_path = string.gsub(full_path, "(.*[/|\\])(.*)", "%1")
        os.cp("$(projectdir)/*.jpg", dir_path)
    end)
    on_clean(function (target) 
        local full_path = target:targetfile()
        local dir_path = string.gsub(full_path, "(.*[/|\\])(.*)", "%1")
        os.rm(string.format("%s*.jpg", dir_path))
    end)

target("alpha")
    set_kind("binary")
    add_files("alpha_blend.cpp")
    after_build(function (target)
        local full_path = target:targetfile()
        local dir_path = string.gsub(full_path, "(.*[/|\\])(.*)", "%1")
        os.cp("$(projectdir)/*.png", dir_path)
    end)
    on_clean(function (target) 
        local full_path = target:targetfile()
        local dir_path = string.gsub(full_path, "(.*[/|\\])(.*)", "%1")
        os.rm(string.format("%s*.png", dir_path))
    end)