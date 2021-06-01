//#include <iostream>
//#include <cstdlib>
// 
//using namespace std;
// 
//const int COUNT_EL = 8, WIDTH = 8, HEIGHT = 8;
//const bool SET_DIA = true, DEL_DIA = false;
//int a[HEIGHT][WIDTH];                // доска
//bool is_set[HEIGHT][WIDTH];            // Расположение слонов на доске
//int count_null = WIDTH * HEIGHT;        // Количество пустых клеток
//bool isEnd = false;                // Флаг выхода из рекурсии
//const bool FIRST = true, SECOND = false;    // флаги для индификации диагоналей
//
//void diagonal(bool is_firstD, bool set, int x, int y, int i, int j){ // осуществляет все операции с диагоналями
//    while(y<HEIGHT && (is_firstD? (x<WIDTH) : (x >= 0))){                    // заполняем/очищаем первую\вторую диагональ
//        if(is_firstD? true : x != j || y != i){
//            if(set){
//                a[y][x]++;
//                if(a[y][x] == 1){
//                    count_null--;
//                }
//            }else{
//                a[y][x]--;
//                if(a[y][x] == 0){
//                    count_null++;
//                }
//            }
//        }
//        x += (is_firstD? 1 : -1);
//        y++;
//    }
//}
// 
//void space(bool set, int level, int i, int j){    // функция осуществляет операции с диагоналями (установку \ удаление)
//    is_set[i][j] = set;            // Сохраняем последнее расположение слонов
//    int x, y;
//    if(j>i){    // ищем начало прохода первой диагонали (параллельной или идентичной главной)
//        y = 0;
//        x = j-i;
//    }else{
//        x = 0;
//        y = i-j;
//    }
//    diagonal(FIRST, set, x, y, i, j);
//    // ищем начало второй диагонали (перпендикулярной главной (побочной))
//    int sum = i+j;
//    if(sum < WIDTH){
//        x = sum;
//        y = 0;
//    }else{
//        x = WIDTH-1;
//        y = sum-x;
//    }
//    diagonal(SECOND, set, x, y, i, j);
//}
// 
//bool find_permutation(int level=0){
//    level++;
//    for(int i = level-1, j = (level==1?1:0); j < WIDTH ; j++){
//    /*экспериментально было замечено, что при установки первого слона в самом начале строки нужных нам последовательностей найдено не будет
//      именно по этой причине, если мы задаем первого слона, то начинаем со второй ячейки строки
//    */
//        if(a[i][j] == 0){
//            space(SET_DIA, level, i, j);// устанавливаем слона и поле под его боем
//            if(level != COUNT_EL){
//                find_permutation(level);
//                if(isEnd){
//                    return false;
//                }
//            }else if(count_null == 0){
//                cout << "Ответ найден:"<< endl << endl;
//                for( int i1=0 ; i1<HEIGHT ; i1++ ){
//                    for( int j1=0 ; j1<WIDTH ; j1++ ){
//                        cout << (is_set[i1][j1]? 1 : 0) << (j1+1 == WIDTH ? '\n' : ' ' );
//                    }
//                }
//                isEnd = true;
//                return false;
//            }
//            space(DEL_DIA, level, i, j);// удаляем слона и поле под его боем
//        }
//    }
//    level--;
//}
// 
//int main(){
//    find_permutation();
//}
