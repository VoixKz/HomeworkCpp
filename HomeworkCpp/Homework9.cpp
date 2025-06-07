#include <iostream>
#include <string>
using namespace std;

class Reservoir {
private:
    string name;
    double length;
    double width;
    double depth;
    string type;

public:
    Reservoir() : name("Unnamed"), length(0), width(0), depth(0), type("Unknown") {}

    Reservoir(string name, double length, double width, double depth, string type)
        : name(name), length(length), width(width), depth(depth), type(type) {
    }

    Reservoir(const Reservoir &other) {
        name = other.name;
        length = other.length;
        width = other.width;
        depth = other.depth;
        type = other.type;
    }

    ~Reservoir() {
        cout << "Deleting reservoir: " << name << endl;
    }

    void setName(string name) { name = name; }
    void setLength(double length) { length = length; }
    void setWidth(double width) { width = width; }
    void setDepth(double depth) { depth = depth; }
    void setType(string type) { type = type; }

    string getName() const { return name; }
    double getLength() const { return length; }
    double getWidth() const { return width; }
    double getDepth() const { return depth; }
    string getType() const { return type; }

    double calculateVolume() const {
        return length * width * depth;
    }

    double surfaceArea() const {
        return length * width;
    }

    bool isSameType(const Reservoir &other) const {
        return type == other.type;
    }

    void compareSurfaceArea(const Reservoir &other) const {
        if (!isSameType(other)) {
            cout << "Reservoirs are of different types and cannot be compared.\n";
            return;
        }
        double area1 = surfaceArea();
        double area2 = other.surfaceArea();
        cout << "Surface area of \"" << name << "\": " << area1 << " m^2\n";
        cout << "Surface area of \"" << other.name << "\": " << area2 << " m^2\n";
        if (area1 > area2)
            cout << name << " has a larger surface area.\n";
        else if (area1 < area2)
            cout << other.name << " has a larger surface area.\n";
        else
            cout << "Surface areas are equal.\n";
    }

    Reservoir copy() const {
        return Reservoir(*this);
    }

    void print() const {
        cout << "Name: " << name << "\nType: " << type << "\nLength: " << length
            << " m\nWidth: " << width << " m\nDepth: " << depth
            << " m\nSurface area: " << surfaceArea() << " m^2\nVolume: " << calculateVolume() << " m^3\n";
    }
};

/*
int main() {
    Reservoir r1("Balkhash", 2000, 1500, 30, "lake");
    Reservoir r2("Caspian Sea", 5000, 3000, 100, "sea");
    Reservoir r3 = r1.copy();

    cout << "\nReservoir r1:\n";
    r1.print();

    cout << "\nReservoir r2:\n";
    r2.print();

    cout << "\nComparing r1 and r2:\n";
    r1.compareSurfaceArea(r2);

    cout << "\nCopy of r1 (r3):\n";
    r3.print();

    return 0;
}
*/
