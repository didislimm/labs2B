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
#include "Header.h"
class ObjectFactory {// класс для создания объекта
    map<string, Object*> OBJECTS;
    // так же используем мэп с названием дочернего класса и объектом на него
    void AddObjectType(Object* obj) {//заполнение
        OBJECTS.try_emplace(obj->get_Type(), obj);
    }
public:
    ObjectFactory() {// конструктор без параметра
        AddObjectType(new Dealer());
        AddObjectType(new Player());
        AddObjectType(new Citizen());
        AddObjectType(new Stone());
        AddObjectType(new Chest());
    }
    ~ObjectFactory()
    {
        for (map<string, Object*>::iterator it = OBJECTS.begin(); it != OBJECTS.end(); it++)
        {
            delete it->second;
        }
        OBJECTS.clear();//очистка динам памяти
    }
    Object* create(const char* typeName)
    {
        map<string, Object*>::iterator it = OBJECTS.find(typeName);
        //с помощью этого итератора пробуем найти нужный объект по имени
        //иначе-false
        if (it == OBJECTS.end()) {
            return nullptr;
        }
        return it->second->Clone();// возвращаем копию если нашли
    }
};
