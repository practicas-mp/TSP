#include <stderr>
#include "TSPPartialSolution.h"


TSPPartialSolution::TSPPartialSolution(TSPProblem problem){
	this->problem = &problem;
	this->distances = problem.getDistancesMatrix();

	this->number_of_cities = problem.getNumberOfCities();

	this->cities = new int[this->number_of_cities];
	this->visitadas = new bool[this->number_of_cities];

	this->cities_inserted = 0;
}

