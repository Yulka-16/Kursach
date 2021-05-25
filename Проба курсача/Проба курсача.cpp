#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include "accounts.h"
#include "common.h"
#include "data.h"

const int ADMIN_SIGN = 0;     //идентификатор роли администратора
char bufferBegin[80] = "D/Учёба/2 семестр/Курсовая работа/Для файлов/BufferBegin.txt";   //буферный файл для хранения информации, расположенной до выгруженной
char BufferEnd[80] = "D/Учёба/2 семестр/Курсовая работа/Для файлов/bufferEnd.txt";       //буферный файл для хранения информации, расположенной после выгруженной

void adminChooseMode(vector <Autorization>&, int*, int*);  //выбор режима работы администратора
void userMode();          //выбор действия пользователя
void accountsForAdmin(vector <Autorization>&, int*);       //работа с учетными записями
void clientsForAdmin();   //выбор работы с данными пациентов или с файлами
void infoForAdmin();      //работа с данными пациентов
int defineRole(ifstream&, vector <Autorization>&, int*, int*);   //определение роли
void introduceProgramm(); //приветствие пользователя
void downloadAccounts(int*, ifstream&, vector <Autorization>&);  //выгрузка аккаунтов из файла в вектор

Autorization* autorizations;

int main()
{
	setlocale(0, "");
	ifstream fin(Logins, ios_base::in);
	fin.clear();
	fin.seekg(0);
	int nUsers = countRows(fin), user_num;
	introduceProgramm();
	vector <Autorization> autorize;
	while (true) 
	{
		if (defineRole(fin, autorize, &nUsers, &user_num) == ADMIN_SIGN) 
		{
			user_num = user_num + 1;
			adminChooseMode(autorize, &nUsers, &user_num);
		}
		else
			userMode();
	}
	return 0;
}

int defineRole(ifstream& fin, vector <Autorization>& autorize, int* nUsers, int* user_num)
{
	fin.clear();
	fin.seekg(0);
	openFile(autorize, &*nUsers);
	int role = 1;
	fin.close();
	downloadAccounts(&*nUsers, fin, autorize);
	if (isAccountValid(autorize, &role, &*user_num)) 
	{
		cout << setw(100) << "----------------------------------------------" << endl;
		cout << setw(55) << "|" << "       Вход в систему выполнен успешно       " << "|" << endl;
		if (role == ADMIN_SIGN) 
		{
			cout << setw(55) << "|" << "Авторизация выполнена для роли администратора" << "|" << endl;
			cout << setw(100) << "----------------------------------------------" << endl << endl << endl;
			return 0;
		}
		else
		{
			cout << setw(55) << "|" << "Авторизация выполнена для роли пользователя  " << "|" << endl;
			cout << setw(100) << "----------------------------------------------" << endl << endl << endl;
			return 1;
		}
	}
	else return 0;
}

void downloadAccounts(int* nUsers, ifstream& fin, vector <Autorization>& autorize)
{
	Autorization auto_num;
	for (int i = 0; i < *nUsers; i++)
	{
		fin >> auto_num.login >> auto_num.password >> auto_num.role;
		autorize.push_back(auto_num);
	}
}

