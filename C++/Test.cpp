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