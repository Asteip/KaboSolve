#include "solver.hpp"
#include "problem.hpp"
#include "problems/pNQueen.hpp"
#include "problems/pMoreMoney.hpp"
#include "domain.hpp"
#include "constraint.hpp"
#include "constraints/cInfOrEqual.hpp"
#include "constraints/cNQueen.hpp"
#include "constraints/cAllDiff.hpp"

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char **argv) {
	srand(time(NULL));
	//srand(0);
	clock_t debut, fin;

	cout << "Problème du N-reines" << endl;
	cout << "Démarrage du solver..." << endl << endl;

	int N = 5;
	//Problem *p = new PNQueen(N);

	Problem *p = new PMoreMoney();
	Solver s(p);

	debut = clock();
	s.solve();
	fin = clock();

	cout << endl << "temps : " << (double)(fin-debut)/CLOCKS_PER_SEC << "s" << endl;

	return 0;
}