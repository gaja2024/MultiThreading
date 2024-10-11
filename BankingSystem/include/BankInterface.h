#pragma once
class BankInterface
{
public:
	virtual void Credit(int amount) = 0;
	virtual bool Debit(int amount) = 0;
	virtual int  GetBalance() = 0;
};
