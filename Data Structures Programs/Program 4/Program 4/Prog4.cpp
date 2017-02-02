/*--------------- P r o g 4 . c p p ---------------

by:   James Lynch
      16.322 Data Structures
      ECE Department
      UMASS Lowell

PURPOSE
This is an interactive polygon statistics program. A polygon may be entered from either the keyboard.
Then, upon command, the program will display the circumference and area of
the polygon.

DEMONSTRATES
Singly Linked Lists

CHANGES
10-02-2016 gpc -  Created for 16.322
10-12-2016 GPC -  Corrected to omit missing Point module operations                 
*/

#include <iostream>
#include <cmath>

using namespace std;

#include "Point.h"
#include "LinkedList.h"

//----- c o n s t a n t    d e f i n i t i o n s -----

// Command prompt
const char CmdPrompt[] = "\n>";

// Command Letters
const char AreaCmd =    'A';  // Compute and display the area of the polygon
                              // and its triangles.
const char CircumCmd =  'C';  // Compute and display the circumference of the polygon.
const char DeleteCmd =  'D';  // Delete the current point from the polygon.
const char EraseCmd =   'E';  // Make the polygon empty
const char ForwardCmd = 'F';  // Move the current entry forward one step.
const char InsertCmd =  'I';  // Insert a new point in the polygon.
const char PrintCmd =   'P';  // Show the polygon on the display.
const char QuitCmd =    'Q';  // Quit
const char RewindCmd =  'R';  // Rewind the polygon to the first point.
const char SearchCmd =  'S';  // Find the next entry with a given x coordinate.
const char UpdateCmd =  'U';  // Update the current entry

const unsigned MinPolySides = 3;	// A polygon must have at least 3 sides.

//----- f u n c t i o n    p r o t o t y p e s -----

char GetCmd(LinkedList &polygon);
void InsertPoints(LinkedList &polygon);
void ClearPolygon(LinkedList &polygon);
void DisplayPolygon(LinkedList &polygon);
void ShowArea(LinkedList &polygon);
void ShowCircum(LinkedList &polygon);
bool ValidPoly(LinkedList &polygon);
void UpdateEntry(LinkedList &polygon);
void Search(LinkedList &polygon);

//--------------- m a i n ( ) ---------------

int main()
{
   LinkedList  polygon;  // The polygon list
   char cmd;             // The command letter
   // Repeatedly read a command from the keyboard and execute it.
   for (;;)
      {
      cmd = GetCmd(polygon); // Get the command letter.                    
      // If not empty command, execute it.
      if (cmd != ' ')
         {
         switch (toupper(cmd))
            {
            case AreaCmd: // Display the areas.
               ShowArea(polygon);
               break;
            case CircumCmd: // Display the circumference.
               ShowCircum(polygon);
               break;
            case UpdateCmd: // Update the current entry.
	            UpdateEntry(polygon);
	            break;
            case InsertCmd:// Insert a new point.
               InsertPoints(polygon);
               break;
            case EraseCmd: // Clear the entire polygon.
               ClearPolygon(polygon);
               break;
            case DeleteCmd: // Delete the current point.
               if (!polygon.AtEnd())
                  polygon.Delete();
               if (polygon.Empty())
                  cout << "The polygon is empty." << endl;
               break;
            case PrintCmd: // Display the polygon.
               DisplayPolygon(polygon);
               break;
            case ForwardCmd: // Advance to the next point.
               if (!polygon.AtEnd())
                  polygon.Skip();
               if (polygon.AtEnd())
                  cout << "The polygon is at the end." << endl;
               break;
            case RewindCmd: // ewind making the first point current.
               polygon.Rewind();
               break;
            case SearchCmd: // Find the next point with a given x coordinate.
               Search(polygon);
               break;
            case QuitCmd: // Terminate execution.
               return 0;
            case ' ': // Empty command; do nothing.
               break;
            default: // Bad command; display error message.
               cout << "*** Error: Unknown Command" << endl;
               break;
            }
      }
    }
  return 0;
}



