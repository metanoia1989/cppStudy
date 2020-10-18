add_rules("mode.debug", "mode.release")

target("hello")
    set_kind("binary")
    add_cflags("$(shell pkg-config --cflags libnotify)")
    add_ldflags("$(shell pkg-config --libs libnotify)")
    add_files("hello_world_notify.c")