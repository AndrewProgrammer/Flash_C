#include <iostream>
using namespace std;
void main()
{
	int x0, y0, x1, y1, x, y;
	float L;
	cout << "Vedite x0 i y0\n";
	cin >> x0 >> y0;
	cout << "Vedite x1 i y1\n";
	cin >> x1 >> y1;
	cout << "Vedite  X i Y\n";
	cin >> x >> y;
	if ((x < x1) && (x0 > x))
		cout << "Eta tochka prinadleshit!\n";
	else cout << "Eta tochka ne prinadleshit!\n";
}
