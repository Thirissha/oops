#include <iostream>

// Function to calculate the area of a circle
double calculateCircleArea(double radius) {
    const double pi = 3.14159;
    return pi * radius * radius;
}

int main() {
    double radius;

    // Prompt the user to enter the radius of the circle
    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;

    // Calculate the area of the circle using the calculateCircleArea function
    double area = calculateCircleArea(radius);

    // Display the result
    std::cout << "Area of the circle: " << area << std::endl;

    return 0;
}
