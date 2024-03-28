#include <iostream>
#include <string>

// Function to count the number of elements in a string
int countElements(const std::string& str) {
    return str.length(); // Length of the string gives the number of elements
}

int main() {
    std::string inputStr;

    // Prompt the user to enter a string
    std::cout << "Enter a string: ";
    std::getline(std::cin, inputStr);

    // Count the number of elements in the string using the countElements function
    int count = countElements(inputStr);

    // Display the count
    std::cout << "Number of elements in the string: " << count << std::endl;

    return 0;
}
