#include <iostream>
using namespace std;
void main()
{
	double a, b;
	cout << "Enter number!\n";
	cin >> a;
	b = a - (int)a;
	if (b == 0)
	{
		cout << "This number is fractional, and it has a real part!\n";
	}
	else cout << "This number if fractional, and it doesn`t have a real part!\n";
}