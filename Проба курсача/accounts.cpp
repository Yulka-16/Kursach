#include "accounts.h"
#include "common.h"

size_t hash_func(string str)
{
	hash<string> hash_fn;
	size_t str_hash = hash_fn(str);
	return str_hash;
}

void openFile(vector <Autorization>& autorize, int* nUsers) //на случай, если в файле нет информации
{
	if (*nUsers == 0)
	{
		cout << "Информации в файле не обнаружено" << endl;
		ifCreateFile(*nUsers, autorize);
		*nUsers = 1;
	}
}

bool isAccountValid(vector <Autorization>& autorize, int* role, int* user_num) //проверка подлинности аккаунта
{

	if (isLoginFound(autorize, &*role, &*user_num) != isPasswordValid(autorize))
	{
		identifyMistake();
		isAccountValid(autorize, &*role, &*user_num);
		return true;
	}
	else
		return true;
}

int isPasswordValid(vector <Autorization>& autorize) //ввод и проверка подлинности пароля
{
	string localPass;
	int nPassword = -1;
	cout << "Введите пароль :";
	cin >> localPass;
	cout << endl;

	for (int i = 0; i < autorize.size(); i++)
	{
		if (autorize.at(i).password == hash_func(localPass))
			nPassword = i;
	}
	return nPassword;
}


void identifyMistake()
{
	int oneMore;
	cout << "Ошибка при вводе логина или пароля!Для повторного ввода нажмите 1" << endl;
	cin >> oneMore;
	cout << endl;
	if (oneMore == 1)
		return;
	else
		exit(0);
}

int isLoginFound(vector <Autorization>& autorize, int* role, int* user_num) //проверка подлинности логина
{
	int nLogin = -2;
	string local_login;
	cout << "Введите логин :";
	cin >> local_login;
	cout << endl;

	for (int i = 0; i < autorize.size(); i++)
	{
		if (autorize.at(i).login == local_login)
		{
			nLogin = i;
			*user_num = nLogin;

			if (autorize.at(i).role == 0)
				*role = 0;
		}
	}
	*user_num = nLogin;
	return nLogin;
}

void ifCreateFile(int nUsers, vector <Autorization>& autorize) //создание файла при его отсутствии
{
	cout << "Желаете создать файл? Нажмите 1 для создания" << endl;
	int ifCreate;
	cin >> ifCreate;

	if (ifCreate == 1)
		createFile(nUsers, autorize);
	else
		exit(0);
}

void createFile(int nUsers, vector <Autorization>& autorize)
{
	ofstream fout(Logins, ios_base::out);
	if (fout.is_open())
	{
		cout << "Файл Logins.txt для хранения логинов и паролей успешно создан! " << endl;
		addAccount(autorize);
	}
	fout.close();
}

Autorization addAccount(vector <Autorization>& autorize)
{

	cout << "==============================================================================================================================================================================================" << endl;
	string newPassword;
	Autorization auto_num;
	cout << "Введите логин для новой учетной записи:";
	auto_num.login = checkNewLogin(autorize);
	cout << "Введите пароль для новой учетной записи\n!!!Надёжный пароль должен содержать!!! :\n1.Заглавную букву\n2.Строчную букву\n3.Цифру\n4.Минимум 15 символов\n";
	newPassword = checkNewPassword();

	auto_num.password = hash_func(newPassword);
	if (autorize.size() == 0)
	{
		auto_num.role = ADMIN_SIGN;
		cout << "Произведена запись аккаунта администрaтора" << endl;
		foutUsers(autorize);
	}
	else
	{
		cout << "Введите '0' для присвоения аккаунту прав администратора и '1' для присвоения прав пользователя" << endl;
		checkValue(&auto_num.role, 0, 1);

		if (auto_num.role == ADMIN_SIGN)
			cout << "Произведена запись аккаунта администрaтора" << endl;
		else
			cout << "Произведена запись аккаунта пользователя" << endl;

		foutUsers(autorize);
	}
	return auto_num;
}

string checkNewPassword() //проверка безопасности пароля
{
	string localPass;
	bool isLowercase = false, isCapital = false, isNumber = false, isValid = false;

	do
	{
		cin >> localPass;
		char* pass = &localPass[0];
		int passLength = my_strlen(pass), symbolNo = 0;

		for (int i = 0; i < passLength; i++)
		{
			if ((pass[i] > 64) && (pass[i] < 91))
			{
				isCapital = true;
				symbolNo++;
			}
			if ((pass[i] > 96) && (pass[i] < 123))
			{
				isLowercase = true;
				symbolNo++;
			}
			if ((pass[i] > 47) && (pass[i] < 58))
			{
				isNumber = true;
				symbolNo++;
			}
		}
		if ((symbolNo == passLength) && (isCapital == true) && (isLowercase == true) && (isNumber == true) && (passLength >= 15))
			isValid = true;
		else
			cout << "Убедитесь, что введенный пароль содержит как минимум одну заглавную и маленькую буквы и цифру и состоит из как минимум 15-ти символов" << endl;
	} while (isValid == false);
	return localPass;
}

