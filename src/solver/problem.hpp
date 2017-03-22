#ifndef PROBLEM_HPP
#define PROBLEM_HPP

#include "domain.hpp"
#include "constraint.hpp"

/*!
 * \brief Represent a constraint satisfaction problem. 
 * \details This class represents a generic model of a constraint satisfaction problem. To create
 * a specific problem, this class must be inherited.
 */
class Problem{

public:

	/*!
	 * \brief
	 */
	Problem();
	
	/*!
	 * \brief
	 */
	virtual ~Problem();

	/*!
	 * 
	 */
	virtual Domain * getBestDomain();
	
	/*!
	 * 
	 */
	virtual void applyConstraint(int id);
	
	/*!
	 * 
	 */
	virtual void backtrack(int id);
	
	/*!
	 * 
	 */
	virtual void afficher();

	// ACCESSORS

	/*!
	 * 
	 */
	int getN();
	
	/*!
	 * 
	 */
	Domain ** getDomains();
	
	/*!
	 * 
	 */
	int getM();
	
	/*!
	 * 
	 */
	Constraint ** getConstraints();

protected:
	
	/*!
	 * 
	 */
	virtual void generateProblem() = 0;

protected:
	int _n;							// The number of domains in the problem.
	Domain **_domains;				// The domains concerned by the problem.
	int _m;							// The number of constraint in the problem.
	Constraint **_constraints;		// The constraint uses by the problem.
};

#endif
