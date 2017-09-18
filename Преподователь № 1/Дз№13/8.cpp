#include <iostream>
using namespace std;
void main()
{
	setlocale(0, "ru");
	int  n = 0;
	cout << "¬ведите высоту треугольника:\n";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << "*";
		}
		cout << "\n";
	}
}
