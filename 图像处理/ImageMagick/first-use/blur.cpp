#include <iostream>
#include <string>
#include <Magick++.h>

int main(int argc, char const *argv[])
{
    std::cout << "图像模糊测试" << std::endl;
    std::string picPath = "D:/WorkSpace/C++/Image/ImageMagick/first-use/build/pic_009.jpg"; 
    Magick::InitializeMagick(*argv); 
    Magick::Image origin(picPath);

    Magick::Image blurImg(origin);
    blurImg.blur(6, 1.0);
    blurImg.write("pic_blur_6_1.jpg");
    Magick::Image blurImg2(origin);
    blurImg2.blur(6, 1.5);
    blurImg2.write("pic_blur_6_15.jpg");

    return 0;
}
