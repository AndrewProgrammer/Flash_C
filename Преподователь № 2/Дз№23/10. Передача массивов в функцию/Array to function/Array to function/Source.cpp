#include <iostream>
using namespace std;

/*
	Существует возможность передать массив в функцию.

	При передаче массива в функцию он НЕ КОПИРУЕТСЯ (в отличие от обычных переменных и значений).
	То есть, если изменить массив внутри функции, это повлияет на исходный массив.
*/


// В качестве первого аргумента будет массив. Обратите внимание что скобки остаются пустыми. 
// Можно явно указать размерность литералом (например: void arrayPrint (int arr[6])) 
// или константой (например, void arrayPrint (int arr[SIZE]), но тогда константа должна быть глобальной)
// Для большей гибкости можно оставить скобки пустыми, чтобы передавать массив любой размерности
// Вторым параметром передаем размер, т.к. внутри функции определить размерность массива будет невозможно, даже через sizeof
void arrayPrint (int arr[], int size);
void arrayReverse (int arr[], const int size);



const int ROW = 3, COL = 3;

// При передаче многомерных массивов в функцию можно опустить только первую размерность, т.к. компилятор должен понять как считать смещение
// В данном случае функция может принимать двумерный массив, который состоит из любого кол-ва строк
// но только с COL столбцами
void twoDimArrayPrint (int arr[][COL], int rowSize);

void main ()
{
	const int SIZE = 5;
	int numArray[SIZE] = { 1, 2, 3, 4, 5 };

	cout << "Before reverse: " << endl;
	arrayPrint (numArray, SIZE);
	cout << endl << endl;


	cout << "After reverse: " << endl;
	// Массив передается НЕ по значению. Т.е. если изменить массив внутри функции, это повлияет на исходный массив
	arrayReverse (numArray, SIZE);
	arrayPrint (numArray, SIZE);


	cout << "\n\n\nTwo dimensional array: \n\n";
	int twoDimensionalArray[ROW][COL] = { 1, 2, 3, 4, 5, 6 };
	twoDimArrayPrint (twoDimensionalArray, ROW);

}

void arrayPrint (int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "#" << i << " = " << arr[i] << endl;
	}
}

// Обратите внимание, что второй параметр определен как константа, это значит, что внутри функции его нельзя будет изменить
// Однако помните, что все аргументы кроме массивов передаются по значению, то есть компируются в функцию и не имеют никакой связи между местом вызова
void arrayReverse (int arr[], const int size)
{
	int temp = 0;
	for (int i = 0; i < size / 2; i++)
	{
		temp = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - i - 1] = temp;
	}
}


void twoDimArrayPrint (int arr[][COL], int rowSize)
{
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			cout << arr[i][j] << '\t';
		}
		cout << endl;
	}
}
