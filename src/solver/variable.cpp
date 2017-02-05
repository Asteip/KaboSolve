#include "variable.hpp"

Variable::Variable(std::string name, int id, Domain &domain){
	_name = name;
	_id = id;
	_domain = &domain;
}

std::string Variable::getName(){
	return _name;
}

int Variable::getId(){
	return _id;
}

Domain * Variable::getDomain(){
	return _domain;
}

void Variable::setName(std::string name){
	_name = name;
}

void Variable::setId(int id){
	_id = id;
}

void Variable::setDomain(Domain &domain){
	_domain = &domain;
}