#include <iostream>
#include <string>
#include <random>

using namespace std;



class Good {

private:
	string name;
	double price;
	string description;
	string manufacturer;
	int quantity;

public:

	Good() : name("Unnamed"), price(0), description("No description"), manufacturer("Unknown"), quantity(0) {}

	Good(string name, double price, string description, string manufacturer, int quantity)
		: name(name), price(price), description(description), manufacturer(manufacturer), quantity(quantity) {
	}

	Good(const Good &other) {
		name = other.name;
		price = other.price;
		description = other.description;
		manufacturer = other.manufacturer;
		quantity = other.quantity;
	}

	~Good() {
		cout << "Deleting good: " << name << endl;
	}

	void setName(string name) { this->name = name; }
	void setPrice(double price) { this->price = price; }
	void setDescription(string description) { this->description = description; }
	void setManufacturer(string manufacturer) { this->manufacturer = manufacturer; }
	void setQuantity(int quantity) { this->quantity = quantity; }

	string getName() const { return name; }
	double getPrice() const { return price; }
	string getDescription() const { return description; }
	string getManufacturer() const { return manufacturer; }
	int getQuantity() const { return quantity; }

	void input() {
		cout << "Enter name: ";
		getline(cin, name);
		cout << "Enter price: ";
		cin >> price;
		cin.ignore();
		cout << "Enter description: ";
		getline(cin, description);
		cout << "Enter manufacturer: ";
		getline(cin, manufacturer);
		cout << "Enter quantity: ";
		cin >> quantity;
		cin.ignore();
	}

	void output() const {
		cout << "Name: " << name << endl;
		cout << "Price: " << price << endl;
		cout << "Description: " << description << endl;
		cout << "Manufacturer: " << manufacturer << endl;
		cout << "Quantity: " << quantity << endl;
	}

};



class Shop {

private:
	string name;
	Good *goods;
	int size;

public: 
	Shop() : name("Unnamed"), goods(nullptr), size(0) {}

	Shop(string name, int size = 0) : name(name), size(size) {
		if (size > 0) {
			goods = new Good[size];
		}
		else {
			goods = nullptr;
		}
	}

	Shop(const Shop &other) {
		name = other.name;
		size = other.size;
		goods = new Good[size];
		if (size > 0) {
			for (int i = 0; i < size; ++i) {
				goods[i] = other.goods[i];
			}
		}
		else {
			goods = nullptr;
		}
	}

	Shop &operator=(const Shop &other) {
		if (this == &other) {
			return *this;
		}
		
		delete[] goods;
		
		name = other.name;
		size = other.size;
		goods = new Good[size];
		if (size > 0) {
			for (int i = 0; i < size; ++i) {
				goods[i] = other.goods[i];
			}
		}
		else {
			goods = nullptr;
		}
		return *this;
	}

	~Shop() {
		cout << "Deleting shop: " << name << endl;
		delete[] goods;
	}

	void setName(string name) { this->name = name; }
	void setSize(int size) { this->size = size; }
	void setGoods(Good *goods) { this->goods = goods; }
	void setGood(int index, Good good) {
		if (index >= 0 && index < size) {
			goods[index] = good;
		}
		else {
			cout << "Index out of bounds." << endl;
		}
	}

	string getName() const { return name; }
	int getSize() const { return size; }
	Good *getGoods() const { return goods; }
	Good getGood(int index) const {
		if (index >= 0 && index < size) {
			return goods[index];
		}
		else {
			cout << "Index out of bounds." << endl;
			return Good();
		}
	}

	void input() {
		cout << "Enter shop name: ";
		getline(cin, name);
		cout << "Enter number of goods: ";
		cin >> size;
		cin.ignore();
		
		delete[] goods;
		if (size > 0) {
			goods = new Good[size];
			for (int i = 0; i < size; ++i) {
				cout << "Enter details for good " << i + 1 << ":" << endl;
				goods[i].input();
			}
		}
		else {
			goods = nullptr;
		}
	}

	void randomFill(int size) {
		srand(time(0));
		string names[] = { "Молоко", "Хлеб", "Сок", "Кофе", "Сыр" };
		string manufacturers[] = { "АстанаПродукт", "FoodCorp", "KazMilk", "NomadFarms", "AsiaFoods" };
		
		delete[] goods;
		goods = new Good[size];

		for (int i = 0; i < size; ++i) {
			string name = names[rand() % 5];
			double price = (rand() % 1000) + 1;
			string description = "Description of " + name;
			string manufacturer = manufacturers[rand() % 5];
			int quantity = (rand() % 50);
			goods[i] = Good(name, price, description, manufacturer, quantity);
		}
	}

	void printAll() const {
		cout << "Shop Name: " << name << endl;
		cout << "Number of Goods: " << size << endl;
		for (int i = 0; i < size; ++i) {
			cout << "Good " << i + 1 << ":" << endl;
			goods[i].output();
		}
	}

	void printInRange(double minPrice, double maxPrice) const {
		cout << "Goods in price range [" << minPrice << ", " << maxPrice << "]:" << endl;
		for (int i = 0; i < size; ++i) {
			if (goods[i].getPrice() >= minPrice && goods[i].getPrice() <= maxPrice) {
				goods[i].output();
			}
		}
	}

	void searchByName(string name) const {
		cout << "Searching for goods with name: " << name << endl;
		for (int i = 0; i < size; ++i) {
			if (goods[i].getName() == name) {
				goods[i].output();
			}
		}
	}

	void searchByManufacturer(string manufacturer) const {
		cout << "Searching for goods by manufacturer: " << manufacturer << endl;
		for (int i = 0; i < size; ++i) {
			if (goods[i].getManufacturer() == manufacturer) {
				goods[i].output();
			}
		}
	}

	void sortByName() {
		for (int i = 0; i < size - 1; ++i) {
			for (int j = 0; j < size - i - 1; ++j) {
				if (goods[j].getName() > goods[j + 1].getName()) {
					swap(goods[j], goods[j + 1]);
				}
			}
		}
	}

	void sortByPrice() {
		for (int i = 0; i < size - 1; ++i) {
			for (int j = 0; j < size - i - 1; ++j) {
				if (goods[j].getPrice() > goods[j + 1].getPrice()) {
					swap(goods[j], goods[j + 1]);
				}
			}
		}
	}
};