string checkNewLogin(vector <Autorization>& autorize) //проверка уникальности логина
{
	string localLogin;
	bool isFound = false;
	cin >> localLogin;

	for (int i = 0; i < autorize.size(); i++)
	{
		if (localLogin == autorize.at(i).login)
		{
			cout << "Логин с таким именем уже существует! Пожалуйста, измените его и повторите ввод" << endl;
			isFound = true;
		}
	}
	if (isFound == false)
	{
		cout << "Логин прошел проверку на уникальность" << endl;
		return localLogin;
	}
	else
		return checkNewLogin(autorize);
}


void showAccounts(vector <Autorization>& autorize)
{
	cout << "---------------------------------------------------------------" << endl;
	cout << "   Логин                            Хэш Пароля           Роль" << endl;
	cout << "---------------------------------------------------------------" << endl;

	for (int i = 0; i < autorize.size(); i++)
	{
		char* pass = &autorize.at(i).login[0];
		cout << "| " << i + 1 << ". " << autorize.at(i).login << setw(45 - my_strlen(pass) - numOfRank(i)) << autorize.at(i).password << setw(10) << autorize.at(i).role << " |" << endl;
		cout << "-------------------------------------------------------------" << endl;
	}
	cout << endl;
}

void foutUsers(vector <Autorization>& autorize) //запись аккаунтов в файл(выполняется при каждом изменении)
{
	ofstream fout(Logins, ios_base::out);
	if (fout.is_open())
	{
		for (int i = 0; i < autorize.size(); i++)
			fout << autorize.at(i).login << "\t\t" << autorize.at(i).password << "\t\t" << autorize.at(i).role << endl;
	}
	fout.close();
}

void correctAccounts(vector <Autorization>& autorize)
{
	cout << "==============================================================================================================================================================================================" << endl;
	int num_to_correct = 0, choice, nAccounts = (int)autorize.size();
	cout << "Введите номер учетной записи, которую вы хотите откорректировать:";
	checkValue(&num_to_correct, 2, nAccounts);

	cout << "Вы уверены,что хотите откорректировать учетную запись № " << num_to_correct << "?\n1.Да\n2.Нет" << endl;
	num_to_correct--;

	cin >> choice;
	if (choice == 1)
	{
		autorize.erase(autorize.begin() + num_to_correct);
		autorize.insert(autorize.begin() + num_to_correct, addAccount(autorize));
		num_to_correct++;
		cout << "Данные пациента № " << num_to_correct << " откорректированы" << endl;
	}
	else
		cout << "Данные остались в неизменном состоянии" << endl;
}

void deleteAccounts(vector <Autorization>& autorize, int* user_num)
{
	cout << "==============================================================================================================================================================================================" << endl;
	cout << "Выберите, что именно вы хотите удалить:\n1.Одну учетную запись\n2.Информацию о всех учетных записях" << endl;
	int choice;
	checkValue(&choice, 1, 2);
	switch (choice)
	{
	case 1:
		deleteOneAccount(autorize, &*user_num);
		break;

	case 2:
		deleteAllAccounts(autorize);
		break;
	}
}

void deleteAllAccounts(vector <Autorization>& autorize)
{
	int choice;
	cout << "Вы уверены,что хотите удалить информацию о всех логинах и паролях(кроме аккаунта главного администратора))?\n1.Нет\n2.Да\n" << endl;
	checkValue(&choice, 1, 2);
	switch (choice)
	{
	case 1:
		cout << "Данные остались в неизменном состоянии" << endl;
		break;

	case 2:
		sureDelete(autorize);
		exit(0);
		break;
	}
}

void sureDelete(vector <Autorization>& autorize)
{
	ofstream fout(Logins, ios::out);
	if (fout.is_open())
	{
		for (int i = 1; i < autorize.size(); i++)
			autorize.erase(autorize.begin() + i);
		cout << "Информация о логинах и паролях успешно удалена из файла(кроме аккаунта главного администратора)" << endl;
	}
	fout.close();
}

void deleteOneAccount(vector <Autorization>& autorize, int* user_num)
{
	int num_to_delete = *user_num, rez = 0, nAccounts = (int)autorize.size();
	do
	{
		cout << "Введите номер учетной записи ,которую вы хотите удалить (Вы не сможете удалить свою учетную запись)" << endl;
		checkValue(&num_to_delete, 1, nAccounts);
	} while (num_to_delete == *user_num);
	num_to_delete--;

	cout << "Вы уверены , что хотите удалить учетную запись?\n1.Да\n2.Нет" << endl;
	cin >> rez;
	if (rez == 1)
	{
		autorize.erase(autorize.begin() + num_to_delete);
		num_to_delete++;
		cout << "Аккаунт № " << num_to_delete << " успешно удален" << endl;
	}
	else
		cout << "Данные остались в неизменном состоянии" << endl;
}