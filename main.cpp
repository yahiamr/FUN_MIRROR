#include <opencv2/opencv.hpp>
#include <iostream>
int main() {
        // create video capture object 
        cv::VideoCapture capture(1);

          // Check if the webcam is opened successfully
    if(!capture.isOpened()) {
        std::cerr << "Error: Unable to open the webcam" << std::endl;
        return -1;
    }

    cv::Mat frame;

    // display window 
    cv::namedWindow("Fun_Mirror", cv::WINDOW_AUTOSIZE);

    while(true){
        capture>>frame;

         // Check if the frame is empty
        if(frame.empty()) {
            std::cerr << "Error: Unable to capture the frame" << std::endl;
            break;
        }

        // Display the frame
        cv::imshow("Fun_Mirror", frame);

        // Wait for 1 ms and break the loop if 'Esc' key is pressed
        if(cv::waitKey(1) == 27) {
            break;
        }
    }
      // Release the VideoCapture object
    capture.release();
    // Destroy the window
    cv::destroyWindow("Fun_Mirror");
    return 0;
}