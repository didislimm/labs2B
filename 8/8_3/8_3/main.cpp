#pragma once
#include <iostream>

using namespace std;

template <class T>
void enter(istream& in, T& a) {//проверка на введеные числа
    while (true) {
        in >> a;

        if (in.fail()) {
            in.clear();
            in.ignore(INT_MAX, '\n');

            cout << "An incorrect value. Please try again:" << endl;

            continue;
        }
        else {
            break;
        }
    }
}

class Number {
    static const int size = 64;
    bool num[size];

    friend istream& operator>>(istream& out, Number& number);
    friend ostream& operator<<(ostream& out, const Number& number);

public:
    Number();
    Number(long long decData);
    Number(string binData);
    Number(const Number& number);

    ~Number();

    bool & operator [](const int i);
    bool  operator [](const int i)const;

    Number& operator=(const Number& number);
    Number& operator=(long long decData);
    Number& operator=(string binData);

    Number operator+(const Number& number);
    Number operator*(const Number& number);
    Number pow(const Number& power);//возведение в степень Number& power
    Number pow(int power);//возведение в степень целую

    Number& operator+=(const Number& number);//эта перегрузка оптимизирует перегрузку умножения
    Number& operator*=(const Number& number);//эта перегрузка оптимизирует метод pow

    void decToBin(long long data);// эта функция нужна для перевода  дес чисел в двоичные

    long long binToDec() const;// эта функция нужна для перевода двоич чисел в дес

    void reverse();// эта функция нужна для перевода отриц дес чисел в двоичные
    Number shift(int k);//cмещение влево на k
    void clear();//зануление элементов так как стат массив
};


Number::Number() {
    clear();
}

Number::Number(long long decData) {
    clear();
    decToBin(decData);
}

Number::Number(const Number& number) {
    for (int i = 0; i < size; ++i) {
        num[i] = number.num[i];
    }
}

Number::~Number() {
    clear();
}

istream& operator>>(istream& in, Number& number) {
    long long decData = 0;
    enter(in, decData);

    number.clear();
    number.decToBin(decData);

    return in;
}

ostream& operator<<(ostream& out, const Number& number) {
    out << number.binToDec();
    return out;
}

bool & Number ::operator[](const int i){
    if(i<size && i>=0){
        return num[i];
    }
    else{
        cout<<"Out of bounce"<<endl;
        exit(0);
    }
};

bool Number::operator [](const int i)const{
    if (i<size && i>=0){
        return num[i];
    }
    else{
        cout<<"Out of bounce "<<endl;
        exit(0);
    }

}

Number& Number::operator=(const Number& number) {
    if (this == &number) {
        return *this;
    }

    for (int i = 0; i < size; ++i) {
        num[i] = number[i];
    }

    return *this;
}

Number& Number::operator=(long long decData) {
    clear();
    decToBin(decData);
    return *this;
}

Number& Number::operator=(string binData) {
    clear();
    for (int i = 0; i < binData.size(); ++i) {
        num[i] = binData[binData.size() - i - 1] - 48;//48- сдвиг в таблице
    }
    return *this;
}

Number Number::operator+(const Number& number) {
    Number result;

    int memory = 0;//переменная для хранения "числа в уме"
    //1+1=0 и memory=1;
    for (int i = 0; i < size; ++i) {
        int res = num[i] + number.num[i] + memory;
        if (res <= 1) {
            result[i] = res;
            memory = 0;
        }
        else {
            result[i] = res % 2;
            memory = 1;
        }
    }

    return result;
}

Number Number::operator*(const Number& number) {
    Number result;

    for (int i = 0; i < size; ++i) {
        if (number[i] == 1) {
            Number temp(*this);//текущий объект
            temp = temp.shift(i);//сдвигаем на i
            result += temp;//складываем
        }
    }

    return result;
}

Number Number::pow(const Number& power){
    Number result(*this);

    int powDec = power.binToDec();
    if (powDec <= 0) {
        return 0;
    }
    else {
        for (int i = 0; i < powDec - 1; ++i) {
            result *= *this;
        }
    }

    return result;
}

Number Number::pow(int power){
    Number result(*this);

    if (power <= 0) {
        return 0;
    }
    else {
        for (int i = 0; i < power - 1; ++i) {
            result *= *this;
        }
    }

    return result;
}

Number& Number::operator+=(const Number& number) {
    *this = *this + number;
    return *this;
}

Number& Number::operator*=(const Number& number) {
    *this = *this * number;
    return *this;
}

void Number::decToBin(long long data) {
    long long absData = abs(data);
    // сначала переведем полож число а если окажется отриц проинвертируем все биты и добавим 1
    int i = 0;
    while (absData) {
        if ((absData % 2) == 0) {
            num[i] = 0;
        }
        else {
            num[i] = 1;
        }
        absData /= 2;
        i++;
    }

    if (data < 0) {
        reverse();
    }
}

long long Number::binToDec() const {
    long long decData = 0;

    long long power = 1;
    for (int i = 0; i < size - 1; ++i) {
        decData += (*this)[i] * power;
        power *= 2;
    }
    decData -= (*this)[size - 1] * power;

    return decData;
}

void Number::reverse() {
    for (int i = 0; i < size; ++i) {
        num[i] = !num[i];
    }
    *this += 1;
}

Number Number::shift(int k) {//смещение
    Number result;

    for (int i = 0; i + k < size; ++i) {
        result[i + k] = num[i];
    }

    return result;
}

void Number::clear() {
    for (int i = 0; i < size; ++i) {
        num[i] = 0;
    }
}

int main() {
    Number three = 3;
    Number mThree = -3;

    Number a = three.pow(12);
    Number b = mThree.pow(11);
    Number c = three.pow(10);
    Number d = mThree.pow(9);

    Number result = a + b + c + d;

    cout << "3^12 + (-3)^11 + 3^10 + (-3)^9 = " << result << endl;
    //-----------------------
    string test;
    getline(cin, test);
    Number tst;
    tst=test;
    cout<<tst<<endl;
}
