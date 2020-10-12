# easyX 库使用
这个项目是使用easyX库的例子。easyX库依赖msvc编译链，并且只提供msvc编译好的`.lib`静态库文件。        
vistual studio太笨重了，我不想用。使用msvc+xmake进行编译，配置好了include和linkdir，就开始编译。        
期间有不少`.lib`没有手动链接导致编译失败，根据错误信息网上搜一个个找到要链接的静态库名字，编译通过。    
跑另外一个例子时，又出现函数重复定义，发现不能使用 `EasyXw` 这个unicode版本的，而要使用 `EasyXa`版本的。    

引用 graphics.h 头文件就可以使用 easyX 图形库了。   

编译这个easyX必须要msvc编译器，刚才犯傻配置了 `xmake f -p mingw` =_= 编译了半天，最后还报错。   

[初始化函数]        
initgraph(width, height)        
closegraph()        

[常用的绘图语句]
* line(x1, y1, x2, y2); // 画直线 (x1,y1)-(x2,y2)，都是整形
* circle(x, y, r); // 画圆，圆心为 (x,y)，半径为 r
* putpixel(x, y, c); // 画点 (x,y)，颜色 c

还有很多，如画椭圆、圆弧、矩形、多边形，等等        
* arc(left, top, right, bottom ,stangle, endangle)
* ellipse(left, top, right, bottom)
* rectangle(left, top, right, bottom)
* polygon(points, num) // 坐标数组为 points, 顶点个数为num

[设置颜色]      
setlinecolor(c);    // 设置画线颜色，如 setlinecolor(RED) 设置画线颜色为红色        
* BLACK 黑　　　　DARKGRAY 深灰
* BLUE 蓝　　　　　LIGHTBLUE 亮蓝
* GREEN 绿　　　　LIGHTGREEN 亮绿
* CYAN 青　　　　　LIGHTCYAN 亮青
* RED   红　　　　　LIGHTRED   亮红
* MAGENTA 紫　　　LIGHTMAGENTA   亮紫
* BROWN 棕 　　　YELLOW 黄
* LIGHTGRAY 浅灰　WHITE 白

setcolor(c) // 设置当前绘图前景色       

[配出更多的颜色]        
颜色除了前面写的 16 种以外，还可以自由配色。格式：RGB(r, g, b)      
r / g / b 分别表示红色、绿色、蓝色，范围都是 0~255。例如，RGB(255,0,0) 表示纯红色。     
红色和绿色配成黄色，因此 RGB(255, 255, 0) 表示黄色。        
嫌调色麻烦可以用画笔里面的调色试试，调好了以后直接将数值抄过来就行。        

[用数字表示颜色]        
除了用 RGB(r,g,b) 方式外，还可以用16进制表示颜色，格式：0xbbggrr        
例如，setlinecolor(0x0000ff) 和 setlinecolor(RGB(255, 0, 0)) 是等效的。     

[延时语句]  
这个很简单，Sleep(n) 就可以表示 n 毫秒的延时。例如延时 3 秒，可以用 Sleep(3000);        