#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

#define RND(min, max)  (rand()%((max)-(min)+1)+(min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { system("pause > nul"); } }_;


/*
����������� �����������
�������� �����������

�������� ����� Array (��� ����������� �����
��������� ����).
����� Array - ��� ����� ������������� �������.
������ ������� ����� ���� ������� � ��������
��������� ��� ����� � ������� ������ �������-�����.
����� ������ ��������� ��������� ������ ����������,
���������� ���������� �������, ��������
������ �������, ����������� ������, ����������
����������� � ������������ ��������.
����� ������ ��������� ����� �������������
(����������� ����������� ����������), ����������.
*/

class Array {
private:
    int *Data; // �������� ������
    int Size; // ������� ������ �������
public:
    // ������������ ������ Array
    //   ������������� ������������

    Array() : Size(), Data() {}

    explicit Array(int newSize) : Array() {
        setSize(newSize);
    }

    Array(const int *mas, int masSize) : Array() {
        setData(mas, masSize);
    }


    // ����������� � �������� �����������
    Array(const Array &obj) : Array() {
        *this = obj;
    }

    Array &operator=(const Array &obj) {
        if (this == &obj) return *this;

        setData(obj.Data, obj.Size);
        return *this;
    }

    // ���������� ������ Array
    ~Array() {
        delete[] this->Data;
    }

    // �������
    int getSize() const { return this->Size; }
    const int *getData() const { return this->Data; }

    // �������
    void setSize(int newSize)
    {
        int minSize = newSize < this->Size ?
            newSize : this->Size;

        int *temp = new int[newSize];

        for (int i = 0; i < minSize; i++) {
            temp[i] = this->Data[i];
        }

        delete[] this->Data;
        this->Size = newSize;
        this->Data = temp;
    }   // resize()

    void setData(const int *mas, int masSize) {
        setSize(masSize);

        for (int i = 0; i < masSize; i++) {
            this->Data[i] = mas[i];
        }
    }

    //
    void Show() const {
        for (int i = 0; i < this->Size; i++) {
            cout << this->Data[i] << ", ";
        }

        cout << endl;
    }

    void Input() {
        cout << "Enter size: " << endl;
        int size = 0;
        cin >> size;
        setSize(size);

        for (int i = 0; i < size; i++) {
            cout << "Enter data: ";
            int data;
            cin >> data;
            this->Data[i] = data;
        }

        cout << endl;
    }

    // ��������� ������ ����. ������� � ��������� [Min;Max]
    void InitRand(int Min, int Max) {
        for (int i = 0; i < this->Size; i++) {
            this->Data[i] = RND(Min, Max);
        }
    }
    // ������� ������ �������� Size � ��������� ����. ������� � ��������� [Min;Max]
    void InitRand(int Size, int Min, int Max) {
        setSize(Size);
        InitRand(Min, Max);
    }

    // �������� �� ������� �������� �� ������� index
    //  Data[index];
    int getAt(int index) const {
        if (index > this->Size || index < 0)
            throw exception("Index out of range");

        return this->Data[index];
    }

    int operator[] (int index) const {
        return getAt(index);
    }

    // ���������� ����� �������� val �� ������� index ������ �������
    // Data[index] = val;
    void setAt(int index, int val) {
        //if (index > this->Size || index < 0)
        //  throw exception("Index out of range");

        //this->Data[index] = val;

        (*this)[index] = val;

        //this->operator[](index) = val;
    }

    int &operator[] (int index) {
        if (index > this->Size || index < 0)
            throw exception("Index out of range");

        return this->Data[index];
    }

    // �������� �������� val � ������ �������
    //  ����� ������� ������������� �� 1
    void push_front(int val) {
        setSize(this->Size + 1);

        for (int i = this->Size - 1; i > 0; i--) {
            this->Data[i] = Data[i - 1];
        }

        this->Data[0] = val;
    }

    // �������� �������� val � ����� �������
    //  ����� ������� ������������� �� 1
    void push_back(int val) {
        setSize(this->Size + 1);
        this->Data[this->Size - 1] = val;
    }

    // �������� �������� val � ������ �� ������� index
    //  ����� ������� ������������� �� 1
    void insert(int index, int val) {
        if (index > this->Size || index < 0)
            throw exception("Index out of range");

        setSize(this->Size + 1);

        for (int i = this->Size - 1; i > index; i--) {
            this->Data[i] = this->Data[i - 1];
        }

        this->Data[index] = val;
    }

