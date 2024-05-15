#include "Cards.h"

/// <summary>
/// Шаблон карты
/// </summary>

	Cart::Cart(Recvizit a, int many1, int period1)
		:recvizits(a)
		, many(many1)
		, period(period1)
	{
	}
	void Cart::Popolnenie(int a)
	{
		many += a;
	}

	

	void Cart::SetBalans(int a)
	{
		many = a;
	}
	int Cart::VBalans() const
	{

		return Cart::many;
	}

	
	



/// <summary>
/// Создание дебетовой карты 
/// </summary>///  
/// <param name="Реквизиты(ИМЯ, ИНН, номер карты, КОД"> </param>
/// <param name="Баланс"></param>
/// <param name="Срок"></param>
/// <param name="остаток на счете"></param>

	DebCart ::DebCart(Recvizit a, int many1, int period1, int ostatok1)
		:Cart(a, many1, period1)
	{
	}
	void DebCart::PrOst() const
	{
		cout << "Процент на остаток " << vivodpr << endl;
	}
	void DebCart::Setvivodpr(int a)
	{
		vivodpr = a;
	}




	CreditCart::CreditCart(Recvizit a, int many1, int period1)
		:Cart(a, many1, period1)

	{
	}
	

	void CreditCart::Setostatok(int a)
	{
		ostatok = a;
	}

/// <summary>
/// кошелек
/// </summary>
/// <param name="Реквизиты(ИМЯ, ИНН, номер карты, КОД"> </param>
/// <param name="Баланс"></param>
/// <param name="Срок"></param>



	Wallet::Wallet(Recvizit a, int many1, int period1)
		:Cart(a, many1, period1)
	{
	}
	void Wallet::VivodSredstv() const
	{
		cout << "При выводе средств процент " << ostatocPr << endl;
	}

