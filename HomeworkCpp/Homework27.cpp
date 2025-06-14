#include <iostream>
#include <cmath>

using namespace std;



class Equation {
public:
	virtual ~Equation() {}
	
	virtual void roots() = 0;

	virtual void print() = 0;
};



class LinearEquation : public Equation {
private:
	double a, b;

public:
	LinearEquation(double a, double b) : a(a), b(b) {}
	void roots() override {
		if (a == 0) {
			if (b == 0) {
				cout << "Infinite solutions" << endl;
			}
			else {
				cout << "No solution" << endl;
			}
		}
		else {
			cout << "Root: " << -b / a << endl;
		}
	}
	
	void print() override {
		if (b < 0) {
			cout << "Linear Equation: " << a << "x - " << -b << " = 0" << endl;
		}
		else if (b > 0) {
			cout << "Linear Equation: " << a << "x + " << b << " = 0" << endl;
		}
		else {
			cout << "Linear Equation: " << a << "x = 0" << endl;
		}
	}
};



class QuadraticEquation : public Equation {
private:
	double a, b, c;

public:
	QuadraticEquation(double a, double b, double c) : a(a), b(b), c(c) {}
	void roots() override {
		if (a == 0) {
			cout << "Not a quadratic equation, solving as linear: ";
			LinearEquation(b, c).roots();
			return;
		}

		double D = b * b - 4 * a * c;
		if (D < 0) {
			cout << "No real roots" << endl;
		}
		else if (D == 0) {
			cout << "One root: " << -b / (2 * a) << endl;
		}
		else {
			double root1 = (-b + sqrt(D)) / (2 * a);
			double root2 = (-b - sqrt(D)) / (2 * a);
			cout << "Roots: " << root1 << " and " << root2 << endl;
		}
	}

	void print() override {
		if (a == 0) {
			cout << "Not a quadratic equation, printing as linear: ";
			LinearEquation(b, c).print();
			return;
		}

		if (b < 0) {
			cout << "Quadratic Equation: " << a << "x^2 - " << -b << "x";
		} else if (b > 0) {
			cout << "Quadratic Equation: " << a << "x^2 + " << b << "x";
		} else {
			cout << "Quadratic Equation: " << a << "x^2";
		}

		if (c < 0) {
			cout << " - " << -c << " = 0" << endl;
		}
		else if (c > 0) {
			cout << " + " << c << " = 0" << endl;
		}
		else {
			cout << " = 0" << endl;
		}
	}
};



/*
int main() {
	Equation *eq1 = new LinearEquation(2, -4);
	eq1->print();
	eq1->roots();
	delete eq1;
	cout << endl;

	Equation *eq2 = new QuadraticEquation(1, -3, 2);
	eq2->print();
	eq2->roots();
	delete eq2;
	cout << endl;

	Equation *eq3 = new QuadraticEquation(0, 2, -4);
	eq3->print();
	eq3->roots();
	delete eq3;

	return 0;
}
*/