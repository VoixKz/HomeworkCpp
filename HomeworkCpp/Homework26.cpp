#include <iostream>

using namespace std;



class Pet {
protected:
	string name;
	int age;

public:
	Pet(string n, int a) : name(n), age(a) {}

	virtual void sound() const = 0;

	virtual void type() const = 0;

	virtual void show() const {
		cout << "Name: " << name << ", Age: " << age << endl;
	}

	virtual ~Pet() {}
};



class Dog : public Pet {
private:
	string breed;

public:
	Dog(string n, int a, string b) : Pet(n, a), breed(b) {}
	
	void sound() const override {
		cout << "Woof!" << endl;
	}
	
	void type() const override {
		cout << "Dog - " << breed << endl;
	}
	
	void show() const override {
		Pet::show();
	}
};



class Cat : public Pet {
private:
	string color;

public:
	Cat(string n, int a, string c) : Pet(n, a), color(c) {}

	void sound() const override {
		cout << "Meow!" << endl;
	}

	void type() const override {
		cout << "Cat - " << color << endl;
	}

	void show() const override {
		Pet::show();
	}
};



class Parrot : public Pet {
private:
	string species;

public:
	Parrot(string n, int a, string s) : Pet(n, a), species(s) {}
	
	void sound() const override {
		cout << "Kar kar!" << endl;
	}
	
	void type() const override {
		cout << "Parrot - " << species << endl;
	}
	
	void show() const override {
		Pet::show();
	}
};



class Hamster : public Pet {
private:
	string color;

public:
	Hamster(string n, int a, string c) : Pet(n, a), color(c) {}
	
	void sound() const override {
		cout << "Squeak!" << endl;
	}
	
	void type() const override {
		cout << "Hamster - " << color << endl;
	}
	
	void show() const override {
		Pet::show();
	}
};



/*
int main() {
	Dog myDog("Buddy", 3, "Golden Retriever");
	myDog.show();
	myDog.sound();
	myDog.type();
	cout << endl;

	Cat myCat("Whiskers", 2, "Tabby");
	myCat.show();
	myCat.sound();
	myCat.type();
	cout << endl;

	Parrot myParrot("Polly", 5, "African Grey");
	myParrot.show();
	myParrot.sound();
	myParrot.type();
	cout << endl;

	Hamster myHamster("Nibbles", 1, "Golden");
	myHamster.show();
	myHamster.sound();
	myHamster.type();
	cout << endl;
	
	return 0;
}
*/