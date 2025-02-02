#include <iostream>
using namespace std;

/*
	��������� �������� ����� �� ��������� �������� ������ � � �++. ��������� ���������� ����� ������� ����� ������������� ���������,
		������� ���������� ��� ��������, ���������� �� ������ ��������������� ������. ��������� ���� ����� ����������� ������ ����� ���������,
		� ����� ��-�������.

	��������� - ��� ���������� (������������ ������������� ����), ������� ������ �������� ����� ������ ����������.
	��� ����, ����� ���������� ��������, � ������� (����������), ����� �������� �������� � ���������, 
		���������� � ��������� ��������� �������� ������������� (dereferencing) (������������, �������� ������ �� ��������� (indirection))  (*).


	����� ��� ��������� ������� ���?
		��������:

			int someVar = 10;
			int *pInt = &someVar; // ��������� �� ���������� someVar
			*pInt = 25; // ������������� pInt, �������� ������ � ���������� someVar (�.�. pInt) ��������� �� someVar. ������ ���������� someVar
			cout << someVar << endl; // ������� 25

			int b = 30;
			pInt = &b; // ������ pInt ��������� ��� �� b
			cout << *pInt << endl; // ������� 30

	��� ����� ��������� ������� ���? ������ ��� ��������� ��������� ��� "��������� �� int" (int *), ������ �� double *?
	���� ����� �� ������ ���������� ���������� ���� ��������, � �������� ���������, ����� ��� ������?
	������, ���� �� �� ������ ��������� �������.
	����� �� ������ ���������:

	int *pInt = &b;
	�� � ��������� pInt ������������ ����� ���������� b. � ������, ����� ������� �����(!) ���������� b.
	��������� b ��� int, �� � ��� 4 �����.
	��� ������������� ����� �� ����� ������� ���� �����?

	��������, ��� &b ������� 132. �.�. ����� ������� ����� ���������� b - ��� 132.
	��������������, ���� b ����� ��� int, �� � ��� 4 ����� ����������. ������ ��� �� ����� ����� �� ������ 132-� ����, � � 133, 134 � 135.
	�� �� �� �������� ������ 132 ��� �����. � ��� ������������� ����� ������� 4 �����. ������ ��������� ����� �����, ������� ���� �� ������� ��� �������������?
	���� ��� ������ ����� 132.

	��� ��� �������� � ��� ������� ���. ����� ��� ����������� ��������� ������� int * - ��� ������, ��� ��������� "��������� �� int".
	������ ��� ������������� ����� ����� 4 �����.
	���� ����� � ����������� ������� double * (��������� �� double), �� ��� ������������� ����� ����� 8 ����.
*/

void main ()
{
	//��������:
	int val1 = 5; // �����������, ��� val1 ��������� �� ������ 100
	double val2 = 2.5; // �����������, ��� val2 ��������� �� ������ 200

	int *pVal1;
	double *pVal2;

	pVal1 = &val1; // ���������� � ��������� pVal1 ����� ���������� val1 (�� ���� 100, ��� �� ������������ �����)
	pVal2 = &val2; // ���������� � ��������� pVal2 ����� ���������� val2 (�� ���� 200, ��� �� ������������ �����)

	cout << *pVal1 << endl; // ��������� pVal1 ��������� �� int, �� ��� ������������� �� ������� 4 ����� �� ������ 100
	// �� ���� ����� �� �������: 100, 101, 102, 103

	cout << *pVal2 << endl; // ��������� pVal1 ��������� �� double, �� ��� ������������� �� ������� 8 ���� �� ������ 200
	// �� ���� ����� �� �������: 200, 201, 202, 203, 204, 205, 206, 207


	// ���������� ������������ �������� �����. � ��� ����� � �������� ������������ �����.
	// �� �� �������� ������ �������� ���� ��������� � �������, ���� ������� ��� ����������.

	//pVal1 = &val2; // ������ � int * �������� double *. 
	//pVal2 = pVal1; // ������ � double * �������� int *

	// �� ��� ����������� ����� ������, ���� �� ������, ��� �������.
	pVal1 = (int *)pVal2; // ���� ���������� � int *. ����� ���������� ������� ��������� �����������, � ���������� ����� �� ��������� pVal2, � ��������� pVal1.

	// ������ � pVal1 � pVal2 ��������� �� ���� � �� �� ������� ������:
	cout << "pVal1 = " << pVal1 << endl;
	cout << "pVal2 = " << pVal2 << endl;

	// ������, ��� ������ ����� ��� ������������� pVal1? 
	// ��� ������������� pVal2 �� ����� �������, ��� � ������. ���� ��������� �� double. � �� ������ ���� ����� double.
	// ����� 8 ���� �� ������ � �� �������.

	cout << "*pVal2 = " << *pVal2 << endl;

	// � ��� ��� ������������� pVal1 ����� ����� ������ 4 �����(!).  4 ������ ����� �� ������ � ���������.
	// ��� �� ������, ��� �������� pVal1 �������� ��� ��������� �� int (int *)
	cout << "*pVal1 = " << *pVal1 << endl;

	// �� ��� � ����� ������ �� �����, ������ ����� �� 8 ���� �� ����������, � ������ 4.
	// � ��� ����� ���� ������� ��������?

	pVal2 = (double *)&val1; // val1 ��� int. �������� ����� 4 �����, � �� � ����� (int *) ����������� � double *
	//cout << "*pVal2 = " << *pVal2 << endl; // ����� 8 ���� (�.�. double *), � ���-�� ����� 4!!
	// �� ������� �� ����� ������� ������. ��� ������� ���������� ��������. 

	// ������: ����������� ����� ���������� ���������� ������ � ��� ������, ����� ��������� ��� ������� � ����� �� ��� ���������. 
	// ��������� ��� ����� � ������ ������� ����� ����.
	// � ��������� ������� ���������� ������� �������������� ������������ � ������������ ���-�� ������.
}