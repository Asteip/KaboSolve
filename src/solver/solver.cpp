#include "solver.hpp"
#include "domain.hpp"
#include "constraint.hpp"

#include "constraints/cInfOrEqual.hpp"
#include "constraints/cSupOrEqual.hpp"

#include <string>
#include <iostream>

using namespace std;

Solver::Solver (Problem *p) {
	_p = p;
	_n = p->getN();
	_domains = new Domain * [_n];
}

void Solver::solve() {
	int j, i = 0;
	int id;
	bool chercher = true;
	string entree;
	Domain *d = _p->getBestDomain();
	id = d->getId();


	Domain **dAffich = _p->getDomains();
	/*for (int k = 0; k < _n; ++k) {
 		cout << k << ":\t";
 		dAffich[k]->affichage();
 		//dAffich[k]->affichageNQueen();
 	}
 	cout << endl;*/


		cout << "S: "; dAffich[0]->affichageResultatSENDMORY();
	 	cout << "E: "; dAffich[1]->affichageResultatSENDMORY();
	 	cout << "N: "; dAffich[2]->affichageResultatSENDMORY();
	 	cout << "D: "; dAffich[3]->affichageResultatSENDMORY();
	 	cout << "M: "; dAffich[4]->affichageResultatSENDMORY();
	 	cout << "O: "; dAffich[5]->affichageResultatSENDMORY();
	 	cout << "R: "; dAffich[6]->affichageResultatSENDMORY();
	 	cout << "Y: "; dAffich[7]->affichageResultatSENDMORY();
	 	cout << "rY: "; dAffich[8]->affichageResultatSENDMORY();
	 	cout << "rE: "; dAffich[9]->affichageResultatSENDMORY();
	 	cout << "rN: "; dAffich[10]->affichageResultatSENDMORY();
	 	cout << "rO: "; dAffich[11]->affichageResultatSENDMORY();
	 	cout << "rM: "; dAffich[12]->affichageResultatSENDMORY();


	 	cout << endl << endl << endl;



 	while (chercher) {
		while ((i != -1) && (i < _n)) {
			//cout << "\n////////////////////////////////////////////////////////////" << endl << endl << endl << endl;

			/*for (int k = 0; k < _n; ++k) {
		 		cout << k << ":\t";
		 		dAffich[k]->affichage();
		 		//dAffich[k]->affichageNQueen();
		 	}
		 	cout << endl;

		 	cout << "i=" << i << endl;
			cout << "id=" << d->getId() << endl;*/
			if (d->getIsSet()) {
				_p->backtrack(id);
				if (d->getSize() > 0) {
					d->fixer();
					_p->applyConstraint(id);
					++i;
					if (i < _n) {
						d = _p->getBestDomain();
						id = d->getId();
					}
				} else {
					d->reset();
					--i;
					if (i >= 0) {
						d = _domains[i];
						id = d->getId();
					}
				}
			} else {
				if (d->getSize() > 0) {
					d->fixer();
					_domains[i] = d;
					_p->applyConstraint(id);
					++i;
					if (i < _n) {
						d = _p->getBestDomain();
						id = d->getId();
					}
				} else {
					--i;
					if (i >= 0) {
						d = _domains[i];
						id = d->getId();
					}
				}
			}


		cout << "S: "; dAffich[0]->affichageResultatSENDMORY();
	 	cout << "E: "; dAffich[1]->affichageResultatSENDMORY();
	 	cout << "N: "; dAffich[2]->affichageResultatSENDMORY();
	 	cout << "D: "; dAffich[3]->affichageResultatSENDMORY();
	 	cout << "M: "; dAffich[4]->affichageResultatSENDMORY();
	 	cout << "O: "; dAffich[5]->affichageResultatSENDMORY();
	 	cout << "R: "; dAffich[6]->affichageResultatSENDMORY();
	 	cout << "Y: "; dAffich[7]->affichageResultatSENDMORY();
	 	cout << "rY: "; dAffich[8]->affichageResultatSENDMORY();
	 	cout << "rE: "; dAffich[9]->affichageResultatSENDMORY();
	 	cout << "rN: "; dAffich[10]->affichageResultatSENDMORY();
	 	cout << "rO: "; dAffich[11]->affichageResultatSENDMORY();
	 	cout << "rM: "; dAffich[12]->affichageResultatSENDMORY();


	 	cout << endl << endl << endl;

		}

		//for (int k = 0; k < _n; ++k) {
		//	dAffich[k]->affichage();
		//	cout << endl << endl;
			/*if (dAffich[k]->getIsSet()) {
	 			cout << k << ": " << dAffich[k]->getValue() << endl;
	 		} else {
	 			cout << k << ": X" << endl;
	 		}*/
	 	//}

		if (i != -1) {
			/*for (int k = 0; k < _n; ++k) {
 				cout << k << ":\t";
 				dAffich[k]->affichageResultatNQueen();
 			}*/


 			cout << " "
 			<< dAffich[12]->getValue()
 			<< dAffich[11]->getValue()
 			<< dAffich[10]->getValue()
 			<< dAffich[9]->getValue()
 			<< dAffich[8]->getValue()
 			<< endl;

 			cout << "  "
 			<< dAffich[0]->getValue()
 			<< dAffich[1]->getValue()
 			<< dAffich[2]->getValue()
 			<< dAffich[3]->getValue()
 			<< endl;

 			cout << "+ "
 			<< dAffich[4]->getValue()
 			<< dAffich[5]->getValue()
 			<< dAffich[6]->getValue()
 			<< dAffich[1]->getValue()
 			<< endl;

 			cout << "------" << endl;

 			cout << " "
 			<< dAffich[4]->getValue()
 			<< dAffich[5]->getValue()
 			<< dAffich[2]->getValue()
 			<< dAffich[1]->getValue()
 			<< dAffich[7]->getValue()
 			<< endl;




 			/*for (int k = 0; k < _n; ++k) {
	 			cout << k << ": " << _domains[k]->getValue() << endl;
	 		}*/


 			cout << endl;
	 		cout << endl << "Trouver une autre solution ? o/n : ";
	 		cin >> entree;
	 		chercher = ((entree == "o") || (entree == "O"));
	 		--i;


	 		/*for (int k = 0; k < _n; ++k) {
	 			cout << k << ": " << _domains[k]->getValue() << endl;
	 		}*/
	 	} else {
	 		cout << "Pas de solution" << endl;
	 		chercher = false;
	 	}
 	}
}

