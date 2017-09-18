#include "Header.h"

void InitializeArray(int ar[][cols])
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			ar[i][j] = rand() % 10;
		}
	}
}

void PrintArray(int ar[][cols])
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			cout<< ar[i][j] << " ";
		}
		cout << endl;
	}
}


void InitializeArray(int ar[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		ar[i] = rand() % 10;
	}
}

void PrintArray(int ar[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << ar[i] << " ";
	}
}