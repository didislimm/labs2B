#include "6.2.hpp"



bool createFileWithIntegers(string &name,int amount){
    ofstream fout;
    srand(time(nullptr));
    fout.open(name);
    if(!fout.is_open())
    {
        cout<<"Error 1";
    }
    else{
        cout<<"Reading is successfully"<<endl;
        for(;amount>0;--amount){
            fout << rand()%41-20 << endl;
        }
    }
    fout.close();
    return true;
}
// @param rd read
// @param wt write
// @param bufPst buffer of positive value
// @param bufNgt buffer of negative value

void rewrite(string &rd, string &wt){
    ifstream fPst(rd);
    ifstream fNgt(rd);
    ofstream g(wt);
    if (!fPst.is_open() or !g.is_open()) {
        cout<<"Error 2";
    }
    string bufPst;
    string bufNgt;
    while (!(fPst.eof() and fNgt.eof())) {
        //Потск положительных чисел
        while (getline(fPst, bufPst)) {
            if (bufPst[0] != '-') {
              g << bufPst << endl;
            
                }
            }
      
    while (getline(fNgt, bufNgt)) {
        if (bufNgt[0] == '-') {
         
                g << bufNgt << endl;
            
            }
        }
    }
}
bool createBinWithIntegers(string &name ,int amount){
    ofstream fin;
    srand(time(nullptr));
    fin.open(name);
    if(!fin.is_open())
    {
        cout<<"Eror 3";
    }
    else{
        cout<<"Reading is successfully"<<endl;
        for(;amount>0;--amount){
            int v=rand()%41-20; 
            fin.write(reinterpret_cast <char*> (&v), sizeof (int));
        }
        
    }
    fin.close();
    return true;
    
}
void rewriteBin(string &rd, string &wt){
    ifstream fPst2(rd,ios::binary);
    ifstream fNgt2(rd,ios::binary);
    ofstream g2(wt,ios::binary);
    if (!fPst2.is_open() or !g2.is_open()) {
        cout<<"Error 4";
    }
    int bufPst2=0;
    int bufNgt2=0;
    fPst2.read(reinterpret_cast<char*>(&bufPst2),sizeof (int));
    fNgt2.read(reinterpret_cast<char*>(&bufNgt2),sizeof (int));
    while (!(fPst2.eof() and !fNgt2.eof())) {
       
        while ( fPst2.read(reinterpret_cast<char*>(&bufPst2),sizeof (int))) {
            
          
            if (bufPst2>0) {
                g2.write(reinterpret_cast<char*>(&bufPst2),sizeof (int));
                }
            }
    
        while ( fNgt2.read(reinterpret_cast<char*>(& bufNgt2),sizeof (int))) {
            if (bufNgt2<0) {
                g2.write(reinterpret_cast<char*>(& bufNgt2),sizeof (int));
                }
            }        
    }
}

    




