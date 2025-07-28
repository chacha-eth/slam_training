#include <iostream>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>

int main()
{
    // parameters
   int numfeatures=1000;
    // Load image
    std::string image_path = "../data/img0.png";
    cv::Mat image = cv::imread(image_path, cv::IMREAD_GRAYSCALE);
    if (image.empty())
    {
        std::cerr << "Error loading image: " << image_path << std::endl;
        return -1;
    }
    cv::imshow("Original Image", image);
    cv::waitKey(0);
    // Create ORB detector
    cv::Ptr<cv::ORB> orb = cv::ORB::create(numfeatures);
    // Detect keypoints
    std::vector<cv::KeyPoint> keypoints;
    orb->detect(image, keypoints);

    // Draw keypoints
    cv::Mat image_keypoints;
    cv::drawKeypoints(image, keypoints, image_keypoints, cv::Scalar::all(-1), cv::DrawMatchesFlags::DEFAULT);

    // Show result
    cv::imshow("ORB Keypoints", image_keypoints);
    cv::waitKey(0);

    return 0;
}
