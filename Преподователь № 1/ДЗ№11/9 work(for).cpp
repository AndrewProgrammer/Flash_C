#include <iostream>
using namespace std;
void main()
{
	setlocale(0, "ru");
	int a;
	cout << "����� �� ������� ����� ������� ��� �������\n������� �����\n";
	cin >> a;
	cout << a << " ������� ��� ������� �� ";
	for (int b = 1; b < a; b++)
	{
		if (a % b == 0)
			cout << b << " ";
	}
}