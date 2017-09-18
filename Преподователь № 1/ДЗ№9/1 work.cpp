#include <iostream>
using namespace std;
void main()
{
	int kol, summa, const stoimoct;
	cout << "Enter the quantity and price for the same product in UAH!\n";
	cin >> kol >> stoimoct;
	summa = stoimoct * kol;
	if (summa >= 300)
	{
		cout << "You have 7% discount!\n";
		cout << "You must pay-" << summa - summa / 100 * 7 << "\n";
	}
	else if (summa >= 200 && summa < 300)
	{
		cout << "You have 5% discount!\n";
		cout << "You must pay-" << summa - summa / 100 * 5 << "\n";
	}
	else if (summa >= 100 && summa < 200)
	{
		cout << "You have 3% discount!\n";
		cout << "You must pay-" << summa - summa / 100 * 3 << "\n";
	}
	else cout << "You dont have discount!\n" << "You must pay summa!\n" << summa << endl;



}