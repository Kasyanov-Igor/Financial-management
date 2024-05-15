#include "Expens.h"



	Data::Data(string a)
	{
		data = a;
		int DD = atoi(a.substr(0, 2).c_str());
		int MM = atoi((a.substr(3, 2)).c_str());
		int YY = atoi((a.substr(6, 4)).c_str());
		D = DD;
		M = MM;
		Y = YY;
	}




	Expenses::Expenses(int sum1, string data2, string category1, string cost1)
		:dataStruct(data2)
	{
		sum = sum1;
		category = category1;
		cost = cost1;


	}
	string Expenses::Category()
	{
		return category;
	}
	string Expenses::Data()
	{
		return dataStruct.data;
	}
	int Expenses::Data_D()
	{
		return dataStruct.D;
	}
	int Expenses::Data_M()
	{
		return dataStruct.M;
	}
	int Expenses::Data_Y()
	{
		return dataStruct.Y;
	}

	int Expenses::Balans()
	{
		return sum;
	}

	string Expenses::Cost()
	{
		return cost;
	}
	






