#include "LinkedList.h"
#include <iostream>
#include <cassert>

using namespace std;

LinkedList::LinkedList(){
	//in an empty list, first, current, and pred will be in these states
	first = 0;
	current = first;
	pred = 0;
}

bool LinkedList::Empty() const{

	return first == 0;//if list is empty, first will equal 0
}

bool LinkedList::AtEnd() const{

	return current == 0;//if list at end, current will equal 0
}

void LinkedList::Skip(){

	assert(!AtEnd());//check if current entry exists
	pred = current;//the pred becomes the current
	current = current->next;//the current becomes the next, to the pred
}
NodeData LinkedList::CurrentEntry() const{

	assert(!AtEnd());//checks if current exists
	return current->data;//returns pointer to data
}

void LinkedList::Insert(const NodeData &d){

	Node* newNode = new(nothrow)Node(d);//makes new node
	assert(newNode != 0);//checks if memory is allocated 

	if (current == first){//insert at beginning or in to an empty list
		newNode->next = first;//newNode is the next node, which will be the first in the list
		first = newNode;//newNode is now the first in the list
		pred = newNode;//the pred is now the newNode because the list is empty and newNode is the first
	}
	else{//inserts at middle or at end
		newNode->next = current;//pointer to current
		pred->next = newNode;//points pred pointer to the new node
		pred = newNode;//the pred to current is now newNode
	}
}

void LinkedList::Delete(){

	assert(!AtEnd());//Checks if current entry exists

	if (pred == 0){
		first = current->next;//the first node becomes the next of current
		delete(current);//now current is the first in the list and is deleted
		current = first;//current becomes the new first node in the list
	} 
	else{
		pred->next = current->next;//the pointer to the next of pred is equal to what current pointed to
		delete(current);//deletes the current node
		current = pred->next;//current becomes the next to pred
	}
}

