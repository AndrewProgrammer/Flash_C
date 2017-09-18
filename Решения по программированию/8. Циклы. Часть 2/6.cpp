#include <iostream>
using namespace std;
void main()
{
	setlocale(0, "ru");
	cout << "¬ведите ширину и высоту пр€моугольника\n";
	int dlina = 0, visota = 0;
	cin >> dlina;
	cin >> visota;
	for (int a = 0; a < visota; a++)
	{
		for (int i = 0; i < dlina; i++)
			cout << '*';
		cout << endl;
	}
}