    // �������� ���. � ����. �������� �� �������
    int getMin() const {
		if (this->Size == 0) throw exception("Array is empty");
		int min = this->Data[0];
		for (int i = 1; i < this->Size; i++) {
			if (this->Data[i] < min) {
				min = this->Data[i];
			}
		}
		return min;
    };

    int getMax() const {
		if (this->Size == 0) throw exception("Array is empty");
		int max = this->Data[0];
        for (int i = 1; i < this->Size; i++) {
            if (this->Data[i] > max) {
                max = this->Data[i];
            }
        }
		return max;
    };

    // ������������� ������
    //  �� ��������� - �� ����������� 
    //  ���� Direct == fals - ������������� �� ��������
    void Sort(bool Direct = true) {
		for (int i = 0; i < this->Size - 1; i++) {
			for (int j = 0; j < this->Size - i - 1; j++) {
				if ((Direct && this->Data[j] > this->Data[j + 1]) ||
					(!Direct && this->Data[j] < this->Data[j + 1])) {
					swap(this->Data[j], this->Data[j + 1]);
				}
			}
		}
    };

    // ----------------------------------
    // ���������� ����������
    //
    // ������������� ��������� ������� ������ ()
    //  ����� �������� Search � ��������� ������� StartPos
    Array operator() (int Search, int StartPos) {
		if (StartPos < 0 || StartPos >= this->Size)
			throw exception("Index out of range");
		for (int i = StartPos; i < this->Size; i++) {
			if (this->Data[i] == Search) {
				return *this;
			}
		}
		throw exception("Value not found");
    };
    // ������� ������ �������� Size � ��������� ����. ������� � ��������� [Min;Max]
    Array operator() (int NewSize, int Min, int Max) {
		setSize(NewSize);
		InitRand(Min, Max);
		return *this;
    };


    // Array + int ==> Array  - �������� �� ���� ��������� �������� Value
    Array operator+ (int Value) {
		Array temp(*this);
		for (int i = 0; i < this->Size; i++) {
			temp.Data[i] += Value;
		}
		return temp;
    };

    // Array * int ==> Array  - �������� ��� �������� �� �������� Value
    Array operator* (int Value) {
		Array temp(*this);
        for (int i = 0; i < this->Size; i++) {
            temp.Data[i] *= Value;
        }
		return temp;
    };

    // Array + Array ==> Array   - ��������� ���� ��������, ������������ ��������
    Array operator+ (const Array &Other) {
		Array temp(this->Size + Other.Size);
		for (int i = 0; i < this->Size; i++) {
			temp.Data[i] = this->Data[i];
		}
		for (int i = 0; i < Other.Size; i++) {
			temp.Data[this->Size + i] = Other.Data[i];
		}
		return temp;
    };

    // Array =+ Array ==> Array  - ��������� ���� ��������, ������������ ��������
    Array operator+= (const Array &Other) {
		return Array(*this + Other);
    };

    // �������� ����� �������
    operator int() const {
		return this->Size;
    };

    // �������� ������� �������������� ��� ��������� �������
    operator float() const {
        if (this->Size == 0) return 0.0f;
		float sum = 0.0f;
        for (int i = 0; i < this->Size; i++) {
            sum += this->Data[i];
        }
		return sum / this->Size;
    };

    // ������������� ��������� �����-������ � �����
    friend ostream &operator<<(ostream &os, const Array &obj) {
		os << "Array: ";
		for (int i = 0; i < obj.Size; i++) {
			os << obj.Data[i] << " ";
		}
		return os;
    };
    friend istream &operator>>(istream &os, Array &obj) {
		cout << "Enter size: ";
		int size = 0;
		os >> size;
		obj.setSize(size);
        for (int i = 0; i < size; i++) {
            cout << "Enter data: ";
            int data;
            os >> data;
            obj.Data[i] = data;
        }
		return os;
    };

}; // class Array



/*
int main()
{
    // ����������� ������ ������ Array
    Array A;
    for (int i = 1; i <= 10; i++) {
        A.push_back(i * i);
    }
    A.push_front(123);
    A.Show();
    A.setSize(5);
    A.Show();

    Array B;
    B = A;
    B.Show();

    B.setSize(12);
    B.InitRand(3, 14);
    B.Show();
    cout << "Min = " << B.getMin() << endl;
    cout << "Max = " << B.getMax() << endl;
    B.Sort(); // ���������� �� ����������� - �� ���������
    B.Show();

    B.setAt(1, 100);
    cout << "B[1]: " << B.getAt(1) << endl;

    B.insert(1, 200);
    B.Show();
}
*/
