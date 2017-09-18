#include <iostream>
#include <time.h>

using namespace std;

int ** Create2Array(int rows, int cols);
void Init2Array(int**mas, int rows, int cols);
void Print2Array(int **mas, int rows, int cols);

void main()
{
	int r, c;
	cout << "Enter rows" << endl;
	cin >> r;
	cout << "Enter cols" << endl;
	cin >> c;
	int** mas = Create2Array(r, c);
	Init2Array(mas, r, c);
	Print2Array(mas, r, c);
	system("pause");
}
void Print2Array(int**mas, int rows, int cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			cout << mas[i][j] << "\t";

		}
		cout << endl;
	}
}

void Init2Array(int**mas, int rows, int cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			mas[i][j] = rand() % 10;
		}
	}
}

int ** Create2Array(int rows, int cols)
{
	int ** temp = new int*[rows];
	for (size_t i = 0; i < rows; i++)
	{
		temp[i] = new int[cols];
	}
	return temp;
}