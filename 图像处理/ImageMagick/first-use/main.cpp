#include <iostream>
#include <Magick++.h>

int main(int argc, char const *argv[])
{
    try {
        Magick::InitializeMagick("F:/Program/msys64/mingw64/lib"); 
        Magick::Image image("D:/WorkSpace/C++/Image/ImageMagick/first-use/build/pic_009.jpg");
        image.display();
        // image.magick("JPEG");
        // image.crop(Magick::Geometry(100, 100, 100, 100));
        // Magick::Image tempImg(image);
        // tempImg.display();
        // image.write("D:/WorkSpace/C++/Image/ImageMagick/first-use/build/logo.png");
    } catch(const Magick::Exception& e) {
        std::cerr << "Caught exception: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
