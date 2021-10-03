# libgraph - Turbo C graphics.h in Linux

#  Linux 上使用libgraph

这个库的版本太久了，Ubuntu21.04已经无法编译通过了，只能使用docker了。
```sh
$ docker build -t libgraph .
$ docker run -d -t -v $(pwd):/easyX --name easyX libgraph
$ docker exec -it easyX /bin/bash
$ gcc -o test test.c -lgraph
```

上面的试了试，因为没有装xOrg，显示效果特别的差，还是要真机编译。
```sh
# Ubuntu 21.04
$ sudo apt-get update 
$ sudo apt-get install libsdl-image1.2 libsdl-image1.2-dev guile-2.2 guile-2.2-dev 
$ wget http://download.savannah.gnu.org/releases/libgraph/libgraph-1.0.2.tar.gz
$ tar -xzvf libgraph-1.0.2.tar.gz
$ cd ...
$ CPPFLAGS="$CPPFLAGS $(pkg-config --cflags-only-I guile-2.2) -fcommon" \
CFLAGS="$CFLAGS $(pkg-config --cflags-only-other guile-2.2) -fcommon" \
LDFLAGS="$LDFLAGS $(pkg-config --libs guile-2.2)" \
./configure 
$ make && sudo make install
$ sudo cp /usr/local/lib/libgraph.* /usr/lib 
```
