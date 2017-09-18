#include <iostream>
using namespace std;

/*
	���������� ����������� �������� ������ � �������.

	��� �������� ������� � ������� �� �� ���������� (� ������� �� ������� ���������� � ��������).
	�� ����, ���� �������� ������ ������ �������, ��� �������� �� �������� ������.
*/


// � �������� ������� ��������� ����� ������. �������� �������� ��� ������ �������� �������. 
// ����� ���� ������� ����������� ��������� (��������: void arrayPrint (int arr[6])) 
// ��� ���������� (��������, void arrayPrint (int arr[SIZE]), �� ����� ��������� ������ ���� ����������)
// ��� ������� �������� ����� �������� ������ �������, ����� ���������� ������ ����� �����������
// ������ ���������� �������� ������, �.�. ������ ������� ���������� ����������� ������� ����� ����������, ���� ����� sizeof
void arrayPrint (int arr[], int size);
void arrayReverse (int arr[], const int size);



const int ROW = 3, COL = 3;

// ��� �������� ����������� �������� � ������� ����� �������� ������ ������ �����������, �.�. ���������� ������ ������ ��� ������� ��������
// � ������ ������ ������� ����� ��������� ��������� ������, ������� ������� �� ������ ���-�� �����
// �� ������ � COL ���������
void twoDimArrayPrint (int arr[][COL], int rowSize);

void main ()
{
	const int SIZE = 5;
	int numArray[SIZE] = { 1, 2, 3, 4, 5 };

	cout << "Before reverse: " << endl;
	arrayPrint (numArray, SIZE);
	cout << endl << endl;


	cout << "After reverse: " << endl;
	// ������ ���������� �� �� ��������. �.�. ���� �������� ������ ������ �������, ��� �������� �� �������� ������
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

// �������� ��������, ��� ������ �������� ��������� ��� ���������, ��� ������, ��� ������ ������� ��� ������ ����� ��������
// ������ �������, ��� ��� ��������� ����� �������� ���������� �� ��������, �� ���� ����������� � ������� � �� ����� ������� ����� ����� ������ ������
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
