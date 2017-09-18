//#include <iostream>
//using namespace std;
//
//int* CreateArray(int size);
//int** Create2Array(int rows, int cols);
//void InitArray(int * mas, int size);
//void Init2Array(int** mas, int rows, int cols);
//void PrintArray(int*mas, int size);
//void Print2Array(int**mas, int rows, int cols);
//int**AddRowToIndex(int** mas, int &rows, int cols, int index);
//void AddColByIndex(int**mas, int rows, int&cols, int index);
//int* AddElemByIndex(int* mas, int &size, int index, int value);
//void main()
//{
//	int rows = 0,  cols = 0;
//	cin >> rows;
//	cin >> cols;
//	int ** mas = Create2Array(rows, cols);
//	Init2Array(mas, rows, cols);
//	Print2Array(mas, rows, cols);
//	mas = AddRowToIndex(mas, rows, cols, 3);
//	Print2Array(mas, rows, cols);
//	system("pause");
//	AddColByIndex(mas, rows, cols, 4);
//	Print2Array(mas, rows, cols);
//	system("pause");
//}
//
//void AddColByIndex(int**mas, int rows, int&cols, int index)
//{
//	for (size_t i = 0; i < rows; i++)
//	{
//		mas[i] = AddElemByIndex(mas[i], cols, index, rand() % 10);
//		cols--;
//	}
//	cols++;
//}
//
//int* AddElemByIndex(int* mas, int &size, int index, int value)
//{
//	int * temp = new int[++size];
//	for (int i = 0; i < size; i++)
//	{
//		if (i < index)
//			temp[i] = mas[i];
//		else if (i == index)
//			temp[i] = value;
//		else
//			temp[i] = mas[i - 1];
//	}
//	delete[] mas;
//	return temp;
//}
//
//
//int**AddRowToIndex(int** mas, int &rows, int cols, int index)
//{
//	int ** temp = new int*[++rows];
//	for (size_t i = 0; i < rows; i++)
//	{
//		if (i < index)
//			temp[i] = mas[i];
//		else if (i == index)
//		{
//			temp[i] = CreateArray(cols);
//			InitArray(temp[i], cols);
//		}
//		else
//			temp[i] = mas[i - 1];
//	}
//	delete[] mas;
//	return temp;
//}
//
//void Print2Array(int**mas, int rows, int cols)
//{
//	for (size_t i = 0; i < rows; i++)
//	{
//		PrintArray(mas[i], cols);
//	}
//	cout << endl;
//}
//
//void PrintArray(int*mas, int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		cout << mas[i]<< "\t";
//	}
//	cout << endl;
//}
//
//void InitArray(int * mas, int size)
//{
//	for (size_t i = 0; i < size; i++)
//	{
//		mas[i] = rand() % 10;
//	}
//}
//
//void Init2Array(int** mas, int rows,int cols)
//{
//	for (int i = 0; i < rows; i++)
//	{
//		InitArray(mas[i], cols);
//	}
//}
//
//int* CreateArray(int size)
//{
//	int* tem = new int[size];
//	return tem;
//}
//
//int** Create2Array(int rows, int cols)
//{
//	int** temp = new int*[rows];
//	for (size_t i = 0; i < rows; i++)
//	{
//		temp[i] = CreateArray(cols);
//	}
//	return temp;
//}
