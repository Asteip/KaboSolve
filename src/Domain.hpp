#ifndef DOMAIN_HPP
#define DOMAIN_HPP

class Domain {
	private:
		int n;
		int size;
		int *set;		// Séparé en deux [valeurs prunées / valeurs possibles]
		int *indexes;	// [Indices de la variable qui a imposé le prunage / ignoré]
		
	public:
		Domain(int n, int *set);
};

#endif
