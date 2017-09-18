#pragma once
#include <iostream>
using namespace std;
typedef unsigned int ui;
class Account
{
private:
	char * ID;
	char * Name;
	ui Balance;
	ui Max;
public:
	Account(void);
	Account(char* id, char* name = "", ui balance = 0);
	void	setID(char*);
	char*   getID();
	void	setName(char*);
	char*   getName();
	ui		getBalance();
	void    setBalance(ui);
	virtual void AddBalance(ui);
	virtual void TakeMoney(ui);
	Account MAX(Account&);
	~Account() = default;
};
class ExtraAccount : public Account
{
private :
	const int Over;
	double doubt;
public:
	ExtraAccount() : doubt(0), Over(20000), Account(){};
	ExtraAccount(char * id, char * name, ui balance) : Account(id, name, balance), Over(20000), doubt(0){};
	virtual void TakeMoney(ui Sum) override
	{
		if (doubt > 0.0)
		{
			return;
		}
		if (Sum < Account::getBalance())
		{
			Account::TakeMoney(Sum);
			return;
		}
		if (Sum - Account::getBalance() <= Over)
		{
			doubt = Sum - Account::getBalance() + ((Sum - Account::getBalance()) * 0.15);
			Account::setBalance(0);
			return;
		}
		return;
	}
	virtual void AddBalance(ui Sum) override
	{
		if (doubt == 0)
		{
			Account::AddBalance(Sum);
			return;
		}
		else
		{
			if (Sum < doubt)
			{
				doubt -= Sum;
				return;
			}
			else
			{
				Account::setBalance(Sum - doubt);
				doubt = 0;
			}
		}
	}
	friend ostream& operator << (ostream & os, ExtraAccount & ex)
	{
		os << "Баланс: " << ex.getBalance() << endl;
		os << "Долг: " << ex.doubt << endl;
		return os;
	}
};