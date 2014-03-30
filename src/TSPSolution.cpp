#include "TSPSolution.h"

TSPSolution::TSPSolution(TSPPartialSolution partial_solution_completed){
	this->partial_solution_completed = &partial_solution_completed;
}

int* TSPSolution::getCitiesInOrder(){
	return this->partial_solution_completed->getCities();
}

int TSPSolution::getNumberOfCities(){
	return this->partial_solution_completed->getNumberOfCities();
}

void TSPSolution::displaySolution(){
	// Por implementar aun
}