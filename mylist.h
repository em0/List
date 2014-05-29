#ifndef MYLIST_H 
#define MYLIST_H





template <class Type>
class mylist;

template <class Type>
class Node{
	Type Item;
	typedef Node<Type>* NodePtr;
	NodePtr nextItem;
	Node(const Type &rhs=0, const NodePtr nextPtr = NULL): Item(rhs), nextItem(nextPtr){};
	bool changeItemValue(const Type &rhs){
		Item = rhs;
		return true;
	}
	friend class mylist<Type>;
};


template <class Type>
class mylist{
public:
	typedef Node<Type>* NodePtr;						//ok
	mylist(const NodePtr start = NULL): head(start){};	//ok
	bool addNode(const Type &rhs, NodePtr parent);		//ok
	void addToEnd(Type &rhs);							//ok
	void addToEnd(Type rhs);							//ok
	bool listFromArray(Type v[], const unsigned int size);	//ok
	Type deleteNode(Type node);							// ok
	void reversList();									// ok
	void print() const;									//ok
	~mylist(){											// OK
		NodePtr next = head;
		while(head != NULL){
			next = head->nextItem;
			delete(head);
			head = next;
		}
		head = NULL;
	}
private:
	NodePtr head;
	unsigned int length;
	NodePtr newNode(const Type &T);
};

#endif