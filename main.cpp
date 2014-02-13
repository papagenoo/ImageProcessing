#include <iostream>
#include <Eigen/Dense>

using std::cout;
using std::endl;

using Eigen::Matrix2i;
using Eigen::Matrix2f;
//using namespace std;
//using namespace Eigen;

#include "CImg.h"
using namespace cimg_library;



void squareRGB() {
    const int N = 2;
    float data[] = {
        0,255,0,255,  // Set the 4 values for the red component.
        0,0,255,255,  // Set the 4 values for the green component.
        64,64,64,64   // Set the 4 values for the blue component.
    };

    CImg<float> img(data, /* x dim */ 2, /* y dim */ 2, /* z dim */ 1, /* color dim */ 3);
    img/*.normalize()*/.resize(150.0,150.0).display();
    return;
}

void squareGray() {
    const int N = 2;
    float data[] = {
        0,63,127,255,  // Set the 4 values for the red component.
    };

    CImg<float> img(data, /* x dim */ 2, /* y dim */ 2, /* z dim */ 1, /* color dim */ 1);
    img/*.normalize()*/.resize(150.0,150.0).display();
    return;
}

void square1() {
    CImg<float> img(2,2,1,3,      // Construct a 2x2 color (RGB) image.
                    0,255,0,255,  // Set the 4 values for the red component.
                    0,0,255,255,  // Set the 4 values for the green component.
                    64,64,64,64); // Set the 4 values for the blue component.
    img/*.normalize()*/.resize(150.0,150.0).display();
    return;
}

void synthesize() {
    const int N = 255;
    unsigned char* data = new unsigned char[N*N];
    //*data = '5';
    for (int j = 0; j < N; j++)
        for (int k = 0; k < N; k++) data[(j+1)*(k+1)-1] = 255;//j*k;
    //  cout << ":::" << static_cast<unsigned>(*(data+1)) << endl;
    //cout << ":::" << static_cast<unsigned>(data[1]) << endl;

    CImg<unsigned char> img(data, N, N);
    //cimg_for(img, ptr, unsigned char) { *ptr=128; };

    //   CImg<float> img(2,2,1,3,      // Construct a 2x2 color (RGB) image.
    //                        0,255,0,255,  // Set the 4 values for the red component.
    //                        0,0,255,255,  // Set the 4 values for the green component.
    //                        64,64,64,64); // Set the 4 values for the blue component.
    img/*.normalize()*//*.resize(150.0,150.0)*/.display();
    return;
}

//void showimg() {
//    CImg<unsigned char> image("/Users/max/QtCppProj/lena.jpg"), visu(500,400,1,3,0);
//    const unsigned char red[] = { 255,0,0 }, green[] = { 0,255,0 }, blue[] = { 0,0,255 };
//    image.blur(2.5);

//    const int N = 255;
//    unsigned char* data = new unsigned char[N*N];
//    //*data = '5';
//    for (int j = 0; j < N; j++)
//        for (int k = 0; k < N; k++) data[(j+1)*(k+1)-1] = 255;//j*k;
//    //  cout << ":::" << static_cast<unsigned>(*(data+1)) << endl;
//    //cout << ":::" << static_cast<unsigned>(data[1]) << endl;

//    CImg<unsigned char> img(data, N, N);
//    //cimg_for(img, ptr, unsigned char) { *ptr=128; };

//    //   CImg<float> img(2,2,1,3,      // Construct a 2x2 color (RGB) image.
//    //                        0,255,0,255,  // Set the 4 values for the red component.
//    //                        0,0,255,255,  // Set the 4 values for the green component.
//    //                        64,64,64,64); // Set the 4 values for the blue component.
//    img/*.normalize()*//*.resize(150.0,150.0)*/.display();
//    return;
//    CImgDisplay main_disp(img,"Click a point"), draw_disp(visu,"Intensity profile");

//    while (!main_disp.is_closed() && !draw_disp.is_closed()) {
//        main_disp.wait();
//        if (main_disp.button() && main_disp.mouse_y()>=0) {
//            const int y = main_disp.mouse_y();
//            visu.fill(0).draw_graph(image.get_crop(0,y,0,0,image.width()-1,y,0,0),red,1,1,0,255,0);
//            visu.draw_graph(image.get_crop(0,y,0,1,image.width()-1,y,0,1),green,1,1,0,255,0);
//            visu.draw_graph(image.get_crop(0,y,0,2,image.width()-1,y,0,2),blue,1,1,0,255,0).display(draw_disp);
//        }
//    }
//}

void pointerToPixel()
{
    CImg<unsigned char> src("image.jpg");
    int width = src.width();
    int height = src.height();
    unsigned char* ptr = src.data(10,10); // get pointer to pixel @ 10,10
    unsigned char pixel = *ptr;
}

void rgbComponents(CImg<unsigned char> src)
{
    unsigned char *r = src.data(10, 10, 0, 0);
    unsigned char *g = src.data(10, 10, 0, 1);
    unsigned char *b = src.data(10, 10, 0, 2);

    // operator()
    unsigned char r2 = src(10, 10, 0, 0);
}

void pixelMatrixToImage()
{
    Matrix2f pixels;
    pixels << 255, 63,
              127, 255;

    float *data = pixels.data();

    CImg<float> img(data, /* x dim */ 2, /* y dim */ 2, /* z dim */ 1, /* color dim */ 1);
    img/*.normalize()*/.resize(150.0,150.0).display();
}

int main()
{
    // http://gb01.blogspot.ru/2007/09/cimgh-on-mac-os-x.html
    cimg::imagemagick_path("/usr/local/bin/convert");
    // cimg::imagemagick_path("/opt/local/bin/convert");

    //squareGray();
    //synthesize();
    pixelMatrixToImage();

//    showimg();
//    cout << "!" << endl;
//    return 0;

    //    Matrix2i m();
    //    cout << "Hello World!" << m << endl;
    //    int i;
    //    cin >> i;
    //    cout << "i = " << i << endl;
    //    return 0;
}

