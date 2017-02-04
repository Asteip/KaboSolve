CXX=g++
CXXFLAGS=-g -O2 -std=c++11
LDFLAGS=

TARGET=KaboSolve
HPP_FILE=$(wildcard src/solver/*.hpp) $(wildcard src/prune/*.hpp)
SRC_SOLVER=$(wildcard src/solver/*.cpp)
SRC_PRUNE=$(wildcard src/prune/*.cpp)
OBJ_SOLVER=$(SRC_SOLVER:.cpp=.o)
OBJ_PRUNE=$(SRC_PRUNE:.cpp=.o)


all: $(TARGET)

$(TARGET): $(OBJ_SOLVER) $(OBJ_PRUNE)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

kaboSolve.o: $(HPP_FILE)

.PHONY: clean

clean:
	-rm src/solver/*.o src/prune/*.o KaboSolve