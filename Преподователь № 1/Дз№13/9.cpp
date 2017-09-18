#include <iostream>
using namespace std;
void main()
{
	setlocale(0, "ru");
	int  a;
	cout << "¬ведите высоту треугольника:\n";
	cin >> a;
	for (int n = 0; n <= a; n++)
	{
		for (int y = 0; y <= a; y++)
		{
			if (y == 0 || n == a || y == n)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
}
