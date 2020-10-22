#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    cout << "help" << endl;
    // Open the default video camera
    VideoCapture cap(0);

    // if not success, exit program
    if (cap.isOpened() == false) {
        cout << "Cannot open the video camera" << endl;
        cin.get(); //wait for any key press
        return -1;
    }

    double dWidth = cap.get(CAP_PROP_FRAME_WIDTH);   //get the width of frames of the video
    double dHeight = cap.get(CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

    cout << "Resolution of the video : " << dWidth << " x " << dHeight << endl;

    string window_name = "My Camera Feed";
    namedWindow(window_name); // create a window called "My Camera Feed"

    while(true) {
        Mat frame;
        bool bSuccess = cap.read(frame); // read a new frame from video

        // Breaking the while loop if the frames cannot be captured
        if (bSuccess == false) {
            cout << "Video camera is disconnected" << endl;
            cin.get(); // Wait for any key press
            break;
        }

        // show the frame in the created window
        imshow(window_name, frame);

        if(waitKey(10) == 27) {
            cout << "Esc key is pressed by user. Stoppig the video" << endl;
            break;
        }
    }

    return 0;
}