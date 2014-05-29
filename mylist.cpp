

#include "stdafx.h"
#include "mylist.h"



#include <iostream>
#include <exception>

using namespace std;


template <class Type>
typename mylist<Type>::NodePtr mylist<Type>::newNode(const Type &T){
// meaning: mylist<Type>::NodePtr is a type!!
	try{
		NodePtr np = new Node<Type>(T);
		return np;
	}
	catch(exception &e){
		cout<<"Standard exeption:"<<e.what();
		return NULL;
	}
}


template <class Type>
void mylist<Type>::addToEnd(Type &rhs){ // add node to the end
	NodePtr next = head, prev = head;
	while(next != NULL){
		prev = next;
		next = prev->nextItem;
	}
	prev->nextItem = newNode(rhs);
	if(prev->nextItem != NULL) length ++;
}

template <class Type>
void mylist<Type>::addToEnd(Type rhs){ // add node to the end
	if(head == NULL){
		head = newNode(rhs);
		return;
	}
	NodePtr next = head, prev = head;
	while(next != NULL){
		prev = next;
		next = prev->nextItem;
	}
	NodePtr np = newNode(rhs);
	prev->nextItem = np;
	if(np != NULL) length ++;
}

template <class Type>
bool mylist<Type>::addNode(const Type &rhs, NodePtr parent){ // add node after parent element
	if(parent == NULL){
		cout<<"There is no parent for node:"<<rhs<<endl;
		return false;
	}
	NodePtr np = newNode(rhs);
	np->nextItem = parent->nextItem;
	parent->nextItem = np;
	return true;
}

template <class Type>
void mylist<Type>::print() const{
	NodePtr step = head;
	while(step != NULL){
		cout<<step->Item<<" ";
		step = step->nextItem;
	}
	cout<<endl;
}

template <class Type>
bool mylist<Type>::listFromArray(Type v[], const unsigned int size){
	NodePtr prev = head, step = head;
	while(step != NULL){
		prev = step;
		step = step->nextItem;
	}

	int i = 1;
	step = newNode(v[0]);
	NodePtr prev2 = step, head2 = step;

	while(step != NULL && i<size){
		//prev2 = step;
		length ++;
		step = newNode(v[i]);
		prev2 -> nextItem = step;
		prev2 = prev2->nextItem;
		i++;
	}

	if(step == NULL) // no more space
		return false;
	else{ 
		if(prev == NULL) // this must be the head
			head = head2;
		else
			prev->nextItem = head2;
	}
}

template <class Type>
Type mylist<Type>::deleteNode(Type node){
	NodePtr step = head;
	if(head->Item == node){// when is the head we need to make it differently
		head = head->nextItem;
		delete(step);
		return node;
	}
	NodePtr prev = NULL;
	while(step->Item != node && step->nextItem != NULL){// go till you find the end or the searched element
		prev = step;
		step = step->nextItem;
	}
	if(step->Item == node){// the searched element
		prev->nextItem = step->nextItem;
		delete(step);
		return node;
	}
	return NULL;
}
template <class Type>
void mylist<Type>::reversList(){
	NodePtr prev = NULL,next = head->nextItem,act = head;
	while(act != NULL){
		next = act->nextItem;
		act->nextItem = prev;
		prev = act;
		act = next;
	}
	head = prev;
}

// Explicit template instantiation
template class mylist<int>;