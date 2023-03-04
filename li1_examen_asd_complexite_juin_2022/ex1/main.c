#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include "file.h"

void afficher(struct file *f)
{
    struct file *fi;
    fi = creer_file();
    while (!file_vide(f))
    {
        printf("%d\t", premier(f));
        enfiler(fi, premier(f));
        defiler(f);
    }
    while (!file_vide(fi))
    {
        enfiler(f, premier(fi));
        defiler(fi);
    }
    printf("\n");
}

int traitement(struct file *f1, struct file *f2)
{
    int ref;
    ref = premier(f1);
    defiler(f1);
    while (!file_vide(f1))
    {
        if(premier(f1)<ref)
        {
            enfiler(f1, ref);
            ref = premier(f1);
        }
        else
            enfiler(f2, premier(f1));
        defiler(f1);
    }
    return ref;
}

void tri(struct file * f)
{
    int ref, mloop = 1000;
    struct file *fi, *fr;
    fi = creer_file();
    fr = creer_file();

    while (!file_vide(f))
    {
        enfiler(fr, traitement(f, fi));
        if(!file_vide(fi))
            enfiler(fr, traitement(fi, f));

        //securité pour empecher les boucles infini,
        //le programme va s'arreter si tu depace mloop iterations.
        mloop--;
        assert(mloop>=0);
    }

    while (!file_vide(fr))
    {
        enfiler(f, premier(fr));
        defiler(fr);
    }
}

void remplir(struct file *f)
{
    int n, i, x;
    do
    {
        printf("Donner nbre d'elements >= 1\n");
        scanf("%d", &n);
    } while (n<=1);
    for (i = 0; i < n; i++)
    {
        printf("e%d: ", i);
        scanf("%d",&x);
        enfiler(f, x);
    }
    
}

void main()
{
    struct file *f;
    f = creer_file();

    remplir(f);
    printf("Avant Tri:\n\t");
    afficher(f);
    tri(f);
    printf("Apres Tri:\n\t");
    afficher(f);
}