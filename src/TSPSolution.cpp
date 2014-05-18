#include "TSPSolution.h"
#include "TSPPoint.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>

using namespace std;

TSPSolution::TSPSolution(int *cities, int number_of_cities, double cost){
	this->number_of_cities = number_of_cities;
	this->cost = cost;
	
	this->cities = new int[number_of_cities];
	copy(cities, cities + number_of_cities, this->cities);
}


TSPSolution::TSPSolution(const TSPSolution &other){
	this->number_of_cities = other.number_of_cities;
	this->cost = other.cost;

	this->cities = new int[this->number_of_cities];
	copy(other.cities, other.cities + other.number_of_cities, this->cities);
}

TSPSolution& TSPSolution::operator=(const TSPSolution &other){

	if(this != &other){

		if(this->number_of_cities != other.number_of_cities){

			throw logic_error("Number of cities must meet");

		}

		this->cost = other.cost;
		copy(other.cities, other.cities + other.number_of_cities, this->cities);
		
	}

	return *this;

}

TSPSolution::~TSPSolution(){

	delete[] this->cities;

}

int* TSPSolution::getCitiesInOrder(){
	return this->cities;
}

int TSPSolution::getNumberOfCities(){
	return this->number_of_cities;
}

void TSPSolution::displaySolution(){
	cout << "Total cost: " << cost << endl;

	cout << "Cities: " << this->cities[0] + 1;

	for(int i = 1; i < number_of_cities; i++){
		cout << ", " << this->cities[i] + 1;
	}

	cout << endl;
}