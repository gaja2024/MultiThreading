#pragma once
#include <mutex>
#include "BankInterface.h"
using namespace std;
class ThreadSafeBankUsingLock : public BankInterface
{
private:
	int balance = 0;
	mutex mtx;
public:
	void Credit(int amount)
	{
		lock_guard<mutex>lock(mtx);
		balance += amount;
	}
	bool Debit(int amount)
	{
		lock_guard<mutex>lock(mtx);
		if (balance >= amount)
		{
			balance -= amount;
			return true;
		}
		return false;

	}
	int GetBalance()
	{
		lock_guard<mutex>lock(mtx);
		return balance;
	}
};