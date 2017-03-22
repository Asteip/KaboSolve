#include "pNQueen.hpp"

using namespace std;

PNQueen::PNQueen(int n){
	_n = n;
	generateProblem();
}

PNQueen::~PNQueen() {}

void PNQueen::generateProblem() {
	// Create the domains
	_domains = new Domain * [_n];
	int *line;
	Domain **lDom;

	for (int i = 0 ; i < _n ; ++i){
		line = new int [_n];
		for (int j = 0 ; j < _n ; ++j){
			line[j] = j;
		}
		_domains[i] = new Domain(i, _n, line);
	}

	// Create the constraints
	_m = 3;
	_constraints = new Constraint * [2];

	_constraints[0] = new CNQueen(_domains, _n);
	_constraints[1] = new CAllDiff(_domains, _n);

	lDom = new Domain * [2];
	lDom[0] = _domains[0];
	lDom[1] = _domains[_n-1];
	line = new int [2];
	line[0] = 1;
	line[1] = -1;
	_constraints[2] = new CInfOrEqual(line, 0, lDom, 2);

}

void PNQueen::applyConstraint(int id) {
	for(int i = 0 ; i < _m ; ++i){
		_constraints[i]->applyConstraint(id);
	}
}

void PNQueen::afficher() {
	for (int i = 0; i < _n; ++i) {
		int k;
		for (k = 0; k < _domains[i]->getValue(); ++k) {
			cout << "_ ";
		}
		cout << "O ";
		for (k = k+1; k < _n; ++k) {
			cout << "_ ";
		}
		cout << endl;
	}
}