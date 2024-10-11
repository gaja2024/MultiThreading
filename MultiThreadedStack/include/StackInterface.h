#pragma once
#include <fstream>
template <typename T>
class StackInterface
{
public:
	virtual void Push(const T& data) = 0;
	virtual bool Pop(T& poppedData) = 0;
	virtual ~StackInterface() {};
	virtual void PrintStackElements() = 0;
};
