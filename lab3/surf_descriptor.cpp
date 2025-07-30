#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>  // Required for SURF

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

    // Detect keypoints using SURF
    std::vector<cv::KeyPoint> keypoints;
    // 400 is hessian threshold
    cv::Ptr<cv::xfeatures2d::SURF> surf = cv::xfeatures2d::SURF::create(); 
    surf->detect(image, keypoints);

    // Compute descriptors using SURF
    cv::Mat descriptors;
    surf->compute(image, keypoints, descriptors);

    // Draw and show keypoints
    cv::Mat featureImage;
    cv::drawKeypoints(image, keypoints, featureImage);
    cv::imshow("SURF descriptors and keypoints", featureImage);
    cv::waitKey(0);

    return 0;
}
