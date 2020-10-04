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


--
-- If you want to known more usage about xmake, please see https://xmake.io
--
-- ## FAQ
-- 
-- You can enter the project directory firstly before building project.
--
--   $ cd projectdir
--
-- 1. How to build project?
--
--   $ xmake
--
-- 2. How to configure project?
--
--   $ xmake f -p [macosx|linux|iphoneos ..] -a [x86_64|i386|arm64 ..] -m [debug|release]
--
-- 3. Where is the build output directory?
--
--   The default output directory is `./build` and you can configure the output directory.
--
--   $ xmake f -o outputdir
--   $ xmake
--
-- 4. How to run and debug target after building project?
--
--   $ xmake run [targetname]
--   $ xmake run -d [targetname]
--
-- 5. How to install target to the system directory or other output directory?
--
--   $ xmake install
--   $ xmake install -o installdir
--
-- 6. Add some frequently-used compilation flags in xmake.lua
--
-- @code
--    -- add debug and release modes
--    add_rules("mode.debug", "mode.release")
--
--    -- add macro defination
--    add_defines("NDEBUG", "_GNU_SOURCE=1")
--
--    -- set warning all as error
--    set_warnings("all", "error")
--
--    -- set language: c99, c++11
--    set_languages("c99", "c++11")
--
--    -- set optimization: none, faster, fastest, smallest
--    set_optimize("fastest")
--
--    -- add include search directories
--    add_includedirs("/usr/include", "/usr/local/include")
--
--    -- add link libraries and search directories
--    add_links("tbox")
--    add_linkdirs("/usr/local/lib", "/usr/lib")
--
--    -- add system link libraries
--    add_syslinks("z", "pthread")
--
--    -- add compilation and link flags
--    add_cxflags("-stdnolib", "-fno-strict-aliasing")
--    add_ldflags("-L/usr/local/lib", "-lpthread", {force = true})
--
-- @endcode
--

