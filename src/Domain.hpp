#ifndef DOMAIN_HPP
#define DOMAIN_HPP

class Domain {
	private:
		int n;
		int size;
		int *set;		// Valeurs possibles du domaine 
		int *indexes;	// Identifiant de la variable qui a imposé le prunage
		int *pruned;	// Indices des valeurs prunées du domaine
	
	private:
		void swap(int i, int j);
		
	public:
		Domain(int n, int *set);
};

#endif
