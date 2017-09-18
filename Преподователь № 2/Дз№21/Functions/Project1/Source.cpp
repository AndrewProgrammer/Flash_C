#include <iostream>
using namespace std;

void Hello();
void Star(int count);
void StarEx(int count, char symb);
int MyPow(int number, int st);
int Ted(int value);
int summa(int mas[], int size);

void main()
{
	const int count = 10;
	int ar[count] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	cout << summa(ar, count) << endl << endl;




	int value = 20;			// value1
	cout << value;			// value1
	value += Ted(value);		// value1
	cout << value;			// value1

	int a = MyPow(2, 3);
	cout << " ---- " << a << " ---- " << endl;

	cout << " ---- " << MyPow(2, 3) << " ---- " << endl;


	StarEx(20, 177);
	Hello();
	Hello();
	Hello();
	Star(15);

	for (int i = 0; i < 10; i++)
	{
		Star(i);
	}
	system("pause");
}


void Hello()
{
	cout << "Hello world" << endl;
}

void Star(int count)
{
	for (int i = 0; i < count; i++)
		cout << "*";
	cout << endl;
}


int MyPow(int number, int st)
{
	int res = 1;
	for (int i = 0; i < st; i++)
		res *= number;
	return res;
}

int Ted(int value)	// value2
{
	return ++value;	// value2
}
