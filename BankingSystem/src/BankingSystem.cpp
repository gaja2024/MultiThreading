// BankingSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MultiThreadedTransactions.h"
#include "ThreadSafeBankLockFree.h"
#include "Bank.h"
#include "ThreadSafeBankUsingLock.h"
#include "PerformanceAnalyser.h"
double GetPerformanceData(BankInterface& bankInterface,	const int nNumThreads, const int nNumIterations)
{
	MultiThreadedTransactions multiThreadedTransaction;
	auto start = std::chrono::high_resolution_clock::now();
	int nBalance = multiThreadedTransaction.DoParallelTransactions(nNumThreads, nNumIterations, bankInterface);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
	if (nBalance < 0)
	{
		cout << "negative balance found" << endl;
		cout << "balance is: " << nBalance << endl;
	}
	return duration.count();
}
void PerformBankTransactions(BankInterface& bankInterface)
{
	for (int i = 0; i < 10000; ++i)
	{
		MultiThreadedTransactions multiThreadedTransaction;
		int nBalance = multiThreadedTransaction.DoParallelTransactions(16, 10, bankInterface);
		if (nBalance < 0)
		{
			cout << "negative balance after " << i << " iterations" << endl;
			cout << "balance is: " << nBalance << endl;
			break;
		}
	}
}
void PerformSafeBankTransactions()
{
	int nNumThreads = 2;
	int nNumIterations = 1024 * 8;
	for (int i = 0; i < 10; ++i)
	{
		ThreadSafeBankUsingLock threadSafeBankUsingLock;
		double performanceDataWithLock =  GetPerformanceData(threadSafeBankUsingLock, nNumThreads, nNumIterations);
		ThreadSafeBankLockFree threadSafeBankLockFree;
		double performanceDataLockFree = GetPerformanceData(threadSafeBankLockFree, nNumThreads, nNumIterations);
		DoPerformanceAnalysis(nNumThreads, nNumIterations, performanceDataWithLock, performanceDataLockFree);
		nNumThreads *= 2;
		nNumIterations /= 2;
	}
}
int main()
{
	Bank bank;
	PerformBankTransactions(bank);
	PerformSafeBankTransactions();
}

