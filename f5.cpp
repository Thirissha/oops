#include <iostream>

// Function to find the greatest common divisor (GCD) using the Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;

    // Prompt the user to enter two numbers
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    // Find the GCD of the two numbers using the gcd function
    int result = gcd(num1, num2);

    // Display the GCD
    std::cout << "GCD of " << num1 << " and " << num2 << " is: " << result << std::endl;

    return 0;
}
