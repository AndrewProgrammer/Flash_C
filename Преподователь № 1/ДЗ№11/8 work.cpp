#include <iostream>
using namespace std;
void main()
{
	setlocale(0, "ru");
	int i;
	cout << "Enter number\n";
	cin >> i;
	while (i)
	{
		cout << i % 10;
		i /= 10;
	}
}