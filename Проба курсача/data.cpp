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
		cout << setw(117) << "Выберите действие над файлами:" << endl << setw(105) << "1.Создание новых файлов" << endl << setw(96) << "2.Удаление файлов" << endl << setw(105) << "3.Возврат в главное меню" << endl << setw(100) << "4.Выход из программы" << endl;
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
		cout << setw(125) << "Выберите действие над информацией:" << endl << setw(105) << "1.Просмотр информации" << endl << setw(108) << "2.Добавление информации" << endl << setw(114) << "3.Редактирование информации" << endl << setw(105) << "4.Удаление информации" << endl << setw(107) << "5.Возврат в главное меню" << endl << setw(102) << "6.Выход из программы" << endl;
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
		cout << setw(96) << "Выберите вид поиска:" << endl << setw(85) << "1.По фамилии" << endl << setw(97) << "2.По возрасту" << endl << setw(100) << "3.По диагнозу" << endl << setw(100) << "4.По имени" << endl << setw(100) << "5.Возврат в гланое меню" << endl << setw(96) << "6.Выход из программы" << endl;
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
		cout << setw(109) << "Выберите вид сортировки:" << endl << setw(103) << "1.По алфавиту фамилии" << endl << setw(93) << "2.По возрасту" << endl << setw(102) << "3.По алфавиту города" << endl << setw(102) << "4.По алфавиту имени" << endl << setw(104) << "5.Просмотр информации" << endl << setw(106) << "6.Возврат в главное меню" << endl << setw(102) << "7.Выход из программы" << endl;
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
		cout << "Выберите задание:\n1.Вывести информацию о пациентах, старше x лет с диагнозом y\n2.Вывести информацию об иногородних пациентах\n3.Возврат в главное меню\n4.Выход из программы" << endl;
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
	cout << "Выберите вид данных для выгрузки из файла:\n1.Одного пациента\n2.Пациенты из диапазона\n3.Все данные\n4.Возврат в главное меню\n5.Выход из программы\n";
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

	cout << "Введите номер пациента, которого вы хотите выгрузить из файла:" << endl;
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

	cout << "Введите левую границу диапазона:" << endl;
	checkValue(&begin, 1, *nPatients - 1);
	cout << "Введите правую границу диапазона:" << endl;
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
	cout << "Будет создан файл для хранения изменённых данных" << endl;
	cout << "Введите название файла(без расширения):";
	cin.getline(filename, 14);
	strcat_s(newfilename, FILEPATH);
	strcat_s(newfilename, filename);
	strcat_s(newfilename, EXTENSION);
	ofstream file(newfilename, ios_base::out);

	if (file.is_open())
		cout << "Файл для записи данных создан успешно" << endl;
	else
		cout << "Не удалось создать файл" << endl;
	file.close();
}

