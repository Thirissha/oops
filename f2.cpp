#include <iostream>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main() {
    int n;

    // Prompt the user to enter a number
    std::cout << "Enter a number: ";
    std::cin >> n;

    // Check if the number is prime using the isPrime function
    if (isPrime(n))
        std::cout << n << " is a prime number." << std::endl;
    else
        std::cout << n << " is not a prime number." << std::endl;

    return 0;
}
