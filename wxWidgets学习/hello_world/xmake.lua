-- add rules: debug/release
add_rules("mode.debug", "mode.release")

-- define target
target("hello_world")
    set_languages("c11", "c++17")
    -- set kind
    set_kind("binary")
    set_toolset("cc", "gcc")
    set_toolset("cxx", "g++")
    set_toolset("ld", "g++")
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
    -- add files
    add_files("hello_world.cpp")

