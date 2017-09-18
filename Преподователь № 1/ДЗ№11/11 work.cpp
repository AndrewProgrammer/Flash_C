#include <iostream>
using namespace std;
void main()
{
	int a;
	int last = -1;
	cin >> a;
	while (a)
	{
		if (a % 10 == last)
		{
			cout << "yes!\n";
			break;
		}
		last = a % 10;
		a /= 10;
	}
	if (a == 0)
		cout << "No!\n";
}
