//#include <iostream>
//#include <time.h>
//
//using namespace std;
//
//int** Create2Array(int rows, int cols);
//int * CreateArray(int size);
//void Init2Array(int ** mas, int rows, int cols);
//void InitArray(int *mas, int size);
//void Print2Array(int** mas, int rows, int cols);
//void PrintArray(int* mas, int size);
//void Delete2Array(int ** mas, int rows);
//void DeleteArray(int *mas);
//void AddColToEnd(int ** mas, int rows, int &cols, int value);
//int * AddElemToEnd(int*mas, int &size, int value);
//int ** AddRowToEnd(int ** mas, int &rows, int cols, int value);
//void InitArray(int *mas, int size, int value);
//
//void main()
//{
//	srand(time(0));
//	int rows=0, cols=0;
//	cout << "Enter rows" << endl;
//	cin >> rows;
//	cout << "Enter cols" << endl;
//	cin >> cols;
//	int ** mas = Create2Array(rows, cols);
//	Init2Array(mas, rows, cols);
//	Print2Array(mas, rows, cols);
//	AddColToEnd(mas, rows, cols, 100);
//	Print2Array(mas, rows, cols);
//	mas = AddRowToEnd(mas, rows, cols, 200);
//	Print2Array(mas,rows, cols);
//	system("pause");
//}
//
//int ** AddRowToEnd(int ** mas, int &rows, int cols, int value)
//{
//	int ** temp = new int*[rows + 1];
//	for (size_t i = 0; i < rows; i++)
//	{
//		temp[i] = mas[i];
//	}
//	temp[rows] = CreateArray(cols);
//	InitArray(temp[rows], cols, value);
//	rows++;
//	delete[]mas;
//	return temp;
//}
//
//void AddColToEnd(int ** mas, int rows, int &cols, int value)
//{
//	for (size_t i = 0; i < rows; i++)
//	{
//		mas[i] = AddElemToEnd(mas[i], cols, value);
//		cols--;
//	}
//	cols++;
//}
//
//int * AddElemToEnd(int*mas, int &size, int value)
//{
//	int * temp = new int[size + 1];
//	for (size_t i = 0; i < size; i++)
//	{
//		temp[i] = mas[i];
//	}
//	temp[size] = value;
//	size++;
//	DeleteArray(mas);
//	return temp;
//}
//
//void Delete2Array(int ** mas, int rows)
//{
//	for (size_t i = 0; i < rows; i++)
//	{
//		DeleteArray(mas[i]);
//	}
//	delete[]mas;
//	mas = NULL;
//}
//
//void DeleteArray(int *mas)
//{
//	delete[]mas;
//	mas = NULL;
//}
//
//void Print2Array(int** mas, int rows, int cols)
//{
//	for (size_t i = 0; i < rows; i++)
//	{
//		PrintArray(mas[i], cols);
//	}
//	cout << endl;
//}
//
//void PrintArray(int* mas, int size)
//{
//	for (size_t i = 0; i < size; i++)
//	{
//		cout << mas[i] << "\t";
//	}
//	cout << endl;
//}
//
//void Init2Array(int ** mas, int rows, int cols)
//{
//	for (size_t i = 0; i < rows; i++)
//	{
//		InitArray(mas[i], cols);
//	}
//}
//void InitArray(int *mas, int size, int value)
//{
//	for (size_t i = 0; i < size; i++)
//	{
//		mas[i] = value;
//	}
//}
//
//void InitArray(int *mas, int size)
//{
//	InitArray(mas, size, rand() % 10);	
//}
//
//int * CreateArray(int size)
//{
//	int* temp = new int[size];
//	return temp;
//}
//
//int** Create2Array(int rows, int cols)
//{
//	int ** temp = new int*[rows];
//	for (size_t i = 0; i < rows; i++)
//	{
//		temp[i] = CreateArray(cols);
//	}
//	return temp;
//}