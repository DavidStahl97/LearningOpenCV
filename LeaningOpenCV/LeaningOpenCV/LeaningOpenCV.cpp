#include <filesystem>
#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv)
{
    if (argc < 2) // Check if an argument is provided
    {
        std::cerr << "Usage: " << argv[0] << " <path_to_image>" << std::endl;
        return -1;
    }

    std::filesystem::path currentPath = std::filesystem::current_path();
    std::cout << "Current path is " << currentPath << std::endl << std::endl;

    // Read the image using the path provided as an argument
    cv::Mat image = cv::imread("C:/Users/de18702/tet.png");

    if (image.empty()) // Check if the image was loaded successfully
    {
        std::cerr << "Error: Could not open or find the image! " << argv[1] << std::endl;
        return -1;
    }

    // Display the image in a window named "OpenCV Test"
    cv::namedWindow("OpenCV Test", cv::WINDOW_AUTOSIZE);
    cv::imshow("OpenCV Test", image);

    // Wait for a key press indefinitely
    cv::waitKey(0);

    return 0;
}