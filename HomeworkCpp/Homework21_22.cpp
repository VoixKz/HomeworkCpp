#include <iostream>
#include <vector>

using namespace std;



struct Violation {
	string date;
	string description;

	Violation(string d, string desc) : date(d), description(desc) {}

	void print() const {
		cout << "\tDate: " << date << endl << "\tDescription: " << description << endl;
	}
};

struct TreeNode {
    string carNumber;
    vector<Violation> violations;
    TreeNode *left;
    TreeNode *right;

    TreeNode(string number, const Violation &v)
        : carNumber(number), violations{v}, left(nullptr), right(nullptr) {}
};



class TrafficDB {
private:
	TreeNode *root;

	TreeNode *insert(TreeNode *node, const string &carNumber, const Violation &violation) {
		if (!node) {
			return new TreeNode(carNumber, violation);
		}
		if (carNumber < node->carNumber) {
			node->left = insert(node->left, carNumber, violation);
		}
		else if (carNumber > node->carNumber) {
			node->right = insert(node->right, carNumber, violation);
		}
		else {
			node->violations.push_back(violation);
		}
		return node;
	}

	void printInOrder(TreeNode *node) const {
		if (!node) return;
		printInOrder(node->left);
		cout << "Car Number: " << node->carNumber << endl;
		for (const auto &v : node->violations) {
			v.print();
		}
		printInOrder(node->right);
	}

	TreeNode *find(TreeNode *node, const string &carNumber) const {
		if (!node) return nullptr;
		if (carNumber < node->carNumber) {
			return find(node->left, carNumber);
		}
		else if (carNumber > node->carNumber) {
			return find(node->right, carNumber);
		}
		return node;
	}

	void printInRange(TreeNode *node, const string &start, const string &end) const {
		if (!node) return;
		if (node->carNumber >= start && node->carNumber <= end) {
			printInRange(node->left, start, end);
			cout << "Car Number: " << node->carNumber << endl;
			for (const auto &v : node->violations) {
				v.print();
			}
			printInRange(node->right, start, end);
		}
		else if (node->carNumber < start) {
			printInRange(node->right, start, end);
		}
		else {
			printInRange(node->left, start, end);
		}
	}

	void clear(TreeNode *node) {
		if (!node) return;
		clear(node->left);
		clear(node->right);
		delete node;
	}

public:
	~TrafficDB() { clear(root); }

	void addViolation(const string &number, const string &date, const string &description) {
		Violation v(date, description);
		root = insert(root, number, v);
	}

	void printAll() const {
		cout << "All Violations in Database:" << endl;
		printInOrder(root);
	}

	void printByNumber(const string &carNumber) const {
		TreeNode *node = find(root, carNumber);
		if (node) {
			cout << "Violations for Car Number: " << carNumber << endl;
			for (const auto &v : node->violations) {
				v.print();
			}
		}
		else {
			cout << "No violations found for Car Number: " << carNumber << endl;
		}
	}

	void printInRange(const string &start, const string &end) const {
		cout << "Violations in range [" << start << ", " << end << "]:" << endl;
		printInRange(root, start, end);
	}
};



/*
int main() {
	TrafficDB db;

	db.addViolation("KZ123ABC", "2025-06-01", "Превышение скорости");
	db.addViolation("KZ456XYZ", "2025-06-03", "Неправильная парковка");
	db.addViolation("KZ123ABC", "2025-06-07", "Проезд на красный");
	db.addViolation("KZ999QWE", "2025-06-04", "Отсутствие страховки");
	db.addViolation("KZ345AAA", "2025-06-05", "Нарушение разметки");

	db.printAll();

	db.printByNumber("KZ123ABC");
	db.printByNumber("KZ000XYZ");

	db.printInRange("KZ200AAA", "KZ800ZZZ");

	return 0;
}
*/