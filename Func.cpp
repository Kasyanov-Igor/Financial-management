#include "Func.h"



void PrintDate()
{
	time_t t = time(nullptr);
	tm* now = localtime(&t);
	cout << now->tm_mday << ".";
	cout << now->tm_mon + 1 << ".";
	cout << now->tm_year + 1900;
	
}


void EntryDate(string NameFile)
{
	ofstream out(NameFile, std::ios::app);
	if (out.is_open())
	{
		out << "\t Дата отчета - ";
		time_t t = time(nullptr);
		tm* now = localtime(&t);
		out << now->tm_mday << ".";
		out << now->tm_mon + 1 << ".";
		out << now->tm_year + 1900;
		out << endl;
	}
	out.close();

}



void Otchet(deque < Expenses>& massiv_Expenses)
{
	int num = 0;

	ofstream out;

	cout << "Вывести отчет \n 1 - день \n 2 - месяц \n 3 - неделя \n 4 - топ затрат за неделю \n 5 - Вывести все свои затраты" << endl;
	cin >> num;
	switch (num)
	{
	case 1:
	{
		EntryDate("hello.txt");
		cout << "Введите день для отчета" << endl;

		string d;
		cin >> d;
		Data dataUser(d);
		for (Expenses b : massiv_Expenses)
		{
			if (b.Data() == dataUser.data)
			{
				
				cout << "Категория затрат - " << b.Cost() << "; затрата- " << b.Category() << "; сумма - " << b.Balans() <<
					"; data - " << b.Data() << endl;

				ofstream out("hello.txt", std::ios::app);
				if (out.is_open())
				{
					
					out << "Категория затрат - " << b.Cost() << "; затрата- " << b.Category() << "; сумма - " << b.Balans() <<
						"; data - " << b.Data() << endl;
				}
				out.close();
				
			}
			
		}
		cout << "File has been written" << endl << endl;
		break;
	}
	case 2:
	{
		EntryDate("hello.txt");
		cout << "Введите месяц и год для отчета (пример : 00.12.2022)" << endl;

		string d;
		cin >> d;
		Data dataUser(d);
		for (Expenses b : massiv_Expenses)
		{

			if (b.Data_M() == dataUser.M && b.Data_Y() == dataUser.Y)
			{
			

					cout << "Категория затрат - " << b.Cost() << "; затрата- " << b.Category() << "; сумма - " << b.Balans() <<
						"; data - " << b.Data() << endl;

					ofstream out("hello.txt", std::ios::app);
					if (out.is_open())
					{
						out << "Категория затрат - " << b.Cost() << "; затрата- " << b.Category() << "; сумма - " << b.Balans() <<
							"; data - " << b.Data() << endl;
					}
				}
				out.close();

			
			
		}
		cout << "File has been written" << endl << endl;
		break;
	}
	case 3:
	{
		EntryDate("hello.txt");

		cout << "Введите день для отчета на неделю" << endl;
		string d;
		cin >> d;
		Data dataUser(d);

		for (Expenses b : massiv_Expenses)
		{

			tm time_info = {};

			time_info.tm_year = dataUser.Y - 1900;  // Год с 1900
			time_info.tm_mon = dataUser.M - 1;     // Месяц от 0 до 11
			time_info.tm_mday = dataUser.D;
			for (int i = 0; i < 7; i++)
			{
				time_t next_day = mktime(&time_info) + i * 24 * 60 * 60;
				tm* next_date = localtime(&next_day);

				if (b.Data_D() == next_date->tm_mday && b.Data_M() == next_date->tm_mon + 1 && b.Data_Y() == next_date->tm_year + 1900)
				{
					
					cout << "Категория затрат - " << b.Cost() << "; затрата- " << b.Category() << "; сумма - " << b.Balans() <<
						"; data - " << b.Data() << endl;

					ofstream out("hello.txt", std::ios::app);
					if (out.is_open())
					{
						out << "Категория затрат - " << b.Cost() << "; затрата- " << b.Category() << "; сумма - " << b.Balans() <<
							"; data - " << b.Data() << endl;
					}
					out.close();
				}
				
			}
		
		}
		cout << "File has been written" << endl << endl;
	}
	break;


	case 4:
	{
			map <int, pair<string, string>> Top3_Expenses;

			for (Expenses n : massiv_Expenses)
			{
				Top3_Expenses.insert( {n.Balans(),{n.Category(),n.Cost()}});
			}

			for (int i = 0; i < Top3_Expenses.size(); ++i)
			{
				
				for (pair<int, pair<string, string>> a : Top3_Expenses)
				{
					if (i == Top3_Expenses.size() - 3)
					{
					  cout << a.first << " " << a.second.first << " " << a.second.second << endl;
				    }
				}

			}

		
	}
	case 5:
	{ 
		EntryDate("hello.txt");

		for (Expenses b : massiv_Expenses)
		{

			cout << "Категория затрат - " << b.Cost() << "; затрата- " << b.Category() << "; сумма - " << b.Balans() <<
				"; data - " << b.Data() << endl;

			ofstream out("hello.txt", std::ios::app);
			if (out.is_open())
			{

				out << "Категория затрат - " << b.Cost() << "; затрата- " << b.Category() << "; сумма - " << b.Balans() <<
					"; data - " << b.Data() << endl;
			}
			out.close();
			
		}
		cout << "File has been written" << endl<<endl;
		break;
	}
	}

}



//template <typename Type>
//void Spisanie(Type t, deque < Expenses>& massiv_Expenses)
//{
//	int sum1 = 0;
//	string dataUser;
//	string zatrat1;
//	string cost;
//	cout << "цена" << endl;
//	cin >> sum1;
//	cout << "дата" << endl;
//	cin >> dataUser;
//
//	cout << "Категория затрат" << endl;
//	cin >> cost;
//
//	cout << "затратa" << endl;
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