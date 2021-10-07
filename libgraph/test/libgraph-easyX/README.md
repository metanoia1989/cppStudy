# libgraph easyX 

使用的是 [Lib Graphics -- Turbo C's graphics.h in Linux](https://github.com/Prashant47/libgraph)

我想在 web 上展现，需要进行 Emscripten 移植 ，所以要去除调不必要的文件，然后写 CMakeLists.txt 来编译成静态库，并且方便引用。   

原来的 Makefile 文件里有定义 `FONTDIR` 常量，原来颜色都是写在图片里的，我也是晕倒了，后续需要弄成RGB的格式。
```makefile
libgraphdir = $(pkgdatadir)
libgraphfontdir = $(libgraphdir)/Font
$(CFLAGS) -DFONTDIR=\""$(libgraphfontdir)/"\"
include_HEADERS = graphics.h shapes.h grtext.h polygon.h
libgraph_la_SOURCES = libgraph.c text.c shapes.c polygon.c
```

现有的文件内容   
------------
	In this package are : 
	
	graphics.h : the default header that includes all the others required 
		     so that you don't have to do anything differently.
	libgraph.c : the code for functions in graphics.h. These are mainly
		     the basic settings and initialization functions.
	
	grtext.h : the functions for text manipulation -- This basic part 
		   of this code has been borrowed from Karl Bartel's 
		   <karlb@gmx.net> SFont library. We extended it to fit 
		   our needs. 
	text.c : code for functions in grtext.h

	shapes.h : functions for drawing various shapes, filling and positioning. 
	shapes.c : Code for the above definitions.

	polygon.h : functions for drawing and filling polygons.
	polygon.c :  Code for above functions. These two functions were made
			into a separate module because the code for fillpoly() is pretty
			healthy all by itself and requires quite a few book-keeping 
			trivial functions.
	
	Makefile : We don't know how to write Makefiles. This one has been 
		   hacked up from someone else software. If u know more than us
		   on the subject please oblige by writing a custom Makefile
		   for the package.
	
	README : That's what you are reading.
	
	grc : a no-brainer script to compile libgraph programs.
	
	./Font : Directory containing font(.png) files. There are a number of different
		 	colors but of the same font. Default font is white. Font-color 
		 	selection is still to be implemented. You can change the color by
		 	changing the FONT definition in graphics.h to a different color file
		 	and recompiling the library.
	
	 sample.c : small sample file to try out the library.
		 	Just compile with
	   			$ ./grc sample
			and execute with
				$ ./sample
