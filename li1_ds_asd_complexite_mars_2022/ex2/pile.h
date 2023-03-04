#include <stdio.h>

#define nMax 100

struct pile{
    int elems[nMax];
    int sommet;
};

struct pile * creer_pile();
unsigned pile_vide(struct pile);
int dernier(struct pile);
void empiler(struct pile *, int);
void depiler(struct pile *);