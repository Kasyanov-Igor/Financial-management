

#include "Cards.h"
#include "Func.h"

#include <map>

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


int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("mode con cols=62 lines=35");
	system("color 70");

	deque < Expenses> massiv_Expenses;


	CreditCart Sber({ "Igor",86465445,1505421,111 }, 50000, 2025);
	Wallet Kiwi({ "Igor",86484489546,1505421,010 }, 1500, 2025);
	DebCart Alfa({ "Igor",785487154845,1505421,010 }, 100500, 2025, 25000);


	while (1 != 0)
	{
		

		cout << "\t ------- Система управления финансами -----"; PrintDate(); cout << "\n \t--------------------------------------------  " << endl;
	

		cout << "\n\tВаши карты:\n\n";
		Sber.PrintCart(); cout << endl;
		Kiwi.PrintCart(); cout << endl;
		Alfa.PrintCart(); cout << endl;
		
		cout << "\n 1 - внести затрату \n 2 - вывод отчета \n 3 - топ 3 затрат" << endl;
		int num;
		cin >> num;

		switch (num)
		{


		case 1:
		{
			system("cls");
			int n;
			cout << "С какой карты совершаете покупку \n 1 - Кредитная карта \n 2 - Дебетовая \n 3 - Кошелек \n 4 - Пример " << endl;
			cin >> n;
			switch (n)
			{
			case 1:
			{
			Spisanie(Sber,massiv_Expenses);
				continue;
			}
			case 2:
			{
				Spisanie(Alfa, massiv_Expenses);
				continue;
			}
			case 3:
			{
				Spisanie(Kiwi, massiv_Expenses);
				continue;
			}
			}
		case 4:
		{
			Spisanie(Sber, 500, "11.02.2024", "еда", "продукты", massiv_Expenses);
			Spisanie(Sber, 1500, "15.02.2024", "машина", "бензин", massiv_Expenses);
			Spisanie(Alfa, 20000, "20.02.2024", "квартира", "оплата жилья", massiv_Expenses);
			Spisanie(Kiwi, 100, "01.03.2024", "еда", "кофе", massiv_Expenses);
			Spisanie(Kiwi, 800, "16.03.2024", "развлечение", "кино", massiv_Expenses);
			Spisanie(Sber, 500, "28.02.2024", "еда", "пицца", massiv_Expenses);
			Spisanie(Sber, 1500, "02.03.2024", "машина", "шаровая", massiv_Expenses);
			//break;
			continue;
		}

		break;
		}
		case 2:
		{
			system("cls");
			Otchet(massiv_Expenses);
			break;
		}

		/*case 3:
		{
			map <int, pair<string, string>> top3category;



			for (Expenses& b : massiv_Expenses)
			{
				pair <int, pair<string, string>> V = { b.Balans(),{b.Cost(),b.Data()} };

				top3category = { V };
			}

			for (const pair<int, pair<string, string>> V : top3category)
			{
				cout << V.first << " " << V.second.first << " " << V.second.second << endl;
			}

			break;
		}*/

		}

		
	}
}
