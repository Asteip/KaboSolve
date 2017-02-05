#ifndef DOMAIN_HPP
#define DOMAIN_HPP

class Domain {
	private:
		int n;
		int size;
		int nbPruned;
		int indMin;
		int indMax;

		int *set;		// Valeurs du domaine
		bool *isPruned;	// isPruned[i] = vrai si set[i] est pruné

		int *possibles; // Indices des valeurs possibles du domaine
		int *pruned;	// Indices des valeurs prunées du domaine
		int *indexes;	// Identifiant de la variable qui a imposé le prunage
	
	private:
		// UTILITAIRES
		void triBulle();
		int indVal(int val);
		int indPossiblesInd(int ind);
		int indPrunedInd(int ind);
		void setPruned(int ind);
		void setPossible(int ind);

	public:
		// CONSTRUCTEUR
		Domain(int n, int *set);

		// ACCESSEURS
		int getN();
		int getSize();
		int getMin();
		int getMax();

		// PRUNAGES
		void prunerValeur(int id, int val);
};

#endif
