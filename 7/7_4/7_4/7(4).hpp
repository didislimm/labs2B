#include<iostream>
#define max_for_count_of_simbols 100
using namespace std;
struct Node
{
    char d;
    Node *p;
    int count;
};
void find_eq(Node *, char, Node *&);
void find_gt(Node *, char, Node *&);
void add(Node *&, char);
int Input(int max);
char Generation_of_simbol();
void show(Node*);
void Result(Node* , Node*& );
