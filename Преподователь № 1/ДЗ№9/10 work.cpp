#include <iostream>
using namespace std;
void main()
	{
		int d, m, y;
		cout << "Enter day :\n";
		cin >> d;
		cout << "Enter month :\n";
		cin >> m;
		cout << "Enter year :\n";
		cin >> y;
		if (d > 31)
		{
			cout << "Error! Of days in the month cannot be greater than 31!\n";
		}
		else if (m > 12)
		{
			cout << "Error! Months of the year cannot be more than 12!\n";
		}
		else if (d < 31)
		{
			d++;
			cout << d << "." << m << "." << y << endl;
		}
		else if (d == 31 && m<12)
		{
			m++;
			d -= 30;
			cout << d << "." << m << "." << y << endl;
		}
		else if (d == 31 && m == 12)
		{
			y++;
			d -= 30;
			m -= 11;
			cout << d << "." << m << "." << y << endl;
		}
		else if (m == 2 && d == 28)
		{
			m++;
			d = 1;
		}
		else cout << "You entered is not a valid date\n" << endl; 
}
