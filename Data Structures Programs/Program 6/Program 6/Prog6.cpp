/*--------------- P r o g 6 . c p p ---------------

by:   James Lynch
      16.322 Data Structures
      ECE Dept.
      UMASS Lowell

PURPOSE
Find the shortest path through a maze.

CHANGES
10-28-2016 gpc - Distribute to EECE322 class.
*/

#include <stdlib.h>
#include <iostream>

using namespace std;

#include "CursorCntl.h"
#include "Maze.h"

/*----- S o l v e (  ) -----

PURPOSE
Attempt to find the shortest path through the maze.

INPUT PARAMETERS
maze           -- the maze object to be traversed
positionQueue  -- the queue of current and future positions

RETURN VALUE
true  -- a path was found.
false -- failed to find a path.
*/
bool Solve(Maze &maze, Queue &positionQueue){
	Queue();
	positionQueue.EnQueue(maze.Start());//enqueue start to queue
	maze.Mark(positionQueue.Head(), 0);//mark the start with 0 dist
	int i = 0;
	Position Step[] = {StepEast,StepSouth,StepWest,StepNorth};//array of steps
	while (!positionQueue.Empty()){ 
		while (i<=3){//loops
			if (maze.State(positionQueue.Head()+Step[i]) == Open){//checks for open cells
				if (positionQueue.Head() + Step[i] == maze.Goal()){//checks if any neighbors are the goal
					return true;
				}
				//marks the open neighbor cell with dist from start
				maze.Mark(positionQueue.Head() + Step[i], maze.State(positionQueue.Head()) + 1);
				//Enqueue open neighbor
				positionQueue.EnQueue(positionQueue.Head() + Step[i]);
			}

			i++;//counter for index Step[]
		}
		if (positionQueue.Head() == positionQueue.Tail()){//when there is nowhere to go
			return false;//no path
		}
		i = 0;
		positionQueue.DeQueue();//Dequeue previous head
	}
	return false;//failsafe
}

/*----- R e t r a c e (  ) -----

PURPOSE
Mark the path from the goal to the start cell.

INPUT PARAMETERS
maze           -- the maze object to be marked
*/
void Retrace(Maze &maze)
{
	Position curPos = maze.Goal();//new current pos = goal
	int dist = maze.State(curPos);//dist from goal to start
	maze.Mark(curPos, PathCell);//marks goal cell P
	for (int i = -100; i < dist; i++){//loops until it is at start
		//searches in 4 directions and moves to open cell closest to start
		if (maze.State(curPos+StepEast) == dist-i){
			curPos = curPos + StepEast;
			maze.Mark(curPos, PathCell);
		}
		if (maze.State(curPos + StepSouth) == dist - i){
			curPos = curPos + StepSouth;
			maze.Mark(curPos, PathCell);
		}
		if (maze.State(curPos + StepWest) == dist - i){
			curPos = curPos + StepWest;
			maze.Mark(curPos, PathCell);
		}
		if (maze.State(curPos + StepNorth) == dist - i){
			curPos = curPos + StepNorth;
			maze.Mark(curPos, PathCell);
		}
		//if the next neighbor is the start mark it
		if (curPos + StepEast == maze.Start()){
			curPos = maze.Start();
			maze.Mark(curPos, PathCell);
		}
		if (curPos + StepSouth == maze.Start()){
			curPos = maze.Start();
			maze.Mark(curPos, PathCell);
		}
		if (curPos + StepWest == maze.Start()){
			curPos = maze.Start();
			maze.Mark(curPos, PathCell);
		}
		if (curPos + StepNorth == maze.Start()){
			curPos = maze.Start();
			maze.Mark(curPos, PathCell);
		}
	}

}

/*--------------- m a i n ( ) ---------------*/

int main()
{
	// Screen positions
	const unsigned XResult = 35;
	const unsigned YResult = 5;
	const unsigned XFinish = 0;
	const unsigned YFinish = 23;
       
	Maze  maze;				// Construct a maze from a maze definition file.
	Queue positionQueue;	// Create a queue of future positions to visit

	// Solve the maze.
	bool success = Solve(maze, positionQueue);

	// Indicate success or failure.
	gotoxy(XResult, YResult);
	if (!success)
		cout << "Failed: No path from start to goal exists." << endl;
	else
		{
		cout << "Success: Found the shortest path." << endl;
		gotoxy(XResult, YResult+2);
		cout << "Press ENTER to highlight the shortest path.";
		cin.get();
		// Retrace the path from the goal cell to the start cell.
		Retrace(maze);
		cout << endl;
		}
	// Done
	gotoxy(XFinish, YFinish);
	clreol();
	return 0;
}
