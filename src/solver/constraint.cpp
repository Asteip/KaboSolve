#include "constraint.hpp"

#include <iostream>

using namespace std;

Constraint::Constraint(int *coefficients, int rightMember, Domain **domains, int size) {
	_coefficients = coefficients;
	_rightMember = rightMember;
	_domains = domains;
	_size = size;
}

Constraint::~Constraint() {
	for (int i = 0; i < _size; ++i) {
		delete(_domains[i]);
	}
	delete _domains;
	delete [] _coefficients;
}

void Constraint::display() {
	cout << "size=" << _size << endl;
	cout << "rightMember=" << _rightMember << endl;
	cout << endl << "contrainte : ";
	for (int i = 0; i < _size; ++i) {
		cout << _coefficients[i] << "*X" << _domains[i]->getId() << " + ";
	}
	cout << " <= " << _rightMember << endl;
}

int * Constraint::getCoefficients() {
	return _coefficients;
}

int Constraint::getSize() {
	return _size;
}

int Constraint::getRightMember() {
	return _rightMember;
}

Domain ** Constraint::getDomains() {
	return _domains;
}