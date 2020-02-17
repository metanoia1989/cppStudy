cmake_minimum_required(VERSION 2.8)
project(foo NONE)

set(abc "")

function(scope_2)
    message("Scope 2 (before): '${abc}'")
    set(abc "789" PARENT_SCOPE)
    message("Scope 2 (after): '${abc}'")
endfunction()

function(scope_1)
    message("Scope 1 (before): '${abc}'")
    scope_2()
    message("Scope 1 (after): '${abc}'")
endfunction()

message("Top level (before): '${abc}'")
scope_1()
message("Top level (after): '${abc}'")