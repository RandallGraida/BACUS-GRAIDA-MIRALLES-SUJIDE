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
        // Clear the input buffer first
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // User Input with validation for at least 2 sentences
        std::string userPrompt;
        while (true) {
            std::cout << "Please enter at least 2 sentences (must contain at least 2 periods):" << std::endl;
            std::getline(std::cin, userPrompt);

            // Count the number of sentences (periods followed by space or end of string)
            int sentenceCount = 0;
            for (size_t i = 0; i < userPrompt.size(); i++) {
                if (userPrompt[i] == '.' &&
                    (i == userPrompt.size() - 1 || userPrompt[i+1] == ' ' || userPrompt[i+1] == '\t' || userPrompt[i+1] == '\n')) {
                    sentenceCount++;
                }
            }

            if (sentenceCount >= 2) {
                break;
            }
            std::cout << "Error: You must enter at least 2 sentences. Try again.\n" << std::endl;
        }

        // Word count
        int userPromptWordCount = 0;
        std::istringstream stream(userPrompt);
        std::string word;
        while (stream >> word) {
            userPromptWordCount++;
        }

        // Vowel Uppercase (including both lowercase and uppercase vowels)
        for (char &ch : userPrompt) {
            if (tolower(ch) == 'a' || tolower(ch) == 'e' || tolower(ch) == 'i' ||
                tolower(ch) == 'o' || tolower(ch) == 'u') {
                ch = std::toupper(ch);
            }
        }

        // Reverse the string
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
            std::cout << num << " ";
        }
        std::cout << std::endl;

        // Sort the array
        sortArray(arr);
        std::cout << "Sorted array in ascending order: " << std::endl;
        for (int num : arr) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        return 0;
    }

private:
    void reverseArray(std::vector<int>& arr) {
        std::reverse(arr.begin(), arr.end());
    }

    void sortArray(std::vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
    }

    int findLargestNumber(const std::vector<int>& arr) {
        return *std::max_element(arr.begin(), arr.end());
    }
};

int main() {
    std::cout << "Hello BSIT 1-2!" << std::endl;
    std::cout << "" << std::endl;

    std::string choices = "Please enter the number of the choice that you want\n1. String Manipulation\n2. Array\n";
    std::cout << choices << std::endl;

    int choice = 0;
    std::cin >> choice;

    Activity1 func;

    if (choice == 1) {
        func.stringManipulation();
    }
    else if (choice == 2) {
        func.array();
    }
    else {
        std::cout << "Invalid choice!" << std::endl;
    }

    std::cout << "\n" << std::endl;
    return 0;
}
