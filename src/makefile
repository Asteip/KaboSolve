CXX=g++
CXXFLAGS=-g -O2 -std=c++11

all: KaboSolve

.PHONY: clean

clean:
	-rm *.o KaboSolve

KaboSolve: Domain.o KaboSolve.o Variable.o
	$(CXX) -o KaboSolve Domain.o KaboSolve.o Variable.o