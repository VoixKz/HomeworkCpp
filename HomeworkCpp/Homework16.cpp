#include <iostream>
#include <string>
#include <sstream>
#include <typeinfo>
using namespace std;



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



int max_arr(int *arr) {
	int	max = arr[0];
}