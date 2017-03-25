#ifndef P_MAGIC_SQUARE
#define P_MAGIC_SQUARE

#include "../problem.hpp"
#include "../constraint.hpp"
#include "../constraints/cEqual.hpp"
#include "../constraints/cAllDiff.hpp"
#include "../constraints/cInfOrEqual.hpp"

class PMagicSquare : public Problem {

	private:
		int _taille;
		int _magic;

	public:
		PMagicSquare(int n);
		~PMagicSquare();

		void afficher();

	private:
		void generateProblem();
};

#endif
