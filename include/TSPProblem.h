#ifndef TSPPROBLEM_H
#define TSPPROBLEM_H
#include "TSPPoint.h"
#include "TSPSolver.h"

using namespace std;


/**
 * Clase TSPProblem. Representa una instancia del problema del
 * viajante de comercio (un conjunto de ciudades y las distancias entre ellas).
 */

class TSPProblem {

	private:

		/**
		 * Puntero a una instancia de la clase TSPSolver que
		 * se encargará de resolver el problema
		 */

		TSPSolver* solver;

		/**
		 * Puntero a la matriz de distancias entre las ciudades
		 */

		double** distances;

		/**
		 * Array con las instancias de la clase TSPPoint 
		 * que representan las ciudades del problema
		 */

		TSPPoint* cities;

		/**
		 * @brief Método que permite calcular la matriz de distancias asociada al problema
		 */

		void computeDistances();

		/**
		 * Atributo que controla el número de ciudades que debe manejar el problema
		 */

		int num_cities;

	public:

		/**
		 * @brief Constructor de la clase
		 * @param cities Puntero al array de ciudades del problema
		 * @param num_cities El total de ciudades de que consta el problema
		 */


		TSPProblem(TSPPoint* cities, int num_cities);

		/**
		 * @brief Getter de la matriz de distancias
		 * @return Puntero a la matriz
		 */			

		double** getDistancesMatrix();

		/**
		 * @brief Getter del número de ciudades del problema
		 * @return Número de ciudades
		 */			

		int getNumberOfCities();
};

#endif