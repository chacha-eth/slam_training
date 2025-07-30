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

    // Detect keypoints using ORB
    std::vector<cv::KeyPoint> keypoints;
    cv::Ptr<cv::ORB> orb = cv::ORB::create();
    orb->detect(image, keypoints);

    // Compute descriptors using ORB
    cv::Mat descriptors;
    orb->compute(image, keypoints, descriptors);

    // Draw and show keypoints
    cv::Mat featureImage;
    cv::drawKeypoints(image, keypoints, featureImage);
    cv::imshow("ORB descriptors and keypoints", featureImage);
    cv::waitKey(0);

    return 0;
}
