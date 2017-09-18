#include <iostream>
#include <iomanip>
using namespace std;

void printArray (int *arr, int size);
void fillArray (int *arr, int size);

void main ()
{
	/*
		���������� ����������� ����� ��������� new ��� ��������� ����� ������ ��� ������.

		���������:
			new ���[������];
	*/

	int sizeOfArray = 20; // �������� ��������, ��� ��� ����������, � �� ���������
	int *pDynArray = new int[sizeOfArray];	// ������ ��� ������ ���������� ����������� �� ����� ����������, ��������������
							//	����������� �� ����� ����� ������ ����� ������ �� ����� ����������, ��� ��� ����������� ��������

	fillArray (pDynArray, sizeOfArray);
	printArray (pDynArray, sizeOfArray);

	// ����������� ������, ����������������� ��� ������
	delete[]pDynArray; // �������� �������� �� ����� ��������� delete ��� ������������ ������ ���. �������
	pDynArray = NULL; 

	cout << "\n==============================================\n";

	cout << "Enter new size of array: ";
	cin >> sizeOfArray; // ������������ ������ ����� ������ �������


	if (sizeOfArray >= 0)
		pDynArray = new int[sizeOfArray]; // �������� ������ ���������� ������. 
	else
		cout << "Error! Wrong array size!" << endl;

	fillArray (pDynArray, sizeOfArray);
	printArray (pDynArray, sizeOfArray);

	delete[] pDynArray; // ����������� ���������� ������
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