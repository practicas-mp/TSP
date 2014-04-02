CC = g++
BIN = ./bin
DOC = ./doc
INCLUDE = ./include
OBJ = ./obj
SRC = ./src
SOURCES = $(wildcard src/*.cpp)
OBJECTS = $((SOURCES:.cpp=.o):src=obj)

all: $(BIN)/tsp

$(BIN)/tsp: TSPBestInsertion.o  TSPPartialSolution.o  TSPPoint.o  TSPProblem.o  TSPProblemReader.o  TSPSolution.o  TSPSolver.o
	g++ -I $(INCLUDE) -o $@ $^

$(OBJ)/%.o: $(SRC)/%.cpp $(INCLUDE)/%.h
	g++ -I $(INCLUDE) -o $@  -c $<

$(OBJ)/main.o: $(SRC)/main.cpp
	g++ -I $(INCLUDE) -o $@ -c $<

clean:
	rm -f $(OBJ)/*.o

doc:
	doxygen $(DOC)/doxys/Doxyfile

.PHONY: all clean doc