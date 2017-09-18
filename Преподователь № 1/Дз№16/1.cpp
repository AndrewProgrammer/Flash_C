#include <iostream>
using namespace std;
void main()
{
	const int size = 10;
	double sum = 0, avg;
	int n = 10;
	int a[size];
	for (int i = 0; i < size; i++)
	{
		cout << "Enter number\n";
		cin >> a[i];
		sum += a[i];
	}
	cout << "Sum of this numbers:\n" << sum << endl;
	avg = sum / n;
	cout << "Avg of this numbers:\n" << avg << endl;
}