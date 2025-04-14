#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void createAndFillArrayBasedOnUserInput() {
    int rows, cols;
    cout << "\nEnter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int **arr = new int *[rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
    }

    int a, b;
    cout << "Enter two numbers (a and b): ";
    cin >> a >> b;

    arr[0][0] = a;
    if (rows * cols > 1) {
        arr[0][1] = b;
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == 0 && j < 2) continue;

            if (j == 0) {
                arr[i][j] = arr[i - 1][cols - 2] + arr[i - 1][cols - 1];
            }
            else if (j == 1 && i > 0) {
                arr[i][j] = arr[i - 1][cols - 1] + arr[i][0];
            }
            else {
                arr[i][j] = arr[i][j - 2] + arr[i][j - 1];
            }
        }
    }

    cout << "\nGenerated 2D array:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}

void sortEachRowInArray() {
    int rows, cols;
    cout << "\nEnter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int **arr = new int *[rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
    }

    srand(time(0));
    cout << "\nGenerated 2D array with random numbers:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = rand() % 100;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols - 1; ++j) {
            for (int k = 0; k < cols - 1 - j; ++k) {
                if (arr[i][k] > arr[i][k + 1]) {
                    int temp = arr[i][k];
                    arr[i][k] = arr[i][k + 1];
                    arr[i][k + 1] = temp;
                }
            }
        }
    }

    cout << "\nSorted 2D array (each row sorted):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}

void calculateRowAndColumnSums() {
    int rows, cols;
    cout << "\nEnter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int **arr = new int *[rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
    }

    srand(time(0));
    cout << "\nGenerated 2D array with random numbers:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = rand() % 20;
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    int *rowSums = new int[rows]();
    int *colSums = new int[cols]();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            rowSums[i] += arr[i][j];
            colSums[j] += arr[i][j];
        }
    }

    cout << "\n2D array with row and column sums:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j] << "\t";
        }
        cout << "| " << rowSums[i] << endl;
    }

    for (int j = 0; j < cols; ++j) {
        cout << "--------";
    }
    cout << "|------\n";

    for (int j = 0; j < cols; ++j) {
        cout << colSums[j] << "\t";
    }
    cout << endl;

    delete[] rowSums;
    delete[] colSums;
    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}


/*
int main() {
    int choice;

    do {
        cout << "\nSelect a task:\n";
        cout << "1 - Create 2D array based on user input\n";
        cout << "2 - Create 2D array and sort each row\n";
        cout << "3 - Calculate row and column sums\n";
        cout << "0 - Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: createAndFillArrayBasedOnUserInput(); break;
        case 2: sortEachRowInArray(); break;
        case 3: calculateRowAndColumnSums(); break;
        case 0: break;
        default: cout << "Invalid input. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
*/
