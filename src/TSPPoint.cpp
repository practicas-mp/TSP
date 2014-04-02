#include <cmath>
#include "TSPPoint.h"

using namespace std;

TSPPoint::TSPPoint(){}

TSPPoint::TSPPoint(double x, double y){

	this->x = x;
	this->y = y;

}


double TSPPoint::getX(){

	return this->x;

}


double TSPPoint::getY(){

	return this->y;

}


double TSPPoint::getDistanceTo(TSPPoint other){

	double delta_x = this->x - other.getX(),
			delta_y = this->y - other.getY();


	return sqrt(delta_x * delta_x + delta_y * delta_y);

}