#include <iostream>
using namespace std;
void main()
{
	setlocale(0, "ru");
	int a,d1,d2,d3,d4;
	cout << "������� 4 ������� �����\n";
	cin >> a;
	d1 = a / 1000;
	d4 = a % 10;
	d2 = a % 1000 / 100;
	d3 = a % 100 / 10;
	if (d1 == d2 || d2 == d3 || d3 == = d4)
	{
		cout << "���� ���������� �����\n";
	}
	else cout << "���� ���������� ����\n";
}