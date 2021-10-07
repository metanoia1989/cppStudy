-- includes("libgraph-easyX")
-- target("sample")
--     set_kind("binary")
--     add_ldflags("-gsource-map")
--     add_files("sample.c")
--     add_deps("libgraph-static")

includes("sdl_bgi")
target("sdi-simple")
    set_kind("binary")
    add_files("sdi-simple.c")
    add_ldflags(
        "-gsource-map", 
        "-s USE_SDL=2",
        "-pthread", 
        "-s USE_PTHREADS=1 -s PTHREAD_POOL_SIZE=4 -s ALLOW_MEMORY_GROWTH=1",
        "-s ASYNCIFY"
    )
    add_deps("libSDL_bgi")