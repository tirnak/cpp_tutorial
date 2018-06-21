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

    namedWindow("output", CV_WINDOW_AUTOSIZE);
    for (const auto& img : {blue, green, red, blueCopy})
    {
        imshow("output", img);
        waitKey();
    }

    Mat hsvMat;
    cvtColor(newImage, hsvMat, COLOR_BGR2HSV);

    // regular iteration, changing values in HSV colour space
    for (int i = 0; i < newImage.rows; ++i)
    {
    	for (int j = 0; j < newImage.cols; ++j)
    	{
    		hsvMat.at<Vec3b>(i,j)[0] =
    				UCHAR_MAX / newImage.cols * j +
    				UCHAR_MAX / newImage.rows * i;
    	}
    }

    imshow("output", hsvMat);
	waitKey();

	Mat detect;

	cvtColor(newImage, detect, COLOR_BGR2GRAY);
    imshow("output", detect);
	waitKey();

	blur( detect, detect, Size(3,3) );
    imshow("output", detect);
	waitKey();

	Canny( detect, detect, 50, 150);
    imshow("output", detect);
	waitKey();

	// affine
    // getAffineTransform accepts only Point2f
    Point2f srcTri[3];
    srcTri[0] = Point2f( 0.f, 0.f );
    srcTri[1] = Point2f( newImage.cols - 1.f, 0.f );
    srcTri[2] = Point2f( 0.f, newImage.rows - 1.f );
    Point2f dstTri[3];
    dstTri[0] = Point2f( 0.f, newImage.rows*0.33f );
    dstTri[1] = Point2f( newImage.cols*0.85f, newImage.rows*0.25f );
    dstTri[2] = Point2f( newImage.cols*0.15f, newImage.rows*0.7f );

    Mat warpMat = getAffineTransform( srcTri, dstTri );

    Mat warpDst(newImage.size(), newImage.type(), Scalar(0,0,0));

    warpAffine( newImage, warpDst, warpMat, warpDst.size() );

    imshow("output", warpDst);
	waitKey();

    return 0;
}