void deleteFiles()
{
	char newfilename[70] = "", filename[15], zero[] = "\0";
	int choice;
	listOfFiles();

	cout << "Введите имя файла, который вы хотите удалить(список выше)" << endl;
	cin.getline(filename, 15);
	strcat_s(newfilename, FILEPATH);
	strcat_s(newfilename, filename);
	strcat_s(newfilename, EXTENSION);
	cout << "Вы уверены, что хотите удалить данный файл? Нажмите 1, для удаления" << endl;
	cin >> choice;

	if (choice == 1)
	{
		if (remove(newfilename) != 0)
			cout << "Ошибка удаления файла" << endl;
		else
		{
			cout << "Файл успешно удалён" << endl;
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
	cout << "Введите имя файла, из которого вы хотите выгрузить информацию(без расширения) или нажмите Enter для создания нового файла" << endl;
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
	cout << "Введите имя файла, из которого вы хотите выгрузить информацию(без расширения)" << endl;
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
		cout << "Список пациентов пуст!" << endl;
		return;
	}
	cout << endl << endl;
	cout << setw(160) << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << setw(140) << "************************  Список пациентов  ***********************" << endl;
	top_table();
	for (int i = 0; i < patients.size(); i++)
		displayInfo(i, patients);
}

Patients addPatient(vector <Patients>& patients)
{
	cout << "==============================================================================================================================================================================================" << endl;
	Patients pat_temp;
	cout << "\n\tВведите фамилию пациента: ";
	cin >> pat_temp.surname;
	swap(&pat_temp.surname[0]);

	cout << "\n\tВведите имя пациента: ";
	cin >> pat_temp.name;
	swap(&pat_temp.name[0]);

	cout << "\n\tВведите отчество пациента: ";
	cin >> pat_temp.lastName;
	swap(&pat_temp.lastName[0]);

	while ((pat_temp.sex != 77) && (pat_temp.sex != 70))
	{
		cout << "\n\tВведите пол пациента(M - мужской, F - женский): ";
		cin >> pat_temp.sex;
	}
	swap(&pat_temp.sex);

	cout << "\n\tВведите число дня рождения: ";
	checkValue(&pat_temp.birthDay, 1, 31);

	cout << "\n\tВведите номер месяца рождения: ";
	checkValue(&pat_temp.birthMonth, 1, 12);

	cout << "\n\tВведите год рождения: ";
	checkValue(&pat_temp.birthYear, 0, 3000);

	cout << "\n\tВведите город проживания: ";
	cin >> pat_temp.city;
	swap(&pat_temp.city[0]);

	cout << "\n\tВведите номер телефона(с кодом): ";
	cin >> pat_temp.phoneNumber;

	cout << "\n\tВведите диагноз: ";
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
		cout << "Список пациентов пуст!" << endl;
		return;
	}
	int num_cor = 0, rez;
	cout << "Введите номер пациента, данные которого вы хотите откорректировать:";
	checkValue(&num_cor, 1, nPatients);
	cout << "Вы уверены,что хотите откорректировать данные пациента № " << num_cor << "?\nНажмите 1 для подтверждения" << endl;
	num_cor--;
	cin >> rez;

	if (rez == 1)
	{
		patients.erase(patients.begin() + num_cor);
		patients.insert(patients.begin() + num_cor, addPatient(patients));
		num_cor++;
		cout << "Данные пациента № " << num_cor << " откорректированы" << endl;
	}
	else
		cout << "Данные остались в неизменном состоянии" << endl;
}

