#include <cassert>
#include <iostream>
#include "Stack.h"

using namespace std;

//Return the value of the top element on the stack
StackElement Stack::Top() const{
	assert(tos != 0);
	return tos->data;
}
//Push a new element onto the stack
void Stack::Push(const StackElement &p){
//(create new node and link it in)
	Node* newNode = new(nothrow)Node(p);//creates newNode
	assert(newNode != 0);
	newNode->data = p;//takes position data
	newNode->next = tos;
	tos = newNode;
}
//Pop the top elemenet from the stack
StackElement Stack::Pop(){
//(Retrieve the positon from the top of the stack and pops it off)
	Node *temp;//create variable to store tos
	assert(tos != 0);
	temp = tos;//tos stored in temp
	tos = tos->next;//tos is relinked
	if (Empty()){//to ensure pop will return the last tos
		return temp->data;
	}
	delete(temp);
	return tos->data;//returns data in tos
}