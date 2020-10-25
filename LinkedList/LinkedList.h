#pragma once
template <typename T>
class LinkedData
{
	T pData;
	LinkedData<T>* pHead;
	LinkedData<T>* pTail;
public:
	LinkedData(T data);
	~LinkedData() {}
	bool IsHead();
	bool IsTail();

	T GetData();
	LinkedData<T>* GetHead();
	LinkedData<T>* GetTail();

	void SetHead(LinkedData* head) { pHead = head; }
	void SetTail(LinkedData* tail) { pTail = tail; }
};

template <typename T>
class LinkedList
{
private:
	LinkedData<T>* pNode;
	unsigned int count = 0;

private:
	LinkedData<T>* GetHead();
	LinkedData<T>* GetTail();
	LinkedData<T>* FindNode(unsigned int index);


public:
	LinkedList();
	~LinkedList() {}

	bool Add(T data);
	bool AddHead(T data);
	bool Insert(T data, unsigned int index);

	bool Remove(LinkedData<T>* data);
	bool RemoveAt(unsigned int index);

	unsigned int GetCount() { return count; }
	void Print();
};



