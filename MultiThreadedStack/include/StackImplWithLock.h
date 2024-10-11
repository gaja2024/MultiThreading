#pragma once
#include <mutex>
#include "StackInterface.h"
using namespace std;
template <typename T>
class StackImplWithLock : public StackInterface<T>
{
private:
	struct Node {
		T data;
		Node* next;
		Node(T const& _data) :data(_data), next(nullptr) {}
	};
	Node* head = nullptr;
	mutex mtx;
public:
	StackImplWithLock() {}
	void Push(const T& data)
	{
		mtx.lock();
		Node* newNode = new Node(data);
		newNode->next = head;
		head = newNode;
		mtx.unlock();
	}
	bool Pop(T& poppedData)
	{
		mtx.lock();
		bool b = false;
		Node*prevHead = head;
		if (prevHead)
		{
			poppedData = prevHead->data;
			head = head->next;
			delete prevHead;
			b = true;
		}
		mtx.unlock();
		return b;
	}
	void PrintStackElements()
	{
		std::ofstream stackData("LockData.txt", std::ios_base::app);
		Node* current = head;
		while (current != nullptr) {
			stackData << current->data << " ";
			current = current->next;
		}
		stackData << endl;
		stackData << endl;
	}
	~StackImplWithLock()
	{
		T dummy;
		while (Pop(dummy));
	}
};
