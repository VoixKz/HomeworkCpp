#include <iostream>

using namespace std;



template <typename T>
class Node {

public:
	T data;
	Node<T> *next;

	Node(T value) : data(value), next(nullptr) {}
};



template <typename T>
class Stack {
private:
	Node<T> *top;
	int size;
	int maxSize;

	void increaseMaxSize() {
		maxSize *= 2;
		cout << "Увеличение размера стека до " << maxSize << endl;
	}

public:
	Stack(int initialMaxSize = 4) :
		top(nullptr),
		size(0),
		maxSize(initialMaxSize) {
	}

	~Stack() {
		while (!isEmpty()) {
			pop();
		}
	}

	bool isEmpty() const { return top == nullptr; }
	int getSize() const { return size; }
	int getMaxSize() const { return maxSize; }
	
	void push(const T &value) {
		if (size >= maxSize) {
			increaseMaxSize();
		}

		Node<T> *newNode = new Node<T>(value);
		newNode->next = top;
		top = newNode;
		size++;
	}
	
	void pop() {
		if (isEmpty()) {
			throw underflow_error("Стек пуст!");
		}
		Node<T> *temp = top;
		top = top->next;
		delete temp;
		size--;
	}
	
	T peek() const {
		if (isEmpty()) {
			throw underflow_error("Стек пуст!");
		}
		return top->data;
	}

	void display() const {
		if (isEmpty()) {
			cout << "Стек пуст!" << endl;
			return;
		}
		Node<T> *current = top;
		while (current != nullptr) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}

	Stack operator+(const Stack &other) const {
		Stack result(max(maxSize, other.maxSize));
		Node<T> *current = top;
		while (current != nullptr) {
			result.push(current->data);
			current = current->next;
		}
		current = other.top;
		while (current != nullptr) {
			result.push(current->data);
			current = current->next;
		}
		return result;
	}

	Stack operator*(const Stack &other) const {
		Stack result(max(maxSize, other.maxSize));
		Node<T> *current = top;
		while (current != nullptr) {
			if (other.contains(current->data)) {
				result.push(current->data);
			}
			current = current->next;
		}
		return result;
	}

	bool contains(const T &value) const {
		Node<T> *current = top;
		while (current != nullptr) {
			if (current->data == value) {
				return true;
			}
			current = current->next;
		}
		return false;
	}
};



/*
int main() {
	Stack<int> stack1(2);
	stack1.push(10);
	stack1.push(20);
	stack1.display();

	stack1.push(30);  // Вместимость увеличивается
	stack1.push(40);
	stack1.display();

	stack1.pop();
	stack1.display();

	cout << "Верхний элемент: " << stack1.peek() << endl;
	cout << "Размер: " << stack1.getSize() << ", Вместимость: " << stack1.getMaxSize() << endl;

	// 2 задание
	Stack<int> stack2(2);
	stack2.push(50);
	stack2.push(20);
	stack2.push(60);

	cout << "\nStack2: ";
	stack2.display();

	Stack<int> sumStack = stack1 + stack2;
	cout << "Результат operator+ (объединение): ";
	sumStack.display();

	Stack<int> interStack = stack1 * stack2;
	cout << "Результат operator* (пересечение): ";
	interStack.display();

	return 0;
}
*/