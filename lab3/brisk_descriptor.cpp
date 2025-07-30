#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>

int main() {

    // Load grayscale image
    const std::string image_path = "img0.png";
    cv::Mat image = cv::imread(image_path, cv::IMREAD_GRAYSCALE);
    if (image.empty()) {
        std::cerr << "Error loading image: " << image_path << std::endl;
        return -1;
    }
    cv::imshow("Original Image", image);
    cv::waitKey(0);
    // Create BRISK detector and descriptor
    cv::Ptr<cv::BRISK> brisk = cv::BRISK::create();
    // Detect keypoints
    std::vector<cv::KeyPoint> keypoints;
    brisk->detect(image, keypoints);

    // Compute descriptors
    cv::Mat descriptors;
    brisk->compute(image, keypoints, descriptors);
    // or in single step detect and describe
    // feature->detectAndCompute(image, cv::noArray(), keypoints, descriptors);

    // Draw and display keypoints
    cv::Mat featureImage;
    cv::drawKeypoints(image, keypoints, featureImage);
    cv::imshow("BRISK Keypoints", featureImage);
    cv::waitKey(0);

    return 0;
}
