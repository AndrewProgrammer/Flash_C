#include "Listdouble.h"
#include "Nodedouble.h"
#include <iostream>
using namespace std;
void main()
{
	setlocale(0, "ru");
	int N; //����� ��������� � ������
	int x; //�������� �������� � ������
	List<int> lst; //����������, ��� ������� ������
	cout << "������� ����������� ��������� � ������: " << endl;
	cout << "N = "; cin >> N; //������� ������� ��������� ������� � ������
	cout << "������� ��� ��������: " << endl;
	for (int i = 0; i<N; i++)
	{
		cout << i + 1 << ". x = "; cin >> x; //���� x � ����������
		lst.Add(x); //���������� �������� � ������
	}
	lst.Show();
	cout << "������� ������ �������: " << endl;
	lst.RemoveFirst();
	lst.Show();
	cout << "������� ������� �� �������: " << endl;
	lst.Remove(3);
	lst.Show();
	cout << "������� ��������� ������� : " << endl;
	lst.RemoveLast();
	lst.Show();
	cout << "������� ������" << endl;
	lst.ClearList();
}