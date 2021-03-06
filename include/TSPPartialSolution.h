#ifndef TSPPARTIALSOLUTION_H
#define TSPPARTIALSOLUTION_H

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
	TSPPartialSolution(TSPProblem *problem);

	/**
	 * @brief Operador de asignación de la clase
	 */
		
	TSPPartialSolution& operator=(const TSPPartialSolution &other);

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

	

	/**
		@brief Un getter para el objeto problema asociado a la solución parcial
		@return El objeto problema asociado a la solución parcial

	*/
	TSPProblem getProblem();


	/**
		@brief Devuelve el número de ciudades de la solución parcial
		@return El número de ciudades de la solución parcial

	*/

	int getNumberOfCities();


	/**
		@brief Devuelve las ciudades tal como han sido insertadas
		@return un array con las ciudades tal como fueron insertadas
	*/
	int *getCities();


	/**
		@brief Devuelve si una ciudad ha sido insertada previamente
		@return true si ha sido insertada
	*/
	bool isAlreadyVisited(int city);

	/**
		@brief Devuelve el coste de la ruta actual 
		@return Un float con el coste actual
	*/
	double getCurrentCost();


	/**
		@brief Devuelve la distancia de la ciudad en la última posición a la indicada
		@param La ciudad indicada
		@return La distancia de la última a la indicada
	*/
	double getLastNeighbourCost(int city);

	/**
		@brief Destructor 
	**/
	~TSPPartialSolution();


};

#endif
