#include "Cards.h"

/// <summary>
/// ������ �����
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
/// �������� ��������� ����� 
/// </summary>///  
/// <param name="���������(���, ���, ����� �����, ���"> </param>
/// <param name="������"></param>
/// <param name="����"></param>
/// <param name="������� �� �����"></param>

	DebCart ::DebCart(Recvizit a, int many1, int period1, int ostatok1)
		:Cart(a, many1, period1)
	{
	}
	void DebCart::PrOst() const
	{
		cout << "������� �� ������� " << vivodpr << endl;
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
/// �������
/// </summary>
/// <param name="���������(���, ���, ����� �����, ���"> </param>
/// <param name="������"></param>
/// <param name="����"></param>



	Wallet::Wallet(Recvizit a, int many1, int period1)
		:Cart(a, many1, period1)
	{
	}
	void Wallet::VivodSredstv() const
	{
		cout << "��� ������ ������� ������� " << ostatocPr << endl;
	}

