#include <iostream>;
using namespace std;
void main()
{
	int a;
	cout << "Vedite a\n";
	cin >> a;
	if (a / 3 && a / 5 && a / 7)
	{
		cout << "chislo a / chislam:3,5,7!!!\n";
	}
	else cout << "chislo a !/(ne kratno) chisla:3,5,7!!!\n";
}
