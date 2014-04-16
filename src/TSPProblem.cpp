#include "TSPProblem.h"

using namespace std;

TSPProblem::TSPProblem(){}

TSPProblem::TSPProblem(TSPPoint* cities, int num_cities){

	this->num_cities = num_cities;
	this->cities = cities;

	// dynamically allocate distances matrix

	this->distances = new double*[num_cities];

	this->distances[0] = new double[num_cities * num_cities];

	for(int i = 1; i < num_cities; i++){

		this->distances[i] = this->distances[0] + i * num_cities;

	}

	// end allocation

	this->computeDistances();

}


void TSPProblem::computeDistances(){

	TSPPoint *city_i, *city_j;
	double dist;

	for(int i = 0; i < this->num_cities - 1; i++){

		this->distances[i][i] = 0;

		for(int j = i + 1; j < this->num_cities; j++){

			city_i = &(this->cities[i]);
			city_j = &(this->cities[j]);

			dist = city_i->getDistanceTo(*city_j);

			this->distances[i][j] = dist;
			this->distances[j][i] = dist;

		}

	}

}


double** TSPProblem::getDistancesMatrix(){

	return this->distances;

}


int TSPProblem::getNumberOfCities(){

	return this->num_cities;

}