#include <iostream>
using namespace std;
void main()
{
	setlocale(0, "ru");
	int n, i, summa = 0, pro = 1;
	cout << "Enter from a by b\n";
	cin >> n >> i;
	while (n < i)
	{
		if (n % 2 == 0)
		{
			summa += n;
		}
		else
		{
			pro *= n;
		}
		n++;
	}
	cout << "Сумма четных чисел : " << summa << " Произведение не четных:" << pro << endl;
}