#include "constraint.hpp"

#include <iostream>

using namespace std;

Constraint::Constraint(Domain **domains, int size) {
	_domains = domains;
	_size = size;
}

Constraint::~Constraint() {
	for (int i = 0; i < _size; ++i) {
		delete(_domains[i]);
	}
	delete _domains;
}

int Constraint::getSize() {
	return _size;
}

Domain ** Constraint::getDomains() {
	return _domains;
}

void Constraint::display() {}