#include <iostream>
using namespace std;
void main()
{
	setlocale(0, "ru");
	int a;
	cout << "Числа на которые число делится без остатка\nВведите число\n";
	cin >> a;
	cout << a << " Делится без остатка на ";
	for (int b = 1; b < a; b++)
	{
		if (a % b == 0)
			cout << b << " ";
	}
}