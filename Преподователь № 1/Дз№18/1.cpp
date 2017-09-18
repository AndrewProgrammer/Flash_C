#include <iostream>
#include <time.h>
using namespace std;
void main()
{
	const int size = 10;
	int a[size];
	srand(time(0));
	rand();
	for (int k = 0; k < size; k++)
	{
		a[k] = rand() % 11;
	}
	cout << "Massiv with 10 random numbers: \n";
	for (int j = 0; j < size; j++)
	{
		cout << a[j] << ' ';
	}
	for (int i = 0; i < size - 1; i += 2)
	{
		int g = a[i + 1];
		a[i + 1] = a[i];
		a[i] = g;
	}
	cout << endl;
	cout << "Result: \n";
	for (int d = 0; d < size; d++)
	{
		cout << a[d] << ' ';
	}
	cout << endl;
}