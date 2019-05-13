// for recording: https://docs.opencv.org/4.1.0/df/d94/samples_2cpp_2videowriter_basic_8cpp-example.html#a8
// for time https://stackoverflow.com/questions/16693897/record-a-video-in-opencv-only-for-30-secs
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace cv;
using namespace std;

int main(int argc, char**)
{
    Mat src;
    time_t start = time(0);

    // do not use default camera as video source
    VideoCapture cap(1);
    // check if we succeeded
    if (!cap.isOpened()) {
        cerr << "ERROR! Unable to open camera\n";
        return -1;
    }
    // get one frame from camera to know frame size and type
    cap >> src;
    // check if we succeeded
    if (src.empty()) {
        cerr << "ERROR! blank frame grabbed\n";
        return -1;
    }
    bool isColor = (src.type() == CV_8UC3);
    //--- INITIALIZE VIDEOWRITER
    VideoWriter writer;
    int codec = VideoWriter::fourcc('M', 'J', 'P', 'G');  // select desired codec (must be available at runtime)
    double fps = 25.0;                          // framerate of the created video stream
    string filename = "./live.avi";             // name of the output video file
    writer.open(filename, codec, fps, src.size(), isColor);
    // check if we succeeded
    if (!writer.isOpened()) {
        cerr << "Could not open the output video file for write\n";
        return -1;
    }
    //--- GRAB AND WRITE LOOP
    cout << "Writing videofile: " << filename << endl
         << "Press any key to terminate" << endl;



    for (;;)
    {
        // check if we succeeded
        if (!cap.read(src)) {
            cerr << "ERROR! blank frame grabbed\n";
            break;
        }
        // encode the frame into the videofile stream
        writer.write(src);
        // show live and wait for a key with timeout long enough to show images
        imshow("Live", src);
	waitKey(1);
	if ( difftime( time(0), start) >= 46) 
		break;
    }
    // the videofile will be closed and released automatically in VideoWriter destructor




    return 0;



}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////





