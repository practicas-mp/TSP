#include "TSPSolution.h"
#include <iostream>

using namespace std;

TSPSolution::TSPSolution(int *cities, int number_of_cities, double cost){
	this->cities = cities;
	this->number_of_cities = number_of_cities;
	this->cost = cost;
}

int* TSPSolution::getCitiesInOrder(){
	return this->cities;
}

int TSPSolution::getNumberOfCities(){
	return this->number_of_cities;
}

void TSPSolution::displaySolution(){
	cout << "Total cost: " << cost;
	for(int i = 0; i < number_of_cities; i++){
		cout << this->cities[i] << ", ";
	}

	cout << endl;
}
