#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>

int main() {
    // parameters
    int threshold = 20;
    bool nonmaxSuppression = true;
    // Load the image
    const std::string image_path = "../data/img0.png";
    cv::Mat image = cv::imread(image_path, cv::IMREAD_GRAYSCALE);
    if (image.empty()) {
        std::cerr << "Error loading image: " << image_path << std::endl;
        return -1;
    }
    cv::imshow("Original Image", image);
    cv::waitKey(0);
    // Create FAST detector
    auto fast = cv::FastFeatureDetector::create(threshold, nonmaxSuppression);
    // Detect keypoints
    std::vector<cv::KeyPoint> keypoints;
    fast->detect(image, keypoints);

    // Draw and show keypoints
    cv::Mat image_with_keypoints;
    cv::drawKeypoints(image, keypoints, image_with_keypoints);
    cv::imshow("FAST Keypoints", image_with_keypoints);
    cv::waitKey(0);

    return 0;
}
