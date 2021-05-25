#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

const int ADMIN_SIGN = 0;

struct Autorization   //Структура данных пользователя;
{
	string login;     //логин пользователя;
	string password;  // пароль пользователя;
	int role;         //роль пользователя (0 – администратор, 1 – пользователь);
};


size_t hash_func(string str);
void openFile(vector <Autorization>& autorize, int* nUsers);
bool isAccountValid(vector <Autorization>& autorize, int* role, int* user_num);
int isPasswordValid(vector <Autorization>& autorize);
void identifyMistake();
int isLoginFound(vector <Autorization>& autorize, int* role, int* user_num);
void ifCreateFile(int nUsers, vector <Autorization>& autorize);
void createFile(int nUsers, vector <Autorization>& autorize);
Autorization addAccount(vector <Autorization>& autorize);
string checkNewPassword();
string checkNewLogin(vector <Autorization>& autorize);
void showAccounts(vector <Autorization>& autorize);
void foutUsers(vector <Autorization>& autorize);
void correctAccounts(vector <Autorization>& autorize);
void deleteAccounts(vector <Autorization>& autorize, int* user_num);
void deleteAllAccounts(vector <Autorization>& autorize);
void sureDelete(vector <Autorization>& autorize);
void deleteOneAccount(vector <Autorization>& autorize, int* user_num);