void adminChooseMode(vector <Autorization>& autorize, int* nUsers, int* user_num)
{
	int choice;
	while (true)
	{
		cout << "==============================================================================================================================================================================================" << endl;
		cout << setw(100) << "Выберите вид работы" << endl << setw(145) << "1.Работа с учетными записями и файлами, хранящими их" << endl << setw(147) << "2.Работа с данными о пациентах и файлами, хранящими их" << endl << setw(105) << "3.Сменить пользователя" << endl << setw(101) << "4.Выход из программы" << endl;
		checkValue(&choice, 1, 4);
		switch (choice) 
		{
		case 1:
			accountsForAdmin(autorize, &*user_num);
			break;

		case 2:
			clientsForAdmin();
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

void userMode() 
{
	int choice = 0, nPatients;
	char mainFile[90] = "\0";
	chooseFileToUpload(mainFile);
	ifstream fin(mainFile, ios_base::in);
	if (fin.is_open()) 
	{
		nPatients = countRows(fin);
		vector <Patients> patients;
		fin.clear();
		fin.seekg(0);

		if (nPatients == 0)
			cout << "Данных в файле не обнаружено" << endl;
		else
		{
			ofstream bufferBeginFout(bufferBegin, ios_base::out);
			bufferBeginFout.is_open();
			bufferBeginFout.close();
			ofstream bufferEndFout(BufferEnd, ios_base::out);
			bufferEndFout.is_open();
			bufferEndFout.close();
			dataToUpload(fin, patients, &nPatients);
		}

		while (true)
		{
			cout << "==============================================================================================================================================================================================" << endl;
			cout << setw(100) << "Выберите действие:" << endl << setw(103) << "1.Просмотр информации" << endl << setw(83) << "2.Поиск" << endl << setw(90) << "3.Сортировка" << endl << setw(107) << "4.Индивидуальное задание" << endl << setw(105) << "5.Сменить пользователя" << endl << setw(101) << "6.Выход из программы" << endl;
			checkValue(&choice, 1, 6);
			switch (choice) 
			{
			case 1:
				showPatients(patients);
				break;

			case 2:
				searchInfo(patients, mainFile);
				break;

			case 3:
				sortInfo(patients, mainFile);
				break;

			case 4:
				individualTask(patients, mainFile);
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
	else
	{
		cout << "Повторите ввод имени файла" << endl;
		userMode();
	}
}

void accountsForAdmin(vector <Autorization>& autorize, int* user_num) 
{
	int choice;
	while (true)
	{
		cout << "==============================================================================================================================================================================================" << endl;
		cout << setw(120) << "Выберите действие над учетными записями\n" << setw(100) << "1.Просмотр учетных записей\n" << setw(102) << "2.Добавление учетной записи\n" << setw(110) << "3.Редактирование учетных записей\n" << setw(100) << "4.Удаление учетных записей\n" << setw(95) << "5.Возврат в меню\n" << setw(91) << "6.Выйти из программы" << endl;
		checkValue(&choice, 1, 6);
		switch (choice) 
		{
		case 1:
			showAccounts(autorize);
			break;

		case 2:
			autorize.push_back(addAccount(autorize));
			break;

		case 3:
			showAccounts(autorize);
			correctAccounts(autorize);
			break;

		case 4:
			showAccounts(autorize);
			deleteAccounts(autorize, &*user_num);
			break;

		case 5:
			foutUsers(autorize);
			return;
			break;

		case 6:
			foutUsers(autorize);
			exitProgramm();
			break;
		}
	}
}

void clientsForAdmin() 
{
	int choice = 0;
	while (true) 
	{
		cout << "==============================================================================================================================================================================================" << endl;
		cout << setw(97) << "Выберите раздел:" << endl << setw(98) << "1.Работа с файлами" << endl << setw(104) << "2.Обработка информации" << endl << setw(95) << "3.Возврат в меню" << endl << setw(101) << "4.Выход из программы" << endl;
		checkValue(&choice, 1, 4);
		switch (choice) 
		{
		case 1:
			workWithFiles();
			break;

		case 2:
			infoForAdmin();
			break;

		case 3:
			return;

		case 4:
			exitProgramm();
			break;
		}
	}
}


void infoForAdmin() 
{
	int choice = 0, nPatients;
	char mainFile[90] = "\0";
	chooseOrCreateFileToUpload(mainFile);
	ifstream fin(mainFile, ios_base::in);
	if (fin.is_open()) 
	{
		nPatients = countRows(fin);
		vector <Patients> patients;
		fin.clear();
		fin.seekg(0);
		if (nPatients == 0)
			cout << "Данных в файле не обнаружено" << endl;
		else
		{
			ofstream bufferBeginFout(bufferBegin, ios_base::out);
			bufferBeginFout.is_open();
			bufferBeginFout.close();
			ofstream bufferEndFout(BufferEnd, ios_base::out);
			bufferEndFout.is_open();
			bufferEndFout.close();
			fin.clear();
			fin.seekg(0);
			dataToUpload(fin, patients, &nPatients);
		}
		while (true) 
		{
			cout << "==============================================================================================================================================================================================" << endl;
			cout << setw(96) << "Выберите раздел:" << endl << setw(103) << "1.Обработка информации" << endl << setw(83) << "2.Поиск" << endl << setw(90) << "3.Сортировка" << endl << setw(107) << "4.Индивидуальное задание" << endl << setw(95) << "5.Возврат в меню" << endl << setw(101) << "6.Выход из программы" << endl;
			checkValue(&choice, 1, 7);
			switch (choice)
			{
			case 1:
				workWithInfo(patients, mainFile);
				break;

			case 2:
				searchInfo(patients, mainFile);
				break;

			case 3:
				sortInfo(patients, mainFile);
				break;

			case 4:
				individualTask(patients, mainFile);
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
	else 
	{
		cout << "Повторите ввод имени файла" << endl;
		infoForAdmin();
	}
}

void introduceProgramm() 
{
	cout << endl << endl << setw(175) << "Добро пожаловать в систему учета пациентов медицинского центра" << endl << setw(157) << "Для начала работы вам необходимо авторизироваться" << endl;
	cout << "==============================================================================================================================================================================================" << endl;
}
/*admin1052         hfg666VBV3tcat2    0
doctor222222      1q2w3e4r5t6yBBB    1
nurse_post13      99REALnbvc3t4yu    1
office912a        Vtlbwbycrbq3333    1
uses12_loc        qwerty823746RRR    1
head_doctor123    WtynhMED22u33i4    1
office156_sys     Rehcjdfz1407200    1
system3_mob5      Lfif1111DjhjBtq    1
user_3floor       2020UEmed098123    1
post_2floorm      HqR980vtlAthcnK    1
user_cab123m      2002Rjvyfnf123M    1
 regist_man111    FGHtake769med111   1*/

