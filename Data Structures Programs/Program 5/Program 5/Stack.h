#include "Position.h"
typedef Position StackElement;

class Stack{
	//stack node class defeinition
	struct Node{

		StackElement data;//The "contents" of the node
		Node *next;//Link to the next node
		//Node constructor functions
		Node(){}
		Node(const StackElement &theData, Node *const theNext = 0)
			:data(theData), next(theNext) { }
	};
public:
	//constructor
	Stack() : tos(0) {};
	//Return true if the stack is empty
	bool Empty() const { return tos == 0; }
	//Return the value of the top element on the stack
	StackElement Top() const;
	//Push a new element onto the stack
	void Push(const StackElement &p);
	//Pop the top elemenet from the stack
	StackElement Pop();

private:
	Node *tos;//pointer to the list node
};