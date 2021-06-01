#pragma once
#include <iostream>
#include <string>

#define DEALER "Dealer"
#define PlAYER "Player"
#define CITIZEN "Citizen"
#define CHEST "Chest"
#define STONE "Stone"
#define HUMANS "Humans"
#define SUBJECT "Subject"
#define OBJECT "Object"

using namespace std;
// в каждом классе дописываю 4 метода для чтения/записи из/в файл ,вывести тип объекта ,и для создания копии объекта 
enum Identifiers// удобство для свитча 
{
DEALER_ID = 1,
PLAYER_ID = 2,
CITIZEN_ID = 3,
STONE_ID = 4,
CHEST_ID = 5,
};

class Object {
protected:
    int X;
    int Y;
public:
    virtual void input();
    Object(int X, int Y) {
        this->X = X;
        this->Y = Y;
    }
    Object() {
        this->X = 0;
        this->Y = 0;
    }
    virtual void print();
    ~Object() = default;
    template <class T>
    void enter(istream& in, T& a) {
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
    virtual const char* get_Type() const
    {
        return "Object";
    }
    virtual Object* Clone()
    {
        return new Object(*this);
    }

    virtual void read(istream& in)
    {
        in >> X;
        in >> Y;
    }
    virtual void write(ostream& out)
    {
        out << get_Type() << endl;
        out << X << endl;
        out << Y << endl;
    }
   
};
void Object::input()
{
    int x = 0;
    int y = 0;
    cout << "Enter X" << endl;
    enter(cin, x);
    X = x;

    cout << "Enter Y" << endl;
    enter(cin, y);
    Y = y;

}
ostream& operator<<(ostream& out, Object& obj)
{
    if (&out == &cout)
    {
        obj.print();
    }
    else
    {
        obj.write(out);
    }

    return out;
}
void Object::print() {
    cout << "Value of X: " << X << endl;
    cout << "Value of Y: " << Y << endl;
}

class Human :public Object {
protected:
    string name;
public:
    Human(int x, int y, string name) :Object(x, y) {
        this->name = name;
    }
    Human() :Object() {
        this->name ="";
    }
    virtual ~Human() = default;
    void print();
    void input();
    virtual const char* get_Type() const
    {
        return "Human";
    }
    virtual Human* Clone()
    {
        return new Human(*this);
    }

    virtual void read(istream& in)
    {
        in >> X;
        in >> Y;
        in >> name;
    }
    virtual void write(ostream& out)
    {
        out << get_Type() << endl;
        out << X << endl;
        out << Y << endl;
        out << name << endl;

    }
};
void Human::input() {
    Object::input();
    cout << "Input name" << endl;
    string Name = "";
    enter(cin, Name);
    name = Name;
}
void Human::print() {
    Object::print();
    cout << "Name of people: " << name << endl;
}

class Dealer :public Human {
protected:
    int Type;
public:
    Dealer(int x, int y, string name, int Type) :Human(x, y, name) {
        this->Type = Type;
    }
    Dealer() :Human() {
        this->Type = 0;
    }
    ~Dealer() = default;
    void print();
    void input();
    virtual const char* get_Type() const
    {
        return "Dealer";
    }
    virtual Dealer* Clone()
    {
        return new Dealer(*this);
    }

    virtual void read(istream& in)
    {
        in >> X;
        in >> Y;
        in >> name;
        in >> Type;
    }
    virtual void write(ostream& out)
    {
        out << get_Type() << endl;
        out << X << endl;
        out << Y << endl;
        out << name << endl;
        out << Type << endl;
    }
};
void Dealer::input() {
   Human::input();
    cout << "Input Type" << endl;
    int type = 0;
    enter(cin, type);
    Type = type;
}
void Dealer::print() {
    Human::print();
    cout << "Value of Type: " << Type << endl;
}

class Player :public Human {
protected:
    string Color;
public:
    Player(int x, int y, string name, string Color) :Human(x, y, name) {

        this->Color = Color;
    }
    Player() :Human() {
        this->Color = "";
    }
    ~Player() = default;
    void print();
    void input();
    virtual const char* get_Type() const
    {
        return "Player";
    }
    virtual Player* Clone()
    {
        return new Player(*this);
    }

