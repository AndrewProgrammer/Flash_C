#include <iostream>
using namespace std;
void main()
{
	setlocale(0, "ru");
	const int N = 10;
	double chet = 0, nechet = 0;
	cout << "������� ������ �����\n";
	for (int ogr = 0; ogr < 10; ogr++)
	{
		int a;
		cin >> a;
		if (a % 2 == 0)
			chet++;
		else 
			nechet++;
	}
		cout << "\n������� ������������� ����� ����� " << (chet / N) * 100 << "%";
		cout << "\n������� ������������� ����� ����� " << (nechet/ N) * 100 << "%";
	cout << endl;
}