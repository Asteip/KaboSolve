#include "constraint.hpp"

Constraint::Constraint(int type, int constraintTabSize, int &constraintTab, int rightMember, Domain &domainTab, int domainTabSize){
	if(constraintTabSize != domainTabSize){
		std::cerr << "The number of left member of the constraint must be equal to the number of domain (ie : the number of possible variable)." << std::endl;
		return;
	}

	_type = type;
	_constraintTab = &constraintTab;
	_constraintTabSize = constraintTabSize;
	_rightMember = rightMember;
	_domainTab = &domainTab;
	_domainTabSize = domainTabSize;
}

Constraint::~Constraint(){
	delete _constraintTab;
}

// TODO modifier cette classe pour éviter la duplication de code.
void Constraint::prune(){
	if(_type == EQUAL){
		for(int i = 0 ; i < _domainTabSize ; ++i){
			//if(domainTab[i].)
		}
	}

	if(_type == INF_OR_EQUAL){
		for(int i = 0 ; i < _constraintTabSize ; ++i){
			int t  = _rightMember;

			for(int j = 0 ; j < _constraintTabSize ; ++j){
				if (j != i){
					if(_domainTab[j].getIsSet()){
						t += -1 * _constraintTab[j] * domainTab[j].getValue();
					}
					else{
						t += -1 * _constraintTab[j] * domainTab[j].getMin();
					}
				}
			}

			t /= _constraintTab[i];

			_domainTab[i].prunerSup(_domainTab[i].getId(), t);
		}
	}

	if(_type == INF){
		for(int i = 0 ; i < _constraintTabSize ; ++i){
			int t  = _rightMember;

			for(int j = 0 ; j < _constraintTabSize ; ++j){
				if (j != i){
					if(_domainTab[j].getIsSet()){
						t += -1 * _constraintTab[j] * domainTab[j].getValue();
					}
					else{
						t += -1 * _constraintTab[j] * domainTab[j].getMin();
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
						t += -1 * _constraintTab[j] * domainTab[j].getValue();
					}
					else{
						t += -1 * _constraintTab[j] * domainTab[j].getMax();
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
						t += -1 * _constraintTab[j] * domainTab[j].getValue();
					}
					else{
						t += -1 * _constraintTab[j] * domainTab[j].getMax();
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

	}
}

int Constraint::getType(){
	return _type;
}

int * Constraint::getConstraintTab(){
	return _constraintTab;
}

int Constraint::getConstraintTabSize(){
	return _constraintTabSize;
}

int Constraint::getRightMember(){
	return _rightMember;
}

Domain * Constraint::getDomainTab(){
	return _domainTab;
}

int Constraint::getDomainTabSize(){
	return _domainTabSize;
}