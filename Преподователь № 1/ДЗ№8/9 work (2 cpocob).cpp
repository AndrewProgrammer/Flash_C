#include <math.h>
#include <iostream>
using namespace std;
void main()
{
	int x0, y0, x1, y1, x, y;
	float L;
	cout << "Vedite koordinati verxnego ugla x0 i y0\n";
	cin >> x0 >> y0;
	cout << "Vedite koordinati nichnego ugla x1 i y1\n";
	cin >> x1 >> y1;
	cout << "Vedite koordinati X i Y\n";
	cin >> x >> y;
	L = sqrt(pow(x - x0,2) + pow(y- y0,2));
	if ((x1 < L) && (L > y1))
		cout << "Eta tochka prinadleshit treygolniky!\n";
	else cout << "Eta tochka ne prinadleshit treygolniky!\n";
}
