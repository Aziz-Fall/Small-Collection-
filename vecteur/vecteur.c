#include "vecteur.h"

//Retourne l'indice du pivot.
int partition(int t[], int gauche, int droite)
{
    int var_pivot = t[droite - 1], 
                g = gauche - 1,
                d = droite - 1;
    while(g <= d)
    {
        while(t[++g] < var_pivot);
        while(t[--d] > var_pivot);
        if(g < d)
        {
            int tmp = t[g];
            t[g] = t[d];
            t[d] = tmp;
        }
    }

    int tmp = t[droite - 1];
    t[droite - 1] = t[g];
    t[g] = tmp;

    return g;
}
//Tri rapide.
void tri_rapide(int t[], int gauche, int droite)
{
    if(gauche < droite)
    {
        int pivot = partition(t, gauche, droite);
        tri_rapide(t, gauche, (pivot - 1));
        tri_rapide(t, (pivot + 1), droite);
    }
}

//Creer et retourner un vecteur vide.
Vecteur creer_vecteur()
{
    Vecteur v = (Vecteur)malloc(sizeof(struct Vecteur));
    v->element = (int*)malloc(sizeof(int*));
    if(v == NULL || v->element == NULL)
    {
        fprintf(stderr, "Impossible de créer un vecteur.\n");
        exit(EXIT_FAILURE);
    }

    v->nomber_element = 0;

    return v;
}
//Retourne true si le vecteur est vide sinon false.
Bool est_vide(Vecteur v)
{
    if(v->nomber_element == 0)
        return true;
    return false;
}
//Affiche le contenu du vecteur.
void affiche_vecteur(Vecteur v)
{
    if(est_vide(v))
    {
        fprintf(stderr, "Impossible d'afficher le vecteur.\n");
        return;
    }

    for(int i = 0; i < v->nomber_element; i++)
        printf("< %2d >", *(v->element + i));

    printf("\n");
}
//insére un élement dans le vecteur.
void inserer(Vecteur v, int valeur)
{
    v->element = (int *)realloc(v->element, (v->nomber_element + 1));
    if((v->element) == NULL) 
    {
        fprintf(stderr, "Impossible d'ajouter un élement.\n");
        return;
    }

    *(v->element + v->nomber_element) = valeur;
    v->nomber_element++;
    tri_rapide(v->element, 0, (v->nomber_element));
}

//Supprime un élement à la fin du vecteur.
int supprimer_dernier_element(Vecteur v)
{  
    if(est_vide(v))
    {
        fprintf(stderr, "Max introuvable.\n");
        return 0;
    }
    
    int valeur_supprimee = *(v->element + v->nomber_element - 1);

    --(v->nomber_element);
    v->element = (int *)realloc(v->element, v->nomber_element);

    return valeur_supprimee;
}
//Retourne le maximum du vecteur.
int max(Vecteur v)
{
    if(est_vide(v))
    {
        fprintf(stderr, "Max introuvable.\n");
        return 0;
    }

    return *(v->element + v->nomber_element - 1);
}
//Retourne le minimum du vecteur.
int min(Vecteur v)
{
    if(est_vide(v))
    {
        fprintf(stderr, "Min introuvable.\n");
        return 0;
    }

    return *(v->element);
}
//Retourne l'élement d'indice passé en argument.
int lire(Vecteur v, int index)
{
    if(est_vide(v) || index >= v->nomber_element)
    {
        fprintf(stderr, "Index introuvable.\n");
        return 0;
    }

    return *(v->element + index - 1);
}
//Retourne la valeur supprimée.
int supprimer(Vecteur v, int index)
{
    if(est_vide(v) || index >= v->nomber_element)
    {
        fprintf(stderr, "Index n'existe pas.\n");
        return 0;
    }
    int var_deleted = *(v->element + index);

    for(int i = index; i < (v->nomber_element - 1); i++)
        v->element[i] = v->element[i + 1];
    
    v->nomber_element -= 1;
    v->element = (int *)realloc(v->element, v->nomber_element);

    if(v->element == NULL)
    {
        fprintf(stderr, "Impossible de suppimer l'element.\n");
        exit(EXIT_FAILURE);
    }

    return var_deleted;
}

//Supprime le premier element du vecteur.
int supprimer_premier_element(Vecteur v)
{
    if(est_vide(v))
    {
        fprintf(stderr, "Impossible supprimer le premier element.\n");
        return 0;
    }
    int valeur_supprimee = *(v->element);
    for(int i = 0; i < (v->nomber_element - 1); i++)
        v->element[i] = v->element[i + 1];
    
    v->element = (int *)realloc(v->element, (v->nomber_element - 1));
    if (v->element == NULL) 
    {
        fprintf(stderr, "Impossible de réalouer de la mémoire\n");
        return 0;
    }
    v->nomber_element -= 1;

    return valeur_supprimee; 
}

void clear_vector(Vecteur v)
{
    free(v->element);
    free(v);
}