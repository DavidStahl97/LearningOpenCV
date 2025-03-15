#include <iostream>
#include <opencv2/opencv.hpp>

#include "Chapter_2.h"

int Example_2_1()
{
    std::string filePath;
    std::cout << "Image file path: ";
    std::cin >> filePath;

    // Read the image using the path provided as an argument
    cv::Mat image = cv::imread(filePath);

    if (image.empty()) // Check if the image was loaded successfully
    {
        std::cerr << "Error: Could not open or find the image! " << filePath << std::endl;
        return -1;
    }

    // Display the image in a window named "OpenCV Test"
    cv::namedWindow("OpenCV Test", cv::WINDOW_AUTOSIZE);
    cv::imshow("OpenCV Test", image);

    // Wait for a key press indefinitely
    cv::waitKey(0);

    return 0;
}