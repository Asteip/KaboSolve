#ifndef CONSTRAINT_HPP
#define CONSTRAINT_HPP

#include <iostream>
#include "domain.hpp"

/*!
 * \brief Represent a constraint of a constraint satisfaction problem.
 * \details This class represent a sum constraint of a satisfaction problem,
 * it can be an equal, a different or an inequality constraint.
 */
class Constraint {

public:
	/*!
	 * \brief Create a new instance of a constraint.
	 * \param coefficients The array that contains left members of the constraint.
	 * \param rightMember The right member of the constraint.
	 * \param domains The set of all domain identified by their id.
	 * \param size The number of variables (ie : the number of coefficicents and domains)
	 */
	Constraint(Domain **domains, int size);

	/*!
	 * \brief Destructor of Constraint.
	 */
	virtual ~Constraint();

	/*!
	 * \brief Verify that the constraint is respected.
	 * \details This function is called when a variable is fixed in a domain.
	 * All domain are checked using this constraint.
	 */
	virtual void applyConstraint(int id) = 0;

	/*!
	 * \brief Display information to the standard output.
	 */
	virtual void display() = 0;

	// ACCESSORS

	virtual int getSize();
	virtual Domain ** getDomains();

protected:
	int _size;
	Domain **_domains;
};

#endif