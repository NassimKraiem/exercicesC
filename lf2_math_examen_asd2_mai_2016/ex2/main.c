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

void supprimerKeme(int start, int k, struct noeud **plc)
{
	struct noeud *p;
	int i=start;

	p = *plc;
	while(p!=p->suivant)
	{
		if(i-start >= k-2)
		{
			/////enfants qui va sortir: p->suivant->i
			supprimerApres(p, plc);
			//afficher_lc(*plc);
			i-=(k-1);
		}
		i++;
		p=p->suivant;
	}
}

void main()
{
	struct noeud * lc = creer_lc_uni();
	
	remplir(&lc, 7);
	afficher_lc(lc);
	
	supprimerKeme(0, 5, &lc);
	
	printf("\nRes : ");
	afficher_lc(lc);
}