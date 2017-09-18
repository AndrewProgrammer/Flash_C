#include <iostream>
using namespace std;
void main()
{
	int year;
	cout << "Enter year\n";
	cin >> year;
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
	{
		cout << "This is a leap year!\n" << endl;
	}
	else cout << "This year isn`t leap!\n" << endl;
}