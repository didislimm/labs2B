#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <stdlib.h>
#include<string>
using namespace std;

void  createFile(string rd,short kol,short size);

short  fill(short arr[],string rd,short size);

void getArr(short arr[],short result[],short k, short size);

void output(short result[],short k);
