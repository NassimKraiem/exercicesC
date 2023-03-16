#include <stdio.h>

#define nMax 100

struct pile{
    char elems[nMax];
    int sommet;
};

struct pile * creer_pile();
unsigned pile_vide(struct pile);
char dernier(struct pile);
void empiler(struct pile *, char);
void depiler(struct pile *);