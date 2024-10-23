#include <iostream>
#include <fstream>
#include <map>
#include <cctype> // for isalpha function
#include <limits> // for numeric_limits

char findMaxFrequencyCharacter(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return '\0'; // Return null character if file can't be opened
    }

    std::map<char, int> charCount;
    char ch;

    // Read characters from the file and count their occurrences
    while (file.get(ch)) {
        if (std::isalpha(ch)) { // Only consider alphabetic characters
            ch = std::tolower(ch); // Convert to lowercase for case insensitivity
            charCount[ch]++;
        }
    }

    file.close();

    // Find the character with the maximum frequency
    char maxChar = '\0';
    int maxFreq = std::numeric_limits<int>::min();

    for (const auto& pair : charCount) {
        if (pair.second > maxFreq) {
            maxFreq = pair.second;
            maxChar = pair.first;
        }
    }

    return maxChar;
}

int main() {
    std::string filename = "text.txt"; // Replace with your file name
    char result = findMaxFrequencyCharacter(filename);

    if (result != '\0') {
        std::cout << "Character with maximum frequency: " << result << std::endl;
    } else {
        std::cout << "No valid characters found." << std::endl;
    }

    return 0;
}
