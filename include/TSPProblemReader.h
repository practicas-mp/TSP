#ifndef TSPPROBLEMREADER_H
#define TSPPROBLEMREADER_H

#include <iostream>
#include <fstream>
#include "TSPProblem.h"

using namespace std;

class TSPProblemReader {
private:

public:
	TSPProblem read(string filename); 	
};

#endif