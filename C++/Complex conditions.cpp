//Complex conditions
//Nickalus Lowrey
//Version 0.1.1

//Instuctions when using a code comment out other codes.

//Fix the logic error
// #include <iostream>

// int main() {
//     int age = 20;
//     bool student = true;

//     if (age <= 18 && student) {
//         std::cout << "Discount applied." << std::endl;
//     } else {
//         std::cout << "No discount." << std::endl;
//     }

//     return 0;
// }

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