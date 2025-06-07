#include <iostream>
#include <string>
#include <random>

using namespace std;



class Worker {

private:
	string name;
	string occupation;
	int entranceYear;
	int salary;

public:
	explicit Worker() : name("Unnamed"), occupation("Unknown"), entranceYear(0), salary(0) {}
	
	explicit Worker(string name, string occupation, int entranceYear, int salary)
		: name(name), occupation(occupation), entranceYear(entranceYear), salary(salary) {
	}
	
	Worker(const Worker &other) {
		name = other.name;
		occupation = other.occupation;
		entranceYear = other.entranceYear;
		salary = other.salary;
	}

	~Worker() {
		cout << "Deleting worker: " << name << endl;
	}

	void setName(string name) { this->name = name; }
	void setOccupation(string occupation) { this->occupation = occupation; }
	void setEntranceYear(int entranceYear) { this->entranceYear = entranceYear; }
	void setSalary(int salary) { this->salary = salary; }
	
	string getName() const { return name; }
	string getOccupation() const { return occupation; }
	int getEntranceYear() const { return entranceYear; }
	int getSalary() const { return salary; }
	
	void input() {
		cout << "Enter name: ";
		getline(cin, name);
		cout << "Enter occupation: ";
		getline(cin, occupation);
		cout << "Enter entrance year: ";
		cin >> entranceYear;
		cin.ignore();
		cout << "Enter salary: ";
		cin >> salary;
		cin.ignore();
	}
	
	void output() const {
		cout << "Name: " << name << endl;
		cout << "Occupation: " << occupation << endl;
		cout << "Entrance Year: " << entranceYear << endl;
		cout << "Salary: " << salary << endl;
	}

};



class ListWorkers {

private:
	int size;
	Worker *workers;

public:
	ListWorkers() : size(0), workers(nullptr) {}
	
	ListWorkers(int size) : size(size) {
		workers = new Worker[size];
	}
	
	ListWorkers(const ListWorkers &other) {
		size = other.size;
		workers = new Worker[size];
		for (int i = 0; i < size; ++i) {
			workers[i] = other.workers[i];
		}
	}

	ListWorkers &operator = (const ListWorkers &other) {
		if (this == &other) {
			return *this;
		}

		delete[] workers;

		size = other.size;
		workers = new Worker[size];
		for (int i = 0; i < size; ++i) {
			workers[i] = other.workers[i];
		}

		return *this;
	}
	
	~ListWorkers() {
		cout << "Deleting list of workers." << endl;
		delete[] workers;
	}
	
	void addWorker(const Worker &worker) {
		Worker *newArr = new Worker[size + 1];
		for (int i = 0; i < size; ++i) {
			newArr[i] = workers[i];
		}
		newArr[size] = worker;
		delete[] workers;
		workers = newArr;
		size++;
	}

	void addWorkers(const Worker *newWorkers, int count) {
		Worker *newArr = new Worker[size + count];
		for (int i = 0; i < size; ++i) {
			newArr[i] = workers[i];
		}

		for (int i = 0; i < count; ++i) {
			newArr[size + i] = newWorkers[i];
		}
		
		delete[] workers;
		workers = newArr;
		size += count;
	}

	void removeByName(const string &name) {
		int newSize = 0;
		for (int i = 0; i < size; ++i) {
			if (workers[i].getName() != name) {
				newSize++;
			}
		}
		Worker *newArr = new Worker[newSize];
		int j = 0;
		for (int i = 0; i < size; ++i) {
			if (workers[i].getName() != name) {
				newArr[j++] = workers[i];
			}
		}

		delete[] workers;
		workers = newArr;
		size = newSize;
	}

	void removeByOccupation(const string &occupation) {
		int newSize = 0;
		for (int i = 0; i < size; ++i) {
			if (workers[i].getOccupation() != occupation) {
				newSize++;
			}
		}
		Worker *newArr = new Worker[newSize];
		int j = 0;
		for (int i = 0; i < size; ++i) {
			if (workers[i].getOccupation() != occupation) {
				newArr[j++] = workers[i];
			}
		}
		delete[] workers;
		workers = newArr;
		size = newSize;
	}

	void removeByExperience(int years) {
		int newSize = 0;
		for (int i = 0; i < size; ++i) {
			if (2025 - workers[i].getEntranceYear() >= years) {
				newSize++;
			}
		}
		Worker *newArr = new Worker[newSize];
		int j = 0;
		for (int i = 0; i < size; ++i) {
			if (2025 - workers[i].getEntranceYear() >= years) {
				newArr[j++] = workers[i];
			}
		}
		delete[] workers;
		workers = newArr;
		size = newSize;
	}

	void sortByName() {
		for (int i = 0; i < size - 1; ++i) {
			for (int j = 0; j < size - i - 1; ++j) {
				if (workers[j].getName() > workers[j + 1].getName()) {
					swap(workers[j], workers[j + 1]);
				}
			}
		}
	}

	void sortByEntranceYear() {
		for (int i = 0; i < size - 1; ++i) {
			for (int j = 0; j < size - i - 1; ++j) {
				if (workers[j].getEntranceYear() > workers[j + 1].getEntranceYear()) {
					swap(workers[j], workers[j + 1]);
				}
			}
		}
	}

	void sortBySalary() {
		for (int i = 0; i < size - 1; ++i) {
			for (int j = 0; j < size - i - 1; ++j) {
				if (workers[j].getSalary() > workers[j + 1].getSalary()) {
					swap(workers[j], workers[j + 1]);
				}
			}
		}
	}

	void printAll() const {
		for (int i = 0; i < size; ++i) {
			workers[i].output();
			cout << endl;
		}
	}

	void printByExperience(int years) const {
		for (int i = 0; i < size; ++i) {
			if (2025 - workers[i].getEntranceYear() >= years) {
				workers[i].output();
				cout << endl;
			}
		}
	}

	void printByOccupation(const string &occupation) const {
		for (int i = 0; i < size; ++i) {
			if (workers[i].getOccupation() == occupation) {
				workers[i].output();
				cout << endl;
			}
		}
	}

	void printBySalary(int maxSalary) const {
		for (int i = 0; i < size; ++i) {
			if (workers[i].getSalary() <= maxSalary) {
				workers[i].output();
				cout << endl;
			}
		}
	}
};