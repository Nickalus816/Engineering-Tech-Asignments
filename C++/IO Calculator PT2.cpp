// I/O Calculator PT2
// Nickalus Lowrey
// Version 0.1.5

#include <iostream>
using namespace std;

// Functions
int addition() {
    double num1, num2, sum;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    sum = num1 + num2;

    cout << "The sum of " << num1 << " and " << num2 << " is: " << sum << endl;

    return 0;
}

int subtraction() {
    double num1, num2, difference;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    difference = num1 - num2;

    cout << "The difference of " << num1 << " and " << num2 << " is: " << difference << endl;

    return 0;
}

int multiplication() {
    double num1, num2, product;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    product = num1 * num2;

    cout << "The product of " << num1 << " and " << num2 << " is: " << product << endl;

    return 0;
}

int division() {
    double num1, num2, quotient;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    // Check for division by zero
    if (num2 == 0) {
        cout << "Error: Cannot divide by zero!" << endl;
        return 1;
    }

    quotient = num1 / num2;

    cout << "The quotient of " << num1 << " and " << num2 << " is: " << quotient << endl;

    return 0;
}

int main() {
    int choice;
    bool running = true;

    while (running) {
        // Display menu options
        cout << "\n===== MENU =====\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Exit Program\n";
        cout << "Enter your choice (1-5): ";

        // Get user input
        cin >> choice;

        // Process the choice
        switch (choice) {
            case 1:
                cout << "You selected Addition!\n";
                addition();
                break;
            case 2:
                cout << "You selected Subtraction!\n";
                subtraction();
                break;
            case 3:
                cout << "You selected Multiplication!\n";
                multiplication();
                break;
            case 4:
                cout << "You selected Division!\n";
                division();
                break;
            case 5:
                cout << "Exiting program. Goodbye!\n";
                running = false;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1-5.\n";
        }
    }

    return 0;
}
