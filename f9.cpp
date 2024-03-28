#include <iostream>
#include <string>
#include <algorithm>

// Function to check if a string is a palindrome
bool isPalindrome(const std::string& str) {
    std::string reversedStr = str;
    std::reverse(reversedStr.begin(), reversedStr.end());
    return str == reversedStr;
}

int main() {
    std::string inputStr;

    // Prompt the user to enter a string
    std::cout << "Enter a string: ";
    std::getline(std::cin, inputStr);

    // Check if the entered string is a palindrome using the isPalindrome function
    if (isPalindrome(inputStr))
        std::cout << "The entered string is a palindrome." << std::endl;
    else
        std::cout << "The entered string is not a palindrome." << std::endl;

    return 0;
}
