#include "data.h"
#include "common.h"

struct predAgeDecrease
{
	bool operator()(const Patients& patients1, const Patients& patients2)
	{
		return computeAge(patients1.birthDay, patients1.birthMonth, patients1.birthYear) > computeAge(patients2.birthDay, patients2.birthMonth, patients2.birthYear);
	}
};

struct predAgeIncrease
{
	bool operator()(const Patients& patients1, const Patients& patients2)
	{
		return computeAge(patients1.birthDay, patients1.birthMonth, patients1.birthYear) < computeAge(patients2.birthDay, patients2.birthMonth, patients2.birthYear);
	}
};

struct predCityDecrease
{
	bool operator()(const Patients& patients1, const Patients& patients2)
	{
		return strcmp(patients1.city, patients2.city) < strcmp(patients2.city, patients1.city);
	}
};

struct predCityIncrease
{
	bool operator()(const Patients& patients1, const Patients& patients2)
	{
		return strcmp(patients1.city, patients2.city) > strcmp(patients2.city, patients1.city);
	}
};

struct predSurnameDecrease
{
	bool operator()(const Patients& patients1, const Patients& patients2)
	{
		return strcmp(patients1.surname, patients2.surname) < strcmp(patients2.surname, patients1.surname);
	}
};

struct predSurnameIncrease
{
	bool operator()(const Patients& patients1, const Patients& patients2)
	{
		return strcmp(patients1.surname, patients2.surname) > strcmp(patients2.surname, patients1.surname);
	}
};

struct predNameIncrease
{
	bool operator()(const Patients& patients1, const Patients& patients2)
	{
		return strcmp(patients1.surname, patients2.surname) > strcmp(patients2.surname, patients1.surname);
	}
};

struct predNameDecrease
{
	bool operator()(const Patients& patients1, const Patients& patients2)
	{
		return strcmp(patients1.surname, patients2.surname) < strcmp(patients2.surname, patients1.surname);
	}
};

void workWithFiles()
{
	int choice;
	while (true)
	{
		cout << "==============================================================================================================================================================================================" << endl;
		cout << setw(117) << "�������� �������� ��� �������:" << endl << setw(105) << "1.�������� ����� ������" << endl << setw(96) << "2.�������� ������" << endl << setw(105) << "3.������� � ������� ����" << endl << setw(100) << "4.����� �� ���������" << endl;
		checkValue(&choice, 1, 4);
		switch (choice)
		{
		case 1:
			createFile();
			break;

		case 2:
			deleteFiles();
			break;

		case 3:
			return;
			break;

		case 4:
			exitProgramm();
			break;
		}
	}
}

void workWithInfo(vector <Patients>& patients, char* fileToUpload)
{
	int choice;
	while (true)
	{
		cout << "==============================================================================================================================================================================================" << endl;
		cout << setw(125) << "�������� �������� ��� �����������:" << endl << setw(105) << "1.�������� ����������" << endl << setw(108) << "2.���������� ����������" << endl << setw(114) << "3.�������������� ����������" << endl << setw(105) << "4.�������� ����������" << endl << setw(107) << "5.������� � ������� ����" << endl << setw(102) << "6.����� �� ���������" << endl;
		checkValue(&choice, 1, 6);
		switch (choice)
		{
		case 1:
			showPatients(patients);
			break;

		case 2:
			patients.push_back(addPatient(patients));
			downloadData(fileToUpload, patients);
			break;

		case 3:
			showPatients(patients);
			correctPatients(patients);
			downloadData(fileToUpload, patients);
			break;

		case 4:
			showPatients(patients);
			deletePatients(patients, fileToUpload);
			downloadData(fileToUpload, patients);
			break;

		case 5:
			downloadData(fileToUpload, patients);
			return;
			break;

		case 6:
			downloadData(fileToUpload, patients);
			exitProgramm();
			break;
		}
	}
}

