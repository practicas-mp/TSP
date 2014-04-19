CC = g++
BIN = ./bin
DOC = ./doc
INCLUDE = ./include
OBJ = ./obj
SRC = ./src
SOURCES := $(wildcard $(SRC)/*.cpp)
OBJECTS := $(SOURCES:$(SRC)/%.cpp=$(OBJ)/%.o)

all: $(BIN)/tsp

$(BIN)/tsp: $(OBJECTS)
	$(CC) -I $(INCLUDE) -o $@ $^

$(OBJECTS): $(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) -I $(INCLUDE) -o $@  -c $<

clean:
	rm -f $(OBJ)/*.o

doc:
	doxygen $(DOC)/doxys/Doxyfile

.PHONY: all clean doc