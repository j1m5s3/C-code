#ifndef POINT_H
#define POINT_H

struct Point
{
	double x;// x coordinate
	double y;// y coordinate
};

double Length(Point pt1, Point pt2);
void ShowPoint(Point &pt);//prints user selected points to screen
bool GetPoint(Point &pt);//gets point from user

#endif