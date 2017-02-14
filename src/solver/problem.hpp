#ifndef PROBLEM_HPP
#define PROBLEM_HPP

#include "domain.hpp"
#include "constraint.hpp"

class Problem{

public:
	Problem();
	virtual ~Problem();

	virtual Domain * getMinDomain() = 0;

	virtual int getN();
	virtual Domain ** getDomains();
	virtual int getM();
	virtual Constraint ** getConstraints();

protected:
	int _n;
	Domain **_domains;
	int _m;
	Constraint **_constraints;
};

#endif