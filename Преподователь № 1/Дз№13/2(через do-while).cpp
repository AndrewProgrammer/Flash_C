#include <iostream>
using namespace std;
void main()
{
	setlocale(0, "ru");
	const int N = 10;
	int n, a = 10;
	float chet = 0, nechet = 0;
	cout << "������� ������ �����\n";
	do
	{
		cin >> n;
		if (n % 2 == 0)
			chet ++;
		else if (n % 2 != 0)
			nechet++;
		a--;
	} 
	while (a);
	{
		cout << "\n������� ������������� ����� ����� " << (chet/ N) * 100 << "%";
		cout << "\n������� ������������� ����� ����� " << (nechet / N) * 100 << "%";
		
	}
	cout << endl;
}