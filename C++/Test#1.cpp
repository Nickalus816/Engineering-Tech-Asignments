//Test#1
//Nickalus Lowrey
//Version 0.0.1

//Instructions - Comment out every code but the one you use.

// Age to Title 

#include <iostream>

int main() {
    int age;

    std::cout << "Enter your age: ";
    std::cin >> age;

    if (age >= 0 && age <= 18) {
        std::cout << "Your are a minor." << std::endl;
    } 
    else if (age >= 18 && age <= 64) {
        std::cout << "You are an adult." << std::endl;
    } 
    else if (age >= 65 && age <= 115) {
        std::cout << "You are a senior." << std::endl;
    }
    else if (age >= 116) {
        std::cout << "Your the new oldest person alive, if that isn't your real age do it agian." << std::endl;
    }
    else if (age < 0) {
        std::cout << "Stop lying, do it again for real." << std::endl;
    }

    return 0;
}

//Divisble Number??

#include <iostream>

int main(){
    int num;
    
    std::cout << "Enter a number: ";
    std::cin >> num;

    if (num % 3 == 0) {
    std::cout << num << " Fizz" << std::endl;
  }
  else if (num % 5 == 0) {
    std::cout << num << " Buzz" << std::endl;
  }
   else if (num % 3 == 0 && num % 5 == 0) {
    std::cout << num << " FizzBuzz" << std::endl;
  }
  else {
    std::cout << num << std::end1;
  }
}