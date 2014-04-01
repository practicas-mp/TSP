#include "TSPProblem.h"
#include "TSPSolution.h"
#include "TSPReader.h"
#include <iostream>

using namespace std;


int main(int argc, char *argv[]){

	if(argc == 1){

		cout << "Usage: ./tsp <filename.tsp>";

	}

	TSPReader reader;

	TSPProblem problem = reader.read(string(argv[1]));

	TSPSolution sol = problem.solve();

	sol.displaySolution();

}