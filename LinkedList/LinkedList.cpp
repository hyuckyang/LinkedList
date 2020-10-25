#include "LinkedList.h"
#include <stdio.h>

template <typename T>
LinkedData<T>::LinkedData(T data)
{
	pData = data;
	pHead = nullptr;
	pTail = nullptr;
}

/*
*  Data
*/
template <typename T>
bool LinkedData<T>::IsHead()
{
	return pHead == nullptr;
}

template <typename T>
bool LinkedData<T>::IsTail()
{
	return pTail == nullptr;
}

template <typename T>
LinkedData<T>* LinkedData<T>::GetHead()
{
	return pHead;
}

template <typename T>
LinkedData<T>* LinkedData<T>::GetTail()
{
	return pTail;
}

template <typename T>
T LinkedData<T>::GetData()
{
	return pData;
}

/*
* List
*/

template <typename T>
LinkedList<T>::LinkedList()
{
	pNode = nullptr;
}


template <typename T>
bool LinkedList<T>::Add(T data)
{
	// 
	// Try - Catch
	//

	auto processData = new LinkedData<T>(data);
	auto node = GetTail();

	if (node == nullptr)
	{
		pNode = processData;

	}
	else
	{
		node->SetTail(processData);
		processData->SetHead(node);
		pNode = processData;
	}

	count++;
	return false;
}



template <typename T>
bool LinkedList<T>::AddHead(T data)
{
	//
	// Try - Catch
	//

	auto processData = new LinkedData<T>(data);
	auto node = GetHead();

	if (node == nullptr)
	{
		pNode = processData;

	}
	else
	{
		node->SetHead(processData);
		processData->SetTail(node);
		pNode = processData;
	}

	count++;
	return false;
}


template <typename T>
bool LinkedList<T>::Insert(T data, unsigned int index)
{
	//
	// Try - Catch
	//

	if (pNode == nullptr && index == 0)
	{
		return Add(data);
	}

	auto processData = new LinkedData<T>(data);
	auto node = FindNode(index);

	if (node == nullptr)
	{
		if (index == count)
		{
			return Add(data);
		}
	}
	else
	{
		auto head = node->GetHead();

		if (head != nullptr)
		{
			head->SetTail(processData);
		}

		processData->SetHead(head);
		processData->SetTail(node);
		node->SetHead(processData);

		count++;

	}

	return true;
}


template <typename T>
bool LinkedList<T>::RemoveAt(unsigned index)
{
	auto node = FindNode(index);
	if (node == nullptr)
		return false;

	auto head = node->GetHead();
	auto tail = node->GetTail();

	if (head != nullptr)
	{
		head->SetTail(tail);
	}

	if (tail != nullptr)
	{
		tail->SetHead(head);
	}

	pNode = head ? head : tail;

	delete(node);
	count--;
	return true;
}



template <typename T>
LinkedData<T>* LinkedList<T>::GetHead()
{
	if (pNode == nullptr)
	{
		return pNode;
	}

	LinkedData<T>* temp = pNode;
	while (temp != nullptr)
	{
		if (temp->IsHead())
			break;

		temp = temp->GetHead();
	}

	return temp;
}


template <typename T>
LinkedData<T>* LinkedList<T>::GetTail()
{
	if (pNode == nullptr)
	{
		return pNode;
	}

	LinkedData<T>* temp = pNode;
	while (temp != nullptr)
	{
		if (temp->IsTail())
			break;

		temp = temp->GetTail();
	}
	return temp;
}


template <typename T>
LinkedData<T>* LinkedList<T>::FindNode(unsigned int index)
{
	if (index > count - 1)
	{
		// Try - Catch - Not Index
		return nullptr;
	}

	unsigned int findCount = 0;
	auto node = GetHead();

	while (true)
	{
		if (node == nullptr)
		{
			// Try - Catch
			return nullptr;
		}

		if (findCount > count - 1)
		{
			// Try - Catch - Failed Index
			return nullptr;
		}

		if (index == findCount)
		{
			break;
		}

		node = node->GetTail();
		findCount++;
	}

	return node;
}


template <typename T>
void LinkedList<T>::Print()
{

	printf("-----------------------------------------\n");

	LinkedData<T>* node = GetHead();
	int i = 0;

	while (node != nullptr)
	{
		i = i + 1;

		printf("index %d value %d  \n", i, (int)node->GetData());
		//printf("index %d   \n", i);
		node = node->GetTail();
	}

	printf("-----------------------------------------\n");
}