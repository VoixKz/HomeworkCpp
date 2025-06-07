#include <iostream>
#include <string>

using namespace std;



class Airplane {

private:
	string type;
	int currentPassengers;
	int maxPassengers;

	void check() {
		if (currentPassengers < 0) {
			currentPassengers = 0;
		}
		if (currentPassengers > maxPassengers) {
			currentPassengers = maxPassengers;
		}
	}

public:
	explicit Airplane(string type = "", int currentPassengers = 0, int maxPassengers = 0)
		: type(type), currentPassengers(currentPassengers), maxPassengers(maxPassengers) {
		check();
	}

	Airplane(const Airplane &other) {
		type = other.type;
		currentPassengers = other.currentPassengers;
		maxPassengers = other.maxPassengers;
	}

	~Airplane() {
		cout << "Deleting airplane of type: " << type << endl;
	}

	bool operator==(const Airplane &other) const {
		return type == other.type;
	}

	bool operator!=(const Airplane &other) const {
		return !(*this == other);
	}

	bool operator>=(const Airplane &other) const {
		return maxPassengers >= other.maxPassengers;
	}

	bool operator<=(const Airplane &other) const {
		return maxPassengers <= other.maxPassengers;
	}

	bool operator>(const Airplane &other) const {
		return maxPassengers > other.maxPassengers;
	}

	bool operator<(const Airplane &other) const {
		return maxPassengers < other.maxPassengers;
	}

	Airplane &operator++() {
		if (currentPassengers < maxPassengers) {
			++currentPassengers;
		}
		return *this;
	}

	Airplane &operator--() {
		if (currentPassengers > 0) {
			--currentPassengers;
		}
		return *this;
	}

	Airplane operator++(int) {
		Airplane temp = *this;
		++(*this);
		return temp;
	}

	Airplane operator--(int) {
		Airplane temp = *this;
		--(*this);
		return temp;
	}
};



class Overcoat {

private:
	string type;
	double price;
	int size;

	void check() {
		if (size < 0) {
			size = 0;
		}
		if (price < 0) {
			price = 0;
		}
	}

public:
	explicit Overcoat(string type = "", double price = 0.0, int size = 0)
		: type(type), price(price), size(size) {
		check();
	}

	Overcoat(const Overcoat &other) {
		type = other.type;
		price = other.price;
		size = other.size;
	}

	~Overcoat() {
		cout << "Deleting overcoat of type: " << type << endl;
	}

	bool operator==(const Overcoat &other) const {
		return type == other.type;
	}

	bool operator!=(const Overcoat &other) const {
		return !(*this == other);
	}

	Overcoat &operator=(Overcoat &other) {
		if (this != &other) {
			type = other.type;
			price = other.price;
			size = other.size;
		}
		return *this;
	}

	bool operator>=(const Overcoat &other) const {
		return price >= other.price;
	}

	bool operator<=(const Overcoat &other) const {
		return price <= other.price;
	}

	bool operator>(const Overcoat &other) const {
		return price > other.price;
	}

	bool operator<(const Overcoat &other) const {
		return price < other.price;
	}

	Overcoat &operator++() {
		price += 1.0;
		return *this;
	}

	Overcoat &operator--() {
		price -= 1.0;
		return *this;
	}

	Overcoat operator++(int) {
		Overcoat temp = *this;
		++(*this);
		return temp;
	}

	Overcoat operator--(int) {
		Overcoat temp = *this;
		--(*this);
		return temp;
	}
 };