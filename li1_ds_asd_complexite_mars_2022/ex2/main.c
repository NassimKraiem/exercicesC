#include <stdio.h>
#include "pile.h"

#define nMax 100

int bien_paranthesee(char exp[])
{
    struct pile *ordre;
    int i = 0;

    ordre = creer_pile();
    
    while (exp[i])
    {
        switch (exp[i])
        {
        case '(':
            empiler(ordre, exp[i]);
            break;
        case '[':
            empiler(ordre, exp[i]);
            break;
        case '{':
            empiler(ordre, exp[i]);
            break;
        case ')':
            if(!pile_vide(*ordre) && (dernier(*ordre) == '('))
            {
                depiler(ordre);
            }
            else
                return 0;
            break;
        case ']':
            if(!pile_vide(*ordre) && (dernier(*ordre) == '['))
            {
                depiler(ordre);
            }
            else
                return 0;
            break;
        case '}':
            if(!pile_vide(*ordre) && (dernier(*ordre) == '{'))
            {
                depiler(ordre);
            }
            else
                return 0;
            break;
        }

        i++;
    }

    return(pile_vide(*ordre));
}

int nbre_facteurs(char exp[])
{
    struct pile *ordre;
    int i = 0;
    int cmp = 0;

    ordre = creer_pile();
    
    while (exp[i])
    {
        switch (exp[i])
        {
        case '(':
        case '[':
        case '{':
            empiler(ordre, exp[i]);
            break;
        case ')':
        case ']':
        case '}':
            depiler(ordre);
            break;
        }

        if(pile_vide(*ordre))
            cmp++;

        i++;
    }

    return cmp;
}

void main()
{
    char exp[nMax];

    printf("Donner l'expression: \n");
    fflush(stdin);
    scanf("%[^\n]" , exp);
    printf("\n%s\n", exp);

    if(bien_paranthesee(exp))
    {
        printf("valide!\n");
        printf("Elle est composée de %d facteurs\n", nbre_facteurs(exp));
    }
    else
        printf("n'est pas valide!\n");
}