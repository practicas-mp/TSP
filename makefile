CC = g++
BIN = ./bin
DOC = ./doc
INCLUDE = ./include
OBJ = ./obj
SRC = ./src
SOURCES = $(SRC)/$(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

all: $(BIN)/tsp

$(BIN)/tsp: $(OBJECTS)
	$(CC) -o $@ $^

$(OBJ)/%.o: $(SRC)/%.cpp $(INCLUDE)/%.h
	$(CC) -o $@ -I $(INCLUDE) -c $<

$(OBJ)/main.o: $(SRC)/main.cpp $(INCLUDE)/tsp.h
	g++ -o $@ -I $(INCLUDE) -c $<

clean:
	rm $(OBJ)/*.o

doc:
	doxygen $(DOC)/doxys/Doxyfile

.PHONY: all clean doc