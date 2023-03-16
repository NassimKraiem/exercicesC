#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "pile.h"

struct pile * creer_pile()
{
    struct pile * p;
    p = (struct pile *)malloc(sizeof(struct pile));
    p->sommet = -1;
    return p;
}
unsigned pile_vide(struct pile p)
{
    return (p.sommet==-1);
}
char dernier(struct pile p)
{
    assert(!pile_vide(p));
    return p.elems[p.sommet];
}
void empiler(struct pile * p, char info)
{
    p->sommet++;
    p->elems[p->sommet] = info;
}
void depiler(struct pile * p)
{
    assert(!pile_vide(*p));
    p->sommet--;
}