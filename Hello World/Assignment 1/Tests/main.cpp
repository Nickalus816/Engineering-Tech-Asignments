// Test 1
// Nickalus lowrey
// Issues found 8 out of 8
#include <iostream>
using namespace std;

int main() {
string name;
int age;
int yearsTo100;

//Didn't have << endl;
cout << "Enter your name: " << endl;
cin >> name;

cout << "Enter your age: " << endl;
cin >> age;

if (age < 0) { // parenthesis before age and after 0
cout << "Age cannot be negative." << endl;
} else {
yearsTo100 = 100 - age; // Semi Colon
cout << name << ", you will be 100 years old in " << yearsTo100 << " years. "; //Semi Colon and quotations
}

for (int i = 0; i < 3; i++) { // semi colon after 3
cout << "Loop number: " << i << endl;
}

return 0; // semi colon at the end
}
