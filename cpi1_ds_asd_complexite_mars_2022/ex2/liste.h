#include <stdio.h>

struct noeud {
	int i;
	struct noeud * suivant;
	struct noeud * precedent;
};

struct noeud * creer_lc_uni();
unsigned lc_uni_vide(struct noeud *);

void insererAvantPtAcc(struct noeud **, int);
void supprimerApres(struct noeud *, struct noeud **);