#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <limits>

class Activity1
{
public:
  int stringManipulation() {
    // User Input
    std::string userPrompt;
    std::cout << "Please enter at least 2 sentences:" << std::endl;
    std::cin >> userPrompt;
    std::getline(std::cin, userPrompt);

    if (userPrompt.empty()) {
      std::cout << "Error: Input cannot be empty. Please try again." << std::endl;
      return 1;
    }

    // Word count ito
    int userPromptWordCount = 1;
    std::istringstream stream(userPrompt);
    std::string word;
    while (stream >> word) {
      userPromptWordCount++;
    }

    // Vowel Uppercase
    for (char &ch : userPrompt) {
      if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
        ch = std::toupper(ch);
      }
    }

    // Ibabaliktad niya ito
    std::reverse(userPrompt.begin(), userPrompt.end());

    std::cout << "Modified text: " << userPrompt << std::endl;
    std::cout << "Word count: " << userPromptWordCount << std::endl;

    return 0;
  }

  int array() {
    int size;
        
    std::cout << "Enter the size of the array (greater than 0): " << std::endl;
    std::cin >> size;

    if (size < 1) {
        std::cout << "Error: Array size must be at least 1.\n" << std::endl;
        return 1;
    }

    std::vector<int> arr(size);
    std::cout << "Enter " << size << " elements for the array: " << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    // Find largest number
    int largest = findLargestNumber(arr);
    std::cout << "Largest number in the array: " << largest << std::endl;

    // Reverse the array
    reverseArray(arr);
    std::cout << "Reversed array: " << std::endl;
    for (int num : arr) {
        std::cout << num << " " << std::endl;
    }
    std::cout << std::endl;

    // Sort the array
    sortArray(arr);
    std::cout << "Sorted array in ascending order: " << std::endl;
    for (int num : arr) {
        std::cout << num << " " << std::endl;
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

// Closing brace for Activity1 class
};

int main() {
    std::cout << "Hello BSIT 1-2!" << std::endl;
    std::cout << "" << std::endl;

    std::string choices = "Please enter the number the choice that you want\n 1. String Manipulation \n 2. Array";
    std::cout << choices << std::endl;

    int choice = 0;
    std::cin >> choice;

    Activity1 func;

    if (choice == 1){
      std::cout << func.stringManipulation() << std::endl;
    } 
    if (choice == 2){
      std::cout << func.array() << std::endl;
    }

    std::cout << "\n" << std::endl;
    return 0;
}