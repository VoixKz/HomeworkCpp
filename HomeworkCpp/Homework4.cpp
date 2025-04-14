#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void shiftArray() {
    int size, shifts;
    char direction;

    cout << "Enter array size: ";
    cin >> size;

    int *arr = new int[size];

    srand(time(0));
    cout << "Original array:\n";
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 10;
        cout << arr[i] << " ";
    }
    cout << "\nEnter number of shifts: ";
    cin >> shifts;
    shifts %= size;

    cout << "Direction (L for left, R for right): ";
    cin >> direction;

    int *temp = new int[size];

    for (int i = 0; i < size; ++i) {
        if (direction == 'L' || direction == 'l')
            temp[i] = arr[(i + shifts) % size];
        else
            temp[i] = arr[(i - shifts + size) % size];
    }

    cout << "Shifted array:\n";
    for (int i = 0; i < size; ++i) {
        cout << temp[i] << " ";
    }
    cout << endl;

    delete[] arr;
    delete[] temp;
}

void sum2DArray() {
    int rows, cols;
    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    int **arr = new int *[rows];
    for (int i = 0; i < rows; ++i)
        arr[i] = new int[cols];

    srand(time(0));

    int totalSum = 0;
    int *colSums = new int[cols];
    for (int j = 0; j < cols; ++j)
        colSums[j] = 0;

    cout << "Matrix with row sums:\n";
    for (int i = 0; i < rows; ++i) {
        int rowSum = 0;
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = rand() % 10;
            cout << arr[i][j] << " ";
            rowSum += arr[i][j];
            colSums[j] += arr[i][j];
        }
        totalSum += rowSum;
        cout << "| " << rowSum << endl;
    }

    for (int i = 0; i < cols; ++i)
        cout << "--";
    cout << "------\n";

    for (int j = 0; j < cols; ++j)
        cout << colSums[j] << " ";
    cout << "| " << totalSum << endl;

    for (int i = 0; i < rows; ++i)
        delete[] arr[i];
    delete[] arr;
    delete[] colSums;
}

void shift2DArray() {
    int rows, cols, shifts;
    char dir;
    cout << "Enter rows and cols: ";
    cin >> rows >> cols;

    int **arr = new int *[rows];
    for (int i = 0; i < rows; ++i)
        arr[i] = new int[cols];

    srand(time(0));
    cout << "Original:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = rand() % 10;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Enter number of shifts: ";
    cin >> shifts;

    cout << "Direction (L/R/U/D): ";
    cin >> dir;

    int **result = new int *[rows];
    for (int i = 0; i < rows; ++i)
        result[i] = new int[cols];

    if (dir == 'L' || dir == 'l') {
        shifts %= cols;
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result[i][j] = arr[i][(j + shifts) % cols];
    }
    else if (dir == 'R' || dir == 'r') {
        shifts %= cols;
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result[i][j] = arr[i][(j - shifts + cols) % cols];
    }
    else if (dir == 'U' || dir == 'u') {
        shifts %= rows;
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result[i][j] = arr[(i + shifts) % rows][j];
    }
    else if (dir == 'D' || dir == 'd') {
        shifts %= rows;
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result[i][j] = arr[(i - shifts + rows) % rows][j];
    }

    cout << "Shifted:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << result[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
        delete[] result[i];
    }
    delete[] arr;
    delete[] result;
}

void spiralFill() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int size = 2 * n + 1;
    int **A = new int *[size];
    for (int i = 0; i < size; ++i)
        A[i] = new int[size];

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            A[i][j] = -1;

    int x = n, y = n;
    A[x][y] = 0;
    int num = 1;
    int dx[] = { -1, 0, 1, 0 };
    int dy[] = { 0, -1, 0, 1 };
    int steps = 1;

    while (num < size * size) {
        for (int dir = 0; dir < 4; dir++) {
            for (int s = 0; s < steps; ++s) {
                x += dx[dir];
                y += dy[dir];
                if (x >= 0 && y >= 0 && x < size && y < size)
                    A[x][y] = num++;
            }
            if (dir % 2 == 1) steps++;
        }
    }

    cout << "Spiral array:\n";
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j)
            cout << A[i][j] << "\t";
        cout << endl;
    }

    for (int i = 0; i < size; ++i)
        delete[] A[i];
    delete[] A;
}


/*
int main() {
    int choice;
    do {
        cout << "\nChoose task:\n";
        cout << "7. Shift 1D array\n";
        cout << "8. Sum 2D array rows/cols\n";
        cout << "9. Shift 2D array\n";
        cout << "10. Spiral array\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
        case 7: shiftArray(); break;
        case 8: sum2DArray(); break;
        case 9: shift2DArray(); break;
        case 10: spiralFill(); break;
        case 0: break;
        default: cout << "Invalid option.\n";
        }
    } while (choice != 0);

    return 0;
}
*/