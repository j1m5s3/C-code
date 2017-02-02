/*--------------- P r o g 4 . c p p ---------------

by:   James Lynch
      16.322 Data Structures
      ECE Dept.
      UMASS Lowell

PURPOSE
Find a path through a maze.

DEMOSTRATES
Stack as Linked List
Backtracking

CHANGES
10-19-2016 gpc - Distribute to 16.322 class.
10-20-2016 gpc - Install naive SolveMaze( ) function.
*/

#include <stdlib.h>
#include <iostream>

using namespace std;

#include "CursorCntl.h"
#include "Maze.h"
#include "Stack.h"

/*----- M a z e : : T r a v e r s e (  ) -----

PURPOSE
Naive maze traversal algorithm. Try all possible next
positions, but give up at a dead end..

RETURN VALUE
true  -- a solution was found.
false -- failed to find a solution.
*/

bool SolveMaze(Maze &maze, Stack &stack){
	
	Stack();//makes stack
	stack.Push(maze.Start());//pushes start on stack
	maze.Visit(stack.Top());//make the start cell visited
	Position pos = stack.Top();//position of current element

	do{
		if (stack.Top() == maze.Goal()){//checks if current element is at goal
			return true;
		}
		//if statements below check for open cells 360 deggress
		pos = stack.Top();
		if (maze.IsOpen(pos + StepEast)){
			stack.Push(pos + StepEast);
			maze.Visit(stack.Top());
		}else if (maze.IsOpen(pos+StepSouth)){
			stack.Push(pos+StepSouth);
			maze.Visit(stack.Top());
		}else if (maze.IsOpen(pos+StepWest)){
			stack.Push(pos+StepWest);
			maze.Visit(stack.Top());
		}else if (maze.IsOpen(pos + StepNorth)){
			stack.Push(pos+StepNorth);
			maze.Visit(stack.Top());
		}else{//if there is nowhere to go the program will go back 
			maze.Reject(stack.Top());//rejects blocked path
			stack.Pop();//pops it off
			if (stack.Empty()){//if the stack is empty return
				return false;
			}
		}
	} while (!stack.Empty());
	return false;//failsafe
}


/*--------------- m a i n ( ) ---------------*/

int main(void)
{
	// Screen positions
	const unsigned XResult = 15;
	const unsigned YResult = 5;
	const unsigned XFinish = 0;
	const unsigned YFinish = 20;

	// Position stack remembers visited positions.
	Stack posStack;   

	// Construct a maze from a maze definition file.
	Maze maze;     
   
	// Traverse the maze.
	bool success = SolveMaze(maze, posStack);
	// Indicate success or failure.
	gotoxy(XResult, YResult);
	if (!success)
		cout << "Failed: No path from start to goal exists." << endl;
	else
		{
		cout << "Success: Found a path." << endl;
			
		cin.get();  // Wait for a key press.
			
   // Retrace the path back to the goal.
		while (!posStack.Empty())
			maze.MarkPathCell(posStack.Pop());
			}
	// Done
	gotoxy(XFinish, YFinish);

   return 0;
}