void searchInfo(vector <Patients>& patients, char* fileToUpload)
{
	int choice;
	while (true)
	{
		cout << "==============================================================================================================================================================================================" << endl;
		cout << setw(96) << "�������� ��� ������:" << endl << setw(85) << "1.�� �������" << endl << setw(97) << "2.�� ��������" << endl << setw(100) << "3.�� ��������" << endl << setw(100) << "4.�� �����" << endl << setw(100) << "5.������� � ������ ����" << endl << setw(96) << "6.����� �� ���������" << endl;
		checkValue(&choice, 1, 6);
		switch (choice)
		{
		case 1:
			searchBySurname(patients);
			break;

		case 2:
			searchByAge(patients);
			break;

		case 3:
			searchByDiagnosis(patients);
			break;

		case 4:
			searchByName(patients);
			break;

		case 5:
			return;
			break;

		case 6:
			exitProgramm();
			break;
		}
	}
}

void sortInfo(vector <Patients>& patients, char* fileToUpload)
{
	int choice;
	while (true)
	{
		cout << "==============================================================================================================================================================================================" << endl;
		cout << setw(109) << "�������� ��� ����������:" << endl << setw(103) << "1.�� �������� �������" << endl << setw(93) << "2.�� ��������" << endl << setw(102) << "3.�� �������� ������" << endl << setw(102) << "4.�� �������� �����" << endl << setw(104) << "5.�������� ����������" << endl << setw(106) << "6.������� � ������� ����" << endl << setw(102) << "7.����� �� ���������" << endl;
		checkValue(&choice, 1, 7);
		switch (choice)
		{
		case 1:
			sortBySurname(patients);
			downloadData(fileToUpload, patients);
			break;

		case 2:
			sortByAge(patients);
			downloadData(fileToUpload, patients);
			break;

		case 3:
			sortByCity(patients);
			downloadData(fileToUpload, patients);
			break;
		case 4:
			sortByName(patients);
			break;

		case 5:
			showPatients(patients);
			break;

		case 6:
			downloadData(fileToUpload, patients);
			return;
			break;

		case 7:
			downloadData(fileToUpload, patients);
			exitProgramm();
			break;
		}
	}
}

void individualTask(vector <Patients>& patients, char* fileToUpload)
{
	int choice;
	while (true)
	{
		cout << "==============================================================================================================================================================================================" << endl;
		cout << "�������� �������:\n1.������� ���������� � ���������, ������ x ��� � ��������� y\n2.������� ���������� �� ����������� ���������\n3.������� � ������� ����\n4.����� �� ���������" << endl;
		checkValue(&choice, 1, 4);
		switch (choice)
		{
		case 1:
			findOlderWithDiagnose(patients);
			break;

		case 2:
			findNonResidents(patients);
			break;

		case 3:
			return;
			break;

		case 4:
			downloadData(fileToUpload, patients);
			exitProgramm();
			break;
		}
	}
}


void dataToUpload(ifstream& fin, vector <Patients>& patients, int* nPatients)
{
	int choice;
	cout << "==============================================================================================================================================================================================" << endl;
	cout << "�������� ��� ������ ��� �������� �� �����:\n1.������ ��������\n2.�������� �� ���������\n3.��� ������\n4.������� � ������� ����\n5.����� �� ���������\n";
	checkValue(&choice, 1, 5);
	switch (choice)
	{
	case 1:
		uploadOnePatient(fin, patients, &*nPatients);
		break;

	case 2:
		uploadFromDiapason(fin, patients, &*nPatients);
		break;

	case 3:
		uploadAll(fin, patients);
		break;

	case 4:
		return;
		break;

	case 5:
		exitProgramm();
		break;
	}
}

void uploadOnePatient(ifstream& fin, vector <Patients>& patients, int* nPatients)
{
	int number, elements = 0;
	ofstream bufferBeginFout(bufferBeginFile, ios_base::out);
	ofstream bufferEndFout(bufferEndFile, ios_base::out);
	Patients pat_temp;
	char row[400];

	cout << "������� ����� ��������, �������� �� ������ ��������� �� �����:" << endl;
	checkValue(&number, 1, *nPatients);
	*nPatients = 1;
	if (fin.is_open())
	{
		while (elements < number - 1)
		{
			fin.getline(row, 400);
			bufferBeginFout << row << endl;
			elements++;
		}

		fin >> pat_temp.surname >> pat_temp.name >> pat_temp.lastName >> pat_temp.sex >> pat_temp.birthDay >> pat_temp.birthMonth >> pat_temp.birthYear >> pat_temp.city >> pat_temp.phoneNumber >> pat_temp.diagnosis;
		patients.push_back(pat_temp);
	}

	while (!fin.eof())
	{
		fin.getline(row, 400);
		bufferEndFout << row << endl;
	}
	bufferBeginFout.close();
	bufferEndFout.close();
	fin.close();
}

