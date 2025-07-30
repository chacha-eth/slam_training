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

    //  Detect keypoints using SIFT
    std::vector<cv::KeyPoint> keypoints;
    cv::Ptr<cv::SIFT> sift = cv::SIFT::create();
    sift->detect(image, keypoints);

    //  Compute descriptors using SIFT
    cv::Mat descriptors;
    sift->compute(image, keypoints, descriptors);

    // Draw and show keypoints
    cv::Mat featureImage;
    cv::drawKeypoints(image, keypoints, featureImage);
    cv::imshow("SIFT descriptors and keypoints", featureImage);
    cv::waitKey(0);

    return 0;
}
