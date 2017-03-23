#ifndef SOLVER_HPP
#define SOLVER_HPP

#include "domain.hpp"
#include "constraint.hpp"
#include "constraints/cAllDiff.hpp"
#include "constraints/cNQueen.hpp"
#include "problem.hpp"

class Solver{

public:

	/*!
	 * \brief Creates an instance of a solver.
	 * \param p The instance of the problem which has to solved.
	 */
	Solver (Problem *p);
	
	/*!
	 * \brief Finds the first solution of the current problem.
	 * \details Solves the current problem and print to the standard output the first solution which can be found.
	 * User can choose between stop the algorithm after the first result or continue the execution for each
	 * solutions until all solutions have been found.
	 */
	void solve();
	
	/*!
	 * \brief Finds all solution of the current problem.
	 * \details Solves the current problem and finds all solution. It doesn't print all the solutions because of the 
	 * too big number of possible solutions. The total of solutions is printed at the end of the execution and the executed
	 * time.
	 */
	void solveAll();

private:
	Problem *_p;		// Instance of a problem
	int _n;				// Number of domains of the problem
	Domain **_domains;	// Array of domains of the problem
};

#endif
