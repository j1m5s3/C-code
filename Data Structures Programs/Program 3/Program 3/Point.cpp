#include "Point.h"
#include <cmath>
#include <iostream>

Point::Point(){
//The constructor initializes x and y, allowing them to be used
	x = -1;
	y = -1;
}

bool Point::Get(istream &is){//function takes user input


	if (cin.peek() != '\n'){//there was a point entered
		
		cin >> x >> y;//user input for x and y
		cin.ignore(INT_MAX, '\n');//ignores previous newline if numbers were input
		return x >= 0;
	}

	return false;//there was no point entered, so end prompt	
}

void Point::Show(ostream &os) const {//function prints user input to screen

	cout << "(" << x << "," << y << ")" << endl;//prints points to screen
}

double Point::Length(Point pt2){
	//The x and y components of point 1
	double pt1X = x;
	double pt1Y = y;
	//The x and y components of point 2
	double pt2X = pt2.X();
	double pt2Y = pt2.Y();
	//distance formula 
	double distX = (pt2X - pt1X)*(pt2X - pt1X);
	double distY = (pt2Y - pt1Y)*(pt2Y - pt1Y);

	double totalDist = sqrt(abs(distX + distY));//distance formula

	return totalDist;//function returns the distance betweeb point 1 and point 2
}

double Point::X() const{//Allows access to data input by user for x 

	return x;
}

double Point::Y() const{//Allows access to data input by user for y

	return y;
}