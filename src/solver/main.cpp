#include "solver.hpp"
#include "problem.hpp"
#include "problems/pNQueen.hpp"
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

int main(int argc, char **argv){
	//srand(time(NULL));
	srand(0);

	cout << "Problème du N-reines" << endl;
	cout << "Démarrage du solver..." << endl << endl;

	int N = 5;
	Problem *p = new PNQueen(N);




		////// NQUEEN

	// clock_t debut, fin;
	// int n = 30;
	// int *set;

	// Domain **d = new Domain * [n];
	// Constraint **c = new Constraint * [2];

	// for (int i = 0; i < n; ++i) {
	// 	set = new int [n];
	// 	for (int j = 0; j < n; ++j) {
	// 		set[j] = j;
	// 	}
	// 	d[i] = new Domain(i, n, set);
	// }

	// c[0] = new CAllDiff(d, n);
	// c[1] = new CNQueen(d, n);

	// /*for (int i = 0; i < n; ++i) {
	// 	d[i]->affichage();
	// }*/

	// Solver s(d, n, c, 2);

	// debut = clock();
	// s.solve();
	// fin = clock();

	// cout << endl << "temps : " << (double)(fin-debut)/CLOCKS_PER_SEC << "s" << endl;

	return 0;
}