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
/// ����� ������
/// </summary>
/// <param name="sum1 - ����� �������� "></param>
/// <param name="data2 - ����"></param>
/// <param name="category1 - ��������� ������"></param>
/// <param name="cost1 - ������a"></param>
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
/// �������� �������
/// </summary>
/// <typeparam name="Type - ������ ������ ������"></typeparam>
/// <param name="t - �����"></param>
template <typename Type>
void Spisanie(Type t, deque < Expenses>& massiv_Expenses)
{
	int sum1 = 0;
	string dataUser;
	string zatrat1;
	string cost;
	cout << "����" << endl;
	cin >> sum1;
	cout << "����" << endl;
	cin >> dataUser;

	cout << "��������� ������" << endl;
	cin >> cost;

	cout << "������a" << endl;
	cin >> zatrat1;

	Expenses exz{ sum1, dataUser, zatrat1, cost };
	massiv_Expenses.push_back(exz);
	t.Spisanie(sum1);


}

/// <summary>
/// �������� �������
/// </summary>
/// <typeparam name="Type - ������ ������"></typeparam>
/// <param name="t - �����"></param>
/// <param name="sum1 - �����"></param>
/// <param name="dataUser - ����"></param>
/// <param name="zatrat1 - ��������� ������"></param>
template <typename Type>
void Spisanie(Type& t, int sum1, string dataUser, string zatrat1, string cost, deque < Expenses>& massiv_Expenses)
{

	Expenses exz{ sum1, dataUser, zatrat1,cost };
	massiv_Expenses.push_back(exz);
	t.Spisanie(sum1);

}