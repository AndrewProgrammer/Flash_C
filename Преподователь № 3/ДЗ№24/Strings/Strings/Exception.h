#pragma once
#include "String.h"
#include <string>
#include <iostream>
using namespace std;
class Exception
{
public:
	string ErrorOutOfRange = " Вы вышли за диапозон допустимых значений!";
	string ErrorWithArgument = " Был введен неверный аргумент!";
	string ErrorNullptr = "Строка которую вы ввели имеет адрес нулевого указателя, ошибка!";
	string ErrorArifmetic = "Неправильный правы параметр для оператора над котором производится действие!";
};