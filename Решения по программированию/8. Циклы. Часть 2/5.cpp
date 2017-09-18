#include <iostream>
using namespace std;
void main()
{
	setlocale(0, "ru");
	cout << "¬ведите длину стороны квадрата \n";
	int dlina = 0;
	cin >> dlina;
	int visota = dlina;
	for (int a = 0; a < visota; a++)
	{
		for (int i = 0; i < dlina; i++)
		if (a == 0 || i == 0 || i == dlina - 1 || a == dlina - 1)
			cout << '*';
		else
			cout << " ";
		cout << endl;
	}
}