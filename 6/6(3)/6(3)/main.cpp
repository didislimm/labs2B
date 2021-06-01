//#include <iostream>
//#include <fstream>
//#include <stdlib.h>
//#include <iomanip>
//#include <string>
//using namespace std;
//int *SearchOlders(string fin);//для нахождения максиммальных возрастов
//void Result(string fin,string fout,int * age );//для записи в результируйщий файл
//int main()
//{
//    int *maxAge= new int[6];
//    string list="list.txt";
//    string result="result.txt";
//    maxAge=SearchOlders(list);
//    Result(list, result,maxAge);
//    
//}
//int * SearchOlders(string list){
//    //я для оптимизирование программы подключил файл со студентами
//    ifstream fin(list);//это файл с написанными 26 студентами
//    int *age =new int[6];//Массив с макс возрастсами на всех курсах 0 элемент не заполняю
//    //курсов-5 но чтобы не писать -1 при работе с ними элементов 6(самый первый пустой)
//    while (!fin.eof())
//    {
//        string var;
//        int var_age = 0;
//        int var_course = 0;// эти 2 переменные для хранения курса и возраста студентов
//        for (int i = 0; i <= 2; i++)
//        {
//            fin >> var;//fin >> var используется для пропусков неинтересующей инфы (ФИО БАЛЛ Пол)
//        }
//        fin >> var_age;
//        
//        fin >> var;
//        fin >> var_course;
//        if (var_age >= age[var_course])//Запись макс возрастов
//        {
//            age[var_course] = var_age;
//        }
//        fin >> var;
//    }
//    fin.close();
//    return age;
//}
//void Result(string list,string result,int *age){
//    ifstream in(list);
//    ofstream out(result);
//    while (!in.eof())
//    {
//        string var_name;
//        string var;// это строка помощи чтобы выводить правильно фамилию
//        int var_age=0;
//        double var_mark=0;
//        int var_course=0;
//        string var_gender;
//        for (int i = 0; i <= 2; i++)
//        {
//            in >> var;
//            var_name += var;//читаем имя -пробел-читаем фамилию-склеиваем и тд
//            if(i!=2)
//                var_name += " ";
//        }
//        in >> var_age;
//        in >> var_gender;
//        in >> var_course;
//        in >> var_mark;
//        if (age[var_course]==var_age)
//        {
//            out << var_name << " " << var_age << " " << var_gender << " " << var_course << " " << var_mark << endl;
//        }
//        else continue;
//        
//        
//    }
//}
