#ifndef TSPSOLVER_H
#define TSPSOLVER_H

#include "TSPSolution.h"

using namespace std;


/**
 * Clase TSPSolver. Es una abstracción de la heurística usada 
 * para resolver el problema del TSP mediante herencia de clases
 */

class TSPSolver {
public:
	virtual TSPSolution solve();
};

#endif