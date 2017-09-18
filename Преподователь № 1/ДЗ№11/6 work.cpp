#include <iostream>
using namespace std;
void main()
{
	double value;
	cout << "Enter number\n";
	cin >> value;
	int power;
	cout << "Enter power\n";
	cin >> power;
	double result = 1;
	while (power-- != 0)
	{
		result *= value;
	}
	cout << "Result - " << result << endl;
}
