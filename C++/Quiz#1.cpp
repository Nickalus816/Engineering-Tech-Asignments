// Fourth Prompot

#include <iostream>
#include <string>

int main() {
    std::string username, password;

    // Hardcoded credentials
    std::string correctUsername = "admin";
    std::string correctPassword = "pass123";

    // Input
    std::cout << "Username: ";
    std::cin >> username;
    
    std::cout << "Password: ";
    std::cin >> password;

    // Check credentials
    if (username == correctUsername) {
        if (password == correctPassword) {
            std::cout << "Login successful" << std::endl;
        } else {
            std::cout << "Incorrect password" << std::endl;
        }
    } else {
        std::cout << "Invalid username" << std::endl;
    }

    return 0;
}