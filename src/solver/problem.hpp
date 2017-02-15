#ifndef PROBLEM_HPP
#define PROBLEM_HPP

#include "domain.hpp"
#include "constraint.hpp"

class Problem{

public:
	Problem();
	virtual ~Problem();

	Domain * getMinDomain();

	int getN();
	Domain ** getDomains();
	int getM();
	Constraint ** getConstraints();

protected:
	virtual void generateProblem() = 0;

protected:
	int _n;
	Domain **_domains;
	int _m;
	Constraint **_constraints;
};

#endif