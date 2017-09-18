#include <iostream>
using namespace std;
void main()
{
	const int coins = 15;
	int th1, tm1, th2, tm2, other, H, M, S, h, m, s;
	cout << "Enter hours of start calling\n";
	cin >> H;
	cout << "Enter minutes of start calling\n";
	cin >> M;
	cout << "Enter seconds of start calling\n";
	cin >> S;
	cout << "Enter hours of end calling\n";
	cin >> h;
	cout << "Enter minutes of end calling\n";
	cin >> m;
	cout << "Enter seconds of end calling\n";
	cin >> s;
	th1 = H * 3600;
	tm1 = M * 60;
	th2 = h * 3600;
	tm2 = s * 60;
	other = (th2 + tm2 + h) - (th1 + tm1 + S);
	cout << "Your price in coins = " << double((other / 60) * coins) << endl;
}