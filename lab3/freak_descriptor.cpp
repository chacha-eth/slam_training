#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>  // Required for FREAK

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

    // Detect keypoints using BRISK
    std::vector<cv::KeyPoint> keypoints;
    cv::Ptr<cv::BRISK> detector = cv::BRISK::create();
    detector->detect(image, keypoints);

    // Compute descriptors using FREAK
    cv::Mat descriptors;
    cv::Ptr<cv::xfeatures2d::FREAK> freak = cv::xfeatures2d::FREAK::create();
    freak->compute(image, keypoints, descriptors);

    // Draw and show keypoints
    cv::Mat featureImage;
    cv::drawKeypoints(image, keypoints, featureImage);
    cv::imshow("FREAK descriptors with BRISK keypoints", featureImage);
    cv::waitKey(0);

    return 0;
}