void deletePatients(vector <Patients>& patients, char* mainFile)
{
	cout << "==============================================================================================================================================================================================" << endl;
	int nPatients = (int)patients.size();
	if (nPatients == 0)
	{
		cout << "Список пациентов пуст!" << endl;
		return;
	}
	int choice, num_to_delete;
	cout << "Выберите, что именно вы хотите удалить:\n1.Одного пациента\n2.Всю выгруженную информацию" << endl;
	checkValue(&choice, 1, 2);
	switch (choice)
	{
	case 1:
		cout << "Введите номер пациента, данные которого вы хотите удалить" << endl;
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
	cout << "Вы уверены , что хотите удалить пациента?Нажмите 1 для подтверждения" << endl;
	checkValue(&rez, 1, 2);
	if (rez == 1)
	{
		patients.erase(patients.begin() + num_to_delete);
		num_to_delete++;
		cout << "Пациент № " << num_to_delete << " успешно удален" << endl;
	}
	else
		cout << "Данные остались в неизменном состоянии" << endl;
}

double computeAge(double day, double month, double year) //расчет возраста на текущую дату
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
//Если день рождения уже был в предыдущих месяцах: прибавить разницу в между ((текущим месяцем и месяцем рождения)*30 и текущим днем и днем рождения)/1000
//Если день рождения был в этом месяце: Прибавить разницу между (сегодняшним днем и днем рождения)/1000
//Если дня рождения еще не было , но будет в этом месяце: от (дня рождения отнять сегодняшний день)/1000
//Если день рождения в следующих месяцах: отнять ((разницу между месяцем рождения и текущим месяцем)/30 + разницу между днем рождения и сегодняшним днем)/1000

void findOlderWithDiagnose(vector <Patients> patients)
{
	cout << "==============================================================================================================================================================================================" << endl;
	int age;
	double locDay, locMonth, locYear;
	char diagnose[] = "";
	bool isFound = false;
	cout << "Поиск пациентов старше x лет с диагнозом y" << endl;
	cout << "Введите нижнюю границу возраста" << endl;
	checkValue(&age, 0, 200);
	cout << "Введите диагноз" << endl;
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
		cout << "Пациентов старше введённого возраста с данным диагнозом не найдено" << endl;
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
		cout << "Иногородних пациентов в списке не обнаружено" << endl;
	else
		cout << "Поиск иногородних пациентов выполнен успешно" << endl;
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
	cout << "Выберите направление сортировки:\n1.По убыванию\n2.По возрастанию" << endl;
	checkValue(&direction, 1, 2);
	if (direction == 1)
		sort(patients.begin(), patients.end(), predAgeDecrease());
	else
		sort(patients.begin(), patients.end(), predAgeIncrease());
	cout << "Сортировка по возрасту выполнена успешно" << endl;
}

void sortByCity(vector <Patients>& patients)
{
	cout << "==============================================================================================================================================================================================" << endl;
	int direction;
	cout << "Выберите направление сортировки:\n1.По убыванию\n2.По возрастанию" << endl;
	checkValue(&direction, 1, 2);

	if (direction == 1)
		sort(patients.begin(), patients.end(), predCityDecrease());
	else
		sort(patients.begin(), patients.end(), predCityIncrease());
	cout << "Сортировка по алфавиту города выполнена успешно" << endl;
}

void sureDeleteAllPatients(vector <Patients>& patients, char* mainFile)
{
	cout << "==============================================================================================================================================================================================" << endl;
	int choice;
	cout << "Вы уверены, что хотите удалить все данные о пациентах? Нажмите 1 для подтверждения" << endl;
	cin >> choice;

	if (choice == 1)
	{
		patients.clear();
		ofstream fout(mainFile, ios_base::out);
		fout.close();
		cout << "Удаление выполнено успешно " << endl;
	}
	cout << "Данные остались в неизменном состоянии" << endl;
}

void sortBySurname(vector <Patients>& patients)
{
	cout << "==============================================================================================================================================================================================" << endl;
	int direction;
	cout << "Выберите направление сортировки:\n1.По убыванию\n2.По возрастанию" << endl;
	checkValue(&direction, 1, 2);

	if (direction == 1)
		sort(patients.begin(), patients.end(), predSurnameDecrease());
	else
		sort(patients.begin(), patients.end(), predSurnameIncrease());
	cout << "Сортировка по алфавиту фамилии выполнена успешно" << endl;
}

void sortByName(vector <Patients>& patients)
{
	cout << "==============================================================================================================================================================================================" << endl;
	int direction;
	cout << "Выберите направление сортировки:\n1.По убыванию\n2.По возрастанию" << endl;
	checkValue(&direction, 1, 2);
	if (direction == 1)
		sort(patients.begin(), patients.end(), predNameDecrease());
	else
		sort(patients.begin(), patients.end(), predNameIncrease());
	cout << "Сортировка по возрасту выполнена успешно" << endl;
}


void searchBySurname(vector <Patients>& patients)
{
	cout << "==============================================================================================================================================================================================" << endl;
	char surname_to_search[20] = "";
	bool isFound = false;
	cout << "Начните вводить фамилию для поиска: ";
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
		cout << "Не найдено пациентов с такой фамилией" << endl;
}

void searchByAge(vector <Patients>& patients)
{
	cout << "==============================================================================================================================================================================================" << endl;
	int age_to_search;
	bool isFound = false;
	cout << "Введите возраст для поиска: ";
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
		cout << "Не найдено пациентов с таким возрастом" << endl;
}

void searchByDiagnosis(vector <Patients>& patients)
{
	cout << "==============================================================================================================================================================================================" << endl;
	char diagnose_to_search[50] = "";
	bool isFound = false;
	cout << "Начните вводить диагноз для поиска: ";
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
		cout << "Не найдено пациентов с таким диагнозом" << endl;
}

void searchByName(vector <Patients>& patients)
{
	cout << "==============================================================================================================================================================================================" << endl;
	char name_to_search[20] = "";
	bool isFound = false;
	cout << "Начните вводить имя для поиска: ";
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
		cout << "Не найдено пациентов с таким именем" << endl;
}
void top_table()
{
	cout << setw(160) << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << setw(33) << "№ " << " | " << "Фамилия     " << " | " << "Имя         " << " | " << "Отчество         " << " |" << "Пол" << "| " << "  Дата рождения " << " | " << "Город проживания " << " | " << "Мобильный телефон" << " | " << "Диагноз     " << " | " << endl;
	cout << setw(160) << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;
}