void Solver::solveAll() {
	int j, i = 0;
	int id;
	Domain *d = _p->getBestDomain();
	id = d->getId();

	Domain **dAffich = _p->getDomains();

	while (i != -1) {
		while ((i != -1) && (i < _n)) {
			if (d->getIsSet()) {
				_p->backtrack(id);
					if (d->getSize() > 0) {
					d->fixer();
					_p->applyConstraint(id);
					++i;
					if (i < _n) {
						d = _p->getBestDomain();
						id = d->getId();
					}
				} else {
					d->reset();
					--i;
					if (i >= 0) {
						d = _domains[i];
						id = d->getId();
					}
				}
			} else {
				if (d->getSize() > 0) {
					d->fixer();
					_domains[i] = d;
					_p->applyConstraint(id);
					++i;
					if (i < _n) {
						d = _p->getBestDomain();
						id = d->getId();
					}
				} else {
					--i;
					if (i >= 0) {
						d = _domains[i];
						id = d->getId();
					}
				}
			}
		}

		if (i != -1) {
			cout << "ABRICOT FARCI" << endl;
			/*for (int k = 0; k < _n; ++k) {
				cout << k << ":\t";
				dAffich[k]->affichageResultatNQueen();
			}
			cout << endl;*/
			--i;
		} else {
			cout << "Pas de solution" << endl;
		}
	}
}

void Solver::test() {
	int *coef = new int [10];
	Domain **d = new Domain * [3];
	//CInfOrEqual *c;
	CSupOrEqual *c;

	int *l = new int [10];
	for (int i = 0; i < 10; ++i) {
		l[i] = 3*i+1;
	}
	coef[0] = 1;
	d[0] = new Domain(0, 10, l);

	l = new int [10];
	for (int i = 0; i < 10; ++i) {
		l[i] = 3*i+1;
	}
	coef[1] = 3;
	d[1] = new Domain(1, 10, l);

	//c = new CInfOrEqual(coef, 20, d, 2);
	c = new CSupOrEqual(coef, 41, d, 2);

	d[0]->affichage();
	d[1]->affichage();

	cout << endl << endl << "APPLICATION DE LA CONTRAINTE |||||||||||||||||||||||||||" << endl << endl;
	c->applyConstraint(0);

	d[0]->affichage();
	d[1]->affichage();
}