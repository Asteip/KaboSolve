#include "constraint.hpp"

#include <iostream>

using namespace std;

Constraint::Constraint(int type, int *coefficients, int rightMember, Domain **domainTab, int size) {
	_type = type;
	_coefficients = coefficients;
	_rightMember = rightMember;
	_domainTab = domainTab;
	_size = size;
}

Constraint::~Constraint() {
	for (int i = 0; i < _size; ++i) {
		delete(_domainTab[i]);
	}
	delete _domainTab;
	delete [] _coefficients;
}

// TODO modifier cette classe pour éviter la duplication de code.
void Constraint::prune(int id) {
	doube td;
	/*if(_type == EQUAL){
		for(int i = 0 ; i < _domainTabSize ; ++i){
			//if(domainTab[i].)
		}
	}*/

	if(_type == INF_OR_EQUAL) {
		for(int i = 0; i < _size; ++i) {
			int t  = _rightMember;
			if (!_domainTab[i]->getIsSet()) {
				for(int j = 0; j < _size; ++j) {
					if (i!=j) {
						if(_domainTab[j]->getIsSet()) {
							t += -_coefficients[j]*_domainTab[j]->getValue();
						} else {
							t += -_coefficients[j]*_domainTab[j]->getMin();
						}
					}
				}
				td = t;
				t /= _coefficients[i];
				td /= _coefficients[i];
				cout << "t=" << t << endl;

				if (t == td) {
					_domainTab[i]->prunerSup(id, t);
				} else {
					_domainTab[i]->prunerSup(id, t+1);
				}
			}
		}
	}

	/*if(_type == INF){
		for(int i = 0 ; i < _constraintTabSize ; ++i){
			int t  = _rightMember;

			for(int j = 0 ; j < _constraintTabSize ; ++j){
				if (j != i){
					if(_domainTab[j].getIsSet()){
						t += -1 * _constraintTab[j] * _domainTab[j].getValue();
					}
					else{
						t += -1 * _constraintTab[j] * _domainTab[j].getMin();
					}
				}
			}

			t /= _constraintTab[i];

			_domainTab[i].prunerSup(_domainTab[i].getId(), t - 1);
		}
	}

	if(_type == SUP_OR_EQUAL){
		for(int i = 0 ; i < _constraintTabSize ; ++i){
			int t  = _rightMember;

			for(int j = 0 ; j < _constraintTabSize ; ++j){
				if (j != i){
					if(_domainTab[j].getIsSet()){
						t += -1 * _constraintTab[j] * _domainTab[j].getValue();
					}
					else{
						t += -1 * _constraintTab[j] * _domainTab[j].getMax();
					}
				}
			}

			t /= _constraintTab[i];

			_domainTab[i].prunerInf(_domainTab[i].getId(), t);
		}
	}

	if(_type == SUP){
		for(int i = 0 ; i < _constraintTabSize ; ++i){
			int t  = _rightMember;

			for(int j = 0 ; j < _constraintTabSize ; ++j){
				if (j != i){
					if(_domainTab[j].getIsSet()){
						t += -1 * _constraintTab[j] * _domainTab[j].getValue();
					}
					else{
						t += -1 * _constraintTab[j] * _domainTab[j].getMax();
					}
				}
			}

			t /= _constraintTab[i];

			_domainTab[i].prunerInf(_domainTab[i].getId(), t - 1);
		}
	}

	if(_type == DIFF){

	}

	if(_type == ALL_DIFF){

	}*/
}

int Constraint::getType() {
	return _type;
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

Domain ** Constraint::getDomainTab() {
	return _domainTab;
}


void Constraint::afficher() {
	cout << "size=" << _size << endl;
	cout << "rightMember=" << _rightMember << endl;
	cout << endl << "contrainte : ";
	for (int i = 0; i < _size; ++i) {
		cout << _coefficients[i] << "*X" << _domainTab[i]->getId() << " + ";
	}
	cout << " <= " << _rightMember << endl;
}