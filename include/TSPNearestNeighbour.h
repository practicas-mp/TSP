#ifndef TSPNEARESTNEIGHBOUR_H
#define TSPNEARESTNEIGHBOUR_H

#include "TSPProblem.h"
#include "TSPSolver.h"
#include "TSPSolution.h"
#include "TSPPartialSolution.h"

using namespace std;

/**
 * Clase TSPBestInsertion que se encarga de la heurística
 * que usaremos en esta práctica para resolver el problema del TSP
 */
	

class TSPNearestNeighbour: public TSPSolver {

	private:

		/**
		 * Puntero a una instancia de la clase TSPPartialSolution para
		 * manejar los pasos intermedios de la solución con comodidad
		 */

		TSPPartialSolution *partial;


		/**
			@brief Resuelve el problema usando como primera ciudad la indicada
			@return Una solución parcial que se comparará luego con el resto
		*/
		TSPPartialSolution solveWithCityAsFirst(int city_number);

	public:

		/**
		 * @brief Constructor de la clase TSPNearestNeighbour.
		 * @param problem Puntero a la instancia de TSPProblem que representa el problema concreto a resolver
		 */			

		TSPNearestNeighbour(TSPProblem *problem);

		/**
		 * @brief Constructor de copia de la clase TSPNearestNeighbour
		 * @param other Instancia de la clase TSPNearestNeighbour de la que se quiere copiar
		 */
			
		TSPNearestNeighbour(const TSPNearestNeighbour& other);

		/**
		 * @brief Operador de asignación de la clase TSPBestInsertion
		 * @param other Instancia de la clase TSPBestInsertion que queremos asignar
		 */

		TSPNearestNeighbour& operator=(const TSPNearestNeighbour &other);



		/**
			@brief Destructor
		*/
		~TSPNearestNeighbour();

		/**
		 * Método para resolver por completo el problema que se
		 * nos proporciona
		 * @return TSPSolution del problema
		 */			
		 TSPSolution solve();



};

#endif