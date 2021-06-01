#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MIN_COURSE = 1;
const int MAX_COURSE = 4;

struct Info {
    string name;
    int age;
    string gender;
    int course;
    double mark;
};
int Input();
void inputData(ofstream& file, Info student, int n);
void readData(ifstream& file, Info student);
void writeData(ofstream& file, Info student, int n);
void writeDataBin(ofstream& file, Info student, int n);
void outputData(ifstream& file);
void outputDataBin(ifstream& file);
int searchOldest(ifstream & read_file, int n);
