#ifndef TSPBESTINSERTION_H
#define TSPBESTINSERTION_H

#include "TSPProblem.h"
#include "TSPSolver.h"
#include "TSPSolution.h"
#include "TSPPartialSolution.h"

using namespace std;

/**
 * Clase TSPBestInsertion que se encarga de la heurística
 * que usaremos en esta práctica para resolver el problema del TSP
 */
	

class TSPBestInsertion: public TSPSolver {

	private:

		/**
		 * Puntero a la instancia de TSPProblem que representa el 
		 * problema concreto a resolver
		 */			

		TSPProblem *problem;

		/**
		 * Puntero a una instancia de la clase TSPPartialSolution para
		 * manejar los pasos intermedios de la solución con comodidad
		 */

		TSPPartialSolution *partial;  // Crearla en el constructor (?)


	public:

		/**
		 * @brief Constructor de la clase TSPBestInsertion.
		 * @param problem Puntero a la instancia de TSPProblem que representa el problema concreto a resolver
		 */			

		TSPBestInsertion(TSPProblem *problem);

		/**
		 * Método para insertar una nueva ciudad de acuerdo con
		 * el "algoritmo" seguido por esta solución del problema
		 */			

		void insertNextCity();

		/**
		 * Método para resolver por completo el problema que se
		 * nos proporciona
		 * @return Puntero a la solución TSPSolution del problema
		 */			

		TSPSolution* solve();

};

#endif