void uploadFromDiapason(ifstream& fin, vector <Patients>& patients, int* nPatients)
{
	int begin, end, elements = 0;
	char row[400];
	ofstream bufferBeginFout(bufferBeginFile, ios_base::out);
	ofstream bufferEndFout(bufferEndFile, ios_base::out);
	Patients pat_temp;

	cout << "������� ����� ������� ���������:" << endl;
	checkValue(&begin, 1, *nPatients - 1);
	cout << "������� ������ ������� ���������:" << endl;
	checkValue(&end, begin, *nPatients);

	if (fin.is_open())
	{
		while (elements < begin - 1)
		{
			fin.getline(row, 400);
			if (row[0] == '\0')
				fin.ignore();
			else
				bufferBeginFout << row << endl;
			elements++;
		}

		for (int i = 0; i < (end - begin + 1); i++)
		{
			fin >> pat_temp.surname >> pat_temp.name >> pat_temp.lastName >> pat_temp.sex >> pat_temp.birthDay >> pat_temp.birthMonth >> pat_temp.birthYear >> pat_temp.city >> pat_temp.phoneNumber >> pat_temp.diagnosis;
			patients.push_back(pat_temp);
		}

		while (!fin.eof())
		{
			fin.getline(row, 400);
			if (row[0] == '\0')
				fin.ignore();
			else
				bufferEndFout << row << endl;
		}
	}
	bufferBeginFout.close();
	bufferEndFout.close();
	fin.close();
}

void uploadAll(ifstream& fin, vector <Patients>& patients)
{
	Patients pat_temp;
	while (!fin.eof())
	{
		fin >> pat_temp.surname >> pat_temp.name >> pat_temp.lastName >> pat_temp.sex >> pat_temp.birthDay >> pat_temp.birthMonth >> pat_temp.birthYear >> pat_temp.city >> pat_temp.phoneNumber >> pat_temp.diagnosis;
		patients.push_back(pat_temp);
	}
	fin.close();
}

void createFile()
{
	char filename[15], newfilename[70];
	cout << "����� ������ ���� ��� �������� ��������� ������" << endl;
	cout << "������� �������� �����(��� ����������):";
	cin.getline(filename, 14);
	strcat_s(newfilename, FILEPATH);
	strcat_s(newfilename, filename);
	strcat_s(newfilename, EXTENSION);
	ofstream file(newfilename, ios_base::out);

	if (file.is_open())
		cout << "���� ��� ������ ������ ������ �������" << endl;
	else
		cout << "�� ������� ������� ����" << endl;
	file.close();
}

void deleteFiles()
{
	char newfilename[70] = "", filename[15], zero[] = "\0";
	int choice;
	listOfFiles();

	cout << "������� ��� �����, ������� �� ������ �������(������ ����)" << endl;
	cin.getline(filename, 15);
	strcat_s(newfilename, FILEPATH);
	strcat_s(newfilename, filename);
	strcat_s(newfilename, EXTENSION);
	cout << "�� �������, ��� ������ ������� ������ ����? ������� 1, ��� ��������" << endl;
	cin >> choice;

	if (choice == 1)
	{
		if (remove(newfilename) != 0)
			cout << "������ �������� �����" << endl;
		else
		{
			cout << "���� ������� �����" << endl;
			for (int i = 0; i < 69; i++)
				filename[i] = zero[i];
		}
	}
	else
		return;
}

void chooseOrCreateFileToUpload(char* newfilename)
{
	char filename[20] = "";
	listOfFiles();
	cout << "������� ��� �����, �� �������� �� ������ ��������� ����������(��� ����������) ��� ������� Enter ��� �������� ������ �����" << endl;
	cin.getline(filename, 15);
	if (my_strlen(filename) != 0)
	{
		int length = my_strlen(FILEPATH);
		strcat_s(newfilename, length, FILEPATH);
		int length1 = my_strlen(filename);
		strcat_s(newfilename, length, filename);
		int length2 = my_strlen(EXTENSION);
		strcat_s(newfilename, length, EXTENSION);
	}
	else
		createFile();
}

