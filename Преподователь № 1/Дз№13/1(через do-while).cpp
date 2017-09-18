#include <iostream>
using namespace std;
void main()
{
	setlocale(0, "ru");
	const int N = 10;
	int n, a = N;
	float poz = 0, neg = 0, null = 0;
	cout << "Введите десять чисел\n";
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
		cout << "\nПроцент положительных чисел равен " << (poz / N) * 100 << "%";
		cout << "\nПроцент отрицательных чисел равен " << (neg / N) * 100 << "%";
		cout << "\nПроцент нулей равен " << (null / N) * 100 << "%";
	}
	cout << endl;
}