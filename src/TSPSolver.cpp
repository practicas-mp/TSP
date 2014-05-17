#include "TSPSolver.h"
#include "TSPSolution.h"
#include "TSPProblem.h"

using namespace std;


TSPSolver::TSPSolver(){}

TSPSolver::TSPSolver(TSPProblem *problem){

	this->problem = problem;

}