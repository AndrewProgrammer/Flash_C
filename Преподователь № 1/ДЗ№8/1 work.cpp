#include <iostream>
using namespace std;
void main()
{
	int a, b, c;
	int choise;
	cout << "Vedite a\n";
	cin >> a;
	cout << "Vedite b\n";
	cin >> b;
	cout << "1-a+b\n";
	cout << "2-a-b\n";
	cout << "3-a*b\n";
	cout << "4-a/b\n";
	cout << "5-a%b\n";
	cin >> choise;
	if (choise == 1)
	{
		c = a + b;
		cout << c << endl;
	}
	else if (choise == 2)
	{
		c = a - b;
		cout << c << endl;
	}
	else if (choise == 3)
	{
		c = a*b;
		cout << c << endl;
	}
	else if (choise == 4)
	{
		if (b)
		{
			c = a / b;
			cout << c << endl;
		}
		else 
			cout << "Eror!!! na 0 delit nelzya!!!\n";
	}
	else if (choise == 5)
	{
		c = a % b;
		cout << c << endl;
	}
	else cout << "Vash otvet:" << "Done!!!\n" << endl;
}
