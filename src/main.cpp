#include "TSPProblem.h"
#include "TSPSolution.h"
#include "TSPProblemReader.h"
#include "TSPBestInsertion.h"
#include "TSPNearestNeighbour.h"
#include <iostream>

using namespace std;


int main(int argc, char *argv[]){

	if(argc < 3){

		cout << "Usage: ./tsp <filename.tsp> {1|2}" << endl;

		return 1;

	}


	string problem_filename = string(argv[1]), heuristic_index = string(argv[2]);

	TSPProblemReader reader;
	TSPProblem problem = reader.read(problem_filename);

	if(heuristic_index == "1"){
		
		TSPBestInsertion best_insertion(&problem);
	
		cout << "Using Best Insertion Heuristic" << endl;
		best_insertion.solve().displaySolution();

	}
	
	else if(heuristic_index == "2") {
		
		TSPNearestNeighbour nearest(&problem);

		cout << "Using Nearest Neighbour Heuristic" << endl;
		nearest.solve().displaySolution();

	}	

}