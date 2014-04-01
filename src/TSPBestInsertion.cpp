#include "TSPBestInsertion.h"
#include "TSPPartialSolution.h"
#include <limits>

using namespace std;


TSPBestInsertion::TSPBestInsertion(TSPProblem *problem){

	this->problem = problem;
	this->partial = new TSPPartialSolution(*problem);

}


void TSPBestInsertion::insertNextCity(TSPPartialSolution *partial){

	int total_cities = this->problem->getNumberOfCities(),
		total_inserted = partial->getNumberOfCities();

	double min_dist = numeric_limits<double>::infinity(), curr_dist;
	int min_city, min_pos;

	for(int city = 0; city < total_cities; city++){

		for(int pos = 0; pos < total_inserted; pos++){

			if(not partial.isAlreadyVisited(city)){

				curr_dist = partial->getCostOfInsertion();

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


TSPSolution* TSPBestInsertion::solve(){

	TSPProblem problem = *this->problem;

	TSPPartialSolution partial(problem);

	partial.insertCity(0, 0);  // Insert first city in the first position

	int total_cities = problem.getNumberOfCities();

	while(partial->getNumberOfCities() <= total_cities){

		this->insertNextCity(partial);

	}

	TSPSolution sol(*partial);

	return &sol;

}