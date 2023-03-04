#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

void afficher_lc(struct noeud * lc)
{
	struct noeud * p;
	p=lc;
	do
	{
		printf("%d\t", p->i);
		p = p->suivant;
	} while(p!=lc);
	printf("\n");
}

void remplir(struct noeud **plc, int n)
{
	int i;
	for(i=0;i<n;i++)
		insererAvantPtAcc(plc, n-i);
}

void main()
{
	struct noeud * lc = creer_lc_uni(), *p;
	
	remplir(&lc, 7);
	afficher_lc(lc);
	
	p=lc;
	while(p!=p->suivant)
	{
		supprimerApres(p, &lc);
		afficher_lc(lc);
		p=p->suivant;
	}
	
	printf("\nRes : ");
	afficher_lc(lc);
}