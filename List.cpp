// List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "mylist.h"

int _tmain(int argc, _TCHAR* argv[])
{
	mylist<int> list2;
	list2.addToEnd(1);
	list2.addToEnd(2);
	list2.addToEnd(3);
	list2.print();
	list2.deleteNode(2);
	list2.print();
	list2.deleteNode(1);
	list2.print();
	list2.deleteNode(3);
	list2.print();
	int v[]={4,5,6};
	list2.listFromArray(v,3);
	list2.print();
	list2.reversList();
	list2.print();
	return 0;
}

