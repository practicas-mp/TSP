#include "TSPProblem.h"
#include <algorithm>
#include <stdexcept>

using namespace std;

TSPProblem::TSPProblem(){}

TSPProblem::TSPProblem(TSPPoint* cities, int num_cities){

	this->num_cities = num_cities;

	this->cities = cities;

	// dynamically allocate distances matrix

	this->allocateDistanceMatrix();

	this->computeDistances();

}


TSPProblem::TSPProblem(const TSPProblem &other){

	this->num_cities = other.num_cities;

	this->allocateCities();

	this->allocateDistanceMatrix();

	copy(other.cities, other.cities + other.num_cities, this->cities);

	for(int i = 0; i < num_cities; i++){

		copy(other.distances[i], other.distances[i] + num_cities * num_cities, this->distances[i]);
			
	}

}


TSPProblem& TSPProblem::operator=(const TSPProblem &other){

	if(this != &other){

		if(this->num_cities != other.num_cities){

			this->num_cities = other.num_cities;

			delete [] this->cities;

			this->allocateCities();

			delete [] this->distances;

			this->allocateDistanceMatrix();

		}

		copy(other.cities, other.cities + num_cities, this->cities);

		for(int i = 0; i < num_cities; i++){

			copy(other.distances[i], other.distances[i] + num_cities * num_cities, this->distances[i]);
				
		}

	}
	
	return *this;

}


TSPProblem::~TSPProblem(){

	delete [] this->cities;
	delete [] this->distances[0];
	delete [] this->distances;

}


void TSPProblem::allocateCities(){

	this->cities = new TSPPoint[this->num_cities];

}


void TSPProblem::allocateDistanceMatrix(){

	this->distances = new double*[num_cities];

	this->distances[0] = new double[num_cities * num_cities];

	for(int i = 1; i < num_cities; i++){

		this->distances[i] = this->distances[0] + i * num_cities;

	}

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