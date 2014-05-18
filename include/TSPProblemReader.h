#ifndef TSPPROBLEMREADER_H
#define TSPPROBLEMREADER_H

#include <iostream>
#include <fstream>
#include "TSPProblem.h"

using namespace std;

class TSPProblemReader {
private:

public:
	/**
		@brief Devuelve una instancia de la clase problema a partir de su archivo
		@param El nombre del archivo del problema
		@return El problema especificado en el archivo
	*/
	TSPProblem read(string filename); 	
};

#endif