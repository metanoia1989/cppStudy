cmake_minimum_required(VERSION 2.8)
project(foo NONE)

function(foo)
    message("[foo]: Scope for function 'foo' copied from parent 'boo': { abc = '${abc}', xyz = '${xyz}' }")
    unset(abc)
    message("[foo]: Command 'unset(abc)' will remove variable from current scope: { abc = '${abc}', xyz = '${xyz}' }")
endfunction()

function(boo)
    message("[boo]: Scope for function 'boo' copied from parent: { abc = '${abc}', xyz = '${xyz}' }")
    set(abc "789")
    message("[boo]: Command 'set(abc ...)' modify current scope: { abc = '${abc}', xyz = '${xyz}' }")
    foo()
endfunction()

set(abc "123")
set(xyz "456")

message("Top level scope state: { abc = '${abc}', xyz = '${xyz}'}")

boo()

message("Top level scope state after: { abc = '${abc}', xyz = '${xyz}'}")