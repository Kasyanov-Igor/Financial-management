#pragma once
#pragma warning(disable : 4996)
#include "Expens.h"



using namespace std;


void Otchet(deque < Expenses>& massiv_Expenses);

void PrintDate();

/// <summary>
/// Списание средств
/// </summary>
/// <typeparam name="Type - шаблон нашего класса"></typeparam>
/// <param name="t - класс"></param>
//template <typename Type>
//void Spisanie(Type t, deque < Expenses>& massiv_Expenses);

/// <summary>
/// Списание средств
/// </summary>
/// <typeparam name="Type - шаблон класса"></typeparam>
/// <param name="t - класс"></param>
/// <param name="sum1 - сумма"></param>
/// <param name="dataUser - дата"></param>
/// <param name="zatrat1 - категория затрат"></param>
//template <typename Type>
//void Spisanie(Type t, int sum1, string dataUser, string zatrat1, string cost, deque < Expenses>& massiv_Expenses);
