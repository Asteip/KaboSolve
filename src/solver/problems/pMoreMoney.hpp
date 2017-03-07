#ifndef P_MORE_MONEY_HPP
#define P_MORE_MONEY_HPP

#include "../problem.hpp"
#include "../constraint.hpp"
#include "../constraints/cEqual.hpp"
#include "../constraints/cSupOrEqual.hpp"
#include "../constraints/cInfOrEqual.hpp"

class PMoreMoney : public Problem {

	public:
		PMoreMoney();
		~PMoreMoney();

	private:
		void generateProblem();
};

#endif