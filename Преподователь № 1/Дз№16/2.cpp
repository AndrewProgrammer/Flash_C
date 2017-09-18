#include <iostream>
using namespace std;
void main()
{
	const int size = 10;
	int imin, a[size];
	cout << "Enter numbers:\n";
	for (int i = 0; i < size; i++)
	{
		cin >> a[i];
	}
	int min = a[0];
	for (int j = 1; j<size; j++)
	{
		if (min>a[j])
		{
			min = a[j]; 
			imin = j + 1;
		}
	}
	cout << "min=" << min << endl;
	cout << "imin=" << imin << endl;
}