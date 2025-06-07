#include <iostream>
#include <string>
#include <numeric>
#include <sstream>
#include <typeinfo>

using namespace std;



class Fraction {

	int numerator;
	int denominator;

	void reduce() {
		int g = gcd(numerator, denominator);
		numerator /= g;
		denominator /= g;
	}

public:
	explicit Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
		if (denominator == 0) {
			throw invalid_argument("Denominator cannot be zero");
		}
		reduce();
	}

	Fraction(const Fraction &other) : numerator(other.numerator), denominator(other.denominator) {
		reduce();
	}

	Fraction &operator=(const Fraction &other) {
		if (this != &other) {
			numerator = other.numerator;
			denominator = other.denominator;
			reduce();
		}
		return *this;
	}

	~Fraction() {
		cout << "Deleting fraction: " << numerator << "/" << denominator << endl;
	}

	Fraction operator+(const Fraction &other) const {
		int num = numerator * other.denominator + other.numerator * denominator;
		int denom = denominator * other.denominator;
		return Fraction(num, denom);
	}

	Fraction operator-(const Fraction &other) const {
		int num = numerator * other.denominator - other.numerator * denominator;
		int denom = denominator * other.denominator;
		return Fraction(num, denom);
	}

	Fraction operator*(const Fraction &other) const {
		int num = numerator * other.numerator;
		int denom = denominator * other.denominator;
		return Fraction(num, denom);
	}

	Fraction operator/(const Fraction &other) const {
		if (other.numerator == 0) {
			throw invalid_argument("Cannot divide by zero");
		}
		int num = numerator * other.denominator;
		int denom = denominator * other.numerator;
		return Fraction(num, denom);
	}

	friend ostream &operator<<(ostream &os, const Fraction &f) {
		os << f.numerator << "/" << f.denominator;
		return os;
	}

	friend istream &operator>>(istream &is, Fraction &f) {
		char slash;
		is >> f.numerator >> slash >> f.denominator;
		if (f.denominator == 0) {
			throw invalid_argument("Denominator cannot be zero");
		}
		f.reduce();
		return is;
	}
};



class Time {
	int hours;
	int minutes;
	int seconds;

	void normalize() {
		if (seconds >= 60) {
			minutes += seconds / 60;
			seconds %= 60;
		}
		if (minutes >= 60) {
			hours += minutes / 60;
			minutes %= 60;
		}
	}

public:
	explicit Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {
		normalize();
	}

	Time operator+(int s) const {
		return Time(hours, minutes, seconds + s);
	}

	Time operator-(int s) const {
		return Time(hours, minutes, seconds - s);
	}

	int operator-(const Time &lhs) const {
		int rhs_total = hours * 3600 + minutes * 60 + seconds;
		int lhs_total = lhs.hours * 3600 + lhs.minutes * 60 + lhs.seconds;
		return rhs_total - lhs_total;
	}

	Time &operator+=(int s) {
		seconds += s;
		normalize();
		return *this;
	}

	Time &operator-=(int s) {
		seconds -= s;
		normalize();
		return *this;
	}

	Time &operator++() {
		++seconds;
		normalize();
		return *this;
	}

	Time operator++(int) {
		Time temp = *this;
		++seconds;
		normalize();
		return temp;
	}

	friend ostream &operator<<(ostream &os, const Time &t) {
		os << t.hours << ":" << t.minutes << ":" << t.seconds;
		return os;
	}

	friend istream &operator>>(istream &is, Time &t) {
		char colon1, colon2;
		is >> t.hours >> colon1 >> t.minutes >> colon2 >> t.seconds;
		t.normalize();
		return is;
	}
};



class Var {

private:
	enum Type { INT, DOUBLE, STRING } type;
	int i_val;
	double d_val;
	string s_val;

	static bool is_number(const string &s) {
		istringstream iss(s);
		double f;
		return (iss >> f) && (iss.eof());
	}

public:
	Var() : type(INT), i_val(0) {};
	Var(int value) : type(INT), i_val(value) {};
	Var(double value) : type(DOUBLE), d_val(value) {};
	Var(const string &value) : type(STRING), s_val(value) {};
	Var(const char *value) : type(STRING), s_val(value) {};

	void Display() const {
		switch (type) {
		case INT:
			cout << "Integer: " << i_val << endl;
			break;
		case DOUBLE:
			cout << "Double: " << d_val << endl;
			break;
		case STRING:
			cout << "String: " << s_val << endl;
			break;
		}
	}

	operator int() const {
		if (type == INT) return i_val;
		if (type == DOUBLE) return (int)d_val;
		if (is_number(s_val)) return stoi(s_val);
	}

	operator double() const {
		if (type == INT) return (double)i_val;
		if (type == DOUBLE) return d_val;
		if (is_number(s_val)) return stod(s_val);
	}

	operator string() const {
		if (type == INT) return to_string(i_val);
		if (type == DOUBLE) return to_string(d_val);
		return s_val;
	}

	operator const char *() const {
		if (type == INT) return to_string(i_val).c_str();
		if (type == DOUBLE) return to_string(d_val).c_str();
		if (type == STRING) return s_val.c_str();
		return "";
	}

	Var operator+ (const Var &other) const {
		if (type == STRING && other.type == STRING) return s_val + other.s_val;
		if (type == STRING) return s_val + to_string((double)other);
		if (other.type == STRING) return to_string((double)*this) + other.s_val;
		if (type == DOUBLE || other.type == DOUBLE) return (double)*this + (double)other;
		return (int)*this + (int)other;
	}

	Var operator- (const Var &other) const {
		if (type == STRING || other.type == STRING) throw invalid_argument("Cannot subtract strings");
		if (type == DOUBLE || other.type == DOUBLE) return (double)*this - (double)other;
		return (int)*this - (int)other;
	}

	Var operator* (const Var &other) const {
		if (type == STRING && other.type == STRING) {
			string result;
			for (char c : s_val) {
				if (other.s_val.find(c) != string::npos) {
					result += c;
				}
			}
			return result;
		}
		if (type == DOUBLE || other.type == DOUBLE) return (double)*this * (double)other;
		return (int)*this * (int)other;
	}

	Var operator/ (const Var &other) const {
		if (type == STRING && other.type == STRING) {
			string result;
			for (char c : s_val) {
				if (other.s_val.find(c) == string::npos) {
					result += c;
				}
			}
			return result;
		}
		if (type == DOUBLE || other.type == DOUBLE) return (double)*this / (double)other;
		return (int)*this / (int)other;
	}

	Var &operator+=(const Var &other) { return *this = *this + other; }
	Var &operator-=(const Var &other) { return *this = *this - other; }
	Var &operator*=(const Var &other) { return *this = *this * other; }
	Var &operator/=(const Var &other) { return *this = *this / other; }

	bool operator==(const Var &other) const { return (double)(*this) == (double)other; }
	bool operator!=(const Var &other) const { return !(*this == other); }
	bool operator<(const Var &other) const { return (double)(*this) < (double)other; }
	bool operator<=(const Var &other) const { return (double)(*this) <= (double)other; }
	bool operator>(const Var &other) const { return (double)(*this) > (double)other; }
	bool operator>=(const Var &other) const { return (double)(*this) >= (double)other; }
};