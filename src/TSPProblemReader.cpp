#include "TSPProblemReader.h"
#include "TSPProblem.h"
#include "TSPPoint.h"
#include <fstream>

TSPProblem TSPProblemReader::read(string filename){
	double x, y;
	string head;
	int number_of_cities;


	ifstream archivo;

	archivo.open(filename.c_str());

	archivo >> head;
	archivo >> number_of_cities;

	TSPPoint *points = new TSPPoint[number_of_cities];

	for(int i = 0; i < number_of_cities; i++){
		archivo >> head;
		archivo >> x;
		archivo >> y;

		points[i] = TSPPoint(x, y);
	}


	return TSPProblem(points, number_of_cities);

}