#include <iostream>
using namespace std;
void main()
{
	setlocale(0, "ru");
	const int N = 10;
	double poz = 0, neg = 0, null = 0;
	cout << "Введите десять чисел\n";
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
		cout << "\nПроцент положительных чисел равен " << (poz / N) * 100 << "%";
		cout << "\nПроцент отрицательных чисел равен " << (neg / N) * 100 << "%";
		cout << "\nПроцент нулей равен " << (null / N) * 100 << "%";
	cout << endl;
}