    virtual void read(istream& in)
    {
        in >> X;
        in >> Y;
        in >> name;
        in >> Color;
    }
    virtual void write(ostream& out)
    {
        out << get_Type() << endl;
        out << X << endl;
        out << Y << endl;
        out << name << endl;
        out << Color << endl;
    }
};
void Player::input() {
    Human::input();
    cout << "Input color" << endl;
    string color = "";
    enter(cin, color);
    Color = color;
}
void Player::print() {
    Human::print();
    cout << "Color: " << Color << endl;
}

class Citizen :public Human {
public:
    Citizen(int x, int y, string name) :Human(x, y, name) {}
    Citizen() :Human() {}
    void input();
    virtual const char* get_Type() const
    {
        return "Citizen";
    }
    virtual Citizen* Clone()
    {
        return new Citizen(*this);
    }

    virtual void read(istream& in)
    {
        in >> X;
        in >> Y;
        in >> name;
    }
    virtual void write(ostream& out)
    {
        out << get_Type() << endl;
        out << X << endl;
        out << Y << endl;
        out << name << endl;
    }
};
void Citizen::input() {
    Human::input();
}
class Subjects :public Object {
protected:
    int Height;
    int Width;
public:
    Subjects(int x, int y, int Height, int Width) :Object(x, y) {
        this->Height = Height;
        this->Width = Width;
    }
    Subjects() :Object() {
        this->Height = 0;
        this->Width = 0;

    }
    virtual ~Subjects() = default;
    void print();
    void input();
    virtual const char* get_Type() const
    {
        return "Subject";
    }
    virtual  Subjects* Clone()
    {
        return new Subjects(*this);
    }

    virtual void read(istream& in)
    {
        in >> X;
        in >> Y;
        in >> Height;
        in >> Width;
    }
    virtual void write(ostream& out)
    {
        out << get_Type() << endl;
        out << X << endl;
        out << Y << endl;
        out << Height << endl;
        out << Width << endl;
    }
};

void Subjects::input() {
    Subjects::input();
    cout << "Input Height :" << endl;
    int height;
    enter(cin, height);
    Height = height;

    cout << "Input Width :" << endl;
    int width;
    enter(cin, width);
    Width = width;
}
void Subjects::print() {
    Object::print();
    cout << "Value of Height: " << Height << endl;
    cout << "Value of Width: " << Width << endl;
}

class Stone :public Subjects {
protected:
    int Pict;
public:
    Stone(int x, int y, int height, int width, int Pict) :Subjects(x, y, height, width) {
        this->Pict = Pict;
    }
    Stone() :Subjects() {
        this->Pict = 0;
    }
    ~Stone() = default;
    void print();
    void input();
    virtual const char* get_Type() const
    {
        return "Stone";
    }
    virtual  Stone* Clone()
    {
        return new Stone(*this);
    }

    virtual void read(istream& in)
    {
        in >> X;
        in >> Y;
        in >> Height;
        in >> Width;
        in >> Pict;
    }
    virtual void write(ostream& out)
    {
        out << get_Type() << endl;
        out << X << endl;
        out << Y << endl;
        out << Height << endl;
        out << Width << endl;
        out << Pict << endl;
    }
};
void Stone::print() {
    Subjects::print();
    cout << "Value of Pict: " << Pict << endl;
}
void Stone::input() {
    Subjects::input();
    cout << "Input Pict" << endl;
    int pict = 0;
    enter(cin, pict);
    Pict = pict;
 }
class Chest :public Subjects {
protected:
    int Coins;
public:
    Chest(int x, int y, int height, int width, int Coins) :Subjects(x, y, height, width) {
        this->Coins = Coins;
    }
    Chest() :Subjects() {
        this->Coins = 0;
    }
    ~Chest() = default;
    void print();
    void input();
    virtual const char* get_Type() const
    {
        return "Chest";
    }
    virtual  Chest* Clone()
    {
        return new Chest(*this);
    }

    virtual void read(istream& in)
    {
        in >> X;
        in >> Y;
        in >> Height;
        in >> Width;
        in >> Coins;
    }
    virtual void write(ostream& out)
    {
        out << get_Type() << endl;
        out << X << endl;
        out << Y << endl;
        out << Height << endl;
        out << Width << endl;
        out << Coins << endl;
    }
};
void Chest::input() {
   Subjects::input();
    cout << "Input Coins" << endl;
    int coins = 0;
    enter(cin, coins);
   Coins = coins;
}
void Chest::print() {
    Subjects::print();
    cout << "Value of Coins: " << Coins << endl;
}
