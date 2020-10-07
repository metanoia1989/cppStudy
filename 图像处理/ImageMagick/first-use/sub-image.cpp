#include <iostream>
#include <string>
#include <Magick++.h>

int main(int argc, char const *argv[])
{
    std::cout << "图像提取测试" << std::endl;
    std::string picPath = "D:/WorkSpace/C++/Image/ImageMagick/first-use/build/pic_009.jpg"; 
    Magick::InitializeMagick(*argv); 
    Magick::Image origin(picPath);

    size_t width = origin.columns(), height = origin.rows();

    Magick::Image chopImg(origin);
    chopImg.chop(Magick::Geometry(100, 100));
    chopImg.write("pic_chop_100_100.jpg");

    Magick::Image cropImg(origin);
    cropImg.crop(Magick::Geometry(100, 100));
    cropImg.write("pic_crop_100_100.jpg");

    return 0;
}
