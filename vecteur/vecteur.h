#ifndef __VECTEUR__H__
#define __VECTEUR__H__

#include <stdio.h>
#include <stdlib.h>

typedef struct Vecteur
{
    int nomber_element;
    int *element;
}*Vecteur;

typedef enum 
{
    false,
    true
}Bool;

Vecteur creer_vecteur();
Bool est_vide(Vecteur v);
void affiche_vecteur(Vecteur v);
void inserer(Vecteur v, int valeur);
int supprimer_dernier_element(Vecteur v);
int supprimer_premier_element(Vecteur v);
int max(Vecteur v);
int min(Vecteur v);
int lire(Vecteur v, int index);
int supprimer(Vecteur v, int index);
void clear_vector(Vecteur v);
#endif