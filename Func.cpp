#include "Func.h"


void Otchet(deque < Expenses>& massiv_Expenses)
{
	int num = 0;

	cout << "������� ����� \n 1 - ���� \n 2 - ����� \n 3 - ������ \n 4 - ��� ������ �� ������ \n 5 - ������� ��� ���� �������" << endl;
	cin >> num;
	switch (num)
	{
	case 1:
	{
		cout << "������� ���� ��� ������" << endl;

		string d;
		cin >> d;
		Data dataUser(d);
		for (Expenses b : massiv_Expenses)
		{

			if (b.Data() == dataUser.data)
			{
				cout << "������� ��  " << dataUser.data << endl;
				cout << "��������� ������ - " << b.Cost() << "; �������- " << b.Category() << "; ����� - " << b.Balans() <<
					"; data - " << b.Data() << endl;
			}

		}

		break;
	}
	case 2:
	{
		cout << "������� ����� � ��� ��� ������ (������ : 00.12.2022)" << endl;

		string d;
		cin >> d;
		Data dataUser(d);
		for (Expenses b : massiv_Expenses)
		{

			if (b.Data_M() == dataUser.M && b.Data_Y() == dataUser.Y)
			{
				cout << "��������� ������ - " << b.Cost() << "; �������- " << b.Category() << "; ����� - " << b.Balans() <<
					"; data - " << b.Data() << endl;
			}

		}
		break;
	}
	case 3:
	{



		cout << "������� ���� ��� ������ �� ������" << endl;
		string d;
		cin >> d;
		Data dataUser(d);

		for (Expenses b : massiv_Expenses)
		{

			tm time_info = {};

			time_info.tm_year = dataUser.Y - 1900;  // ��� � 1900
			time_info.tm_mon = dataUser.M - 1;     // ����� �� 0 �� 11
			time_info.tm_mday = dataUser.D;
			for (int i = 0; i < 7; i++)
			{
				time_t next_day = mktime(&time_info) + i * 24 * 60 * 60;
				tm* next_date = localtime(&next_day);

				if (b.Data_D() == next_date->tm_mday && b.Data_M() == next_date->tm_mon + 1 && b.Data_Y() == next_date->tm_year + 1900)
				{

					cout << "��������� ������ - " << b.Cost() << "; �������- " << b.Category() << "; ����� - " << b.Balans() <<
						"; data - " << b.Data() << endl;
				}
			}
		}
	}
	break;


	/*case 4:
	{
		cout << "������� ���� ��� ������ ��� 3 ������" << endl;
		string d;
		cin >> d;
		Data dataUser(d);
		for (Expenses b : a)
		{

			for (int i = 0; i < 7; ++i)
			{
				if (b.Datavivod_D() == dataUser.D + i && b.Datavivod_M() == dataUser.M && b.Datavivod_Y() == dataUser.Y)
				{
					for (pair <int, Expenses*> ell : TOP)
					{
						for (int i = 0; i < 3; ++i)
						{
							cout << ell.first << ell.second->Zatratvivod() << endl;
						}
					}

				}

			}

		}
		break;
	}*/
	case 5:
	{

		for (Expenses b : massiv_Expenses)
		{


			cout << "��������� ������ - " << b.Cost() << "; �������- " << b.Category() << "; ����� - " << b.Balans() <<
				"; data - " << b.Data() << endl;




		}
		break;
	}
	}

}

void PrintDate()
{
	time_t t = time(nullptr);
	tm* now = localtime(&t);
	cout << now->tm_mday << ".";
	cout << now->tm_mon + 1 << ".";
	cout << now->tm_year + 1900;
}

//template <typename Type>
//void Spisanie(Type t, deque < Expenses>& massiv_Expenses)
//{
//	int sum1 = 0;
//	string dataUser;
//	string zatrat1;
//	string cost;
//	cout << "����" << endl;
//	cin >> sum1;
//	cout << "����" << endl;
//	cin >> dataUser;
//
//	cout << "��������� ������" << endl;
//	cin >> cost;
//
//	cout << "������a" << endl;
//	cin >> zatrat1;
//
//	Expenses exz{ sum1, dataUser, zatrat1, cost };
//	massiv_Expenses.push_back(exz);
//	t.Spisanie(sum1);
//
//
//}
//
//template <typename Type>
//void Spisanie(Type t, int sum1, string dataUser, string zatrat1, string cost, deque < Expenses>& massiv_Expenses)
//{
//
//	Expenses exz{ sum1, dataUser, zatrat1,cost };
//	massiv_Expenses.push_back(exz);
//	t.Spisanie(sum1);
//
//}