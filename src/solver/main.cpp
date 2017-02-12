#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "solver.hpp"
#include "domain.hpp"

using namespace std;

int main(int argc, char **argv){
	srand(time(NULL));
	
	cout << "Démarrage du solver..." << endl;
	
	int *coco = new int [10];
	for (int i = 0; i < 10; ++i) {
		coco[i] = 20 - 2*i;
	}
	Domain D(10, coco);

	return 0;
}