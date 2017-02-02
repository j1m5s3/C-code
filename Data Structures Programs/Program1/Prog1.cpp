/*=============== P r o g 1 . c p p ===============

Starter Code by:  George Cheney
                  ECE Dept.
                  UMASS Lowell

Finshed Code by:  James Lynch

PURPOSE
Read in the definition of an arbitrary convex polygon, and then
compute both the circumerence and the area of the polygon.

CHANGES
09-02-2016 gpc  -   Distribute to EECE322 class.
*/

#include <iostream>
#include <cmath>

using namespace std;

// --------------- D a t a    T y p e    P o i n t ---------------

struct Point
{
	double x;// x coordinate
	double y;// y coordinate
};




//----- D a t a    T y p e    P o i n t    F u n c t i o n s -----

bool GetPoint(Point &pt){

	cin >> pt.x >> pt.y;//user in put for x and y

	return pt.x >= 0;//return pt if greater than or equal to 0. the program terminates otherwise		
}

void ShowPoint(Point &pt){

	cout << "(" << pt.x << "," << pt.y << ")"<< endl;//prints points to screen
}

double Length(Point pt1, Point pt2){

	double pt1X = pt1.x;
	double pt1Y = pt1.y;

	double pt2X = pt2.x;
	double pt2Y = pt2.y;
	//distance formula 
	double distX = (pt2X - pt1X)*(pt2X - pt1X);
	double distY = (pt2Y - pt1Y)*(pt2Y - pt1Y);

	double totalDist = sqrt(abs(distX + distY));//distance formula

	return totalDist;//function returns the distance betweeb point 1 and point 2
}


// --------------- D a t a    T y p e    P o l y g o n ---------------

const unsigned MaxSides = 10;
const unsigned MinSides = 3;

struct Polygon
{
	unsigned numSides;// number of sides
	Point vert[MaxSides];//array of points taken from user

};


//----- D a t a    T y p e    P o l y g o n    F u n c t i o n s -----

double PolyCircumference(Polygon &thePoly){

	double totalCircum = 0;

	for (int i = 0; i < thePoly.numSides; i++){
		double len = Length(thePoly.vert[i], thePoly.vert[(i + 1) % thePoly.numSides]);//point 1 and point 2 are passed through the length function
		totalCircum += len;// the total circumference is calculated using the return value of the function length
		
	}
	return totalCircum;// function returns the total circumference
}

void PolyArea(Polygon &thePoly, double *area){
	
	double s = 0;
	double a = 0;
	double b = 0;
	double c = 0;
	double totalArea = 0;

	area[0] = 0;

	for (int i = 0; i < thePoly.numSides - 2; i++){

		a = Length(thePoly.vert[0], thePoly.vert[i + 1]);//side a of the triangle inside of the polygon
		b = Length(thePoly.vert[i+1], thePoly.vert[i + 2]);//side b of the triangle inside of the polygon
		c = Length(thePoly.vert[0], thePoly.vert[i + 2]);//side c of the triangle inside of the polygon
		s = (a + b + c) / 2;//the semiperimter of the triangle 
		area[i+1] = sqrt(abs(s*(s - a)*(s - b)*(s - c)));//using the area formula, the area of the triangle
	}
	for (int j = 1; j < thePoly.numSides - 1; j++){

		area[0] += area[j];//sum of areas assigned to the 0th element of the array
	}
}


/*--------------- S h o w P o l y ( ) ----------

PURPOSE: Display a polygon.

INPUT PARAMETERS:
p  -- the polygon to be displayed.
*/
void ShowPoly(Polygon &p)
{
   for (unsigned i=0; i<p.numSides; i++)
      ShowPoint(p.vert[i]);
}

//--------------- m a i n ( ) ---------------

int main()
{
   Polygon poly;   // The polygon definition
   
   // Start out with zero polygon sides.
   poly.numSides = 0;

   // Read in a polygon definition. If a valid polygon was entered,
   // display its circumference and area; otherwise display an
   // error message and terminate execution.
   cout << "ENTER A POLYGON DEFINITION: " << endl << endl;

   for (;;)
      {
      // Read in the next point
      cout << "\nEnter next point: ";
      if (!GetPoint(poly.vert[poly.numSides]))
         break;

      // Update the ploygon size.
      ++poly.numSides;

      // If the polygon is full, say so and stop taking input.
      if (poly.numSides >= MaxSides)
         {
         cout << "\nPolynomial Full" << endl;
         break;
         }
      }

   // Make sure that the polygon is valid.
   if (poly.numSides < MinSides)
      {
      cout << "***ERROR: A polygon must have at least 3 sides" << endl;
      return 0;
      }

   // The definition is valid, show the definition.
   cout << endl << "Here is the polygon definition:" << endl;
   ShowPoly(poly);

   // Compute and display the circumference.
   cout << "\nCircumference = " << PolyCircumference(poly) << endl;

   // Compute and display the areas of the polygon and its embedded triangles.

   // area[0] gives the area of the entire polygon.
   // area[i] (i > 0) gives the area of the i'th embedded triangle.
   double area[MaxSides+1];

   PolyArea(poly, area);

   cout << "\nPolygon Area = " << area[0] << endl << endl;

   const unsigned numTriangles = poly.numSides - 2;   // Number of embedded triangles

   for (unsigned i=1; i<=numTriangles; ++i)
      cout << "Triangle " << i << ": Area = " << area[i] << endl;

   cout << endl;

   return 0;
}
 