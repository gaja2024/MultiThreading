#pragma once
#include <atomic>
#include "BankInterface.h"
using namespace std;
class ThreadSafeBankLockFree : public BankInterface
{
private:
	atomic<int>balance = 0;
public:
	void Credit(int amount)
	{
		balance += amount;
	}
	bool Debit(int amount)
	{
		int currentBalance = balance.load();
		while (currentBalance >= amount) {
			if (balance.compare_exchange_weak(currentBalance, currentBalance - amount)) {
				return true;
			}
		}
		return false;

	}
	int GetBalance()
	{
		return balance.load();
	}
};
