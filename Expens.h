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

