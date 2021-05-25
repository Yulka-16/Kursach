#pragma once
#include <iomanip>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

char FILEPATH[70] = "D/�����/2 �������/�������� ������/��� ������/";  //���� � ������ � �������
char EXTENSION[5] = ".txt";      //���������� ������
char RESIDENCE[20] = "Minsk";    //��������������� ���������
const char bufferBeginFile[80] = "D/�����/2 �������/�������� ������/��� ������/BufferBegin.txt";  //�������� ���� ��� �������� ������
const char bufferEndFile[80] = "D/�����/2 �������/�������� ������/��� ������/bufferEnd.txt";      //�������� ���� ��� �������� ������

struct Patients  //��������� ��� ������ � ���������
{
	char surname[20];
	char name[15];
	char lastName[15]; //�������, ���, ��������
	char sex; //���
	int birthDay;
	int birthMonth;
	int birthYear; // ����, �����, ��� ��������
	char city[20];
	char phoneNumber[20];
	char diagnosis[12]; //����� ����������,����� ��������, �������
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
