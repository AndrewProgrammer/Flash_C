#include <iostream>;
using namespace std;
void main()
{
	char a;
	cout << "Vedite a\n";
	cin >> a;
	if (a >= 'a' && a <= 'z')
	{
		cout << "a = symbol\n";
	}
	else if (a >= '0' && a <= '9')
	{
		cout << "a = number\n";
	}
	else cout << "a = znak pynktyazi!\n";
}
