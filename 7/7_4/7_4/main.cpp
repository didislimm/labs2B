/*
 * Выполнить задания, используя связанные динамические структуры данных в виде связных компонент.
 Оценить асимптотическую сложность алгоритма.
 
 2. Описать функцию, которая формирует список символов L2, включив в не-
 го те символы из L1, которые входят в него более одного раза.
 */
#include "7(4).hpp"
int main()
{
    Node* top = NULL;
    Node* top_result = NULL;
    
    int count_of_simbols = 0;
    count_of_simbols = Input(max_for_count_of_simbols);
    for (int i = 0; i < count_of_simbols; ++i)
    {
        char simbol = Generation_of_simbol();
        add(top, simbol);
    }
    
    cout << '\n';
    show(top);
    
    Result(top, top_result);
    show(top_result);
    
    return 0;
}
