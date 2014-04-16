#include "TSPProblem.h"
#include "TSPSolution.h"
#include "TSPProblemReader.h"
#include "TSPBestInsertion.h"
#include <iostream>

using namespace std;


int main(int argc, char *argv[]){

	if(argc == 1){

		cout << "Usage: ./tsp <filename.tsp>";

	}

	TSPProblemReader reader;

	TSPProblem *problem = new TSPProblem();

	*problem = reader.read(string(argv[1]));

	TSPBestInsertion insertion(problem);

	TSPSolution sol = insertion.solve();

	sol.displaySolution();

}