#pragma once
#include "BankInterface.h"
class Bank : public BankInterface
{
private:
	int balance = 0;
public:
	void Credit(int amount)
	{
		balance += amount;
	}
	bool Debit(int amount)
	{
		if (balance >= amount)
		{
			balance -= amount;
			return true;
		}
		return false;
	}
	int GetBalance()
	{
		return balance;
	}
};

