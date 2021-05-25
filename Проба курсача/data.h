#pragma once
#include <iomanip>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

char FILEPATH[70] = "D/Учёба/2 семестр/Курсовая работа/Для файлов/";  //путь к файлам с данными
char EXTENSION[5] = ".txt";      //расширение файлов
char RESIDENCE[20] = "Minsk";    //местонахождение медцентра
const char bufferBeginFile[80] = "D/Учёба/2 семестр/Курсовая работа/Для файлов/BufferBegin.txt";  //буферный файл для хранения данных
const char bufferEndFile[80] = "D/Учёба/2 семестр/Курсовая работа/Для файлов/bufferEnd.txt";      //буферный файл для хранения данных

struct Patients  //структура для данных о пациентах
{
	char surname[20];
	char name[15];
	char lastName[15]; //фамилия, имя, отчество
	char sex; //пол
	int birthDay;
	int birthMonth;
	int birthYear; // день, месяц, год рождения
	char city[20];
	char phoneNumber[20];
	char diagnosis[12]; //город проживания,номер телефона, диагноз
};

void workWithFiles();
void workWithInfo(vector <Patients>& patients, char* fileToUpload);
void searchInfo(vector <Patients>& patients, char* fileToUpload);
void sortInfo(vector <Patients>& patients, char* fileToUpload);
void individualTask(vector <Patients>& patients, char* fileToUpload);
void dataToUpload(ifstream& fin, vector <Patients>& patients, int* nPatients);
void uploadOnePatient(ifstream& fin, vector <Patients>& patients, int* nPatients);
void uploadFromDiapason(ifstream& fin, vector <Patients>& patients, int* nPatients);
void uploadAll(ifstream& fin, vector <Patients>& patients);
void createFile();
void deleteFiles();
void chooseOrCreateFileToUpload(char* newfilename);
void chooseFileToUpload(char* newfilename);
void showPatients(vector <Patients> patients);
Patients addPatient(vector <Patients>& patients);
void correctPatients(vector <Patients>& patients);
void deletePatients(vector <Patients>& patients, char* mainFile);
void downloadData(char* mainFile, vector <Patients> patients);
void sureDeletePatient(vector <Patients>& patients, int num_to_delete);
double computeAge(double day, double month, double year);
void findOlderWithDiagnose(vector <Patients> patients);
void findNonResidents(vector <Patients> patients);
void displayInfo(int nPatients, vector <Patients> patients);
void sortByAge(vector <Patients>& patients);
void sortByCity(vector <Patients>& patients);
void sureDeleteAllPatients(vector <Patients>& patients, char* mainFile);
void sortBySurname(vector <Patients>& patients);
void sortByName(vector <Patients>& patients);
void searchBySurname(vector <Patients>& patients);
void searchByAge(vector <Patients>& patients);
void searchByDiagnosis(vector <Patients>& patients);
void searchByName(vector <Patients>& patients);
void top_table();
