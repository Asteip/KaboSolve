#include "solver.hpp"
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

	cout << "Démarrage du solver..." << endl << endl;
	
	/*Domain **d = new Domain * [5];
	int taille;
	int **coco = new int * [5];
	for (int i = 0; i < 5; ++i) {
		taille = 3 + rand() % 7;
		coco[i] = new int [taille];
		for (int j = 0; j < taille; ++j) {
			//coco[i][j] = rand() % 100;
			coco[i][j] = j;
		}
		d[i] = new Domain(i, taille, coco[i]);
	}


	cout << "ENSEMBLES DE DEPART" << endl;
	for (int j = 0; j < 5; ++j) {
		d[j]->affichage();
	}

	int *toto = new int [5];
	for (int i = 0; i < 5; ++i) {
		toto[i] = 1 + rand() % 3;
	}

	//Constraint * c = new CInfOrEqual(toto, 150, d, 5);
	Constraint * c = new CNQueen(d, 5);
	Constraint * cdiff = new CAllDiff(d, 5);

	cout << endl << endl << "CONTRAINTE" << endl;
	c->display();

	cout << endl << "PRUNAGE" << endl;
	d[0]->fixer();
	c->applyConstraint(0);
	cdiff->applyConstraint(0);

	cout << endl << "ENSEMBLES APRES PRUNAGE" << endl;
	for (int j = 0; j < 5; ++j) {
		d[j]->affichage();
	}*/



		////// NQUEEN

	int n = 4;
	int *set;

	Domain **d = new Domain * [n];
	Constraint **c = new Constraint * [2];

	for (int i = 0; i < n; ++i) {
		set = new int [n];
		for (int j = 0; j < n; ++j) {
			set[j] = j;
		}
		d[i] = new Domain(i, n, set);
	}

	c[0] = new CAllDiff(d, n);
	c[1] = new CNQueen(d, n);

	/*for (int i = 0; i < n; ++i) {
		d[i]->affichage();
	}*/

	Solver s(d, n, c, 2);
	s.solve();

	return 0;
}