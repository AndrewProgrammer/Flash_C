#include <iostream>
using namespace std;
void main()
{
	int day;
	cout << "Vedite chislo ot 1 do 7\n";
	cin >> day;
	switch (day)
	{
	case 1 :
		cout << "Today is Monday!\n";
		break;
	case 2 :
		cout << "Today is Tuesday!\n";
		break;
	case 3 :
		cout << "Today is Wednesday!\n";
		break;
	case 4 :
		cout << "Today is Thursday!\n";
		break;
	case 5 :
		cout << "Today is Friday!\n";
		break;
	case 6 :
		cout << "Today is Sunday!\n";
		break;
	case 7 :
		cout << "Today is Saturday!\n";
		break;
	default :
		cout << "Error! It is incorrect symbol!\n" << endl;
		break;
	}
}