# easyX 库使用
这个项目是使用easyX库的例子。easyX库依赖msvc编译链，并且只提供msvc编译好的`.lib`静态库文件。        
vistual studio太笨重了，我不想用。使用msvc+xmake进行编译，配置好了include和linkdir，就开始编译。        
期间有不少`.lib`没有手动链接导致编译失败，根据错误信息网上搜一个个找到要链接的静态库名字，编译通过。    
跑另外一个例子时，又出现函数重复定义，发现不能使用 `EasyXw` 这个unicode版本的，而要使用 `EasyXa`版本的。    

编译这个easyX必须要msvc编译器，刚才犯傻配置了 `xmake f -p mingw` =_= 编译了半天，最后还爆粗。   
