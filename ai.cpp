#include <iostream>
#include <cmath>    // For mathematical functions
#include <limits>   // For std::numeric_limits

using namespace std;

// Function prototypes
void showMenu();
void performOperation(int choice);

int main() {
    int choice;

    do {
        showMenu();
        cout << "Enter your choice (1-7) or 0 to exit: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a number between 0 and 7." << endl;
            continue;
        }

        if (choice != 0) {
            performOperation(choice);
        }

    } while (choice != 0);

    cout << "Exiting the calculator. Goodbye!" << endl;
    return 0;
}

void showMenu() {
    cout << "\n--- Scientific Calculator ---" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Trigonometric Functions" << endl;
    cout << "6. Logarithms" << endl;
    cout << "7. Square Root" << endl;
    cout << "0. Exit" << endl;
}

void performOperation(int choice) {
    double a, b;

    switch (choice) {
        case 1: // Addition
            cout << "Enter two numbers: ";
            cin >> a >> b;
            cout << "Result: " << a + b << endl;
            break;
        
        case 2: // Subtraction
            cout << "Enter two numbers: ";
            cin >> a >> b;
            cout << "Result: " << a - b << endl;
            break;
        
        case 3: // Multiplication
            cout << "Enter two numbers: ";
            cin >> a >> b;
            cout << "Result: " << a * b << endl;
            break;
        
        case 4: // Division
            cout << "Enter two numbers: ";
            cin >> a >> b;
            if (b != 0) {
                cout << "Result: " << a / b << endl;
            } else {
                cout << "Error: Division by zero!" << endl;
            }
            break;

        case 5: // Trigonometric Functions
            cout << "Choose function: " << endl;
            cout << "1. sin(x)" << endl;
            cout << "2. cos(x)" << endl;
            cout << "3. tan(x)" << endl;
            int trigChoice;
            cin >> trigChoice;

            if (trigChoice == 1 || trigChoice == 2 || trigChoice == 3) {
                cout << "Enter angle in degrees: ";
                cin >> a;
                // Convert degrees to radians
                double rad = a * M_PI / 180.0;
                switch (trigChoice) {
                    case 1:
                        cout << "Result: " << sin(rad) << endl;
                        break;
                    case 2:
                        cout << "Result: " << cos(rad) << endl;
                        break;
                    case 3:
                        cout << "Result: " << tan(rad) << endl;
                        break;
                }
            } else {
                cout << "Invalid choice." << endl;
            }
            break;

        case 6: // Logarithms
            cout << "Choose function: " << endl;
            cout << "1. log10(x)" << endl;
            cout << "2. ln(x)" << endl;
            int logChoice;
            cin >> logChoice;

            if (logChoice == 1 || logChoice == 2) {
                cout << "Enter a number: ";
                cin >> a;
                if (a > 0) {
                    switch (logChoice) {
                        case 1:
                            cout << "Result: " << log10(a) << endl;
                            break;
                        case 2:
                            cout << "Result: " << log(a) << endl;
                            break;
                    }
                } else {
                    cout << "Error: Logarithm of non-positive number is undefined!" << endl;
                }
            } else {
                cout << "Invalid choice." << endl;
            }
            break;

        case 7: // Square Root
            cout << "Enter a number: ";
            cin >> a;
            if (a >= 0) {
                cout << "Result: " << sqrt(a) << endl;
            } else {
                cout << "Error: Square root of negative number is undefined!" << endl;
            }
            break;

        default:
            cout << "Invalid choice. Please enter a number between 0 and 7." << endl;
    }
}
