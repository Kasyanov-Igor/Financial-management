#pragma once


#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

struct Recvizit
{
	string name;
	long long int INN;
	int num_cart;
	int cod;
};

/// <summary>
/// Шаблон карты
/// </summary>
class Cart
{

	int many = 0;
	int period;
	Recvizit recvizits;
	string NameCart = "карта";


public:
	/// <summary>
	/// Созданме карты
	/// </summary>
	/// <param name="a"></ реквизиты >
	/// <param name="many1"></param>
	/// <param name="period1"></param>
	Cart(Recvizit a, int many1, int period1);
		
	void Popolnenie(int a);

	virtual void PrintCart() const
	{
		cout<< recvizits.name << " на вашем счете " << many << " руб" << endl;
	}

	void SetBalans(int a);

	int VBalans() const;

	virtual void Spisanie(int a)
	{
		many -= a;

	}

	/*void PrintCart()const
	{
		cout<<
	}*/

	virtual ~Cart() = default;

};

/// <summary>
/// Создание дебетовой карты 
/// </summary>///  
/// <param name="Реквизиты(ИМЯ, ИНН, номер карты, КОД"> </param>
/// <param name="Баланс"></param>
/// <param name="Срок"></param>
/// <param name="остаток на счете"></param>
class DebCart final :public Cart
{
	int vivodpr = 3;
	string NameCart = "Дебетовая карта";

public:

	void PrintCart() const override
	{
		cout << NameCart << " - ";
		Cart::PrintCart();
	}

	DebCart(Recvizit a, int many1, int period1, int ostatok1);
	void PrOst() const;
	void Setvivodpr(int a);

};

class CreditCart final :public Cart
{	
	string NameCart = "Кредитная карта";

	int ostatok = 25000;
public:



	CreditCart(Recvizit a, int many1, int period1);

	void Spisanie(int a) override
	{
		if (VBalans() - a < ostatok)
		{
			cout << "Error" << endl;
		}
		else
		{
			Cart::Spisanie(a);
		}

	}
	void PrintCart() const override
	{
		cout << NameCart<<" - ";
		Cart::PrintCart();

		cout << " - oстаток по вашей кредитной карте " << ostatok << endl;

	}

	void Setostatok(int a);
};

/// <summary>
/// кошелек
/// </summary>
/// <param name="Реквизиты(ИМЯ, ИНН, номер карты, КОД"> </param>
/// <param name="Баланс"></param>
/// <param name="Срок"></param>
class  Wallet final :public Cart
{
	int ostatocPr = 5;
	string NameCart = "Кошелек";

public:
	void PrintCart() const override
	{
		cout << NameCart << " - ";
		Cart::PrintCart();
	}


	Wallet(Recvizit a, int many1, int period1);

	void VivodSredstv() const;

};