void chooseFileToUpload(char* newfilename)
{
	char filename[20] = "";
	listOfFiles();
	cout << "������� ��� �����, �� �������� �� ������ ��������� ����������(��� ����������)" << endl;
	cin.getline(filename, 15);
	if (my_strlen(filename) != 0)
	{
		int length = my_strlen(FILEPATH);
		strcat_s(newfilename, length, FILEPATH);
		int length1 = my_strlen(filename);
		strcat_s(newfilename, length, filename);
		int length2 = my_strlen(EXTENSION);
		strcat_s(newfilename, length, EXTENSION);
	}
	else
		chooseFileToUpload(newfilename);
}

void showPatients(vector <Patients> patients)
{
	if (patients.size() == 0)
	{
		cout << "������ ��������� ����!" << endl;
		return;
	}
	cout << endl << endl;
	cout << setw(160) << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << setw(140) << "************************  ������ ���������  ***********************" << endl;
	top_table();
	for (int i = 0; i < patients.size(); i++)
		displayInfo(i, patients);
}

Patients addPatient(vector <Patients>& patients)
{
	cout << "==============================================================================================================================================================================================" << endl;
	Patients pat_temp;
	cout << "\n\t������� ������� ��������: ";
	cin >> pat_temp.surname;
	swap(&pat_temp.surname[0]);

	cout << "\n\t������� ��� ��������: ";
	cin >> pat_temp.name;
	swap(&pat_temp.name[0]);

	cout << "\n\t������� �������� ��������: ";
	cin >> pat_temp.lastName;
	swap(&pat_temp.lastName[0]);

	while ((pat_temp.sex != 77) && (pat_temp.sex != 70))
	{
		cout << "\n\t������� ��� ��������(M - �������, F - �������): ";
		cin >> pat_temp.sex;
	}
	swap(&pat_temp.sex);

	cout << "\n\t������� ����� ��� ��������: ";
	checkValue(&pat_temp.birthDay, 1, 31);

	cout << "\n\t������� ����� ������ ��������: ";
	checkValue(&pat_temp.birthMonth, 1, 12);

	cout << "\n\t������� ��� ��������: ";
	checkValue(&pat_temp.birthYear, 0, 3000);

	cout << "\n\t������� ����� ����������: ";
	cin >> pat_temp.city;
	swap(&pat_temp.city[0]);

	cout << "\n\t������� ����� ��������(� �����): ";
	cin >> pat_temp.phoneNumber;

	cout << "\n\t������� �������: ";
	cin >> pat_temp.diagnosis;
	swap(&pat_temp.diagnosis[0]);
	return pat_temp;
}

void correctPatients(vector <Patients>& patients)
{
	cout << "==============================================================================================================================================================================================" << endl;
	int nPatients = (int)patients.size();
	if (nPatients == 0)
	{
		cout << "������ ��������� ����!" << endl;
		return;
	}
	int num_cor = 0, rez;
	cout << "������� ����� ��������, ������ �������� �� ������ ����������������:";
	checkValue(&num_cor, 1, nPatients);
	cout << "�� �������,��� ������ ���������������� ������ �������� � " << num_cor << "?\n������� 1 ��� �������������" << endl;
	num_cor--;
	cin >> rez;

	if (rez == 1)
	{
		patients.erase(patients.begin() + num_cor);
		patients.insert(patients.begin() + num_cor, addPatient(patients));
		num_cor++;
		cout << "������ �������� � " << num_cor << " ����������������" << endl;
	}
	else
		cout << "������ �������� � ���������� ���������" << endl;
}

