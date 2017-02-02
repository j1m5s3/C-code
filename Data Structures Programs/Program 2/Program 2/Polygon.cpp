#include "Polygon.h"
#include <cmath>
#include <iostream>

using namespace std;

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
		b = Length(thePoly.vert[i + 1], thePoly.vert[i + 2]);//side b of the triangle inside of the polygon
		c = Length(thePoly.vert[0], thePoly.vert[i + 2]);//side c of the triangle inside of the polygon
		s = (a + b + c) / 2;//the semiperimter of the triangle 
		area[i + 1] = sqrt(abs(s*(s - a)*(s - b)*(s - c)));//using the area formula, the area of the triangle
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
void ShowPoly(Polygon &p){
	for (unsigned i = 0; i<p.numSides; i++)
		ShowPoint(p.vert[i]);
}