/*--------------- G e t C m d ( ) ---------------

PURPOSE
Accept a command from the keyboard.

INPUT PARAMETERS
polygon      -- the polygon list.

RETURN VALUE
The command letter.
*/
char GetCmd(LinkedList &polygon)
{
   // Display the current point before accepting each command.
   if (!polygon.AtEnd())
      {
      // Display the current item.
      cout << "\nCURRENT ITEM" << endl;
      polygon.CurrentEntry().Show();
      cout << endl;
      }

   // Prompt for a new command.
   cout << CmdPrompt;

   // initialize command empty.
   char cmd = ' ';

   // Read the command letter from the keyboard.
   if (cin.peek() != '\n')
      cmd = cin.get();    // Command line

   cin.ignore(INT_MAX, '\n');

   return cmd;
}

/*--------------- I n s e r t P o i n t s ( ) ---------------

PURPOSE
Insert a new point in the polygon before the current point.

INPUT PARAMETERS
polygon  -- the polygon list.
*/
void InsertPoints(LinkedList &polygon)
{
  Point             point;                // New polygon point
  
   for (;;)
      {
      // Read the new point and insert it into the polygon.
      cout << "Enter point: ";
      if (!point.Get())
         return;
      polygon.Insert(point);
      }   
}

/*--------------- U p d a t e E n t r y( ) ---------------

PURPOSE
Modify the current entry in the polygon.

INPUT PARAMETERS
polygon  -- the polygon list.
*/
void UpdateEntry(LinkedList &polygon)
{
   Point             point;                // New point value
  
   // If at end, say so.
	if (polygon.AtEnd())
		{
		cout << "***Error: There is no current entry." << endl;
		return;
		}

   // Read the new point and insert it into the polygon.
   cout << "Enter point: ";
   if(point.Get())
      polygon.Update(point);
}


/*--------------- D i s p l a y P o l y g o n ( ) ---------------

PURPOSE
Display a polygon from beginning to end.

INPUT PARAMETERS
polygon  -- the polygon to be displayed.
*/
void DisplayPolygon(LinkedList &polygon)
{
   // If the polygon is empty, say so.
   if (polygon.Empty())
      cout << "The polygon is empty." << endl;
   else
      {
      cout << "\nPOLYGON DEFINITION" << endl;

      // Start at the beginning.
      polygon.Rewind();
      
      // Keep displaying until the end.
      while (!polygon.AtEnd())
        {
        // Display the current entry..
        polygon.CurrentEntry().Show();
        cout << endl;

        // Move to the next entry.
        polygon.Skip();
        }
  
      cout << endl;
      }

   // Rewind when done.
   polygon.Rewind();
}

/*--------------- C l e a r P o l y g o n ( ) ---------------

PURPOSE
Make the polygon empty.

INPUT PARAMETERS
polygon  -- the polygon list.
*/
void ClearPolygon(LinkedList &polygon)
{
  // Delete vertexes until empty.
  polygon.Rewind();
  while (!polygon.Empty())
    polygon.Delete();
}


/*--------------- V a l i d P o l y ( ) ---------------

PURPOSE
Make sure that there at least 3 points.

INPUT PARAMETERS
polygon  -- the polygon list.

RETURN VALUE
true if there are at least 3 points,
false otherwise
*/
bool ValidPoly(LinkedList &polygon)
{
	// Rewind to the first point.
	polygon.Rewind();

	// Make sure that there are at least 3 points.
	for (unsigned i=0; i<MinPolySides; i++)
		{
		if (polygon.AtEnd())
			{
			// If not valid, say so.
			cout << "*** ERROR: At least " << MinPolySides << " points are needed to define a polygon." << endl;
			return false;
			}
		polygon.Skip();
		}

	// Indicate valid.
	return true;
}

