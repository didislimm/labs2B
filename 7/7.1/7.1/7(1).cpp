#include "7(1).hpp"
void createFile(string rd,short kol,short size){
ofstream fout;
    //kol- количество чисел
    //size-интервал от 0 до size
    fout.open(rd);
    if(!fout.is_open())
    {
        cout<<"Error 1";
    }
    else{
        cout<<"Reading is succesfully"<<'\n';
        for(short i=0;i<kol;++i){
            fout<<rand()%size<<endl;
        }
    }
    fout.close();
}
short fill(short arr[],string rd,short size)
{
    ifstream read_file(rd);
    if (!read_file.is_open())
    {
        cout<<"Error 2";
    }
    cout << endl;
    while(!read_file.eof())
    {
        short value = 0;
        read_file>>value;
        
        arr[value]++;
    }
    
    for(int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    short numb=0;
    for(short i=0;i<size;i++)
    {
        if(arr[i]!=0)
        {
        numb++;
        }
    }
    cout<<numb<<"size"<<endl;
    return numb;
    
}
void getArr(short arr[],short result[],short k, short size)
{
    short a = 0;
    for(short i=0;i<size;i++)
    {
        if(arr[i]!=0)
        {
            result[a++]=i;
        }
        
    }
}
void output(short result[],short k)
{
    for (short i=0;i<=k;i++){
        cout<<result[i]<<endl;
    }

}

