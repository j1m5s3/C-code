#ifndef QUEUE_HEADER
#define QUEUE_HEADER
#include "Position.h"

typedef Position QueueElem;

class Queue {

private:
	//List node class definition
	struct Node{
		QueueElem data;//The "contents" of the node
		Node *succ;//Link to the successor node

		Node() : succ(0) {}
		Node(const QueueElem &theData) :data(theData), succ(0) {}
	};

public:
	Queue() : head(0), tail(0) {}//Default constructor
	bool Empty() const { return head == 0; }//Returns true if empty
	void EnQueue(QueueElem &p);//Add new tail element
	QueueElem DeQueue();//Remove and return head element
	QueueElem Head();//Return but don't remove head element
	QueueElem Tail() {return tail->data; }//Returns tail element

private:
	Node *head;//Points to head node
	Node *tail;//Points to tail node
};
#endif



