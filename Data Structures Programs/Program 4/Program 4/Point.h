#ifndef POINT_H
#define POINT_H
#include <istream>
#include <ostream>
#include <iostream>
using namespace std;

class Point{
public:

	Point();//Default constructor
	Point(double xVal, double yVal);//Explicit constructor

	double X() const;//returns x coordinate
	double Y() const;//returns y coordinate

	//Mutator: Set the x and the y coordinates of a Point
	void Set(double xVal, double yVal);

	double Length(Point pt2);//Length takes one argument, being point 2

	bool Get(istream &is = cin);//Input a Point from the stream "is"
	void Show(ostream &os = cout) const;//Output a point to the sream "os"

private:
	double x;//x coordinate of point
	double y;//y coordinate of point
};


#endif