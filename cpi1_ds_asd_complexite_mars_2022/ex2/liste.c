#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

struct noeud * creer_lc_uni()
{ return NULL; }

unsigned lc_uni_vide(struct noeud * lc)
{ return (lc == NULL); }

void insererAvantPtAcc(struct noeud ** plc, int i)
{
	struct noeud * p;
	p = (struct noeud *)malloc(sizeof(struct noeud));
	p->i = i;
	if(lc_uni_vide(*plc))
	{
		p->suivant = p;
		p->precedent = p;
	}
	else
	{
		p->suivant = *plc;
		p->precedent = (*plc)->precedent;
		p->precedent->suivant = p;
		(*plc)->precedent = p;
	}
	*plc=p;
}

void supprimerApres(struct noeud * elem, struct noeud **plc)
{
	struct noeud * p = elem->suivant;
	if(p==elem)
	{
		printf("Cette fonction efface ssi el existe plus qu'un seul element!");
		return;
	}
	
	elem->suivant = p->suivant;
	p->suivant->precedent = elem;
	
	if(*plc==p)
		*plc = p->suivant;
		
	free(p);
}