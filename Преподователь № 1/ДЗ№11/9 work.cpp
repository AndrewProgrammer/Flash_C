#include <iostream>
using namespace std;
void main()
{
	int value;
	cout << "Enter number\n";
	cin >> value;
	int divider = 1;
	while (divider <= value) 
	{
		if (value % divider == 0)
		{
			cout << divider << endl;
		}
		divider++;
	}
}
