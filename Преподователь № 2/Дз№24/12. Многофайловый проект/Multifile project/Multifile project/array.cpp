#include "array.h"
using namespace std;
int rez()
{
	int kubik_1 = rand() % 6 + 1;
	bros(kubik_1);

	int kubik_2 = rand() % 6 + 1;
	bros(kubik_2);

	int rezult;
	rezult = kubik_1 + kubik_2;
	cout << "Result: " << rezult << "\n\n";

	return rezult;
}
void bros(int kubik)
{
	switch (kubik)
	{
	case 1:
		cout << "***********" << endl;
		cout << "*         *" << endl;
		cout << "*         *" << endl;
		cout << "*    *    *" << endl;
		cout << "*         *" << endl;
		cout << "*         *" << endl;
		cout << "***********" << endl;
		break;
	case 2:
		cout << "***********" << endl;
		cout << "*         *" << endl;
		cout << "*    *    *" << endl;
		cout << "*         *" << endl;
		cout << "*    *    *" << endl;
		cout << "*         *" << endl;
		cout << "***********" << endl;
		break;
	case 3:
		cout << "***********" << endl;
		cout << "*         *" << endl;
		cout << "*  *      *" << endl;
		cout << "*    *    *" << endl;
		cout << "*      *  *" << endl;
		cout << "*         *" << endl;
		cout << "***********" << endl;
		break;
	case 4:
		cout << "***********" << endl;
		cout << "*         *" << endl;
		cout << "*  *   *  *" << endl;
		cout << "*         *" << endl;
		cout << "*  *   *  *" << endl;
		cout << "*         *" << endl;
		cout << "***********" << endl;
		break;
	case 5:
		cout << "***********" << endl;
		cout << "*         *" << endl;
		cout << "*  *   *  *" << endl;
		cout << "*    *    *" << endl;
		cout << "*  *   *  *" << endl;
		cout << "*         *" << endl;
		cout << "***********" << endl;
		break;
	case 6:
		cout << "***********" << endl;
		cout << "*         *" << endl;
		cout << "*  *   *  *" << endl;
		cout << "*  *   *  *" << endl;
		cout << "*  *   *  *" << endl;
		cout << "*         *" << endl;
		cout << "***********" << endl;
		break;
	}
}
double gameproccess()
{
	char brosok;
	int total_chel = 0;
	int total_komp = 0;
	do
	{
		cout << "sequence of throwing\nPress button * to throw: \n" << endl;
		cin >> brosok;
	} while (brosok != '*');
	int rez_chel, rez_komp;
	do
	{
		rez_chel = rez();
		cout << "Your result: " << rez_chel << endl;

		cout << "Computer throw: " << endl;

		rez_komp = rez();
		cout << "Computer result: " << rez_komp << endl;
	} while (rez_chel == rez_komp);
	if (rez_chel > rez_komp)
	{
		cout << "You throw first= \n" << endl;
		for (int i = 1; i <= 5; i++)
		{
			do
			{
				cout << "Press button * to throw: \n" << endl;
				cin >> brosok;
			} while (brosok != '*');
			total_chel += rez();

			total_komp += rez();

		}
		cout << "Your all score= \n" << total_chel << endl;
		cout << "Computer all score= \n" << total_komp << endl;
	}
	else
	{
		cout << "Computer throw first: \n" << endl;
		for (int i = 1; i <= 5; i++)
		{
			total_komp += rez();

			do
			{
				cout << "Press button * to throw: \n" << endl;
				cin >> brosok;
			} while (brosok != '*');
			total_chel += rez();

		}
		cout << "Your all score= " << total_chel << endl;
		cout << "Computer all score= " << total_komp << endl;
	}

	if (total_chel == total_komp)
	{
		cout << "DRAW\n" << endl;
	}
	else
	{
		if (total_chel > total_komp)
		{
			cout << "You win\n" << endl;
		}

		if (total_chel < total_komp)
		{
			cout << "Computer win\n" << endl;
		}
	}
	return 0;
}