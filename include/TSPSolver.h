#ifndef TSPSOLVER_H
#define TSPSOLVER_H

#include "TSPSolution.h"
#include "TSPProblem.h"

using namespace std;


/**
 * Clase TSPSolver. Es una abstracción de la heurística usada 
 * para resolver el problema del TSP mediante herencia de clases
 */

class TSPSolver {
	public:

		/**
		 * Puntero a la instancia de TSPProblem que representa el 
		 * problema concreto a resolver
		 */			

		TSPProblem *problem;

		TSPSolver();

		TSPSolver(TSPProblem *problem);

		virtual TSPSolution solve() = 0;
};

#endif