#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>

int main() {
    int num_features=1000;
    // Load a single image
    const std::string image_path = "../data/img0.png";
    cv::Mat image = cv::imread(image_path, cv::IMREAD_GRAYSCALE);
    if (image.empty()) {
        std::cerr << "Error loading image: " << image_path << std::endl;
        return -1;
    }

    cv::imshow("Original Image", image);
    cv::waitKey(0);

    // Create SIFT detector
    auto sift = cv::SIFT::create(num_features);

    // Detect keypoints 
    std::vector<cv::KeyPoint> keypoints;
    sift->detect(image, keypoints);

    // Draw and display keypoints
    cv::Mat image_with_keypoints;
    cv::drawKeypoints(image, keypoints, image_with_keypoints);
    cv::imshow("SIFT Keypoints", image_with_keypoints);
    cv::waitKey(0);

    return 0;
}
