#include <opencv2/viz/vizcore.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/**
* @function main
*/
int main(int argc, char** argv )
{

	// read cloud
    Mat cloud = viz::readCloud(argv[1]);

    // fill with random colours
    Mat colors(cloud.size(), CV_8UC3);
    theRNG().fill(colors, RNG::UNIFORM, 50, 255);

    // Create a window
	viz::Viz3d myWindow("Coordinate Frame");

	// Add coordinate axes
	myWindow.showWidget("Coordinate Widget", viz::WCoordinateSystem());

	// Add line to represent (1,1,1) axis
	viz::WLine axis(Point3f(-1.0f,-1.0f,-1.0f), Point3f(1.0f,1.0f,1.0f));
	axis.setRenderingProperty(viz::LINE_WIDTH, 2.0);

	myWindow.showWidget("Line Widget", axis);
	myWindow.showWidget("Cloud Widget", viz::WCloud(cloud, colors));

	// Rodrigues vector
	Mat rot_vec = Mat::zeros(1,3,CV_32F);
	float translation_phase = 0.0, translation = 0.0;
	while(!myWindow.wasStopped())
	{
		/* Rotation using Rodrigues */
		// Rotate around (1,1,1)
		rot_vec.at<float>(0,0) += CV_PI * 0.01f;
		rot_vec.at<float>(0,1) += CV_PI * 0.01f;
		rot_vec.at<float>(0,2) += CV_PI * 0.01f;
		// Shift on (1,1,1)
		translation_phase += CV_PI * 0.01f;
		translation = sin(translation_phase);

		Mat rot_mat;
		Rodrigues(rot_vec, rot_mat);

		// Construct pose
		Affine3f pose(rot_mat, Vec3f(translation, translation, translation));
		myWindow.setWidgetPose("Cloud Widget", pose);
		myWindow.spinOnce(1, true);
	}

    return 0;
}
