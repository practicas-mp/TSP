#include <stderr>
#include "TSPPartialSolution.h"
#include "TSPProblem.h"

TSPPartialSolution::TSPPartialSolution(TSPProblem problem){
	this->problem = &problem;
	this->distances = problem.getDistancesMatrix();

	this->number_of_cities = problem.getNumberOfCities();

	this->cities = new int[this->number_of_cities];


	this->visitadas = new bool[this->number_of_cities];
	for(int i = 0; i < number_of_cities; i++)
		visitadas[i] = false;

	this->cities_inserted = 0;
}

double  TSPPartialSolution::getCostOfInsertion(int city, int position){
	double cost = 0;

	if (position == 0)
		position = number_of_cities;
	

	int city_before = cities[position - 1];
	int city_after = cities[position % number_of_cities];

	cost += distances[city_before][city];
	cost += distances[city_after][city];

	cost -= distances[city_before][city_after];
	

	return cost;
}

void TSPPartialSolution::insertCity(int city, int position){

	for(int i = number_of_cities - 1; i > position; i--){
		cities[i] = cities[i - 1];
	}

	cities[position] = city;
	visitadas[city] = true;
	
	cities_inserted++;
}

TSPProblem TSPPartialSolution::getProblem(){
	return *problem;
}

int TSPPartialSolution::getNumberOfCities(){
	return cities_inserted;	
}

int* TSPPartialSolution::getCities(){
	return cities;
};

bool isAlreadyVisited(int city){
	return visitadas[city];
};