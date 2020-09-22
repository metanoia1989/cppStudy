#include <iostream>
#include <string>
#include <Magick++.h>

int main(int argc, char const *argv[])
{
    std::cout << "图像合并测试" << std::endl;
    Magick::InitializeMagick(*argv); 
    std::string picPath = "D:/WorkSpace/C++/Image/ImageMagick/first-use/build/pic_009.jpg"; 
    Magick::Image origin(picPath);
    Magick::Image supportImg(origin);
    picPath = "D:/WorkSpace/C++/Image/ImageMagick/first-use/build/icon.png"; 
    Magick::Image overlay(picPath);

    size_t width = origin.columns(), height = origin.rows(); 
    size_t x =  width - overlay.columns() - 10;
    size_t y =  height - overlay.rows() - 10;

    // OverCompostiteOp 图上加图 添加水印的操作
    supportImg.composite(overlay, x, y, Magick::OverCompositeOp);
    supportImg.write("pic_composite_over.jpg");

    supportImg = Magick::Image(origin);
    supportImg.composite(overlay, "+10+10", Magick::OverCompositeOp);
    supportImg.write("pic_composite_over2.jpg");

    // OutCompositeOp 
    supportImg = Magick::Image(origin);
    supportImg.composite(overlay, x, y, Magick::OutCompositeOp);
    supportImg.write("pic_composite_out.jpg");

    supportImg = Magick::Image(origin);
    supportImg.composite(overlay, x, y, Magick::InCompositeOp);
    supportImg.write("pic_composite_in.jpg");

    return 0;
}
