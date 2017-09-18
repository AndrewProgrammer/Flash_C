#include <iostream>
using namespace std;
void main()
{
	int value;
	cout << "Enter number\n";
	cin >> value;
	int lastDigit = 10;
	while (value != 0)
	{
		if (value % 10 > lastDigit)
		{
			cout << "Does not match";
			break;
		}
		lastDigit = value % 10;
		value /= 10;
	}
	if (value == 0)
		cout << "Match";
}