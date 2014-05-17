#include "TSPBestInsertion.h"
#include "TSPPartialSolution.h"
#include "TSPSolver.h"
#include <limits>
#include <algorithm>

using namespace std;


TSPBestInsertion::TSPBestInsertion(TSPProblem *problem)
	:TSPSolver(problem){

	this->partial = new TSPPartialSolution(problem);

}

TSPBestInsertion::TSPBestInsertion(const TSPBestInsertion& other){

		this->partial = new TSPPartialSolution(other.problem);

}

TSPBestInsertion& TSPBestInsertion::operator=(const TSPBestInsertion &other){

	if(this != &other){

		*this->partial = *other.partial;
		
	}

	return *this;

}

TSPBestInsertion::~TSPBestInsertion(){

	delete this->partial;

}


void TSPBestInsertion::insertNextCity(TSPPartialSolution *partial){

	int total_cities = this->problem->getNumberOfCities(),
		total_inserted = partial->getNumberOfCities();

	double min_dist = numeric_limits<double>::infinity(), curr_dist;
	int min_city, min_pos;

	for(int city = 0; city < total_cities; city++){

		for(int pos = 0; pos < total_inserted; pos++){

			if(not partial->isAlreadyVisited(city)){

				curr_dist = partial->getCostOfInsertion(city, pos);

				if(min_dist > curr_dist){

					min_dist = curr_dist;
					min_city = city;
					min_pos = pos;

				}
				
			}

		}

	}

	partial->insertCity(min_city, min_pos);

}


TSPSolution TSPBestInsertion::solve(){

	TSPProblem *problem = this->problem;

	TSPPartialSolution best(problem);

	double best_cost = numeric_limits<double>::infinity(), curr_cost;

	int total_cities = problem->getNumberOfCities();

	for(int i = 0; i < total_cities; i++){

		TSPPartialSolution partial(problem);

		partial.insertCity(i, 0);  // Insert ith city in the first position


		while(partial.getNumberOfCities() < total_cities){

			this->insertNextCity(&partial);

		}

		curr_cost = partial.getCurrentCost();

		if(curr_cost < best_cost){

			best_cost = curr_cost;

			best = partial;

		}
				
	}

	TSPSolution sol(best.getCities(), best.getNumberOfCities(), best.getCurrentCost());

	return sol;

}
