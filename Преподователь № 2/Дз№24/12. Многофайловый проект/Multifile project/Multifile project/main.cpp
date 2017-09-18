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
	cout << "Введите 2 числа: " << endl;
	cin >> a >> b;
	cout << "Наибольльший общий делитель равен: " << NOD(b, a % b) << endl;
}