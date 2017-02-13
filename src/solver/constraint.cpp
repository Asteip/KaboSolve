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

/*void Constraint::display() {
	cout << "size=" << _size << endl;
	cout << "rightMember=" << _rightMember << endl;
	cout << endl << "contrainte : ";
	for (int i = 0; i < _size; ++i) {
		cout << _coefficients[i] << "*X" << _domains[i]->getId() << " + ";
	}
	cout << " <= " << _rightMember << endl;
}*/

int Constraint::getSize() {
	return _size;
}

Domain ** Constraint::getDomains() {
	return _domains;
}