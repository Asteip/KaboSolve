#ifndef CONSTRAINT_HPP
#define CONSTRAINT_HPP

#include <iostream>
#include "domain.hpp"

/*!
 * \brief Represent a constraint of a constraint satisfaction problem.
 * \details This class represent a sum constraint of a satisfaction problem,
 * it can be an equal, a different or an inequality constraint.
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
	 * \param type The type of the constraint.
	 * \param constraintTabSize The size of the array that contains left members of the constraint.
	 * \param constraintTab The array that contains left members of the constraint.
	 * \param rightMember The right member of the constraint.
	 * \param domainTab The set of all domain identified by their id.
	 * \param domainTabSize The size of domainTab.
	 */
	Constraint(int type, int constraintTabSize, int &constraintTab, int rightMember, Domain &domainTab, int domainTabSize);

	/*!
	 * \brief Destructor of Constraint.
	 * \details Delete the constraintTabSize.
	 */
	~Constraint();

	/*!
	 * \brief Prune the set of domain.
	 * \details This function is called when a variable is fixed in a domain.
	 * All domain are pruned using this constraint.
	 */
	void prune();

	// ACCESSORS

	int getType();
	int * getConstraintTab();
	int getConstraintTabSize();
	int getRightMember();
	Domain * getDomainTab();
	int getDomainTabSize();

private:
	int _type;
	int *_constraintTab;
	int _constraintTabSize;
	int _rightMember;

	Domain *_domainTab;
	int _domainTabSize;
};

#endif