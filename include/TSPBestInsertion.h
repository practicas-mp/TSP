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
		 * Puntero a una instancia de la clase TSPPartialSolution para
		 * manejar los pasos intermedios de la solución con comodidad
		 */

		TSPPartialSolution *partial;

	public:

		/**
		 * @brief Constructor de la clase TSPBestInsertion.
		 * @param problem Puntero a la instancia de TSPProblem que representa el problema concreto a resolver
		 */			

		TSPBestInsertion(TSPProblem *problem);

		/**
		 * @brief Constructor de copia de la clase TSPBestInsertion
		 * @param other Instancia de la clase TSPBestInsertion de la que se quiere copiar
		 */
			
		TSPBestInsertion(const TSPBestInsertion& other);

		/**
		 * @brief Operador de asignación de la clase TSPBestInsertion
		 * @param other Instancia de la clase TSPBestInsertion que queremos asignar
		 */

		TSPBestInsertion& operator=(const TSPBestInsertion &other);
			
		/**
		 * @brief Destructor de la clase TSPBestInsertion
		 */
		
		~TSPBestInsertion();

		/**
		 * Método para insertar una nueva ciudad de acuerdo con
		 * el "algoritmo" seguido por esta solución del problema
		 */			

		void insertNextCity(TSPPartialSolution*);

		/**
		 * Método para resolver por completo el problema que se
		 * nos proporciona
		 * @return Puntero a la solución TSPSolution del problema
		 */			
		 TSPSolution solve();
};

#endif