#include <iostream>
using namespace std;
void main()
{
	setlocale(0, "ru");
	int  n = 0, k = 0;
	cout << "¬ведите высоту треугольника:\n";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << (j == 0 || j == i || i == n - 1 ? "*" : " ");
		}
		k++;
		cout << "\n";
	}
}
