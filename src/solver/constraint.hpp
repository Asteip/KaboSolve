#ifndef CONSTRAINT_HPP
#define CONSTRAINT_HPP

#include <iostream>
#include "domain.hpp"

/*!
 * \brief Represents a constraint of a constraint satisfaction problem.
 * \details The constraint is represented by a set of domains on which the constraint has to be applied of.
 */
class Constraint {

public:
	/*!
	 * \brief Creates a new instance of a constraint.
	 * \param domains The set of all domain concerned by the current constraint, identified by their id.
	 * \param size The number of elements in the set of domains. It's also the number of variables concerned by the current constraint.
	 */
	Constraint(Domain **domains, int size);

	/*!
	 * \brief Deletes a Constraint.
	 */
	virtual ~Constraint();

	/*!
	 * \brief Checks if the constraint is respected.
	 * \details This function is called when a variable is fixed in a domain. 
	 * All unset domain are pruned using this constraint.
	 * \param id The domain which is the cause of the applyConstraint called.
	 * \return True if some modifications occured, false otherwise.
	 */
	virtual bool applyConstraint(int id) = 0;

	/*!
	 * \brief Display information to the standard output.
	 */
	virtual void display() = 0;

	// ACCESSORS

	/*!
	 * \brief Returns the number of domains.
	 * \return The size of the set of domains.
	 */
	int getSize();
	
	/*!
	 * \brief Returns the set of domains.
	 * \return The set of domains.
	 */
	Domain ** getDomains();

protected:
	int _size;
	Domain **_domains;
};

#endif
