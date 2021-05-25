#include "common.h"

int countRows(ifstream& fin) //������� ���������� ����� � �����
{
	char row[200];
	int elements = 0;
	if (fin.is_open())
	{
		while (fin.getline(row, 200))
			elements++;
	}
	else
		cout << "�� ������� ������� ����!" << endl;
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

int checkValue(int* checked_value, int min, int max) //��������� ���������� ���� int � ��������������
{
	int numTrials = 0;
	while (true)
	{
		cin >> *checked_value;
		if ((*checked_value < min) || (*checked_value > max) || cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "���, ������������ ����. ���������� ��� ���\n";
			numTrials++;
			if (numTrials == 3)
			{
				cout << "��������� ������������, ����������� ��������� ������������ �����, ���������� :)\n";;
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

int numOfRank(int x) //������ ���������� �������� � �����
{
	int n = 1;
	while ((x /= 10) > 0)
		n++;
	return n;
}

void listOfFiles() //����� ���� ������ � ����������� ��� ������ ����� � ������� ��� ��������
{
	DIR* folder = opendir("D/�����/2 �������/�������� ������/��� ������/");
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
		cout << "������ ��������� ����������" << endl;
}

void swap(char* first) //������ ��������� ����� �� �������
{
	if (*first > 96)
		*first = *first - 32;
	else
		return;
}

void exitProgramm()
{
	int choice;
	cout << "�� �������, ��� ������ ��������� ����� �� ���������? ������� 1 ��� ������" << endl;
	cin >> choice;

	if (choice == 1)
	{
		cout << "����� �� ��������� �������� �������" << endl;
		exit(0);
	}
	else
		return;
}