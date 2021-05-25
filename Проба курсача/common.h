#pragma once
#include <iomanip>
#include <iostream>
#include <fstream>
#include <filesystem>

//#include <dir.h>

using namespace std;

int countRows(ifstream& fin);
int my_strlen(char* str);
int checkValue(int* checked_value, int min, int max);
int numOfRank(int x);
void listOfFiles();
void swap(char* first);
void exitProgramm();
