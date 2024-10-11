#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include "Bank.h"
using namespace std;
class MultiThreadedTransactions
{
public:
	int DoParallelTransactions(int nNumThreads, int nNumIterations, BankInterface & bankInterface)
	{
		double nBalance = 0;
		vector<thread>creditThreads(nNumThreads);
		vector<thread>debitThreads(nNumThreads );
		for (int i = 0; i < nNumThreads; ++i)
		{
			creditThreads[i] = std::thread([&, this] {
				for (int j = 0; j < nNumIterations; j++)
				{
					if (nBalance < 0)
					{
						break;
					}

					bankInterface.Credit(100);
				}
			});

		}
		for (auto & thread : creditThreads)
		{
			thread.join();
		}
		for (int i = 0; i < nNumThreads ; ++i)
		{
			debitThreads[i] = std::thread([&, this] {
				for (int j = 0; j < nNumIterations; j++)
				{
					bankInterface.Debit(200);
					nBalance = bankInterface.GetBalance();
					if (nBalance < 0)
					{
						break;
					}
				}
			});
		}
		for (auto & thread : debitThreads)
		{
			thread.join();
		}

		return bankInterface.GetBalance();

	}
};
