#include <iostream>
#include <opencv2/opencv.hpp>
#define CVUI_IMPLEMENTATION
#include <src/cvui.h> // import cv gui

std::string WINDOW_NAME = "Camera Thing";
unsigned int cameraDevice = 0;

int main() {
    cv::VideoCapture cap(cameraDevice); // open default video camera

    if(cap.isOpened() == false) {
        std::cout << "cannot open video camera!" << std::endl;
        std::cin.get(); //wait for any key press
        return -1;
    }

    double dWidth = cap.get(cv::CAP_PROP_FRAME_WIDTH);   //get the width of frames of the video
    double dHeight = cap.get(cv::CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

    std::cout << "res of video capture: " << dWidth << " x " << dHeight << std::endl;

    cv::Mat frame = cv::Mat(1000, 1000, CV_8UC3);
    cv::namedWindow(WINDOW_NAME); // create a window called "My Camera Feed"
    cvui::init(WINDOW_NAME);

    // window loop until exited/esc key pressed
    while(true) {
        frame = cv::Scalar(255, 0, 0); // background
        bool bSuccess = cap.read(frame); // read a new frame from capture device

        if(bSuccess == false) { // if capture device dead
            std::cout << "cannot locate video capture device" << std::endl;
            std::cin.get(); // wait till user p*resses key in console
            break;
        }

        // if (cvui::button(frame, 100, 100, "random button"))
        //     std::cout << "yooo" << std::endl;
        // cvui::printf(frame, 100, 100, 0.5, 0xff0000, "random text");

        // show the frame in the created window
        cvui::update();

        cv::imshow(WINDOW_NAME, frame);

        if(cv::waitKey(1) == 27 || cv::getWindowProperty(WINDOW_NAME, cv::WND_PROP_VISIBLE) < 1)
            break;
    }

    return 0;
}