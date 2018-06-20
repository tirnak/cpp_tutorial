// simple.cpp
#include <vector>
#include <stdio.h>
#include <opencv2/opencv.hpp>

/**
 *
    CV_8U  - 8-bit unsigned integers ( 0..255 )
    CV_8S  - 8-bit signed integers ( -128..127 )
    CV_16U - 16-bit unsigned integers ( 0..65535 )
    CV_16S - 16-bit signed integers ( -32768..32767 )
    CV_32S - 32-bit signed integers ( -2147483648..2147483647 )
    CV_32F - 32-bit floating-point numbers ( -FLT_MAX..FLT_MAX, INF, NAN )
    CV_64F - 64-bit floating-point numbers ( -DBL_MAX..DBL_MAX, INF, NAN )
 */

using namespace cv;
using namespace std;
int main(int argc, char** argv )
{

    Mat newImage = imread(argv[1]);

    // create matrix per channel
    Mat blue  = Mat(newImage.size(), newImage.type(), Scalar(0, 0, 0));
    // internally data is stored as a shared pointer
    Mat blueCopy(blue);
    Mat green = blue.clone();
    Mat red   = green.clone();

    int elemSize = newImage.elemSize();

    // get the pointer to the beginning of internal data
    Vec3b* blueStart  = blue.ptr<Vec3b>(0);
    Vec3b* greenStart = green.ptr<Vec3b>(0);
    Vec3b* redStart   = red.ptr<Vec3b>(0);
    Vec3b* origStart  = newImage.ptr<Vec3b>(0);

    // internally, Mat is stored as 1dim array
    for (long i = 0; i < newImage.total(); ++i)
    {
    	Vec3b* origShifted = origStart + i;
    	(*(blueStart  + i))[0] = (*origShifted)[0];
    	(*(greenStart + i))[1] = (*origShifted)[1];
    	(*(redStart   + i))[2] = (*origShifted)[2];
    }

    namedWindow("channel", CV_WINDOW_AUTOSIZE);
    for (const auto& img : {blue, green, red, blueCopy})
    {
        imshow("channel", img);
        waitKey();
    }

    return 0;
}
