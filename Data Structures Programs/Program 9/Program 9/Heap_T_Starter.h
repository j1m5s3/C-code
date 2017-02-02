#ifndef HEAP_H
#define HEAP_H
/*--------------- H e a p _ T . h ---------------

by:   George Cheney
EECE322 Data Structures
ECE Department
UMASS Lowell

PURPOSE
Implements standard heap operations including Heap Sort.

DEMONSTRATES
Heaps and Heap Sort

CHANGES
11-19-2016 gpc - Created for EECE322
*/

#include <iostream>

#include <cassert>
#include "CursorCntl.h"
template <typename ElemData, unsigned Capacity>
class Heap
{
public:
	// Constructor
	Heap() : size(0), current(0) { }
	// Return the number of elements in the array.
	unsigned Size() { return size; }
	// Return true if the array is empty.
	bool Empty() { return size == 0; }
	// Return true if the array is full.
	bool Full() { return size >= Capacity; }
	// Insert a new element into the array properly stored in ascending order..
	void Insert(ElemData &data);
	// Perform Heap Sort to sort the array into ascending order.
	void Sort();
	// Call "BinSearch()" to search the sorted array for the entry "data". 
	// If found, make this the current entry and return true;
	// otherwise, return false.
	bool Search(ElemData &data);
	// Output the array to the stream "os".
	void Output(ostream &os);
	// Show the heap on the right side of the screen.
	void ShowTree() const;
	// Return the current entry.
	ElemData &CurrentEntry() { return heap[current]; }

	// Standard heap operations
	void PercolateUp();
	void DeleteMax();
	void PercolateDown(unsigned r, unsigned n);
	void Heapify();

private:
	unsigned size;				// The number of items in the heap
	unsigned current;			// The index of the entry found by the last search
	ElemData heap[Capacity+1];	// The heap array

	// Perform a binary search for "data". Search the index range from
	// "start" to "end". If the item is found, make it the current item and return true.
	// Otherwise, return false.
	bool BinSearch(unsigned start, unsigned end, ElemData &data);

	// Recursive function to show the tree graphics
	void RShowTree(unsigned r, int x, int y) const;
};

const unsigned XRoot = 40;        // Column number for root node

/*--------------- R S h o w T r e e ( ) ---------------

PURPOSE
Recursive function to display a tree on the right half of the screen
using (crude) character graphics.

INPUT PARAMETERS
r         -- the root of the sub-tree to display
x         -- the cursor x coordinate index
y         -- the cursor y coordinate
*/
template <typename ElemData, unsigned Capacity>
void Heap<ElemData, Capacity>::RShowTree(unsigned r, int x, int y) const
{
  const unsigned VertSpacing = 7;   // Vertical spacing constant
  const unsigned HorizSpacing = 10; // Horizontal spacing of tree nodes
  const unsigned MaxLevels = 4;     // The number of levels that fit on the screen

  // If the tree is not empty display it..
  if (r <= size && x < MaxLevels)
    {
    // Show the left sub-tree.
    RShowTree(2*r, x+1, y+VertSpacing/(1<<x));

    // Show the root.
    gotoxy(XRoot+HorizSpacing*x, y);

	ElemData wc = heap[r];

	wc.Show(cout);

    // Show the right subtree.
    RShowTree(2*r+1, x+1, y-VertSpacing/(1<<x));
    }
}

/*--------------- S h o w T r e e ( ) ---------------

PURPOSE
Display a tree on the right half of the screen using (crude)
character graphics.This function calls RShowTree() which does
the work.
*/
template <typename ElemData, unsigned Capacity>
void Heap<ElemData, Capacity>::ShowTree() const
{
  const unsigned YRoot = 12;      // Line number of root node
  const unsigned ScrollsAt = 24;  // Screen scrolls after line 24

#if (defined _WIN32) && (!defined NoGraphics)

  int xOld;                       // Old cursor x coordinate
  int yOld;                       // Old cursor y coordinate

  // Save cursor position
  getxy(xOld, yOld);

  // Has the screen scrolled yet?
  int deltaY = 0;

  if (yOld > ScrollsAt)
    deltaY = yOld - ScrollsAt+1;

  // Clear the right half of the screen.
  for (int y=0; y<ScrollsAt+1; y++)
    {
    gotoxy(XRoot,y+deltaY);
    clreol();
    }

  // Show the tree and offset if scrolled.
  RShowTree(1, 0, YRoot+deltaY);   

  // Restore old cursor position.
  gotoxy(xOld,yOld);      
#endif
}

// M I S S I N G    M E M B E R    F U N C T I O N S    G O    H E R E

#endif