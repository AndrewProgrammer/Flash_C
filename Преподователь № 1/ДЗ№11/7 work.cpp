#include <iostream>
using namespace std;
void main()
{
	int value;
	cout << "Enter number\n";	
	cin >> value;
	int digits = 0;
	int sum = 0;
	while (value > 0)
	{
   		sum += (value % 10);
		value /= 10;
    		digits++;
	}
	cout << value << "Kol numbers\n" << sum << "Sum of numbers\n" << endl; 
}
