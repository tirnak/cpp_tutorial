// process.cpp
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "get_time.cpp"

using namespace cv;
int main(int argc, char** argv )
{
    if ( argc != 2 )
    {
        printf("usage: process <Image_Path>\n");
        return -1;
    }
    Mat image;
    image = imread( argv[1] );
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }

    Mat newImage(image.rows, image.cols, CV_8UC3, Scalar(0, 0, 0));

    long t1 = getMs();
    std::cout << t1 << std::endl;

    int i,j;
    for( i = 0; i < image.cols; ++i)
    {
        for ( j = 0; j < image.rows; ++j)
        {
            Vec3b color = image.at<Vec3b>(j,i);
            newImage.at<Vec3b>(j,i) = color;
        }
    }

    long t2 = getMs();
    std::cout << t2 << std::endl;
    std::cout << t2 - t1 << std::endl;

    imwrite( "converted.png", newImage );
    return 0;
}
