#include "Point.h"
#include <cmath>
#include <iostream>

using namespace std;

bool GetPoint(Point &pt){


	if (cin.peek() != '\n'){//there was a point entered
		
		cin >> pt.x >> pt.y;//user input for x and y
		cin.ignore(INT_MAX, '\n');//ignores previous newline if numbers were input
		return pt.x >= 0;
	}

	return false;//there was no point entered, so end prompt	
}

void ShowPoint(Point &pt){

	cout << "(" << pt.x << "," << pt.y << ")" << endl;//prints points to screen
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