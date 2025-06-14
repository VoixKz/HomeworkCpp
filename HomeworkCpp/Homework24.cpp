#include <iostream>

using namespace std;



class Transport {
protected:
	string model;
	int speed; // in km/h
	float cost; // in $/km

public:
	Transport(string model, int speed, float cost)
		: model(model), speed(speed), cost(cost) {
	}
	
	virtual ~Transport() {}
	
	virtual void print() const {
		cout << "Model: " << model << ", Speed: " << speed << " km/h, Cost: $" << cost << endl;
	}
	
	virtual float calculateTime(float distance) const {
		float time = distance / speed;
		cout << "Time: " << time << " hours" << endl;
		return time;
	}

	virtual float calculateCost(float distance, float fuelWaste) const {
		float totalCost = distance * cost + fuelWaste * 0.5;
		cout << "Total Cost: $" << totalCost << endl;
		return totalCost;
	}
};



class Car : public Transport {
public:
	Car() : Transport("Car", 120, 0.2) {}

	void print() const override {
		cout << "Car Details: ";
		Transport::print();
	}

	float calculateTime(float distance) const override {
		cout << "Car - ";
		return Transport::calculateTime(distance);
	}

	float calculateCost(float distance, float fuelWaste) const override {
		cout << "Car - ";
		return Transport::calculateCost(distance, fuelWaste);
	}
};



class Bicycle : public Transport {
public:
	Bicycle() : Transport("Bicycle", 20, 0.05) {}
	
	void print() const override {
		cout << "Bicycle Details: ";
		Transport::print();
	}
	
	float calculateTime(float distance) const override {
		cout << "Bicycle - ";
		return Transport::calculateTime(distance);
	}
	
	float calculateCost(float distance, float fuelWaste) const override {
		cout << "Bicycle - ";
		return Transport::calculateCost(distance, fuelWaste);
	}
};



class Cart : public Transport {
public:
	Cart() : Transport("Cart", 10, 0.1) {}

	void print() const override {
		cout << "Cart Details: ";
		Transport::print();
	}

	float calculateTime(float distance) const override {
		cout << "Cart - ";
		return Transport::calculateTime(distance);
	}

	float calculateCost(float distance, float fuelWaste) const override {
		cout << "Cart - ";
		return Transport::calculateCost(distance, fuelWaste);
	}
};



class Employer {
protected:
	int salary;

public:
	Employer(int salary) : salary(salary) {}

	virtual ~Employer() {}

	virtual void print() const {
		cout << "Generic Employer" << endl;
		cout << "Salary: " << salary << endl;
	}
};



class President : public Employer {
public:
	President(int salary) : Employer(salary) {}
	
	void print() const override {
		cout << "President Details: " << endl;
		cout << "Salary: " << salary << endl;
	}
};

class Manager : public Employer {
public:
	Manager(int salary) : Employer(salary) {}
	
	void print() const override {
		cout << "Manager Details: " << endl;
		cout << "Salary: " << salary << endl;
	}
};

class Worker : public Employer {
public:
	Worker(int salary) : Employer(salary) {}
	
	void print() const override {
		cout << "Worker Details: " << endl;
		cout << "Salary: " << salary << endl;
	}
};



/*
int main() {
	// 1 task
	Car car;
	car.print();
	car.calculateTime(100);
	car.calculateCost(100, 5);
	cout << endl;

	Bicycle bicycle;
	bicycle.print();
	bicycle.calculateTime(100);
	bicycle.calculateCost(100, 2);
	cout << endl;
	
	Cart cart;
	cart.print();
	cart.calculateTime(100);
	cart.calculateCost(100, 10);
	cout << endl;

	// 2 task
	President president(1000000);
	president.print();
	cout << endl;

	Manager manager(50000);
	manager.print();
	cout << endl;

	Worker worker(30000);
	worker.print();

	return 0;
}
*/