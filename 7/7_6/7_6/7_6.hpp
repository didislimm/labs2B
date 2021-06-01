#include <iostream>
#define random 1.234;
using namespace std;

struct Node
{
float d;
Node *next;
Node *pred;
};

void add(Node *&top, Node *&end);
void output(Node *top);
//void output1(Node* end);
int Input();
double result(Node *top,Node *end);
