WebAssembly 
============

让C++能够在浏览器上运行，Amazing的功能。    

使用 `emascripten` 来编译  https://emscripten.org/index.html        



hello-world运行
---------------

```sh
cd ./hello-world
$ emcc hello_world.c
$ node a.out.js

# 生成 html
$ emcc hello_world.c -o hello.html
$ emcc hello_world_sdl.cpp -o hello-sdl.html

# 文件API
$ emcc hello_world_file.cpp -o hello-file.html --preload-file hello_world_file.txt
```