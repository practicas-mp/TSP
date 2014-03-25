#include "TSPProblem.h"

class TSPPartialSolution {
private:
	TSPProblem *problem;
	
	int number_of_cities;

	int *cities;
	bool *visitadas;

	int cities_inserted;

	double **distances;




public:
	
	/**
		@brief Constructor principal de la solución parcial
		@param problem El problema que se quiere resolver
		@return void
	*/
	TSPPartialSolution(TSPProblem problem);


	/** 
		@brief Calcula el coste que tendría la inserción de una ciudad en una posición concreta
		@param city El numero que representa la ciudad
		@param position La posicion en la que se quiere calcular el coste
		@return cost El coste
	*/
	double getCostOfInsertion(int city, int position);



	/**
		@brief Fija una ciudad en una posición determinada
		@param city El numero que representa a la ciudad
		@param position La posicion en la que insertar la ciudad
		@return void
	*/
	void insertCity(int city, int position);

	
};