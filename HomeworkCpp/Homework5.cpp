#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;



void task1() {
    const int size = 30;
    int *a = new int[size];
    srand(time(0));

    cout << "\nArray: ";
    for (int i = 0; i < size; ++i) {
        a[i] = rand() % 100;
        cout << a[i] << " ";
    }
    cout << endl;

    int count = 0;
    for (int i = 0; i < size - 1; ++i) {
        if (a[i] % 2 == 0 && a[i + 1] % 2 == 0) {
            ++count;
        }
    }

    if (count > 0)
        cout << "Number of consecutive even pairs: " << count << endl;
    else
        cout << "No consecutive even pairs found.\n";

    delete[] a;
}

void task2a() {
    const int size = 19;
    int *a = new int[size];
    bool present[21] = { false };

    srand(time(0));
    int missing = 1 + rand() % 20;
    int index = 0;

    for (int i = 1; i <= 20; ++i) {
        if (i == missing) continue;
        a[index++] = i;
    }

    for (int i = 0; i < size; ++i) {
        int r = rand() % size;
        int temp = a[i];
        a[i] = a[r];
        a[r] = temp;
    }

    cout << "\nArray: ";
    for (int i = 0; i < size; ++i) {
        cout << a[i] << " ";
        present[a[i]] = true;
    }
    cout << endl;

    for (int i = 1; i <= 20; ++i) {
        if (!present[i]) {
            cout << "Missing number: " << i << endl;
            break;
        }
    }

    delete[] a;
}

void task2b() {
    const int size = 19;
    int *a = new int[size];
    srand(time(0));
    int missing = 1 + rand() % 20;
    int index = 0;
    int expectedSum = 20 * 21 / 2;

    for (int i = 1; i <= 20; ++i) {
        if (i == missing) continue;
        a[index++] = i;
    }

    for (int i = 0; i < size; ++i) {
        int r = rand() % size;
        int temp = a[i];
        a[i] = a[r];
        a[r] = temp;
    }

    cout << "\nArray: ";
    int actualSum = 0;
    for (int i = 0; i < size; ++i) {
        cout << a[i] << " ";
        actualSum += a[i];
    }
    cout << endl;

    cout << "Missing number: " << expectedSum - actualSum << endl;
    delete[] a;
}

void task3() {
    int rows, cols;
    cout << "\nEnter number of rows and columns: ";
    cin >> rows >> cols;

    int **matrix = new int *[rows];
    for (int i = 0; i < rows; ++i)
        matrix[i] = new int[cols];

    srand(time(0));
    int sum = 0;
    int minVal, maxVal;
    int minRow = 0, minCol = 0, maxRow = 0, maxCol = 0;

    cout << "\nMatrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 100;
            cout << matrix[i][j] << "\t";
            sum += matrix[i][j];

            if (i == 0 && j == 0) {
                minVal = maxVal = matrix[i][j];
            }
            else {
                if (matrix[i][j] < minVal) {
                    minVal = matrix[i][j];
                    minRow = i;
                    minCol = j;
                }
                if (matrix[i][j] > maxVal) {
                    maxVal = matrix[i][j];
                    maxRow = i;
                    maxCol = j;
                }
            }
        }
        cout << endl;
    }

    double average = (double)sum / (rows * cols);
    cout << "\nTotal sum: " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Minimum value: " << minVal << " at position (" << minRow << ", " << minCol << ")\n";
    cout << "Maximum value: " << maxVal << " at position (" << maxRow << ", " << maxCol << ")\n";

    for (int i = 0; i < rows; ++i)
        delete[] matrix[i];
    delete[] matrix;
}


/*
int main() {
    int choice;
    do {
        cout << "\nSelect a task:\n";
        cout << "1 - Consecutive even number pairs (Task 1)\n";
        cout << "2 - Find missing number (any method) [Task 2a]\n";
        cout << "3 - Find missing number (one-pass only) [Task 2b]\n";
        cout << "4 - 2D array analysis (sum, avg, min, max) [Task 3]\n";
        cout << "0 - Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: task1(); break;
        case 2: task2a(); break;
        case 3: task2b(); break;
        case 4: task3(); break;
        case 0: break;
        default: cout << "Invalid input. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
*/
