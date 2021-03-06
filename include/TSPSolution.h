#ifndef TSPSOLUTION_H
#define TSPSOLUTION_H


class TSPSolution {
private:
	int *cities;
	int number_of_cities;
	double cost;

public:

	/**
		@brief Construye un objeto solución a partir de la solución parcial
		@param Solución parcial ya acabada
	*/
	TSPSolution(int *cities, int number_of_cities, double cost);

	/**
	 * @brief Constructor de copia de la clase
	 */

	TSPSolution(const TSPSolution &other);
	
	/**
	 * @brief Operador de asignación de la clase
	 */

	TSPSolution& operator=(const TSPSolution &other);
		

	/**
	 * @brief Destructor de la clase
	 */
	
	~TSPSolution();

	/**
		@brief Devuelve las ciudades en orden tal que el camino es óptimo
		@return un array con los índices de las ciudades en orden
	*/
	int *getCitiesInOrder();


	/**
		@brief Devuelve el número de ciudades
		@return el número de ciudades
	*/
	int getNumberOfCities();


	/**
		@brief Muestra por pantalla la solución
	*/
	void displaySolution();

};

#endif
