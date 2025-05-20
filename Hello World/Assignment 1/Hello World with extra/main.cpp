//PART 2

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Function to convert numeric grade to letter grade

char getLetterGrade(int grade) {

    if (grade >= 90 && grade <= 100)

        return 'A';

    else if (grade >= 80)

        return 'B';

    else if (grade >= 70)

        return 'C';

    else if (grade >= 60)

        return 'D';

    else

        return 'F';

}


// Function to get base GPA points from letter grade

double getBaseGPA(char letter) {

    switch (letter) {

        case 'A': return 4.0;

        case 'B': return 3.0;

        case 'C': return 2.0;

        case 'D': return 1.0;

        default:  return 0.0;

    }

}


// Function to get GPA weight based on class type

double getClassWeight(const string& classType) {

    if (classType == "Regular")

        return 0.0;

    else if (classType == "Honors")

        return 0.5;

    else if (classType == "AP")

        return 1.0;

    else

        return -1.0; // Invalid class type

}

int main() {

    int totalClasses = 0;

    double totalGPA = 0.0;

    string continueInput;


    do {

        int numericGrade;

        string classType;


        // Prompt for numeric grade with validation

        while (true) {

            cout << "Enter numeric grade (0-100): ";

            cin >> numericGrade;


            if (cin.fail() || numericGrade < 0 || numericGrade > 100) {

                cin.clear(); // Clear error flags

                cin.ignore(numericGrade, '\n'); // Discard invalid input

                cout << "Please enter a number between 0 and 100." << endl;

            } else {

                break;

            }

        }


        // Determine letter grade

        char letterGrade = getLetterGrade(numericGrade);


        // Prompt for class type with validation

        while (true) {

            cout << "Enter class type (Regular, Honors, AP): ";

            cin >> classType;


            // Convert input to proper case for comparison

            for (auto & c: classType) c = toupper(c);


            if (classType == "REGULAR" || classType == "HONORS" || classType == "AP") {

                break;

            } else {

                cout << "Invalid class type. Please enter Regular, Honors, or AP." << endl;

            }

        }


        // Convert classType to proper case for display

        if (classType == "REGULAR") classType = "Regular";

        else if (classType == "HONORS") classType = "Honors";

        else if (classType == "AP") classType = "AP";


        // Calculate GPA points

        double baseGPA = getBaseGPA(letterGrade);

        double weight = getClassWeight(classType);

        double gpaPoints = baseGPA + weight;


        // Accumulate totals

        totalGPA += gpaPoints;

        totalClasses++;


        // Display results

        cout << fixed << setprecision(2);

        cout << "Letter Grade: " << letterGrade << endl;

        cout << "GPA Points for this class: " << gpaPoints << endl;


        // Prompt to continue

        cout << "Do you want to enter another class? (yes/no): ";

        cin >> continueInput;


        // Convert input to lowercase for comparison

        for (auto & c: continueInput) c = tolower(c);


    } while (continueInput == "yes");


    // Calculate and display average GPA

    if (totalClasses > 0) {

        double averageGPA = totalGPA / totalClasses;

        cout << fixed << setprecision(2);

        cout << "Total GPA across " << totalClasses << " classes: " << averageGPA << endl;

    } else {

        cout << "No classes entered. GPA calculation not performed." << endl;

    }


    return 0;

}
