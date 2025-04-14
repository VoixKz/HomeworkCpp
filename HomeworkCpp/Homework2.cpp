#include <iostream>
#include <string>

using namespace std;

class Product {
private:
    string name;          
    double price;         
    string description;   
    string manufacturer;  
    int quantity;

public:
    
    Product() : price(0.0), quantity(0) {}

    Product(string name, double price, string description, string manufacturer, int quantity)
        : name(name), price(price), description(description), manufacturer(manufacturer), quantity(quantity) {
    }

    void input() {
        cout << "Enter product name: ";
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
        cout << "\nProduct: " << name << endl;
        cout << "Price: " << price << " KZT " << endl;
        cout << "Description: " << description << endl;
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Quantity: " << quantity << endl;
    }
    
    void setName(const string &newName) { name = newName; }
    void setPrice(double newPrice) { price = newPrice; }
    void setDescription(const string &newDescription) { description = newDescription; }
    void setManufacturer(const string &newManufacturer) { manufacturer = newManufacturer; }
    void setQuantity(int newQuantity) { quantity = newQuantity; }
    
    string getName() const { return name; }
    double getPrice() const { return price; }
    string getDescription() const { return description; }
    string getManufacturer() const { return manufacturer; }
    int getQuantity() const { return quantity; }
};


/*
int main() {

    system("chcp 65001");
    
    Product product1;

    product1.input();
    product1.output();

    return 0;
}
*/