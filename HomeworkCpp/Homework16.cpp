#include <iostream>
#include <string>
#include <sstream>
#include <typeinfo>
using namespace std;



// 1 task
int max(int a, int b) { return a > b ? a : b; }
long long max(long long a, long long b) { return a > b ? a : b; }
float max(float a, float b) { return a > b ? a : b; }
double max(double a, double b) { return a > b ? a : b; }

int max(int a, int b, int c) { return max(max(a, b), c); }
long long max(long long a, long long b, long long c) { return max(max(a, b), c); }
float max(float a, float b, float c) { return max(max(a, b), c); }
double max(double a, double b, double c) { return max(max(a, b), c); }

int max(int a, int b, int c, int d) { return max(max(a, b), max(c, d)); }
long long max(long long a, long long b, long long c, long long d) { return max(max(a, b), max(c, d)); }
float max(float a, float b, float c, float d) { return max(max(a, b), max(c, d)); }
double max(double a, double b, double c, double d) { return max(max(a, b), max(c, d)); }

template <typename T>
T max(T a, T b) { return a > b ? a : b; }

template <typename T>
T max(T a, T b, T c) { return max(max(a, b), c); }

template <typename T>
T max(T a, T b, T c, T d) { return max(max(a, b), max(c, d)); }



// 2 task
int max_arr(const int* arr, int size) {
	if (size <= 0) return 0;
	int max_value = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] > max_value) {
			max_value = arr[i];
		}
	}
	return max_value;
}

long long max_arr(const long long* arr, int size) {
	if (size <= 0) return 0;
	long long max_value = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] > max_value) {
			max_value = arr[i];
		}
	}
	return max_value;
}

float max_arr(const float* arr, int size) {
	if (size <= 0) return 0.0f;
	float max_value = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] > max_value) {
			max_value = arr[i];
		}
	}
	return max_value;
}

double max_arr(const double* arr, int size) {
	if (size <= 0) return 0.0;
	double max_value = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] > max_value) {
			max_value = arr[i];
		}
	}
	return max_value;
}

template <typename T>
T max_arr(const T* arr, int size) {
	if (size <= 0) return T();
	T max_value = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] > max_value) {
			max_value = arr[i];
		}
	}
	return max_value;
}



// 3 task
template <typename T>
int count_less_than(const T* arr, int size, T value) {
	if (size <= 0) return 0;
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] < value) {
			count++;
		}
	}
	return count;
}



// 4 task
template <typename T>
void reverse_array(T* arr, int size) {
	for (int i = 0; i < size / 2; ++i)
		swap(arr[i], arr[size - 1 - i]);
}



//int main() {
//	cout << "--- 1. Max из 2, 3, 4 ---" << endl;
//	cout << "max(3, 5): " << max(3, 5) << endl;
//	cout << "max(1.5f, 2.3f, 0.9f): " << max(1.5f, 2.3f, 0.9f) << endl;
//	cout << "max(1.1, 2.2, 3.3, 0.5): " << max(1.1, 2.2, 3.3, 0.5) << endl;
//
//	cout << "tmax(10, 20): " << max(10, 20) << endl;
//	cout << "tmax(5.5, 2.2, 8.8): " << max(5.5, 2.2, 8.8) << endl;
//	cout << "tmax(1LL, 2LL, 3LL, 4LL): " << max(1LL, 2LL, 3LL, 4LL) << endl;
//
//	cout << "\n--- 2. Max в массиве ---" << endl;
//	int a[] = { 1, 3, 2, 8, 5 };
//	float b[] = { 1.1f, 3.3f, 0.5f };
//	cout << "max_arr<int>: " << max_arr(a, 5) << endl;
//	cout << "tmax_arr<float>: " << max_arr(b, 3) << endl;
//
//	cout << "\n--- 3. Элементы меньше заданного ---" << endl;
//	cout << "count_less_than<int>: " << count_less_than(a, 5, 4) << endl;
//	cout << "count_less_than<float>: " << count_less_than(b, 3, 2.0f) << endl;
//
//	cout << "\n--- 4. Reverse массива ---" << endl;
//	reverse_array(a, 5);
//	cout << "reversed int array: ";
//	for (int i = 0; i < 5; ++i) cout << a[i] << " ";
//	cout << endl;
//
//	reverse_array(b, 3);
//	cout << "reversed float array: ";
//	for (int i = 0; i < 3; ++i) cout << b[i] << " ";
//	cout << endl;
//
//	return 0;
//}