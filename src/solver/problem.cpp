#include "problem.hpp"

Problem::Problem(){}

Problem::~Problem(){
	for (int i = 0 ; i < _n ; ++i){
		delete _domains[i];
	}

	for (int i = 0 ; i < _m ; ++i){
		delete _constraints[i];
	}

	delete _domains;
	delete _constraints;
}

int Problem::getN(){
	return _n;
}

Domain ** Problem::getDomains(){
	return _domains;
}

int Problem::getM(){
	return _m;
}

Constraint ** Problem::getConstraints(){
	return _constraints;
}