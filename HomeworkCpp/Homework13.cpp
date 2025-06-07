#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

#define RND(min, max)  (rand()%((max)-(min)+1)+(min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { system("pause > nul"); } }_;


/*
Конструктор копирования
Оператор копирования

Создайте класс Array (или используйте ранее
созданный вами).
Класс Array - это класс динамического массива.
Размер массива может быть передан в качестве
параметра или задан с помощью вызова функции-члена.
Класс должен позволять заполнять массив значениями,
отображать содержимое массива, изменять
размер массива, сортировать массив, определять
минимальное и максимальное значение.
Класс должен содержать набор конструкторов
(конструктор копирования обязателен), деструктор.
*/

class Array {
private:
    int *Data; // полезные данные
    int Size; // текущий размер массива
public:
    // Конструкторы класса Array
    //   Перегруженные конструкторы

    Array() : Size(), Data() {}

    explicit Array(int newSize) : Array() {
        setSize(newSize);
    }

    Array(const int *mas, int masSize) : Array() {
        setData(mas, masSize);
    }


    // конструктор и оператор копирования
    Array(const Array &obj) : Array() {
        *this = obj;
    }

    Array &operator=(const Array &obj) {
        if (this == &obj) return *this;

        setData(obj.Data, obj.Size);
        return *this;
    }

    // деструктор класса Array
    ~Array() {
        delete[] this->Data;
    }

    // геттеры
    int getSize() const { return this->Size; }
    const int *getData() const { return this->Data; }

    // сеттеры
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

    // заполнить массив случ. числами в диапазоне [Min;Max]
    void InitRand(int Min, int Max) {
        for (int i = 0; i < this->Size; i++) {
            this->Data[i] = RND(Min, Max);
        }
    }
    // создать массив размером Size и заполнить случ. числами в диапазоне [Min;Max]
    void InitRand(int Size, int Min, int Max) {
        setSize(Size);
        InitRand(Min, Max);
    }

    // получить из массива значение по индексу index
    //  Data[index];
    int getAt(int index) const {
        if (index > this->Size || index < 0)
            throw exception("Index out of range");

        return this->Data[index];
    }

    int operator[] (int index) const {
        return getAt(index);
    }

    // установить новое значение val по индексу index внутри массива
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

    // вставить значение val в начало массива
    //  длина массива увеличивается на 1
    void push_front(int val) {
        setSize(this->Size + 1);

        for (int i = this->Size - 1; i > 0; i--) {
            this->Data[i] = Data[i - 1];
        }

        this->Data[0] = val;
    }

    // вставить значение val в конец массива
    //  длина массива увеличивается на 1
    void push_back(int val) {
        setSize(this->Size + 1);
        this->Data[this->Size - 1] = val;
    }

    // вставить значение val в массив по индексу index
    //  длина массива увеличивается на 1
    void insert(int index, int val) {
        if (index > this->Size || index < 0)
            throw exception("Index out of range");

        setSize(this->Size + 1);

        for (int i = this->Size - 1; i > index; i--) {
            this->Data[i] = this->Data[i - 1];
        }

        this->Data[index] = val;
    }

    // получить мин. и макс. значения из массива
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

    // отсортировать массив
    //  по умолчанию - по возрастанию 
    //  если Direct == fals - отсортировать по убыванию
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
    // Перегрузка операторов
    //
    // Перегруженные операторы круглые скобки ()
    //  поиск значения Search с заданного индекса StartPos
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
    // создать массив размером Size и заполнить случ. числами в диапазоне [Min;Max]
    Array operator() (int NewSize, int Min, int Max) {
		setSize(NewSize);
		InitRand(Min, Max);
		return *this;
    };


    // Array + int ==> Array  - добавить ко всем элементам значение Value
    Array operator+ (int Value) {
		Array temp(*this);
		for (int i = 0; i < this->Size; i++) {
			temp.Data[i] += Value;
		}
		return temp;
    };

    // Array * int ==> Array  - умножить все элементы на значение Value
    Array operator* (int Value) {
		Array temp(*this);
        for (int i = 0; i < this->Size; i++) {
            temp.Data[i] *= Value;
        }
		return temp;
    };

    // Array + Array ==> Array   - сцепление двух массивов, конкатенация массивов
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

    // Array =+ Array ==> Array  - сцепление двух массивов, конкатенация массивов
    Array operator+= (const Array &Other) {
		return Array(*this + Other);
    };

    // получить длину массива
    operator int() const {
		return this->Size;
    };

    // получить среднее арифметическое для элементов массива
    operator float() const {
        if (this->Size == 0) return 0.0f;
		float sum = 0.0f;
        for (int i = 0; i < this->Size; i++) {
            sum += this->Data[i];
        }
		return sum / this->Size;
    };

    // перегруженные операторы ввода-вывода в поток
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
    // Демострация работы класса Array
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
    B.Sort(); // сортировка по возрастанию - по умолчанию
    B.Show();

    B.setAt(1, 100);
    cout << "B[1]: " << B.getAt(1) << endl;

    B.insert(1, 200);
    B.Show();
}
*/
