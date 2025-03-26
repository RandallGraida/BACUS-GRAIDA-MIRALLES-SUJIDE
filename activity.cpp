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
  int activity1() {
    std::string userPrompt;
    std::cout << "Please enter at least 2 sentences:" << std::endl;
    std::getline(std::cin, userPrompt);

    // Word count
    int userPromptWordCount = 0;
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
};

int main() {
    std::cout << "Hello BSIT 1-2!" << std::endl;
    std::cout << "" << std::endl;

    Activity1 func;
    func.activity1();

    std::cout << "\n" << std::endl;
    return 0;
}