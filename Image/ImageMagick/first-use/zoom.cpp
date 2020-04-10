#include <iostream>
#include <string>
#include <Magick++.h>

int main(int argc, char const *argv[])
{
    std::cout << "图像缩放测试" << std::endl;
    std::string picPath = "D:/WorkSpace/C++/Image/ImageMagick/first-use/build/pic_009.jpg"; 
    Magick::InitializeMagick(*argv); 
    Magick::Image origin(picPath);

    Magick::Image zoomImg(origin);
    size_t width = zoomImg.columns(), height = zoomImg.rows();
    // Magick::Geometry zoomInSize(width * 0.5,  height * 0.5);
    // zoomImg.zoom(zoomInSize);
    zoomImg.zoom("50%");
    zoomImg.write("pic_zoom_0_5.jpg");

    Magick::Geometry zoomOutSize(width * 1.5, height * 1.5);
    zoomImg.zoom(zoomOutSize);
    zoomImg.write("pic_zoom_1_5.jpg");

    return 0;
}
