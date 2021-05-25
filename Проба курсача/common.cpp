#include "common.h"

int countRows(ifstream& fin) //подсчет количества строк в файле
{
	char row[200];
	int elements = 0;
	if (fin.is_open())
	{
		while (fin.getline(row, 200))
			elements++;
	}
	else
		cout << "Не удалось открыть файл!" << endl;
	fin.clear();
	fin.seekg(0);
	return elements;
}

int my_strlen(char* str)
{
	int length = 0;

	while (*str++)
		++length;

	return length;
}

int checkValue(int* checked_value, int min, int max) //валидация переменных типа int с ограничителями
{
	int numTrials = 0;
	while (true)
	{
		cin >> *checked_value;
		if ((*checked_value < min) || (*checked_value > max) || cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Упс, некорректный ввод. Попробуйте ещё раз\n";
			numTrials++;
			if (numTrials == 3)
			{
				cout << "Уважаемый пользователь, ВНИМАТЕЛЬНО ПРОВЕРЬТЕ КОРРЕКТНОСТЬ ВВОДА, пожалуйста :)\n";;
				numTrials = 0;
			}
		}
		else
		{
			cin.ignore(32767, '\n');
			return *checked_value;
		}
	}
}

int numOfRank(int x) //расчет количества разрядов в числе
{
	int n = 1;
	while ((x /= 10) > 0)
		n++;
	return n;
}

void listOfFiles() //вывод имен файлов в дирректории для выбора файла с данными для выгрузки
{
	DIR* folder = opendir("D/Учёба/2 семестр/Курсовая работа/Для файлов/");
	if (folder)
	{
		struct dirent* ent;
		while ((ent = readdir(folder)) != NULL)
		{
			if (ent->d_name[0] != '.')
				cout << ent->d_name << endl;
		}
	}
	else
		cout << "Ошибка просмотра директории" << endl;
}

void swap(char* first) //замена маленькой буквы на большую
{
	if (*first > 96)
		*first = *first - 32;
	else
		return;
}

void exitProgramm()
{
	int choice;
	cout << "Вы уверены, что хотите выполнить выход из программы? Нажмите 1 для выхода" << endl;
	cin >> choice;

	if (choice == 1)
	{
		cout << "Выход из программы выполнен успешно" << endl;
		exit(0);
	}
	else
		return;
}