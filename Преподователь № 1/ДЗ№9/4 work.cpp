#include <iostream>
using namespace std;
void main()
{
	int x, y;
	cout << "Enter the coordinates of a point\n";
	cin >> x >> y;
	if (x > 0 && y > 0)
	{
		cout << "This is the first quarter!\n";
	}
	else if (x > 0 && y < 0)
	{
		cout << "This is the fourth quarter!\n";
	}
	else if (x < 0 && y > 0)
	{
		cout << "This is the second quarter!\n";
	}
	else if (x < 0 && y < 0)
	{
		cout << "This is the third quarter!\n";
	}
	else if (x == 0 && y == 0)
	{
		cout << "This point lies in Center of coordinates!\n";
	}
	else if (x == 0)
	{
		cout << "This point is in the Vertical Axis!\n";
	}
	else if (y == 0)
	{
		cout << "This point is in the Horizontal Axis!\n";
	}
}