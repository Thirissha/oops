#include <iostream>

// Function to find the minimum and maximum elements in an array
void findMinMax(const int arr[], int size, int& min, int& max) {
    if (size == 0) {
        std::cerr << "Error: Array is empty." << std::endl;
        return;
    }

    min = max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
}

int main() {
    int size;
    int min, max;

    // Prompt the user to enter the size of the array
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    // Create an array of the given size
    int* arr = new int[size];

    // Prompt the user to enter the elements of the array
    std::cout << "Enter " << size << " integers separated by space:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    // Find the minimum and maximum elements in the array using the findMinMax function
    findMinMax(arr, size, min, max);

    // Display the minimum and maximum elements
    std::cout << "Minimum element: " << min << std::endl;
    std::cout << "Maximum element: " << max << std::endl;

    // Free the dynamically allocated memory
    delete[] arr;

    return 0;
}

