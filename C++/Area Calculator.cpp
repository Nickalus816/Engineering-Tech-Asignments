//Area Calculator
//Nickalus Lowrey
//Version 0.0.1

#include <iostream>

// Functions
int square() {
    double num1, num2, sum;

    std::cout << "Enter the first Length: ";
    std::cin >> num1;

    std::cout << "Enter the second Width: ";
    std::cin >> num2;

    sum = num1 * num2;

    std::cout << "The Area of " << num1 << " and " << num2 << " is: " << sum << std::endl;

    return 0;
}

int rectangle() {
    double num1, num2, sum;

    std::cout << "Enter the first Length: ";
    std::cin >> num1;

    std::cout << "Enter the second Width: ";
    std::cin >> num2;

    sum = num1 * num2;

    std::cout << "The Area of " << num1 << " and " << num2 << " is: " << sum << std::endl;

    return 0;
}

int parallelogram() {
    double num1, num2, sum;

    std::cout << "Enter the first Length: ";
    std::cin >> num1;

    std::cout << "Enter the second Width: ";
    std::cin >> num2;

    sum = num1 * num2;

    std::cout << "The Area of " << num1 << " and " << num2 << " is: " << sum << std::endl;

    return 0;
}

int circle() {
    double num1, PI, sum;

    std::cout << "Enter the first Length: ";
    std::cin >> num1;

    sum = num1 * num1 * PI;

    std::cout << "The Area of " << num1 << " and " << PI << " is: " << sum << std::endl;

    return 0;
}

int main() {
    int choice;
    bool running = true;

    while (running) {
        // Display menu options
        std::cout << "\n===== MENU =====\n";
        std::cout << "1. Square\n";
        std::cout << "2. Rectangle\n";
        std::cout << "3. Parallelogram\n";
        std::cout << "4. Circle\n";
        std::cout << "5. Pentagon\n";
        std::cout << "6. Triangle\n";
        std::cout << "7. Exit Program\n";
        std::cout << "Enter your choice (1-7): ";

        // Get user input
        std::cin >> choice;

        // Process the choice
        switch (choice) {
            case 1:
                std::cout << "You selected Square!\n";
                square();
                break;
            case 2:
                std::cout << "You selected Rectangle!\n";
                rectangle();
                break;
            case 3:
                std::cout << "You selected Parallelogram!\n";
                parallelogram();
                break;
            case 4:
                std::cout << "You selected Circle!\n";
                circle();
                break;
            case 5:
                std::cout << "You selected Pentagon!\n";
                pentagram();
                break;
            case 6:
                std::cout << "You selected Triangle!\n";
                triangle();
                break;
            case 7:
                std::cout << "Exiting program. Goodbye!\n";
                running = false;
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1-5.\n";
        }
    }

    return 0;
}