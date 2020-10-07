add_rules("mode.debug", "mode.release")

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
