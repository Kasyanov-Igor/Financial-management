#pragma once

#include <iostream>
#include <string>
#include <deque>
#include <Windows.h>


using namespace std;



struct Data
{
	int D = 0, M = 0, Y = 0;
	string data;
	Data(string a);

};



/// <summary>
/// Класс затрат
/// </summary>
/// <param name="sum1 - сумма списания "></param>
/// <param name="data2 - дата"></param>
/// <param name="category1 - категория затрат"></param>
/// <param name="cost1 - затратa"></param>
class Expenses
{
	int sum = 0;
	Data dataStruct;
	string cost;
	string category;

public:

	Expenses(int sum1, string data2, string category1, string cost1);
	
	string Category();
	string Data();
	int Data_D();
	int Data_M();
	int Data_Y();

	int Balans();

	string Cost();
	~Expenses() = default;


};

/// <summary>
/// Списание средств
/// </summary>
/// <typeparam name="Type - шаблон нашего класса"></typeparam>
/// <param name="t - класс"></param>
template <typename Type>
void Spisanie(Type t, deque < Expenses>& massiv_Expenses)
{
	int sum1 = 0;
	string dataUser;
	string zatrat1;
	string cost;
	cout << "цена" << endl;
	cin >> sum1;
	cout << "дата" << endl;
	cin >> dataUser;

	cout << "Категория затрат" << endl;
	cin >> cost;

	cout << "затратa" << endl;
	cin >> zatrat1;

	Expenses exz{ sum1, dataUser, zatrat1, cost };
	massiv_Expenses.push_back(exz);
	t.Spisanie(sum1);


}

/// <summary>
/// Списание средств
/// </summary>
/// <typeparam name="Type - шаблон класса"></typeparam>
/// <param name="t - класс"></param>
/// <param name="sum1 - сумма"></param>
/// <param name="dataUser - дата"></param>
/// <param name="zatrat1 - категория затрат"></param>
template <typename Type>
void Spisanie(Type& t, int sum1, string dataUser, string zatrat1, string cost, deque < Expenses>& massiv_Expenses)
{

	Expenses exz{ sum1, dataUser, zatrat1,cost };
	massiv_Expenses.push_back(exz);
	t.Spisanie(sum1);

}