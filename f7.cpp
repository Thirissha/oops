#include <iostream>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

int main() {
    double celsius, fahrenheit;

    // Prompt the user to enter temperature in Celsius
    std::cout << "Enter temperature in Celsius: ";
    std::cin >> celsius;

    // Convert Celsius to Fahrenheit using the celsiusToFahrenheit function
    fahrenheit = celsiusToFahrenheit(celsius);

    // Display the result
    std::cout << "Temperature in Fahrenheit: " << fahrenheit << std::endl;

    // Prompt the user to enter temperature in Fahrenheit
    std::cout << "Enter temperature in Fahrenheit: ";
    std::cin >> fahrenheit;

    // Convert Fahrenheit to Celsius using the fahrenheitToCelsius function
    celsius = fahrenheitToCelsius(fahrenheit);

    // Display the result
    std::cout << "Temperature in Celsius: " << celsius << std::endl;

    return 0;
}
