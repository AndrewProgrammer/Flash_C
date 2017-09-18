#include <iostream>
using namespace std;
void main()
{
	int begin,end;
	cout << "Endter begin\n";
	cin >> begin;
	cout << "Enter end\n";
	cin >> end;
	int summa = 0;
	int i = begin;
	while (i <= end)
	{
		summa += i;
		i++;
	}
	cout << "Result - " << summa << endl;
}