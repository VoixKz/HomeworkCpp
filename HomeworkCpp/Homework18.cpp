#include <iostream>
#include <vector>

using namespace std;



template <typename T>
class QueuePrior {
private:
	vector<pair<T, int>> data;
	int maxSize;

public:
	QueuePrior(int maxSize) : maxSize(maxSize) {
		if (maxSize < 0) {
			throw invalid_argument("Количество элементов не может быть отрицательным!");
		}
		else if (maxSize == 0) {
			throw invalid_argument("Очередь не может быть пустой!");
		}
	}

	QueuePrior(const QueuePrior& other) : data(other.data), maxSize(other.maxSize) {}

	QueuePrior& operator=(const QueuePrior& other) {
		if (this != &other) {
			data = other.data;
			maxSize = other.maxSize;
		}
		return *this;
	}

	~QueuePrior() {
		cout << "Очередь удалена!" << endl;
	}

	bool isEmpty() const {
		return data.empty();
	}

	bool isFull() const {
		return data.size() >= maxSize;
	}

	void enQueue(const T& value, int priority = 0) {
		if (isFull()) {
			throw overflow_error("Очередь переполнена!");
		}
		auto it = data.begin();
		while (it != data.end() && it->second >= priority) {
			++it;
		}
		data.insert(it, { value, priority });
	}

	void deQueue() {
		if (isEmpty()) {
			throw underflow_error("Очередь пуста!");
		}
		data.erase(data.begin());
	}

	T peek() const {
		if (isEmpty()) {
			throw underflow_error("Очередь пуста!");
		}
		return data.front().first;
	}

	friend ostream& operator<<(ostream& os, const QueuePrior& queue) {
		os << "Очередь: ";
		for (const auto& item : queue.data) {
			os << "(" << item.first << ", " << item.second << ") ";
		}
		return os;
	}
};



int main() {
	QueuePrior<string> q(5);

	q.enQueue("low", 1);
	q.enQueue("medium", 5);
	q.enQueue("high", 10);
	q.enQueue("mid-high", 7);

	cout << q;

	cout << "Peek: " << q.peek() << endl;

	q.deQueue();
	cout << "\nAfter Dequeue:\n" << q;

	return 0;
}
