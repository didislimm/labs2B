//#include "7(5).hpp"
//
//void input(char* list, int* p, int n) {//функция ввода ;list- массив значений p-массив индексов следующего элемента в списке n-количество элементов
//    int i = 0;//
//    
//    enter(list[i]);
//    p[i] = i + 1;
//    i = p[i];
//    
//    while (i < n) {
//        enter(list[i]);
//        p[i] = i + 1;
//        i = p[i];
//    }
//    
//    p[n - 1] = 0;
//}
//
//void output(char* list, int* p) {//функция вывода list и p- массивы как в функции выше
//    int i = 0;
//    int link = p[i];
//    while (link) {
//        cout << list[i] << " ";
//        link = p[i];
//        i = p[i];
//    }
//}
//
//bool repeat(char* list1, char* list2, int* p1, int* p2, char symbol) {//эта функция описана ниже
//    
//    bool flag = true;
//    
//    int k = 0;
//    
//    int i = 0;
//    int link = p1[i];
//    
//    while (link && k < 2) {
//        if (symbol == list1[i]) {
//            k++;
//        }
//        link = p1[i];
//        i = p1[i];
//    }
//    
//    if (k == 1) {
//        flag = false;
//    }
//    else {
//        i = 0;
//        link = p2[i];
//        
//        while (link) {
//            if (symbol == list2[i]) {
//                flag = false;
//                break;
//            }
//            link = p2[i];
//            i = p2[i];
//        }
//    }
//    
//    return flag;
//}
//
//void createList(char* list1, char* list2, int* p1, int* p2) {//функция заполнения листа 2(результирующего)
//    int i = 0;//мы сюда передаем все массивы для первого и второго списка
//    int j = 0;//потом пробегаемся по листу 1 с помощью числа LINK ,когда мы найдем ноль это будет значить что список закончился
//    
//    int link = p1[i];
//    
//    while (link) {//функция REPEAT ищет элемент LIST[I] в списке list 1 и проверяет добавлен ли он уже в список list 2  если нет -добавляет
//        if (repeat(list1, list2, p1, p2, list1[i])) {
//            list2[j] = list1[i];
//            p2[j] = j + 1;
//            j = p2[j];
//            p2[j] = 0;
//        }
//        link = p1[i];
//        i = p1[i];
//    }
//    
//    p2[j - 1] = 0;
//}
//
