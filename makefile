CXX=g++
CXXFLAGS=-g -Ofast
LDFLAGS=-std=c++11

TARGET=KaboSolve
HPP_FILE=$(wildcard src/solver/*.hpp)
SRC_SOLVER=$(wildcard src/solver/*.cpp)
OBJ_SOLVER=$(SRC_SOLVER:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ_SOLVER) $(OBJ_PRUNE)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

kaboSolve.o: $(HPP_FILE)

.PHONY: clean

clean:
	-rm src/solver/*.o KaboSolve
