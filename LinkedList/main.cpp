#include <iostream>
#include "LinkedList.h"
#include "LinkedList.cpp"

int main(int argc, char* argv[])
{
	auto* l = new LinkedList<int>();

	l->Add(0);
	l->Add(1);
	l->Add(2);
	l->RemoveAt(0);
	l->RemoveAt(0);
	l->Print();
}