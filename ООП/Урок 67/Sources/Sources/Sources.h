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
			of << 3 << 4.18 << "Hello";//ofstream ��������� ��� ��� ��� �� ������������ ����� ��� ������ 
			//Date d;��� ���� ����� ��� �������� ����� ����������� operator << � ������ Date
			//of << d;
			of.write((char*)&a, sizeof(int));//��������� ��������� �� ������ ����,� ������( � ������ ������ 4) ��� ��� ��� ������ int
			of.seekp(10, ios::beg);//Get ��������� ��������� �� ������ � ����� �� 10 ������ �� ������(����� ���� ios::cur,ios::end)
			of.tellp();// ��������� ������� ������� ���������� ������ ������
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
			f >> a;// ����������� ������������ ������ a � ����� �����
			f.eof();// - ���������� true ���� ����� ���������
			f.read(reinterpret_cast<char*>(&a), sizeof(int));//��������� ��������� �� ������ ����,� ������( � ������ ������ 4)��� ��� ��� ������ int
			f.seekg(10, ios::cur);//Get ��������� ��������� �� ������ � ����� �� 10 ������ �� ������(����� ���� ios::cur,ios::end)
			f.tellg();// ��������� ������� ������� ���������� ������ ������
			f.gcount();//���������� ���������� ���� ��������� ������� input ���������

			f.close();
		}
	}
};