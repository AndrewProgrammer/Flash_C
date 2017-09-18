#include <iostream>;
using namespace std;
void main()
{
	double h, Vpok, l, s, P1, P2, P3,P4,P, const pro = 0.2, const lit = 0.5;
	cout << "Dlina komnati\n";
	cin >> l;
	cout << "Shirina komnati\n";
	cin >> s;
	cout << "vicoty komnati\n";
	cin >> h;
	P1 = l * h;
	P2 = s * h;
	P3 = P1 * 2 + P2 * 2;
	P4 = P3 * pro;
	P = P3 - P4;
	Vpok = P * lit;
	cout << "Litri kracki\n" << Vpok;
}