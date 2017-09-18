#include <iostream>
using namespace std;
void main()
{
	int  kol,v,kolf,f, const f1 = 760;
	cout << "Vedite V fleshki\n";
	cin >> v;
	cout << "kolishectvo filmov\n";
	cin >> f;
	kol = (f * 760) / 1000;
	kolf = v - kol;
	cout << "filmov umectiloc na fleshke\n" << kolf;
}
