#include "Account.h"
#include <iostream>
using namespace std;
void main()
{
	setlocale(0, "ru");
	ExtraAccount ea("14255", "Denis", 1000);
	Account a("14254325", "Alex", 1000);
	Account ** pa = new Account*[2];
	pa[0] = &ea;
	pa[1] = &a;
	pa[0]->TakeMoney(5000);//с виртуалом 0(БЕЗ 1000)
	pa[1]->TakeMoney(5000);//с виртуалом 1000(БЕЗ 1000)
	cout << pa[0]->getBalance() << endl;//с виртуалом 0(БЕЗ 1000)
	cout << pa[1]->getBalance();//с виртуалом 1000(БЕЗ 1000)

}