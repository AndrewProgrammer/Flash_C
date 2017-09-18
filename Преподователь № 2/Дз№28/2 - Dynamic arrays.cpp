#include <iostream>
#include <iomanip>
using namespace std;

void printArray (int *arr, int size);
void fillArray (int *arr, int size);

void main ()
{
	/*
		Существует специальная форма оператора new для выделения блока памяти под массив.

		Синтаксис:
			new тип[размер];
	*/

	int sizeOfArray = 20; // Обратите внимание, что это переменная, а не константа
	int *pDynArray = new int[sizeOfArray];	// Память под массив выделяется динамически на ЭТАПЕ ВЫПОЛНЕНИЯ, соответственно
							//	компилятору не нужно знать размер блока памяти на этапе компиляции, как при статических массивах

	fillArray (pDynArray, sizeOfArray);
	printArray (pDynArray, sizeOfArray);

	// Освобождаем память, зарезервированную под массив
	delete[]pDynArray; // Обратите внимание на форму оператора delete для освобождения памяти дин. массива
	pDynArray = NULL; 

	cout << "\n==============================================\n";

	cout << "Enter new size of array: ";
	cin >> sizeOfArray; // Пользователь вводит новый размер массива


	if (sizeOfArray >= 0)
		pDynArray = new int[sizeOfArray]; // Выделяем нужное количество памяти. 
	else
		cout << "Error! Wrong array size!" << endl;

	fillArray (pDynArray, sizeOfArray);
	printArray (pDynArray, sizeOfArray);

	delete[] pDynArray; // Освобождаем занимаемую память
}

void printArray (int *arr, int size)
{
	if (arr == NULL)
		return;

	for (int i = 0; i < size; ++i)
	{
		cout << "Element #" << setw (2) << i << " = " << *(arr + i) << endl;
	}

}

void fillArray (int *arr, int size)
{
	if (arr == NULL)
		return;

	for (int i = 0; i < size; ++i)
	{
		arr[i] = i + 1;
	}

}