void deletePatients(vector <Patients>& patients, char* mainFile)
{
	cout << "==============================================================================================================================================================================================" << endl;
	int nPatients = (int)patients.size();
	if (nPatients == 0)
	{
		cout << "������ ��������� ����!" << endl;
		return;
	}
	int choice, num_to_delete;
	cout << "��������, ��� ������ �� ������ �������:\n1.������ ��������\n2.��� ����������� ����������" << endl;
	checkValue(&choice, 1, 2);
	switch (choice)
	{
	case 1:
		cout << "������� ����� ��������, ������ �������� �� ������ �������" << endl;
		checkValue(&num_to_delete, 1, nPatients);
		num_to_delete--;
		sureDeletePatient(patients, num_to_delete);
		break;

	case 2:
		sureDeleteAllPatients(patients, mainFile);
		break;
	}
}
void downloadData(char* mainFile, vector <Patients> patients)
{
	ofstream fout(mainFile, ios_base::out);
	ifstream bufferBeginFout(bufferBeginFile, ios_base::out);
	ifstream bufferEndFout(bufferEndFile, ios_base::out);
	int surnameLength = 0, nameLength, lastLength, cityLength;
	char row[400];

	while (!bufferBeginFout.eof())
	{
		bufferBeginFout.getline(row, 400);
		fout << row << endl;
	}
	for (int i = 0; i < patients.size(); i++)
	{
		surnameLength = my_strlen(patients.at(i).surname);
		nameLength = my_strlen(patients.at(i).name);
		lastLength = my_strlen(patients.at(i).lastName);
		cityLength = my_strlen(patients.at(i).city);

		fout << patients.at(i).surname << setw(20 - surnameLength) << patients.at(i).name << setw(20 - nameLength) << patients.at(i).lastName << setw(20 - lastLength) << patients.at(i).sex << "\t" << patients.at(i).birthDay << " " << patients.at(i).birthMonth << " " << patients.at(i).birthYear << "\t" << patients.at(i).city << setw(25 - cityLength) << patients.at(i).phoneNumber << "\t" << patients.at(i).diagnosis << endl;
	}
	while (!bufferEndFout.eof())
	{
		bufferEndFout.getline(row, 400);
		fout << row << endl;
	}
	fout.close();
	bufferBeginFout.close();
	bufferEndFout.close();
}


void sureDeletePatient(vector <Patients>& patients, int num_to_delete)
{
	int rez;
	cout << "�� ������� , ��� ������ ������� ��������?������� 1 ��� �������������" << endl;
	checkValue(&rez, 1, 2);
	if (rez == 1)
	{
		patients.erase(patients.begin() + num_to_delete);
		num_to_delete++;
		cout << "������� � " << num_to_delete << " ������� ������" << endl;
	}
	else
		cout << "������ �������� � ���������� ���������" << endl;
}

double computeAge(double day, double month, double year) //������ �������� �� ������� ����
{
	double age;
	time_t  seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	age = timeinfo->tm_year + 1900 - year;

	if (month < timeinfo->tm_mon + 1)
	{
		age = age + ((timeinfo->tm_mon + 1 - month) * 30 + timeinfo->tm_mday - day) / 1000;
	}
	else if ((month == timeinfo->tm_mon + 1) && (day < timeinfo->tm_mday))
	{
		age = age + (timeinfo->tm_mday - day) / 1000;
	}
	else if ((month == timeinfo->tm_mon + 1) && (day > timeinfo->tm_mday))
	{
		age = age - (day - timeinfo->tm_mday) / 1000;
	}
	else
	{
		age = age - ((month - timeinfo->tm_mon + 1) * 30 + timeinfo->tm_mday - day) / 1000;
	}

	return age;
}
//���� ���� �������� ��� ��� � ���������� �������: ��������� ������� � ����� ((������� ������� � ������� ��������)*30 � ������� ���� � ���� ��������)/1000
//���� ���� �������� ��� � ���� ������: ��������� ������� ����� (����������� ���� � ���� ��������)/1000
//���� ��� �������� ��� �� ���� , �� ����� � ���� ������: �� (��� �������� ������ ����������� ����)/1000
//���� ���� �������� � ��������� �������: ������ ((������� ����� ������� �������� � ������� �������)/30 + ������� ����� ���� �������� � ����������� ����)/1000

