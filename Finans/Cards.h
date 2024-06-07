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
/// ������ �����
/// </summary>
class Cart
{

	int many = 0;
	int period;
	Recvizit recvizits;
	string NameCart = "�����";


public:
	/// <summary>
	/// �������� �����
	/// </summary>
	/// <param name="a"></ ��������� >
	/// <param name="many1"></param>
	/// <param name="period1"></param>
	Cart(Recvizit a, int many1, int period1);
		
	void Popolnenie(int a);

	virtual void PrintCart() const
	{
		cout<< recvizits.name << " �� ����� ����� " << many << " ���" << endl;
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
/// �������� ��������� ����� 
/// </summary>///  
/// <param name="���������(���, ���, ����� �����, ���"> </param>
/// <param name="������"></param>
/// <param name="����"></param>
/// <param name="������� �� �����"></param>
class DebCart final :public Cart
{
	int vivodpr = 3;
	string NameCart = "��������� �����";

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
	string NameCart = "��������� �����";

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

		cout << " - o������ �� ����� ��������� ����� " << ostatok << endl;

	}

	void Setostatok(int a);
};

/// <summary>
/// �������
/// </summary>
/// <param name="���������(���, ���, ����� �����, ���"> </param>
/// <param name="������"></param>
/// <param name="����"></param>
class  Wallet final :public Cart
{
	int ostatocPr = 5;
	string NameCart = "�������";

public:
	void PrintCart() const override
	{
		cout << NameCart << " - ";
		Cart::PrintCart();
	}


	Wallet(Recvizit a, int many1, int period1);

	void VivodSredstv() const;

};

