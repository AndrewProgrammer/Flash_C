#include <iostream>
using namespace std;
void main()
{
	int cekv,minytiv,zhaciv, cek, minyti, zhaci,ostc,ostm,ostz,const pol=86400;
	cout << "Vedite t\n";
	cin >> cekv;
	minytiv = cekv / 60;
	zhaciv = cekv / 3600;
	cek = pol;
	minyti = pol / 60;
	zhaci = pol / 3600;
	ostc = cek - cekv;
	ostm = minyti - minytiv;
	ostz = zhaci - zhaciv;
	cout << "ostavschiesa v cek\n" << ostc << endl;
	cout << "ostavsschiesa v min\n" << ostm << endl;
	cout << "ostavshiesa v zhacax\n" << ostz << endl;
}
