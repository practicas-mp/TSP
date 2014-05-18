#include "TSPNearestNeighbour.h"
#include "TSPPartialSolution.h"
#include <limits>


using namespace std;

TSPNearestNeighbour::TSPNearestNeighbour(TSPProblem *problem) : TSPSolver(problem){
	this->partial = new TSPPartialSolution(problem);
}


TSPNearestNeighbour::~TSPNearestNeighbour(){
	delete this->partial;
}

TSPNearestNeighbour::TSPNearestNeighbour(const TSPNearestNeighbour& other){

		this->partial = new TSPPartialSolution(other.problem);

}

TSPNearestNeighbour& TSPNearestNeighbour::operator=(const TSPNearestNeighbour &other){

	if(this != &other){

		*this->partial = *other.partial;
		
	}

	return *this;

}

TSPSolution TSPNearestNeighbour::solve(){
	int total_cities = problem->getNumberOfCities();
	double min_cost = numeric_limits<double>::infinity(), curr_cost;

	TSPPartialSolution min_partial(this->problem);

	for(int i = 0; i < total_cities; i++){
		TSPPartialSolution curr_partial = solveWithCityAsFirst(i);

		curr_cost = curr_partial.getCurrentCost();

		if(curr_cost < min_cost){
			min_cost = curr_cost;
			min_partial = curr_partial;
		}
	}

	TSPSolution sol(min_partial.getCities(), min_partial.getNumberOfCities(), min_partial.getCurrentCost());

	return sol;

}

TSPPartialSolution TSPNearestNeighbour::solveWithCityAsFirst(int city_number){
	int total_cities = problem->getNumberOfCities();
	TSPPartialSolution partial(this->problem);

	partial.insertCity(city_number, 0);

	while(partial.getNumberOfCities() < total_cities){

		double min_cost = numeric_limits<double>::infinity(), curr_dist;

		int min_city;

		for(int i = 0; i < total_cities; i++){

			if (partial.isAlreadyVisited(i) == not true){

				curr_dist = partial.getLastNeighbourCost(i);


				if (curr_dist < min_cost){
					min_cost = curr_dist;
					min_city = i;
				}
			}

		}

		partial.insertCity(min_city, partial.getNumberOfCities());
	}


	return partial;

}

