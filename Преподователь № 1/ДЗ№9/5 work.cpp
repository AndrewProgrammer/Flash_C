#include <iostream>
using namespace std;
void main()
{
	int choise, grn, euro, dollars, rybles;
	const int e = 20;
	const int d = 16;
	const int r = 3;
	cout << "Enter the amount of money in UAH\n";
	cin >> grn;
	cout << "Click 1 to put this amount of money in euros\n";
	cout << "Click 2 to put this amount of money in dollars\n";
	cout << "Click 3 to put this amount of money in rybles\n";
	cin >> choise;
	switch (choise){
	case 1 :
		euro = grn / e;
		cout << "Your amount of money in euros!\n" << euro << endl;
		break;
	case 2 :
		dollars = grn / d;
		cout << "Your amount of money in dollars!\n" << dollars << endl;
		break;
	case 3 :
		rybles = grn / r;
		cout << "Your amount of money in rybles!\n" << rybles << endl;
		break;
	default :
		cout << "Error! It is incorrect symbol!\n";
		break;
	}

}