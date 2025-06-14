#include <iostream>
#include <vector>

using namespace std;



class Pet {
private:
	string name;
	int age;
	string color;

public:
	Pet(string name, int age, string color) : name(name), age(age), color(color) {}
	
	virtual void print() const {
		cout << "Name: " << name << ", Age: " << age << ", Color: " << color << endl;
	}

	virtual ~Pet() {}
};



class Dog : public Pet {
private:
	string breed;

public:
	Dog(string name, int age, string color, string breed)
		: Pet(name, age, color), breed(breed) {
	}

	void print() const override {
		Pet::print();
		cout << "Breed: " << breed << endl;
	}
};



class Cat : public Pet {
private:
	bool likesSwim;

public:
	Cat(string name, int age, string color, bool likesSwim)
		: Pet(name, age, color), likesSwim(likesSwim) {
	}

	void print() const override {
		Pet::print();
		cout << "Likes to swim: " << (likesSwim ? "Yes" : "No") << endl;
	}
};



class Parrot : public Pet {
private:
	bool canTalk;

public:
	Parrot(string name, int age, string color, bool canTalk)
		: Pet(name, age, color), canTalk(canTalk) {
	}
	
	void print() const override {
		Pet::print();
		cout << "Can talk: " << (canTalk ? "Yes" : "No") << endl;
	}
};



class Certificate {
protected:
	string fullName;
	string idNumber;
	string birthDate;
	string nationality;

public:
	Certificate(string name, string id, string birth)
		: fullName(name), idNumber(id), birthDate(birth) {
		nationality = "Kazakhstan";
	}

	virtual void print() const {
		cout << "Full Name: " << fullName << endl;
		cout << "ID Number: " << idNumber << endl;
		cout << "Birth Date: " << birthDate << endl;
		cout << "Nationality: " << nationality << endl;
	}

	virtual ~Certificate() {}
};



class ForeignPassport : public Certificate {
private:
	string foreignPassportNumber;
	vector<string> visas;

public:
	ForeignPassport(string name, string id, string birth, string passportNumber)
		: Certificate(name, id, birth), foreignPassportNumber(passportNumber) {
	}

	void addVisa(const string &visa) {
		visas.push_back(visa);
	}

	void print() const override {
		Certificate::print();
		cout << "Foreign Passport Number: " << foreignPassportNumber << endl;
		cout << "Visas: ";
		if (visas.empty()) {
			cout << "None" << endl;
		}
		else {
			for (const string &visa : visas) {
				cout << visa << " ";
			}
			cout << endl;
		}
	}

	~ForeignPassport() override = default;
};



/*
int main() {
	
	//1 task
	Dog dog("Buddy", 4, "Brown", "Labrador");
	Cat cat("Whiskers", 2, "White", true);
	Parrot parrot("Polly", 1, "Green", true);
	dog.print();
	cat.print();
	parrot.print();


	//2 task
	ForeignPassport person("Bexultan Nurlybek", "123456789", "2006-10-15", "FP987654321");
	person.addVisa("USA");
	person.addVisa("Germany");
	person.addVisa("Japan");
	person.print();


	return 0;
}
*/