class TSPSolution {
private:
	TSPPartialSolution *partial_solution_completed;

public:

	/**
		@brief Construye un objeto solución a partir de la solución parcial
		@param Solución parcial ya acabada
	*/
	TSPSolution(TSPPartialSolution partial_solution_completed);

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