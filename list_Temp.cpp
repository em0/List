
#include "stdafx.h"
#include "list_Temp.h"


#include <exception>
#include <iostream>


using namespace std;

//class ListNodeClass
//   {
//   private:
//      ItemType Info;
//      ListNodePtr Next;
//   public:
//      // First, the constructor:
//      ListNodeClass(const ItemType & Item, ListNodePtr NextPtr = NULL):
//         Info(Item), Next(NextPtr) {};
//      void GetInfo(ItemType & TheInfo) const;			//ok
//   friend class ListClass;   // very convenient to allow this
//   };

void ListNodeClass::GetInfo(ItemType & TheInfo) const{
	TheInfo = Info;
}

ListNodePtr ListClass::GetNode(const ItemType & Item, ListNodePtr NextPtr){// ok
	try{
		 return new ListNodeClass(Item,NextPtr);
	}
	/*catch(exception &e){
		cout<<"Error:"<<e.what();
	}*/
	catch (const std::bad_alloc&) {
		return NULL;
	}

	/*ListNodePtr pt = new (nothrow) ListNodeClass(Item,NextPtr);
	if (pt == NULL){
		cerr << "Memory allocation error!" << endl;
		exit(1);
	}
	return pt;*/
 }

ListClass::ListClass(void){		// ok
	Count = 0;
	ItemType i;
	Front = GetNode(i);
	Rear = Front;
}

void ListClass::FreeNode(ListNodePtr NodePtr){
	delete(NodePtr);	
}

void ListClass::ClearList(void){
	ListNodePtr step = Front -> Next, prev;
	for(; step != NULL; ){
		prev = step;
		step = step -> Next;
		delete(prev);
	}
	Front->Next = NULL;
	Rear = Front;
	Count = 0;
}

ListClass::~ListClass(void){
	ClearList();
	FreeNode(Front);
}

int ListClass::NumItems(void) const{
	return Count;
}

bool ListClass::Empty(void) const{
	return Front == Rear;
}

void ListClass::InsertFront(const ItemType & Item){
	ListNodePtr pt = GetNode(Item,Front->Next);
	Front->Next = pt;
	if(Count == 0) 
		Rear = pt;
	Count++;
}

void ListClass::InsertRear(const ItemType & Item){
	ListNodePtr pt = GetNode(Item);
	Rear -> Next = pt;
	Rear = pt;
	Count++;
}

void ListClass::InsertInOrder(const ItemType & Item){
	ListNodePtr step = Front;
	while(step->Next != NULL && step->Next->Info < Item){
		step = step->Next;
	}
	ListNodePtr pt = GetNode(Item,step->Next);
	if(step->Next == NULL) Rear = pt;
	step->Next = pt;
	Count++;
}

 ItemType ListClass::RemoveFront(void){
	 if(!Count) {
		 cerr<< "There is nothing to be removed! " << endl;
		 exit(1);
	 }
	 ListNodePtr pt = Front -> Next;
	 Front -> Next = Front -> Next ->Next;
	 ItemType item;
	 pt->GetInfo(item);
	 FreeNode(pt);
	 Count --;
	 if(Count == 0) 
		 Rear = Front;
	 return item;
 }

 ListNodePtr ListClass::Find(const ItemType & Item) const{
	 ListNodePtr step = Front->Next;
	 while(step != NULL && step->Info != Item){
		 step = step->Next;
	 }
	 if(step->Info == Item)
		 return step;
	 else 
		 return NULL;
 }

 void ListClass::PrintList() const{
	 ListNodePtr step = Front->Next;
	 while(step != NULL){
		 cout << step->Info << " ";
		 step = step -> Next;
	 }
	 cout << endl;
 }

//class ListClass
//   {
//   private:
//      ListNodePtr GetNode(const ItemType & Item,	//ok
//         ListNodePtr NextPtr = NULL);
//      void FreeNode(ListNodePtr NodePtr);		// ok
//      void ClearList(void);					// ok
//      // Next 3 are sometimes made into protected fields:
//      ListNodePtr Front, Rear;
//      int Count;
//   public:
//      //  constructor:
//      ListClass(void);						// ok
//      //  destructor:
//      ~ListClass(void);						// ok
//      int NumItems(void) const;				// ok
//      bool Empty(void) const;					// ok
//      void InsertFront(const ItemType & Item);// ok
//      void InsertRear(const ItemType & Item); // ok
//      void InsertInOrder(const ItemType & Item);	// ok
//      ItemType RemoveFront(void);				//ok
//      ListNodePtr Find(const ItemType & Item) const;
//   };


