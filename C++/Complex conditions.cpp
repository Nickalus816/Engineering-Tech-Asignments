//Complex conditions
//Nickalus Lowrey
//Version 0.1.1

//Instuctions when using a code comment out other codes.

//Fix the logic error
#include <iostream>

int main() {
    int age = 20;
    bool student = true;

    if (age <= 18 && student) {
        std::cout << "Discount applied." << std::endl;
    } else {
        std::cout << "No discount." << std::endl;
    }

    return 0;
}

// first prompt

#include <iostream>

int first() {
    int number;
    
    std::cout << "Enter a number: ";
    std::cin >> number;

    if (number > 0 && number % 2 == 0) {
        std::cout << "Positive even" << std::endl;
    } else if (number <= 0) {
        std::cout << "Negative or zero" << std::endl;
    } else {
        std::cout << "Positive odd" << std::endl;
    }

    return 0;
}

// Second Prompt

#include <iostream>

int second() {
    bool loggedIn = true;
    bool banned = false;

    if (loggedIn && !banned) {
        std::cout << "Access granted" << std::endl;
    } else {
        std::cout << "Access denied" << std::endl;
    }

    return 0;
}

// Third prompt

#include <iostream>

int main() {
    int age;

    std::cout << "Enter visitor's age: ";
    std::cin >> age;

    if (age < 12 || age > 60) {
        std::cout << "Free ticket" << std::endl;
    } else if (age >= 12 && age <= 18) {
        std::cout << "Half price" << std::endl;
    } else {
        std::cout << "Full price" << std::endl;
    }

    return 0;
}

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