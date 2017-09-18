#include <iostream>
using namespace std;
void main()
{
	int grn, euro, dollars, rybles;
	const int e = 20;
	const int d = 16;
	const int r = 3;
	cout << "Enter the entire amount of money in UAH!\n";
	cin >> grn;
	euro = grn / e;
	dollars = grn / d;
	rybles = grn * r;
	cout << euro << "Your amount of money in euros!\n";
	cout << dollars << "Your amount of money in dollars!\n";
	cout << rybles << "Your amount of money in rybles!\n";
}