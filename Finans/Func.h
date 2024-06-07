#pragma once
#pragma warning(disable : 4996)
#include "Expens.h"
#include "map"
#include "vector"


#include <fstream>


using namespace std;

void PrintDate();

void Otchet(deque < Expenses>& massiv_Expenses);

void Dayreport(deque < Expenses>& massiv_Expenses, Data& dataUser);

void Monthreport(deque < Expenses>& massiv_Expenses, Data& dataUser);

void Weekreport(deque < Expenses>& massiv_Expenses, Data& dataUser);
