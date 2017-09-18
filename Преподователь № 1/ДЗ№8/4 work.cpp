#include <iostream>;
using namespace std;
void main()
{
	int X, Y;
	cout << "Vedite chislo X\n";
	cin >> X;
	cout << "Vedite chislo Y \n";
	cin >> Y;
	if (X / Y)
	{
		cout << "X / Y!\n";
	}
	else cout << "X !/(ne kratno) Y!\n";
}
