target('libSDL_bgi')
    set_kind("static")
    add_headerfiles("graphics.h","SDL_bgi.h", "fonts/*.h") 
    add_includedirs(".", {interface = true})
    add_cxflags("-lDSL2", "-s USE_SDL=2")
    add_files("SDL_bgi.c")