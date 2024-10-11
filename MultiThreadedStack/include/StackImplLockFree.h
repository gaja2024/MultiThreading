#pragma once
#include <atomic>
#include "StackInterface.h"
using namespace std;
template <typename T>
class StackImplLockFree : public StackInterface<T>
{
private:
	struct Node {
		T data;
		Node* next;
		Node(int const& _data) :data(_data), next(nullptr) {}
	};
	atomic<Node*> head = nullptr;
public:
	StackImplLockFree() {}
	void Push(const T& data)
	{
		Node* newNode = new Node(data);
		newNode->next = head.load();
		while (!head.compare_exchange_weak(newNode->next, newNode)) {
			// Retry until we successfully swap the head
		}
	}
	bool Pop(T& poppedData)
	{
		bool b = false;
		Node* oldHead = head.load();

		while (oldHead && !head.compare_exchange_weak(oldHead,
			oldHead->next)) {
			// Retry until we successfully swap the head
		}
		if (oldHead) {
			poppedData = oldHead->data;
			delete oldHead;
			b = true;
		}
		return b;
	}
	void PrintStackElements()
	{
		std::ofstream stackData("LockFreeData.txt", std::ios_base::app);
		Node* current = head.load();
		while (current != nullptr) {
			stackData << current->data << " ";
			current = current->next;
		}
		stackData << endl;
		stackData << endl;
	}
	~StackImplLockFree()
	{
		int dummy;
		while (Pop(dummy));
	}
};
