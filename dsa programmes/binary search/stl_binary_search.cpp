#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Create a vector of integers
    std::vector<int> vec = {1, 3, 5, 7, 9};

    // Define the value we want to search for
    int value = 5;

    // Find the index of the value in the vector
    auto it = std::lower_bound(vec.begin(), vec.end(), value);

    // Check if the value is found in the vector
    if (it != vec.end() && *it == value) {//if it not returns the address of n index(as array start with 0 n index dont contain any value of array) and value in it equal to value
        // Compute the index of the found value
        int index = std::distance(vec.begin(), it);

        // Output the index of the found value
        std::cout << "Value " << value << " found at index " << index << "." << std::endl;
    } else {
        // Output a message indicating that the value is not found
        std::cout << "Value " << value << " not found in the vector." << std::endl;
    }

    return 0;
}