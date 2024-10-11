#pragma once
#include <vector>
#include <thread>
#include "StackInterface.h"
template <typename T>
class StackDataProducerConsumer
{
private:
	StackInterface<T>*m_pStackInterface = nullptr;
public:
	StackDataProducerConsumer(StackInterface<T>*pStackInterface) :m_pStackInterface(pStackInterface){}
	void PushDataIntoStack(int nNumThreads,int nNumIterations)
	{
		vector<thread>producerThread(nNumThreads);
		for (int i = 0; i < nNumThreads; ++i)
		{
			producerThread[i] = std::thread([= ,this] {
				for (int j = 0; j < nNumIterations; j++)
				{
					m_pStackInterface->Push((nNumIterations * i) + j + 1);
				}
			});
		}
		for (auto & thread : producerThread)
		{
			thread.join();
		}
	}
	void PopDataFromStack(int nNumThreads)
	{
		vector<thread>consumerThread(nNumThreads);
		for (int i = 0; i < nNumThreads; ++i)
		{
			consumerThread[i] = std::thread([this] {
				int value;
				while (m_pStackInterface->Pop(value));
			});
			
		}
		for (auto & thread : consumerThread)
		{
			thread.join();
		}
	}
	void Print()
	{
		m_pStackInterface->PrintStackElements();
	}

};

