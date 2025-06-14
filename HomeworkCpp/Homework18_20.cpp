#include <iostream>
#include <vector>
#include <ctime>

using namespace std;



template <typename T>
class QueuePrior {
private:
	vector<pair<T, int>> data;
	int maxSize;

public:
	QueuePrior(int maxSize) : maxSize(maxSize) {
		if (maxSize < 0) {
			throw invalid_argument("���������� ��������� �� ����� ���� �������������!");
		}
		else if (maxSize == 0) {
			throw invalid_argument("������� �� ����� ���� ������!");
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
		cout << "������� �������!" << endl;
	}

	bool isEmpty() const {
		return data.empty();
	}

	bool isFull() const {
		return data.size() >= maxSize;
	}

	void enQueue(const T& value, int priority = 0) {
		if (isFull()) {
			throw overflow_error("������� �����������!");
		}
		auto it = data.begin();
		while (it != data.end() && it->second >= priority) {
			++it;
		}
		data.insert(it, { value, priority });
	}

	void deQueue() {
		if (isEmpty()) {
			throw underflow_error("������� �����!");
		}
		data.erase(data.begin());
	}

	T peek() const {
		if (isEmpty()) {
			throw underflow_error("������� �����!");
		}
		return data.front().first;
	}

	friend ostream& operator<<(ostream& os, const QueuePrior& queue) {
		os << "�������: ";
		for (const auto& item : queue.data) {
			os << "(" << item.first << ", " << item.second << ") ";
		}
		return os;
	}
};



struct PrintJob {
	string user;
	string document;

	friend ostream &operator<<(ostream &os, const PrintJob &job) {
		os << "User: " << job.user << ", Document: " << job.document;
		return os;
	}
};



struct PrintStat {
	PrintJob job;
	string startTime;

	friend ostream &operator<<(ostream &os, const PrintStat &stat) {
		os << "Print Job: [" << stat.job << "], Start Time: " << stat.startTime;
		return os;
	}
};



string getCurrentTime() {
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);
	char buffer[20];
	sprintf_s(buffer, sizeof(buffer), "%02d:%02d:%02d", ltm.tm_hour, ltm.tm_min, ltm.tm_sec);
	return string(buffer);
}



int main() {
	QueuePrior<string> q(4);

	q.enQueue("low", 1);
	q.enQueue("high", 10);
	q.enQueue("medium", 5);
	q.enQueue("mid-high", 7);

	cout << q << endl;
	cout << "������ ������� (peek): " << q.peek() << endl;

	q.deQueue();
	cout << "����� ��������:\n" << q << endl;


	cout << "\n--- ���� ������� ������ ---" << endl;
	QueuePrior<PrintJob> printQueue(3);
	vector<PrintStat> printLog;

	printQueue.enQueue({ "Alice", "Report.pdf" }, 4);
	printQueue.enQueue({ "Bob", "CV.docx" }, 6);
	printQueue.enQueue({ "Charlie", "Thesis.pdf" }, 2);

	cout << "������� ������� ������:\n" << printQueue << endl;

	while (!printQueue.isEmpty()) {
		PrintJob job = printQueue.peek();
		string time = getCurrentTime();
		printLog.push_back({ job, time });
		printQueue.deQueue();
	}

	cout << "\n���������� ������:\n";
	for (const auto &stat : printLog) {
		cout << stat << endl;
	}

	return 0;
}

