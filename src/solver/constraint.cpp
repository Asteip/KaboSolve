#include "constraint.hpp"

Constraint::Constraint(int type, int constraintTabSize, int &constraintTab, int rightMember){
	_type = type;
	_constraintTab = &constraintTab;
	_constraintTabSize = constraintTabSize;
	_rightMember = rightMember;
}

Constraint::~Constraint(){
	delete _constraintTab;
}