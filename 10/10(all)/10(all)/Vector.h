#pragma once
#include <map>
//#include "Object.h"
//#include "Subject.h"
//#include "Humans.h"
//#include "Stone.h"
//#include "Chest.h"
//#include "Player.h"
//#include "Dealer.h"
//#include "Citizen.h"
#include "Header.hpp"
#include "ObjectFactory.h"

class Vector {

    int size;
    Object** arr;

    map<string, int> types;//используем мэп ,чтобы упорядочить дочерние классы каждому из них соответствующий индекс

    friend ostream& operator<<(ostream& file, const Vector& vctr);

public:
    Vector();
    Vector(int size);
    Vector(const Vector& vctr);

    ~Vector();

    Object*& operator[](int index);
    Object*& operator[](int index) const;
    Vector& operator=(const Vector& vctr);
    Vector& operator=(Vector&& vctr);

    void input(int size);
    void read(istream& in);

    void push_back(Object* data);
    void pushAt(int index, Object* obj);
    void deleteAt(int index);
    void clear();

    void setSize(int size);
    int getSize() const;
};

Vector::Vector() {
    size = 0;
    arr = new Object * [size];

    int i = 1;//начинаем добавление
    types.try_emplace(DEALER, 1);//этот метод как пуш бэк
    types.try_emplace(PlAYER, 2);
    types.try_emplace(CITIZEN, 3);
    types.try_emplace(STONE, 4);
    types.try_emplace(CHEST, 5);
}

Vector::Vector(int size) {
    try {
        if (size < 0) {
            throw size;
        }
    }
    catch (int) {
        cerr << "SIZE " << size << " IS NOT ALLOWED" << endl;
        exit(0);
    }

    this->size = size;
    arr = new Object * [size];
    for (int i = 0; i < size; ++i) {
        arr[i] = nullptr;
    }

    int i = 1;
    types.try_emplace(DEALER, 1);
    types.try_emplace(PlAYER, 2);
    types.try_emplace(CITIZEN, 3);
    types.try_emplace(STONE, 4);
    types.try_emplace(CHEST, 5);
}

Vector::Vector(const Vector& vect) {
    size = vect.size;
    arr = new Object * [size];
    for (int i = 0; i < size; ++i) {
        arr[i] = vect.arr[i];
    }
}

Vector::~Vector() {
    clear();
}

ostream& operator<<(ostream& out, const Vector& vctr) {//перегружаем вывод
    for (int i = 0; i < vctr.size; ++i) {
        if (vctr.arr[i]) {
            out << *vctr.arr[i] << endl;
        }
    }

    return out;
}

Object*& Vector::operator[](int index) {
    try {
        if (index < 0 || index >= size) {
            throw index;
        }
    }
    catch (int) {
        cerr << "INDEX " << index << " IS OUT OF RANGE" << endl;
        exit(0);
    }

    return arr[index];
}

Object*& Vector::operator[](int index) const {
    try {
        if (index < 0 || index >= size) {
            throw index;
        }
    }
    catch (int) {
        cerr << "INDEX " << index << " IS OUT OF RANGE" << endl;
        exit(0);
    }

    return arr[index];
}

Vector& Vector::operator=(const Vector& vctr) {//оператор копирования
    if (this == &vctr) {
        return *this;
    }

    clear();
    size = vctr.size;
    arr = new Object * [size];
    for (int i = 0; i < size; ++i) {
        arr[i] = vctr.arr[i];
    }

    return *this;
}

Vector& Vector::operator=(Vector&& vctr) {
    if (this == &vctr) {
        return *this;
    }

    swap(size, vctr.size);
    swap(arr, vctr.arr);

    return *this;
}

