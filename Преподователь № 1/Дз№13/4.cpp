#include <iostream>
using namespace std;
void main()
{
	setlocale(0, "ru");
	cout << "¬ведите длину стороны квадрата \n";
	int size;
	cin >> size;
	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			cout << '*';
		}
		cout << endl;
	}
}