#include <stdio.h>
#include "pile.h"

void afficherTexte(struct pile *p)
{
    struct pile *pi;
    pi = creer_pile();
    while (!pile_vide(*p))
    {
        printf("%c", dernier(*p));
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
void ligneReelle(char ch[])
{
    struct pile *p, *pi;
    int i;

    p = creer_pile();
    pi = creer_pile();
    for (i = 0; ch[i]; i++)
    {
        switch (ch[i])
        {
        case '#':
            if(!pile_vide(*p))
                depiler(p);
            break;
        case '%':
            while(!pile_vide(*p))
                depiler(p);
            break;
        case '$':
            empiler(p, '\n');
            break;
        default:
            empiler(p, ch[i]);
            break;
        }
    }

    // inverser la pile puis l'afficher, ou bien modifier la fonction d'affichage
    // pour qu'elle affiche dans la 2eme boucle
    while (!pile_vide(*p))
    {
        empiler(pi, dernier(*p));
        depiler(p);
    }
    afficherTexte(pi);
}

void main()
{
    //meme taille maxi que la pile (representation contigue)
    char ch[nMax];

    // exemple à saisir:
    // Jem# m'euh%Je m'#euh## suit#s trop#mp&#e$
    printf("Saisir le texte: \n");
    scanf("%[^\n]" , ch);
    ligneReelle(ch);
}