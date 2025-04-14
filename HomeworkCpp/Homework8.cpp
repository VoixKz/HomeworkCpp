#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); ++i)
        if (num % i == 0)
            return false;
    return true;
}

int *removeZerosNew(int *arr, int size, int &newSize) {
    newSize = 0;
    for (int i = 0; i < size; ++i)
        if (arr[i] != 0) ++newSize;

    int *newArr = new int[newSize];
    int j = 0;
    for (int i = 0; i < size; ++i)
        if (arr[i] != 0)
            newArr[j++] = arr[i];

    return newArr;
}

int *extractPrimes(int *arr, int size, int &primeCount) {
    primeCount = 0;
    for (int i = 0; i < size; ++i)
        if (isPrime(arr[i]))
            ++primeCount;

    int *primeArr = new int[primeCount];
    int j = 0;
    for (int i = 0; i < size; ++i)
        if (isPrime(arr[i]))
            primeArr[j++] = arr[i];

    return primeArr;
}

void removeZerosInPlace(int *&arr, int &size) {
    int *temp = new int[size];
    int newSize = 0;

    for (int i = 0; i < size; ++i)
        if (arr[i] != 0)
            temp[newSize++] = arr[i];

    delete[] arr;
    arr = new int[newSize];
    for (int i = 0; i < newSize; ++i)
        arr[i] = temp[i];

    size = newSize;
    delete[] temp;
}

void printArray(int *arr, int size) {
    if (size == 0) {
        cout << "[empty]" << endl;
        return;
    }
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}


/*
int main() {
    int *arr = nullptr;
    int size = 0;

    int choice;
    do {
        cout << "\nSelect a task:\n";
        cout << "1 - Create array\n";
        cout << "2 - Remove zeros (create new array)\n";
        cout << "3 - Remove zeros (in-place)\n";
        cout << "4 - Print array\n";
        cout << "5 - Extract prime numbers\n";
        cout << "0 - Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Enter number of elements: ";
            cin >> size;
            delete[] arr;
            arr = new int[size];
            cout << "Enter " << size << " elements:\n";
            for (int i = 0; i < size; ++i)
                cin >> arr[i];
            break;
        }
        case 2: {
            if (!arr) {
                cout << "Array not created.\n";
                break;
            }
            int newSize;
            int *newArr = removeZerosNew(arr, size, newSize);
            cout << "New array without zeros: ";
            printArray(newArr, newSize);
            delete[] newArr;
            break;
        }
        case 3: {
            if (!arr) {
                cout << "Array not created.\n";
                break;
            }
            removeZerosInPlace(arr, size);
            cout << "Original array after removing zeros (in-place): ";
            printArray(arr, size);
            break;
        }
        case 4: {
            if (!arr) {
                cout << "Array not created.\n";
                break;
            }
            cout << "Current array: ";
            printArray(arr, size);
            break;
        }
        case 5: {
            if (!arr) {
                cout << "Array not created.\n";
                break;
            }
            int primeCount;
            int *primes = extractPrimes(arr, size, primeCount);
            cout << "Array with prime numbers: ";
            printArray(primes, primeCount);
            delete[] primes;
            break;
        }
        case 0:
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    delete[] arr;
    return 0;
}
*/