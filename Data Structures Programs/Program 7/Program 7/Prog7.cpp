/*--------------- P r o g 7 . c p p ---------------

by:   James Lynch
      16.322 Data Structures
      ECE Dept.
      UMASS Lowell

PURPOSE
Find a path through a maze.

DEMOSTRATES
Recursion

CHANGES
10-19-2016 gpc - Distribute to 16.322 class.
10-20-2016 gpc - Install naive SolveMaze( ) function.
*/

#include <stdlib.h>
#include <iostream>

using namespace std;

#include "CursorCntl.h"
#include "Position.h"
#include "Maze.h"

bool GoalIsReachableFrom(Maze &maze, Position const &pos);
/*----- GoalIsReachableFrom(  ) -----

PURPOSE
Solve maze recursively

RETURN VALUE
true  -- a solution was found.
false -- failed to find a solution.
*/
bool GoalIsReachableFrom(Maze &maze, Position const &pos){
	if (!(maze.IsOpen(pos))){//Return false if pos not open
		return false;
	}
	maze.Visit(pos);//Current pos visited
	if (pos == maze.Goal()){//Checks for Goal
		cin.get();//Takes the "Enter" input
		maze.MarkPathCell(pos);//marks the path from goal to start
		return true;//complete
	}
	if ((GoalIsReachableFrom(maze, pos + StepEast))//Searches for goal from neighbors 
		|| (GoalIsReachableFrom(maze, pos + StepSouth)) 
		|| (GoalIsReachableFrom(maze, pos + StepWest)) 
		|| (GoalIsReachableFrom(maze, pos + StepNorth))){

		maze.MarkPathCell(pos);//marks current pos if leads to goal
		return true;
	}else {
		maze.Reject(pos);//rejects if not on path
	}
	return false;//executes if maze is not solvable
	
}



/*--------------- m a i n ( ) ---------------*/

int main(void)
{
	// Screen positions
	const unsigned XResult = 15;
	const unsigned YResult = 5;
	const unsigned XFinish = 0;
	const unsigned YFinish = 20;
	// Construct a maze from a maze definition file.
	Maze maze;     
	// Traverse the maze.
	bool success = GoalIsReachableFrom(maze, maze.Start());
	// Indicate success or failure.
	gotoxy(XResult, YResult);
	if (!success)
		cout << "Failed: No path from start to goal exists." << endl;
	else{
		cout << "Success: Found a path." << endl;
	}
			
	// Reset cursor location
	gotoxy(XFinish, YFinish);
}
