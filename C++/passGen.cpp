#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

std::string generatePassword(int length) {
    const std::string characters = 
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ" // Uppercase letters
        "abcdefghijklmnopqrstuvwxyz" // Lowercase letters
        "0123456789"                    // Digits
        "!@#$%^&*()-_=+[]{}|;:,.<>?";   // Special characters

    std::string password;
    for (int i = 0; i < length; ++i) {
        int index = rand() % characters.size();
        password += characters[index];
    }
    return password;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    const int passwordLength = 12; // Length of each password
    const int numberOfPasswords = 10; // Number of passwords to generate

    for (int i = 0; i < numberOfPasswords; ++i) {
        std::string password = generatePassword(passwordLength);
        std::cout << "Password " << (i + 1) << ": " << password << std::endl;
    }

    return 0;
}
