//User Input and IO Calculator
//Nickalus Lowrey
//Version 0.0.1

//User Input
#include <iostream>
#include <string>

int main(){
    std::string user_input;
    std::cout << "Type something: ";
    std::getline(std::cin, user_input);
    std::cout << "You typed: " << user_input << std::endl;
    return 0;
}

//Addition Calculator
#include <iostream>

int main(){
    int num1, num2, sum;

    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter the second number: ";
    std::cin >> num2;

    sum = num1 + num2;

    std::cout << "The sum of " << num1 << " and " << num2 << " is: " << sum << std::endl;

    return 0;
}