#include <iostream>
#include <map>
#include <string>
#include <functional>
#include <filesystem>

#include "Chapter_2/Chapter_2.h"

#define NAMEOF(name) #name

int main(int argc, char** argv)
{
    std::map<std::string_view, std::function<int()>> functionDictionary = {
        { NAMEOF(Example_2_1), Example_2_1}
    };

    std::filesystem::path currentPath = std::filesystem::current_path();
    std::cout << "Current path is " << currentPath << std::endl << std::endl;

    std::string functionName;
    std::cout << "Enter function: ";
    std::cin >> functionName;

    auto functionPair = functionDictionary.find(functionName);
    if (functionPair == functionDictionary.end()) {
        std::cerr << "Function " << functionName << " was not found" << std::endl;
        return -2;
    }

    std::cout << std::endl << std::endl;

    auto function = functionPair->second;
    int result = function();
    return result;
}