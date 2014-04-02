#include "TSPSolution.h"

TSPSolution::TSPSolution(int *cities, int number_of_cities){
	this->cities = cities;
	this->number_of_cities = number_of_cities;
}

int* TSPSolution::getCitiesInOrder(){
	return this->cities;
}

int TSPSolution::getNumberOfCities(){
	return this->number_of_cities;
}

void TSPSolution::displaySolution(){
	// Por implementar aun
}