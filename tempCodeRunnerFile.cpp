std::cout << "Enter the size of the array (greater than 0): ";
    std::cin >> size;

    if (size < 1) {
        std::cout << "Error: Array size must be at least 1.\n";
        return 1;
    }

    std::vector<int> arr(size);
    std::cout << "Enter " << size << " elements for the array: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    // Find largest number
    int largest = findLargestNumber(arr);
    std::cout << "Largest number in the array: " << largest << std::endl;

    // Reverse the array
    reverseArray(arr);
    std::cout << "Reversed array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Sort the array
    sortArray(arr);
    std::cout << "Sorted array in ascending order: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

void reverseArray(std::vector<int>& arr) {
    std::reverse(arr.begin(), arr.end());
}

void sortArray(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end());
}

int findLargestNumber(const std::vector<int>& arr) {
    return *std::max_element(arr.begin(), arr.end());
}
