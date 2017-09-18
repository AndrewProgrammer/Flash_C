#include <iostream>
using namespace std;
void main()
{
	setlocale(0, "ru");
	int a, i = 1,b = 1;
	cout << "¬ведите факториал\n\n";
	cin >> a;
	while (i < a)
	{
		b = i * b;
		i++;
	}	
	cout << b * a << endl;
}