/*--------------- S h o w C i r c u m ( ) ---------------

PURPOSE
Show on the screen the the circumference of the polygon.

INPUT PARAMETERS
polygon  -- the polygon list.
*/
void ShowCircum(LinkedList &polygon)
{
   // Check for valid polygon.
   if (!ValidPoly(polygon))
	   return;

   // Rewind the current entry.
   polygon.Rewind();

   // Save the first point for computing the length of the last side.
   Point p0 = polygon.CurrentEntry();

   // Prepare to accumulate the circumference.
   double circum = 0;

   // Point 1 of the first side
   Point p1 = p0;

   // Repeatedly add the lengths of the polygon sides.
   while (!polygon.AtEnd())
      {
	   // Advance to the next point.
      polygon.Skip();

	   // If no more points, done
      if (polygon.AtEnd())
	      // Accumulate the length of the last side.
         circum += p1.Length(p0);
      else
         {
		      // Accumulate the length of the next side.
         Point p2 = polygon.CurrentEntry();

         circum += p1.Length(p2);

		   // Point 2 is the next point 1.
		   p1 = p2;
         }
      }

   // Show the circumference.
   cout << "Circumference = " << circum << endl;
}

/*--------------- S e a r c h ( ) ---------------

PURPOSE
Starting at the current point, find the first point with the given x coordinate.

INPUT PARAMETERS
polygon  -- the polygon list.
*/
void Search(LinkedList &polygon)
{
   // Get the desired x.
   cout << "X Coordinate: ";
   double x;
   cin >> x;

   // Skip ahead to the desired x.
   for (;;)
      {
      // If at end and not found, return.
      if (polygon.AtEnd())
         {
         cout << "Polygon at end\n";
         break;
         }
      // If this entry is the one then done.
      if (polygon.CurrentEntry().X() == x)
         break;
      // Keep looking.
      polygon.Skip();
      }
}

/*--------------- S h o w A r e a ( ) ---------------

PURPOSE
Show on the screen the areas of the triangles comprising the
polygon followed by the area of the polygon.

INPUT PARAMETERS
polygon  -- the polygon list.
*/
void ShowArea(LinkedList &polygon){

	// Check for valid polygon.
	if (!ValidPoly(polygon))
		return;

	// Rewind the current entry.
	polygon.Rewind();

	int i = 0;
	double area = 0;//area for each triangle
	double totalArea = 0;//total area of the polygon
	Point p0 = polygon.CurrentEntry();//p0 is equal to the first entry of the list
	Point p1;//p1 will act as point 1 for side b of the triangles
	double s = 0;//semiperimeter
	double a = 0;//side a of the triangle inside of the polygon
	double b = 0;//side b of the triangle inside of the polygon
	double c = 0;//side c of the triangle inside of the polygon
	bool ListEnd = true;
	int count = 0;

	while (ListEnd){//counts how big the list is
		if (polygon.AtEnd()){//if the polygon is at end, then the loop stops
			ListEnd = false;
		}
		else{//if the polygon is not at end, then the loop continues and we skip to the next entry
			polygon.Skip();
			count++;
		}
	}

	polygon.Rewind();
	polygon.Skip();//Advances to next point

	while (!polygon.AtEnd() && i < count-2){//loop will iterate until the list is at end and when i equals the number of sides
		Point p2 = polygon.CurrentEntry();//p2 is equal to the second entry of the list and will be the i+1 entry after first iteration
		a = p0.Length(p2);//side a of the triangle
		p1 = p2;//p1 becomes i+1 entry
		polygon.Skip();//moves forward in list
		Point p3 = polygon.CurrentEntry();//p3 is equal to the i+2 entry
		b = p1.Length(p3);//side b of the triangle
		c = p0.Length(p3);//side c of the triangle
		s = (a + b + c) / 2;
		area = sqrt(abs(s*(s - a)*(s - b)*(s - c)));
		totalArea += area;
		i++;//counts how many triangles
		cout << "Triangle " << i << " area = " << area << endl;//prtints triangle areas
	}
	cout << "Polygon area = " << totalArea << endl;	
}


