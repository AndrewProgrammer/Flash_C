#include <iostream>
using namespace std;
int NOD(int a, int b)
{
	if (b == 0)
		return a;
	if (a > b)
		return NOD(b, a % b);
	else
		return NOD(a, b % a);
}

void main()
{
	setlocale(0, "ru");
	int a, b;
	cout << "������� 2 �����: " << endl;
	cin >> a >> b;
	cout << "������������ ����� �������� �����: " << NOD(b, a % b) << endl;
}