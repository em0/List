#ifndef LIST_TEMP_H
#define LIST_TEMP_H


class ListNodeClass;

typedef ListNodeClass* ListNodePtr;
typedef float ItemType;

class ListNodeClass
   {
   private:
      ItemType Info;
      ListNodePtr Next;
   public:
      // First, the constructor:
      ListNodeClass(const ItemType & Item, ListNodePtr NextPtr = NULL):
         Info(Item), Next(NextPtr) {};
      void GetInfo(ItemType & TheInfo) const;
   friend class ListClass;   // very convenient to allow this
   };



class ListClass
   {
   private:
      ListNodePtr GetNode(const ItemType & Item, ListNodePtr NextPtr = NULL);
      void FreeNode(ListNodePtr NodePtr);
      void ClearList(void);
      // Next 3 are sometimes made into protected fields:
      ListNodePtr Front, Rear;
      int Count;
   public:
      //  constructor:
      ListClass(void);
      //  destructor:
      ~ListClass(void);
      int NumItems(void) const;
      bool Empty(void) const;
      void InsertFront(const ItemType & Item);
      void InsertRear(const ItemType & Item);
      void InsertInOrder(const ItemType & Item);
      ItemType RemoveFront(void);
      ListNodePtr Find(const ItemType & Item) const;
	  void PrintList() const;
   };

#endif
