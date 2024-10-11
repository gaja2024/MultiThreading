// MultiThreadedStack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <chrono>
#include "StackImplWithLock.h"
#include "StackImplLockFree.h"
#include "StackDataProducerConsumer.h"
#include "PerformanceAnalyzer.h"
using namespace std;

double GetPerformanceData(StackDataProducerConsumer<int> &sp,
	const int nNumThreads, const int nNumIterations = 0)
{
	auto start = std::chrono::high_resolution_clock::now();
	nNumIterations ? sp.PushDataIntoStack(nNumThreads, nNumIterations) : sp.PopDataFromStack(nNumThreads);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
	return duration.count();
}
int main()
{
	StackImplWithLock<int> stackImplWithLock;
	StackDataProducerConsumer<int> spLock(&stackImplWithLock);
	StackImplLockFree<int> stackImplLockFree;
	StackDataProducerConsumer<int> spLockFree(&stackImplLockFree);
	int nNumThreads = 2;
	int nNumIterations = 1024*8;
	for (int i = 0; i < 10; ++i)
	{
		double spLockPerformanceData = GetPerformanceData(spLock, nNumThreads, nNumIterations);
		double spLockFreePerformanceData = GetPerformanceData(spLockFree, nNumThreads, nNumIterations);
		DoPerformanceAnalysis(nNumThreads, nNumIterations, spLockPerformanceData, spLockFreePerformanceData,"PerformaceAnalysis_PushData.txt");
		//spLock.Print();
		//spLockFree.Print();
		spLockPerformanceData = GetPerformanceData(spLock, nNumThreads);
		spLockFreePerformanceData = GetPerformanceData(spLockFree, nNumThreads);
		DoPerformanceAnalysis(nNumThreads, nNumIterations, spLockPerformanceData, spLockFreePerformanceData, "PerformaceAnalysis_PopData.txt");
		nNumThreads *= 2; 
		nNumIterations /= 2;
	}
	return 0;
}