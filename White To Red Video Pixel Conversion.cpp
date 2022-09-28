#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    string path = "videos/video_20220926_180519.mp4";
    VideoCapture cap(path);
    Mat currFrame, currWhitePixels;

    cap.read(currFrame);

    while (!currFrame.empty()) {
        inRange(currFrame, Scalar(255, 255, 255), Scalar(255, 255, 255), currWhitePixels);
        currFrame.setTo(Scalar(0, 0, 255), currWhitePixels);
        imshow("Video", currFrame);
        waitKey(10);
        cap.read(currFrame);
    }
    return 0;
}