void Vector::input(int size) {
    setSize(size);
    for (int i = 0; i < size; ++i) {
        cout << "Enter the type of the object " << i + 1 << ":" << endl;
        cout << " " << DEALER_ID << ". " << DEALER << endl;
        cout << " " << PLAYER_ID << ". " << PlAYER << endl;
        cout << " " << CITIZEN_ID << ". " << CITIZEN << endl;
        cout << " " << STONE_ID << ". " << STONE << endl;
        cout << " " << CHEST_ID << ". " << CHEST << endl;
      

        int option = 0;
        cin >> option;

        ObjectFactory factory;
       // arr [i]= factory.create(option);
        switch (option) {
        
        case DEALER_ID:
            arr[i] = factory.create(DEALER);
            break;
        case PLAYER_ID:
            arr[i] = factory.create(PlAYER);
            break;
        case CITIZEN_ID:
            arr[i] = factory.create(CITIZEN);
            break;
        case CHEST_ID:
            arr[i] = factory.create(CHEST);
            break;
        case STONE_ID:
            arr[i] = factory.create(STONE);
            break;
        
        default:
            break;
        }
        arr[i]->input();
        cout << endl;
    }
}

void Vector::read(istream& in) {//метод для записи в массив (из файла)
    int size = 0;
    while (!in.eof()) {
        string currentLine;//создаю буферную строку для чтения
        currentLine.clear();

        getline(in, currentLine);//заполняем

        if (currentLine.empty()) {
            continue;
        }

        ObjectFactory factory;

        map<string, int>::iterator it = types.find(currentLine);
        //с помощью итератора определяем какой тип у читаемого объекта
        if (it != types.end()) {
            switch (it->second) {//смотрим его номер и по нему записываем нужные данные в массив
            case STONE_ID:
                setSize(size + 1);
                arr[size] = factory.create(STONE);
                arr[size++]->read(in);//заполняем из файла
                break;
            case CHEST_ID:
                setSize(size + 1);// создаем размер
                arr[size] = factory.create(CHEST);
                arr[size++]->read(in);
                break;
            case DEALER_ID:
                setSize(size + 1);
                arr[size] = factory.create(DEALER);
                arr[size++]->read(in);
                break;
            case CITIZEN_ID:
                setSize(size + 1);
                arr[size] = factory.create(CITIZEN);
                arr[size++]->read(in);
                break;
            case PLAYER_ID:
                setSize(size + 1);
                arr[size] = factory.create(PlAYER);
                arr[size++]->read(in);
                break;
            default:
                break;
            }
        }
    }
}

void Vector::push_back(Object* obj) {
    setSize(size + 1);
    arr[size - 1] = obj;
}

void Vector::pushAt(int index, Object* obj) {
    try {
        if (index < 0 || index > size) {
            throw index;
        }
    }
    catch (int) {
        cerr << "INDEX " << index << " IS OUT OF RANGE" << endl;
        exit(0);
    }

    setSize(size + 1);
    if (index != size - 1) {
        for (int i = size - 1; i > index; --i) {
            arr[i] = arr[i - 1];
        }
    }
    arr[index] = obj;
}

void Vector::deleteAt(int index) {
    try {
        if (index < 0 || index >= size) {
            throw index;
        }
    }
    catch (int) {
        cerr << "INDEX " << index << " IS OUT OF RANGE" << endl;
        exit(0);
    }

    for (int i = index; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    setSize(size - 1);
}

void Vector::clear() {
    if (arr) {
        size = 0;
        delete[] arr;
        arr = nullptr;
    }
}

void Vector::setSize(int size) {//переопределение
    try {
        if (size < 0) {
            throw size;
        }
    }
    catch (int) {
        cerr << "SIZE " << size << " IS NOT ALLOWED" << endl;
        exit(0);
    }

    Object** newArr = new Object * [size];//создаем с новым размером
    for (int i = 0; i < size; ++i) {
        if (i < this->size) {
            newArr[i] = arr[i];
        }//переписали
        else {
            newArr[i] = nullptr;
        }
    }

    delete[] arr;
    this->size = size;
    arr = newArr;
}

int Vector::getSize() const {
    return size;
}
