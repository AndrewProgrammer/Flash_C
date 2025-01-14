#include <iostream>
#include <time.h>
using namespace std;
int** AddRowToEnd(int** mas, int &rows, int cols);
void InitArray(int *mas, int value);
void InitArray(int *mas);
int * CreateArray(int size);
void Print2Array(int** mas, int rows);
void main()
{
	srand(time(0));
	int rows = 0;
	int** mas = new int*[rows];
	mas = AddRowToEnd(mas, rows, 5);
	mas = AddRowToEnd(mas, rows, 2);
	mas = AddRowToEnd(mas, rows, 7);
	mas = AddRowToEnd(mas, rows, 1);
	mas = AddRowToEnd(mas, rows, 8);
	Print2Array(mas, rows);


	system("pause");
}
void Print2Array(int** mas, int rows)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 1; j <= mas[i][0]; j++)
		{
			cout << mas[i][j] << " ";
		}
		cout << endl;
	}
}

int** AddRowToEnd(int** mas, int &rows, int cols)
{
	int ** temp = new int*[rows + 1];
	for (size_t i = 0; i < rows; i++)
	{
		temp[i] = mas[i];
	}
	temp[rows] = CreateArray(cols);
	temp[rows][0] = cols;
	InitArray(temp[rows]);
	rows++;
	delete[]mas;
	return temp;
}

void InitArray(int *mas)
{
	for (size_t i = 1; i <= mas[0]; i++)
	{
		mas[i] = rand() % 10;
	}
}

int * CreateArray(int size)
{
	int* temp = new int[size+1];
	return temp;
}