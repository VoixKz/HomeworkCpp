#include <iostream>
#include <string>
#include <random>

using namespace std;



class Human {

private: 
	string name;
	int age;

public:
	explicit Human() : name("Unnamed"), age(0) {}

	explicit Human(string name, int age) : name(name), age(age) {}

	Human(const Human &other) {
		name = other.name;
		age = other.age;
	}

	Human &operator=(const Human &other) {
		if (this == &other) {
			return *this;
		}
		name = other.name;
		age = other.age;
		return *this;
	}

	~Human() {
		cout << "Deleting human: " << name << endl;
	}

	void setName(string name) { this->name = name; }
	void setAge(int age) { this->age = age; }

	string getName() const { return name; }
	int getAge() const { return age; }

	void input() {
		cout << "Enter name: ";
		getline(cin, name);
		cout << "Enter age: ";
		cin >> age;
		cin.ignore();
	}

	void output() const {
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
	}
};



class Apartment {

private:
	int number;
	int residentsCount;
	Human *residents;

public:
	explicit Apartment() : number(0), residentsCount(0), residents(nullptr) {}

	explicit Apartment(int number, int residentsCount, Human *residents)
		: number(number), residentsCount(residentsCount), residents(residents) {
	}

	Apartment(const Apartment &other) {
		number = other.number;
		residentsCount = other.residentsCount;
		residents = new Human[residentsCount];
		for (int i = 0; i < residentsCount; ++i) {
			residents[i] = other.residents[i];
		}
	}

	Apartment &operator=(const Apartment &other) {
		if (this == &other) {
			return *this;
		}
		number = other.number;
		residentsCount = other.residentsCount;
		delete[] residents;
		residents = new Human[residentsCount];
		for (int i = 0; i < residentsCount; ++i) {
			residents[i] = other.residents[i];
		}
		return *this;
	}

	~Apartment() {
		cout << "Deleting apartment number: " << number << endl;
		delete[] residents;
	}

	void printResidents() const {
		cout << "Apartment number: " << number << endl;
		cout << "Residents count: " << residentsCount << endl;
		for (int i = 0; i < residentsCount; ++i) {
			residents[i].output();
			cout << endl;
		}
	}

	void addResident(const Human &human) {
		Human *newResidents = new Human[residentsCount + 1];
		for (int i = 0; i < residentsCount; ++i) {
			newResidents[i] = residents[i];
		}
		newResidents[residentsCount] = human;
		delete[] residents;
		residents = newResidents;
		residentsCount++;
	}

	int getNumber() const { return number; }
	int getResidentsCount() const { return residentsCount; }
};



class House {

private:
	Apartment *apartments;
	int apartmentCount;

public:
	explicit House(int count = 0) : apartmentCount(count) {
		apartments = new Apartment[apartmentCount];
	}

	House(const House &other) {
		apartmentCount = other.apartmentCount;
		apartments = new Apartment[apartmentCount];
		for (int i = 0; i < apartmentCount; ++i) {
			apartments[i] = other.apartments[i];
		}
	}

	House &operator=(const House &other) {
		if (this == &other) {
			return *this;
		}
		apartmentCount = other.apartmentCount;
		delete[] apartments;
		apartments = new Apartment[apartmentCount];
		for (int i = 0; i < apartmentCount; ++i) {
			apartments[i] = other.apartments[i];
		}
		return *this;
	}

	~House() {
		cout << "Deleting house with " << apartmentCount << " apartments." << endl;
		delete[] apartments;
	}

	void addApartment(const Apartment &apartment) {
		Apartment *newApartments = new Apartment[apartmentCount + 1];
		for (int i = 0; i < apartmentCount; ++i) {
			newApartments[i] = apartments[i];
		}
		newApartments[apartmentCount] = apartment;
		delete[] apartments;
		apartments = newApartments;
		apartmentCount++;
	}

	void printApartments() const {
		for (int i = 0; i < apartmentCount; ++i) {
			apartments[i].printResidents();
			cout << endl;
		}
	}
};

/*
int main() {
	House house(2);

	Human *residents1 = new Human[2];
	residents1[0] = Human("Alice", 30);
	residents1[1] = Human("Bob", 35);
	Apartment apartment1(101, 2, residents1);
	house.addApartment(apartment1);
	Human *residents2 = new Human[3];
	residents2[0] = Human("Charlie", 40);
	residents2[1] = Human("David", 45);
	residents2[2] = Human("Eve", 50);
	Apartment apartment2(102, 3, residents2);
	house.addApartment(apartment2);
	house.printApartments();
	delete[] residents1;
	delete[] residents2;
	return 0;
}
*/