void findOlderWithDiagnose(vector <Patients> patients)
{
	cout << "==============================================================================================================================================================================================" << endl;
	int age;
	double locDay, locMonth, locYear;
	char diagnose[] = "";
	bool isFound = false;
	cout << "����� ��������� ������ x ��� � ��������� y" << endl;
	cout << "������� ������ ������� ��������" << endl;
	checkValue(&age, 0, 200);
	cout << "������� �������" << endl;
	cin.getline(diagnose, '\n');

	top_table();
	for (int i = 0; i < patients.size(); i++)
	{
		locDay = (double)patients.at(i).birthDay;
		locMonth = (double)patients.at(i).birthMonth;
		locYear = (double)patients.at(i).birthYear;

		if ((computeAge(locDay, locMonth, locYear) > age) && (strncmp(patients.at(i).diagnosis, diagnose, my_strlen(diagnose)) == 0))
		{
			isFound = true;
			displayInfo(i, patients);
		}
	}
	if (isFound == false)
		cout << "��������� ������ ��������� �������� � ������ ��������� �� �������" << endl;
}

void findNonResidents(vector <Patients> patients)
{
	cout << "==============================================================================================================================================================================================" << endl;
	bool isFound = false;
	top_table();
	for (int i = 0; i < patients.size(); i++)
	{
		if (strcmp(patients.at(i).city, RESIDENCE) != 0)
		{
			isFound = true;
			displayInfo(i, patients);
		}
	}
	if (isFound == false)
		cout << "����������� ��������� � ������ �� ����������" << endl;
	else
		cout << "����� ����������� ��������� �������� �������" << endl;
}

