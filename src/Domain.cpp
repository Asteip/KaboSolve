#include "Domain.hpp"

#include <iostream>

void Domain::swap(int i, int j) {
	int tmp;
	
	tmp = indexes[i];
	indexes[i] = indexes[j];
	indexes[j] = tmp;
	
	tmp = set[i];
	set[i] = set[j];
	set[j] = tmp;
}

Domain::Domain(int n, int *set) {
	this->n = n;
	this->set = set;
}
