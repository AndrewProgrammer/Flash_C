#include <iostream>
using namespace std;
void main()
{
	int d;
	cout << "Vedite d\n";
	cin >> d;
	if (d >= 0)
		cout << "|" << d << "|";
	else cout << "|" << -d << "|";
}