void displayInfo(int nPatients, vector <Patients> patients)
{
	int surnameLength = 0, nameLength, lastLength, cityLength;

	surnameLength = my_strlen(patients.at(nPatients).surname);
	nameLength = my_strlen(patients.at(nPatients).name);
	lastLength = my_strlen(patients.at(nPatients).lastName);
	cityLength = my_strlen(patients.at(nPatients).city);

	cout << setw(30) << nPatients + 1 << "." << " | " << patients.at(nPatients).surname << setw(15 - surnameLength) << " | " << patients.at(nPatients).name << setw(15 - nameLength) << " | " << patients.at(nPatients).lastName << setw(20 - lastLength) << " | " << patients.at(nPatients).sex << " | " << "\t" << patients.at(nPatients).birthDay << "." << patients.at(nPatients).birthMonth << "." << patients.at(nPatients).birthYear << "\t" << " | " << patients.at(nPatients).city << setw(20 - cityLength) << " | " << patients.at(nPatients).phoneNumber << "     | " << "\t" << patients.at(nPatients).diagnosis << setw(14 - my_strlen(patients.at(nPatients).diagnosis)) << "| " << endl;
	cout << setw(160) << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void sortByAge(vector <Patients>& patients)
{
	cout << "==============================================================================================================================================================================================" << endl;
	int direction;
	cout << "�������� ����������� ����������:\n1.�� ��������\n2.�� �����������" << endl;
	checkValue(&direction, 1, 2);
	if (direction == 1)
		sort(patients.begin(), patients.end(), predAgeDecrease());
	else
		sort(patients.begin(), patients.end(), predAgeIncrease());
	cout << "���������� �� �������� ��������� �������" << endl;
}

void sortByCity(vector <Patients>& patients)
{
	cout << "==============================================================================================================================================================================================" << endl;
	int direction;
	cout << "�������� ����������� ����������:\n1.�� ��������\n2.�� �����������" << endl;
	checkValue(&direction, 1, 2);

	if (direction == 1)
		sort(patients.begin(), patients.end(), predCityDecrease());
	else
		sort(patients.begin(), patients.end(), predCityIncrease());
	cout << "���������� �� �������� ������ ��������� �������" << endl;
}

void sureDeleteAllPatients(vector <Patients>& patients, char* mainFile)
{
	cout << "==============================================================================================================================================================================================" << endl;
	int choice;
	cout << "�� �������, ��� ������ ������� ��� ������ � ���������? ������� 1 ��� �������������" << endl;
	cin >> choice;

	if (choice == 1)
	{
		patients.clear();
		ofstream fout(mainFile, ios_base::out);
		fout.close();
		cout << "�������� ��������� ������� " << endl;
	}
	cout << "������ �������� � ���������� ���������" << endl;
}

void sortBySurname(vector <Patients>& patients)
{
	cout << "==============================================================================================================================================================================================" << endl;
	int direction;
	cout << "�������� ����������� ����������:\n1.�� ��������\n2.�� �����������" << endl;
	checkValue(&direction, 1, 2);

	if (direction == 1)
		sort(patients.begin(), patients.end(), predSurnameDecrease());
	else
		sort(patients.begin(), patients.end(), predSurnameIncrease());
	cout << "���������� �� �������� ������� ��������� �������" << endl;
}

void sortByName(vector <Patients>& patients)
{
	cout << "==============================================================================================================================================================================================" << endl;
	int direction;
	cout << "�������� ����������� ����������:\n1.�� ��������\n2.�� �����������" << endl;
	checkValue(&direction, 1, 2);
	if (direction == 1)
		sort(patients.begin(), patients.end(), predNameDecrease());
	else
		sort(patients.begin(), patients.end(), predNameIncrease());
	cout << "���������� �� �������� ��������� �������" << endl;
}


void searchBySurname(vector <Patients>& patients)
{
	cout << "==============================================================================================================================================================================================" << endl;
	char surname_to_search[20] = "";
	bool isFound = false;
	cout << "������� ������� ������� ��� ������: ";
	cin.getline(surname_to_search, 19);
	swap(&surname_to_search[0]);

	int search_size = my_strlen(surname_to_search);
	top_table();
	for (int i = 0; i < patients.size(); i++)
	{
		if (strncmp(surname_to_search, patients.at(i).surname, search_size) == 0)
		{
			displayInfo(i, patients);
			isFound = true;
		}
	}
	if (isFound == false)
		cout << "�� ������� ��������� � ����� ��������" << endl;
}

void searchByAge(vector <Patients>& patients)
{
	cout << "==============================================================================================================================================================================================" << endl;
	int age_to_search;
	bool isFound = false;
	cout << "������� ������� ��� ������: ";
	checkValue(&age_to_search, 0, 150);

	top_table();
	for (int i = 0; i < patients.size(); i++)
	{
		if ((int)computeAge(patients.at(i).birthDay, patients.at(i).birthMonth, patients.at(i).birthYear) == age_to_search)
		{
			displayInfo(i, patients);
			isFound = true;
		}
	}
	if (isFound == false)
		cout << "�� ������� ��������� � ����� ���������" << endl;
}

void searchByDiagnosis(vector <Patients>& patients)
{
	cout << "==============================================================================================================================================================================================" << endl;
	char diagnose_to_search[50] = "";
	bool isFound = false;
	cout << "������� ������� ������� ��� ������: ";
	cin.getline(diagnose_to_search, 49);
	swap(&diagnose_to_search[0]);
	int search_size = my_strlen(diagnose_to_search);

	top_table();
	for (int i = 0; i < patients.size(); i++)
	{
		if (strncmp(diagnose_to_search, patients.at(i).diagnosis, search_size) == 0)
		{
			displayInfo(i, patients);
			isFound = true;
		}
	}
	if (isFound == false)
		cout << "�� ������� ��������� � ����� ���������" << endl;
}

void searchByName(vector <Patients>& patients)
{
	cout << "==============================================================================================================================================================================================" << endl;
	char name_to_search[20] = "";
	bool isFound = false;
	cout << "������� ������� ��� ��� ������: ";
	cin.getline(name_to_search, 19);
	swap(&name_to_search[0]);

	int search_size = my_strlen(name_to_search);
	top_table();
	for (int i = 0; i < patients.size(); i++)
	{
		if (strncmp(name_to_search, patients.at(i).surname, search_size) == 0)
		{
			displayInfo(i, patients);
			isFound = true;
		}
	}
	if (isFound == false)
		cout << "�� ������� ��������� � ����� ������" << endl;
}
void top_table()
{
	cout << setw(160) << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << setw(33) << "� " << " | " << "�������     " << " | " << "���         " << " | " << "��������         " << " |" << "���" << "| " << "  ���� �������� " << " | " << "����� ���������� " << " | " << "��������� �������" << " | " << "�������     " << " | " << endl;
	cout << setw(160) << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;
}