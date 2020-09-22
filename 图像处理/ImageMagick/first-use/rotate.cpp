#include <iostream>
#include <string>
#include <Magick++.h>

int main(int argc, char const *argv[])
{
    std::cout << "图像旋转测试" << std::endl;
    std::string picPath = "D:/WorkSpace/C++/Image/ImageMagick/first-use/build/pic_009.jpg"; 
    Magick::InitializeMagick(*argv); 
    Magick::Image origin(picPath);

    Magick::Image rotateImg(origin);
    rotateImg.rotate(45);
    rotateImg.write("pic_rotate_45.jpg");
    rotateImg.rotate(45);
    rotateImg.write("pic_rotate_90.jpg");

    return 0;
}
