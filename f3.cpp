#include <iostream>
#include <string>

// Function to reverse a string
std::string reverseString(const std::string& str) {
    std::string reversedStr;
    for (int i = str.length() - 1; i >= 0; --i) {
        reversedStr.push_back(str[i]);
    }
    return reversedStr;
}

int main() {
    std::string inputStr;

    // Prompt the user to enter a string
    std::cout << "Enter a string: ";
    std::getline(std::cin, inputStr);

    // Find the reverse of the string using the reverseString function
    std::string reversedStr = reverseString(inputStr);

    // Display the reversed string
    std::cout << "Reverse of the string: " << reversedStr << std::endl;

    return 0;
}
