#include <iostream>
using namespace std;
void main()
{
	setlocale(0, "ru");
	const int N = 10;
	double poz = 0, neg = 0, null = 0;
	cout << "������� ������ �����\n";
	for (int ogr = 0; ogr < 10; ogr++)
	{
		int a;
		cin >> a;
		if (a > 0)
			poz++;
		else if (a < 0)
			neg++;
		else
			null++;
	}
		cout << "\n������� ������������� ����� ����� " << (poz / N) * 100 << "%";
		cout << "\n������� ������������� ����� ����� " << (neg / N) * 100 << "%";
		cout << "\n������� ����� ����� " << (null / N) * 100 << "%";
	cout << endl;
}