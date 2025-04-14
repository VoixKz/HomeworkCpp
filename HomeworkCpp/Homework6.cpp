#include <iostream>
#include <cstdlib>
using namespace std;

void calculator() {
    double a, b, result;
    char operation;
    double *pA = &a;
    double *pB = &b;
    double *pResult = &result;

    cout << "\n[Calculator]\n";
    cout << "Enter first number: ";
    cin >> *pA;
    cout << "Enter an operator (+ - * /): ";
    cin >> operation;
    cout << "Enter second number: ";
    cin >> *pB;

    switch (operation) {
    case '+': *pResult = *pA + *pB; break;
    case '-': *pResult = *pA - *pB; break;
    case '*': *pResult = *pA * *pB; break;
    case '/':
        if (*pB != 0)
            *pResult = *pA / *pB;
        else {
            cout << "Error: Division by zero!\n";
            return;
        }
        break;
    default:
        cout << "Invalid operator!\n";
        return;
    }

    cout << "Result: " << *pResult << endl;
}

void replaceMultiplesOfFour() {
    const int size = 10;
    int *arr = new int[size];

    cout << "\n[Replace multiples of 4 with 999]\nOriginal array:\n";
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 21;
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int *p = arr; p < arr + size; ++p) {
        if (*p % 4 == 0) {
            *p = 999;
        }
    }

    cout << "Modified array:\n";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
}

void replaceNegativesWithZero() {
    const int size = 10;
    int *arr = new int[size];

    cout << "\n[Replace negatives with 0]\nOriginal array:\n";
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 41 - 20;
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int *p = arr; p < arr + size; ++p) {
        if (*p < 0) {
            *p = 0;
        }
    }

    cout << "Modified array:\n";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
}

/*
int main() {
    srand(time(0));
    int choice;

    do {
        cout << "\nSelect a task:\n";
        cout << "1 - Primitive calculator (using pointers)\n";
        cout << "2 - Replace all multiples of 4 with 999 (using pointers)\n";
        cout << "3 - Replace negative numbers with 0 (using pointers)\n";
        cout << "0 - Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: calculator(); break;
        case 2: replaceMultiplesOfFour(); break;
        case 3: replaceNegativesWithZero(); break;
        case 0: break;
        default: cout << "Invalid input. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
*/