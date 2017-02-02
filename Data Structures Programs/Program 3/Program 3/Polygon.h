#ifndef POLYGON_H
#define POLYGON_H


#include "Point.h"

const unsigned MaxSides = 10;//max number of sides for polygon
const unsigned MinSides = 3;//min number of sides for polygon

struct Polygon{

	unsigned numSides;// number of sides
	Point vert[MaxSides];//array of points taken from user

};

double PolyCircumference(Polygon &thePoly);//calculates circumference of polygon
void PolyArea(Polygon &thePoly, double *area);//calculates area of polygon
void ShowPoly(Polygon &p);//displays polygon

#endif