#include <iostream>
#include <cmath>

using namespace std;

double division(double, double);
int modulus(int, int);
void print_menu();

int main() {
    int choice;
    double first, second, result;

    while (true) {
        print_menu();
        cin >> choice;

        if (choice == 7) {
            break;
        }

        if (choice < 1 || choice > 7) {
            cerr << "Invalid Menu Choice." << endl;
            continue;
        }

        cout << "\nPlease enter the first number: ";
        cin >> first;
        cout << "Now, enter the second number: ";
        cin >> second;

        switch (choice) {
            case 1: // Add
                result = first + second;
                break;
            case 2: // Subtract
                result = first - second;
                break;
            case 3: // Multiply
                result = first * second;
                break;
            case 4: // Divide
                result = division(first, second);
                break;
            case 5: // Modulus (Only for integers)
                if (first == static_cast<int>(first) && second == static_cast<int>(second)) {
                    result = modulus(static_cast<int>(first), static_cast<int>(second));
                } else {
                    cerr << "Modulus operation is only valid for integers." << endl;
                    continue;
                }
                break;
            case 6: // Power
                result = pow(first, second);
                break;
        }

        if (!isnan(result)) {
            cout << "\nResult of operation is: " << result << endl;
        }
    }

    return 0;
}

double division(double a, double b) {
    if (b == 0) {
        cerr << "Invalid Argument for Division" << endl;
        return NAN;
    }
    return a / b;
}

int modulus(int a, int b) {
    if (b == 0) {
        cerr << "Invalid Argument for Modulus" << endl;
        return 0;  // Return 0 instead of NAN for an integer function
    }
    return a % b;
}

int print_menu() {
    cout << "\n\n---------------------------------";
    cout << "\nWelcome to Simple Calculator\n";
    cout << "\nChoose one of the following options:";
    cout << "\n1. Add";
    cout << "\n2. Subtract";
    cout << "\n3. Multiply";
    cout << "\n4. Divide";
    cout << "\n5. Modulus";
    cout << "\n6. Power";
    cout << "\n7. Exit";
    cout << "\nNow, enter your choice: ";
    return 0;
}
