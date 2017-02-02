#include "Queue.h"
#include <cassert>
#include <iostream>

using namespace std;

void Queue::EnQueue(QueueElem &p){//Add new tail element
	Node *newNode = new(nothrow)Node(p);
	assert(newNode != 0);
	if (!Empty()){
		tail->succ = newNode;
		tail = newNode;
	}
	if (Empty()){
		head = newNode;
		tail = newNode;
	}
}
QueueElem Queue::DeQueue(){//Remove and return head element
	Node *temp = 0;
	assert(head != 0);
	temp = head;
	if (!Empty()){
		if (tail == head){//one entry
			return tail->data;
		}
		head = head->succ;
		delete(temp);
		return head->data;
	}
	if (Empty()){
		return temp->data;
	}
}
QueueElem Queue::Head(){//Return but don't remove head element
	assert(head != 0);
	return head->data;
}
