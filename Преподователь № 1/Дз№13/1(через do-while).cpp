#include <iostream>
using namespace std;
void main()
{
	setlocale(0, "ru");
	const int N = 10;
	int n, a = N;
	float poz = 0, neg = 0, null = 0;
	cout << "������� ������ �����\n";
	do
	{
		cin >> n;
		if (n > 0) poz++;
		if (n < 0) neg++;
		if (n == 0) null++;
		a--;
	} 
	while (a);
	{
		cout << "\n������� ������������� ����� ����� " << (poz / N) * 100 << "%";
		cout << "\n������� ������������� ����� ����� " << (neg / N) * 100 << "%";
		cout << "\n������� ����� ����� " << (null / N) * 100 << "%";
	}
	cout << endl;
}