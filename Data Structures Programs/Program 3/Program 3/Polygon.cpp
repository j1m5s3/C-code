#include "Polygon.h"
#include <cmath>
#include <iostream>
#include <istream>
#include <ostream>

using namespace std;

double PolyCircumference(Polygon &thePoly){//Function calculates the polygon circumference

	double totalCircum = 0;//Variable initialized for future use

	for (unsigned i = 0; i < thePoly.numSides; i++){//Loop calculates the total circumference of polygon
		double len = thePoly.vert[i].Length(thePoly.vert[(i + 1) % thePoly.numSides]);
		totalCircum += len;// the total circumference is calculated using the return value of the function length

	}
	return totalCircum;// function returns the total circumference
}

void PolyArea(Polygon &thePoly, double *area){//function calculates the polygon area

	double s = 0;//semiperimeter
	double a = 0;//side a of the triangle inside of the polygon
	double b = 0;//side b of the triangle inside of the polygon
	double c = 0;//side c of the triangle inside of the polygon

	area[0] = 0;//array of areas

	for (unsigned i = 0; i < thePoly.numSides - 2; i++){

		a = thePoly.vert[0].Length(thePoly.vert[i + 1]);
		b = thePoly.vert[i+1].Length(thePoly.vert[i + 2]);
		c = thePoly.vert[0].Length(thePoly.vert[i + 2]);
		s = (a + b + c) / 2;//the semiperimter of triangle a,b,c 
		area[i + 1] = sqrt(abs(s*(s - a)*(s - b)*(s - c)));//using the area formula, the area of the triangle
	}
	for (unsigned j = 1; j < thePoly.numSides - 1; j++){

		area[0] += area[j];//sum of areas assigned to the 0th element of the array
	}
}


/*--------------- S h o w P o l y ( ) ----------

PURPOSE: Display a polygon.

INPUT PARAMETERS:
p  -- the polygon to be displayed.
*/
void ShowPoly(Polygon &p){//diplays dimensions of polygon given by user
	for (unsigned i = 0; i<p.numSides; i++)
		p.vert[i].Show(cout);//
}







void ShowCircum(LinkedList &polygon){
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