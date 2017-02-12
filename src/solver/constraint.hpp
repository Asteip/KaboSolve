#ifndef CONSTRAINT_HPP
#define CONSTRAINT_HPP

#include "variable.hpp"
#include "domain.hpp"

/*!
 * \brief Represent a constraint of a constraint satisfaction problem.
 * \details This class represent a sum constraint of a satisfaction problem,
 * it can be an equal or an inequality constraint.
 */
class Constraint{

public:
	static const int EQUAL = 0;
	static const int INF_OR_EQUAL = 1;
	static const int INF = 2;
	static const int SUP_OR_EQUAL = 3;
	static const int SUP = 4;
	static const int DIFF = 5;
	static const int ALL_DIFF = 6;

	/*!
	 * \brief Create a new instance of a constraint.
	 * \param type The type of the constraint
	 * \param constraintTabSize The size of the array that contains left members of the constraint.
	 * \param constraintTab The array that contains left members of the constraint.
	 * \param rightMember The right member of the constraint
	 * \param variable The variables concerns by the constraint
	 */
	Constraint(int type, int constraintTabSize, int &constraintTab, int rightMember, Variable &variable);

	/*!
	 * \brief Destructor of Constraint
	 * \details delete the constraintTabSize.
	 */
	~Constraint();

	// ACCESSOR AND MODIFIER

	int getType();
	int getConstraintSize();
	int getCoefficient(int index);
	int getRightMember();

private:
	int _type;
	int * _constraintTab;
	int _constraintTabSize;
	int _rightMember;

	Variable * _variable;
};

#endif