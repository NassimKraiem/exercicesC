#include <stdio.h>
#include "pile.h"


void rotation(struct pile *p)
{
    struct pile * pi;
    int valeurDansSommet;

    pi = creer_pile();
    valeurDansSommet = dernier(*p);
    depiler(p);

    while (!pile_vide(*p))
    {
        empiler(pi, dernier(*p));
        depiler(p);
    }
    empiler(p, valeurDansSommet);
    while (!pile_vide(*pi))
    {
        empiler(p, dernier(*pi));
        depiler(pi);
    }
}

void afficher(struct pile *p)
{
    struct pile *pi;
    pi = creer_pile();
    while (!pile_vide(*p))
    {
        printf("%d\t", dernier(*p));
        empiler(pi, dernier(*p));
        depiler(p);
    }
    while (!pile_vide(*pi))
    {
        empiler(p, dernier(*pi));
        depiler(pi);
    }
    printf("\n");
}

void main()
{
    //test

    struct pile * p;
    int i = 0;

    p = creer_pile();
    for (i = 1; i < 6; i++)
    {
        empiler(p, i);
    }
    
    printf("Avant la rotation de la pile:\n");
    afficher(p);

    rotation(p);

    printf("Apres la rotation de la pile:\n");
    afficher(p);
}