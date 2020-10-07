cmake_minimum_required(VERSION 2.8)
project(foo NONE)

set("abc" "123")
set("ab c" "456")
set("ab?c" "789")
set("/user/bin/bash" "987")
set("c:\\Program Files\\" "654")

function(print_name varname)
    message("Variable name: '${varname}', value: '${${varname}}'") 
endfunction()

print_name("abc")
print_name("ab c")
print_name("ab?c")
print_name("/user/bin/bash")
print_name("C:\\Program Files\\")
print_name(" ")
