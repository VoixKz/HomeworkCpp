#include <iostream>
#include <cmath>
using namespace std;

#define M_PI 3.141592

void averageGrades() {
    double grades[5];
    double sum = 0.0;
    double average;

    cout << "Enter 5 student grades: ";
    for (int i = 0; i < 5; ++i) {
        cin >> grades[i];
        sum += grades[i];
    }

    average = sum / 5.0;

    if (average >= 4) {
        cout << "The student is allowed to take the exam (average grade: " << average << ")." << endl;
    }
    else {
        cout << "The student is not allowed to take the exam (average grade: " << average << ")." << endl;
    }
}

void triangleExistence() {
    double a, b, c;
    cout << "Enter the 3 sides of a triangle: ";
    cin >> a >> b >> c;

    if (a + b > c && a + c > b && b + c > a) {
        cout << "The triangle exists." << endl;
    }
    else {
        cout << "The triangle does not exist." << endl;
    }
}

void circleInSquareCheck() {
    double squareArea, circleArea;
    cout << "Enter the area of the circle: ";
    cin >> circleArea;
    cout << "Enter the area of the square: ";
    cin >> squareArea;

    double circleRadius = sqrt(circleArea / M_PI);
    double squareSide = sqrt(squareArea);

    if (circleRadius * 2 <= squareSide) {
        cout << "The circle fits inside the square." << endl;
    }
    else {
        cout << "The circle does not fit inside the square." << endl;
    }

    if (squareSide * sqrt(2) <= circleRadius * 2) {
        cout << "The square fits inside the circle." << endl;
    }
    else {
        cout << "The square does not fit inside the circle." << endl;
    }
}

void numberRangeProcessing() {
    int a, b;
    cout << "Enter two numbers for the range: ";
    cin >> a >> b;

    int min = (a < b) ? a : b;
    int max = (a > b) ? a : b;

    cout << "Even numbers in the range: ";
    for (int i = min; i <= max; ++i) {
        if (i % 2 == 0) cout << i << " ";
    }
    cout << endl;

    cout << "Odd numbers in the range: ";
    for (int i = min; i <= max; ++i) {
        if (i % 2 != 0) cout << i << " ";
    }
    cout << endl;

    cout << "Numbers divisible by 7 in the range: ";
    for (int i = min; i <= max; ++i) {
        if (i % 7 == 0) cout << i << " ";
    }
    cout << endl;
}

void factorialCalc() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (num < 0) {
        cout << "Factorial does not exist for negative numbers." << endl;
        return;
    }

    int maxFactorial = 12;
    if (num > maxFactorial) {
        cout << "Factorial is too large for type int." << endl;
        return;
    }

    long long factorial = 1;
    for (int i = 1; i <= num; ++i) {
        factorial *= i;
    }

    cout << "Factorial of " << num << " is " << factorial << endl;
}

void maxInSequence() {
    int num;
    int maxNum = 0;

    cout << "Finding the maximum number in a sequence of positive numbers.\n";
    cout << "Enter numbers after the arrow. To finish, enter zero.\n";

    while (true) {
        cout << "-> ";
        cin >> num;

        if (num == 0) break;

        if (num > maxNum) maxNum = num;
    }

    cout << "The maximum number is: " << maxNum << endl;
}


/*
int main() {
    int choice;
    do {
        cout << "\nSelect a task:\n";
        cout << "1. Exam admission based on grades\n";
        cout << "2. Triangle existence check\n";
        cout << "3. Circle and square fitting check\n";
        cout << "4. Number range processing (even, odd, divisible by 7)\n";
        cout << "5. Factorial calculation\n";
        cout << "6. Finding the maximum number in a sequence\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: averageGrades(); break;
        case 2: triangleExistence(); break;
        case 3: circleInSquareCheck(); break;
        case 4: numberRangeProcessing(); break;
        case 5: factorialCalc(); break;
        case 6: maxInSequence(); break;
        case 0: cout << "Exiting the program.\n"; break;
        default: cout << "Invalid choice. Please try again.\n";
        }
        cout << endl;

    } while (choice != 0);

    return 0;
}
*/