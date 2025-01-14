#include <iostream>
using namespace std;

void PrintArray(int*mas);
void InitArray(int * mas);
int** AddRowEZArray(int**mas, int & rows, int size);

void Print2Array(int**mas, int rows);

void main()
{
	int rows = 0;
	int ** mas = new int*[rows];
	for (int i = 0; i < 6; i++)
	{
		mas = AddRowEZArray(mas, rows, rand()%10+1);
	}
	Print2Array(mas, rows);
	system("pause");

}

int** AddRowEZArray(int**mas, int & rows, int size)
{
	int ** temp = new int*[rows+1];
	for (size_t i = 0; i < rows; i++)
	{
		temp[i] = mas[i];
	}
	temp[rows] = new int[size+1];
	temp[rows][0] = size;
	InitArray(temp[rows]);
	rows++;
	delete[]mas;
	return temp;
}


void Print2Array(int**mas, int rows)
{
	for (size_t i = 0; i < rows; i++)
	{
		PrintArray(mas[i]);
	}
	cout << endl;
}

void PrintArray(int*mas)
{
	for (int i =1; i <= mas[0]; i++)
	{
		cout << mas[i]<< "\t";
	}
	cout << endl;
}

void InitArray(int * mas)
{
	for (size_t i = 1; i <= mas[0]; i++)
	{
		mas[i] = rand() % 10;
	}
}