#include <iostream>
using namespace std;
void main()
{
	setlocale(0, "ru");
	int a, b = 2;
	cout << "������� a\n";
	cin >> a;
	bool simple = true;
	while (b < a)
	{
		if (a % b == 0)
		{
			simple = false;
			break;
		}
		b++;
	}
	if (simple)
		cout << "��� ������� ����� \n" << endl;
	else
		cout << "��� �� ������� ����� \n" << endl;

}