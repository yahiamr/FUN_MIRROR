#include <opencv2/opencv.hpp>

int main() {
    cv::Mat image = cv::imread("./image.jpg");
    if (image.empty()) {
        std::cout << "Could not read the image" << std::endl;
        return 1;
    }
    cv::imshow("Image", image);
    cv::waitKey(0);
    return 0;
}