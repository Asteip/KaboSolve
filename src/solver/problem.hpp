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
	 * \brief Constructor of Problem. To create an instance of a specific problem, you must use an inherited class of it. 
	 */
	Problem();
	
	/*!
	 * \brief Destructor of Problem.
	 */
	virtual ~Problem();

	/*!
	 * \brief Returns the best domain at a time t.
	 * \details By default, this method returns the domain with the minimum size.
	 * This method can be overridden as needed.
	 * \return A domain object which represent the best domain in the domain list used by the problem.
	 */
	virtual Domain * getBestDomain();
	
	/*!
	 * \brief Calls the applyConstraint method of each constraint.
	 * \details While a modification occurs in the domain list, this method applies each constraint of the problem.
	 * This method can be overridden as needed.
	 * \param id The domain which is the cause of the applyConstraint called (ie : the domain which just has been set).
	 */
	virtual void applyConstraint(int id);
	
	/*!
	 * \brief Calls the backtrack method of each domain.
	 * \details For each domain of the domain list, undo the pruning of the values which have been pruned by the variable with the given id.
	 * \param id The identifiant of the domain responsible of the pruning, this is also the variable which was set.
	 */
	virtual void backtrack(int id);
	
	/*!
	 * \brief Display the problem result to the starndard output.
	 */
	virtual void afficher();

	// ACCESSORS

	/*!
	 * \brief Returns the number of domains in the current problem.
	 * \return The number of domains.
	 */
	int getN();
	
	/*!
	 * \brief Returns the array of domains concerned by the problem.
	 * \return A pointer of the array of domains.
	 */
	Domain ** getDomains();
	
	/*!
	 * \brief Returns the number of constraint of the problem.
	 * \return The number of constraint.
	 */
	int getM();
	
	/*!
	 * \brief Returns the array of constraint used by the problem.
	 * \return A pointer of the array of constraints.
	 */
	Constraint ** getConstraints();

protected:
	
	/*!
	 * \brief Protected method, it must be implemented by a specific problem.
	 * \details This method initializes the domains (variables) and the constraints of the problem.
	 */
	virtual void generateProblem() = 0;

protected:
	int _n;							// The number of domains in the problem.
	Domain **_domains;				// The domains concerned by the problem.
	int _m;							// The number of constraint of the problem.
	Constraint **_constraints;		// The constraint uses by the problem.
};

#endif
