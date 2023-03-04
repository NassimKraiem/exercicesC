#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include "file.h"
struct file *creer_file()
{
    struct file *f;
    f = (struct file *)malloc(sizeof(struct file));
    f->dernier = NULL;
    f->tete = NULL;
    return (f);
}

unsigned file_vide(struct file *f)
{
    return ((f->tete == NULL) && (f->dernier == NULL));
}

int premier(struct file *f)
{
    assert(!file_vide(f));
    return (f->tete->cle);
}

void enfiler(struct file *f, int cle)
{
    struct element *p;
    p = (struct element *)malloc(sizeof(struct element));
    p->cle = cle;
    p->suivant = NULL;
    if (file_vide(f))
        f->tete = p;
    else
        f->dernier->suivant = p;
    f->dernier = p;
}
void defiler(struct file *f)
{
    struct element *p;
    p = (struct element *)malloc(sizeof(struct element));
    assert(!file_vide(f));
    if ((f->tete) == (f->dernier))
    {
        f->tete = NULL;
        f->dernier = NULL;
    }
    else
    {
        p = f->tete;
        f->tete = f->tete->suivant;
        free(p);
    }
}
