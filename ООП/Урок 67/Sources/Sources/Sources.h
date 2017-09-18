#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Sources
{
private:
public:
	void Whrite()
	{
		ofstream of("E:\\Test.txt");
		if (of.is_open())
		{
			int a;
			of << 3 << 4.18 << "Hello";//ofstream принимает все так как он конвертирует сразу все данные 
			//Date d;Для того чтобы это работало нужно перегрузить operator << в классе Date
			//of << d;
			of.write((char*)&a, sizeof(int));//Принимает указатель на массив байт,и размер( в данном случаи 4) так как тип данных int
			of.seekp(10, ios::beg);//Get указатель смещается на начало а потом на 10 байтов от начало(также есть ios::cur,ios::end)
			of.tellp();// Возращают текущие позиции указателей внутри потока
			//of.pcount()

			of.close();
		}
	}
	void Read()
	{
		ifstream f("E:\\Test.txt");
		if (f.is_open())
		{
			int a;
			f >> a;// Запрашивает пользователя ввести a в поток ввода
			f.eof();// - возвращает true если конец достигнут
			f.read(reinterpret_cast<char*>(&a), sizeof(int));//Принимает указатель на массив байт,и размер( в данном случаи 4)так как тип данных int
			f.seekg(10, ios::cur);//Get указатель смещается на начало а потом на 10 байтов от начало(также есть ios::cur,ios::end)
			f.tellg();// Возращают текущие позиции указателей внутри потока
			f.gcount();//Возвращает количество байт считанных прошлой input операцией

			f.close();
		}
	}
};