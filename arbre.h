#ifndef UNTITLED1_ARBRE_H
#define UNTITLED1_ARBRE_H

// Inclusion des bibliothèques nécessaires
#endif //UNTITLED1_ARBRE_H
#include "stdlib.h"
#include "stdio.h"
#include "moves.h"
#include "loc.h"
#include "map.h"

//_________________________________________________________________________________//

// Définition de la structure du noeud de l'arbre : t_node
typedef struct s_node
{
    t_localisation loc;
    int depth; // Profondeur de l'arbre
    int cost; // Coût pour le Rover MARC

    struct s_node **sons;
    int nbSons; // Taille physique du tableau
} t_node;

//_________________________________________________________________________________//

// Déclarations des fonctions

// Fonction pour créer un noeud
// Paramètres : localisation, nombre de fils, profondeur, coût
// Retourne un pointeur vers le nouveau noeud créé
t_node *createNode(t_localisation ,int, int , int);

// Fonction pour créer l'arbre initial
// Paramètre : carte
// Retourne le noeud racine de l'arbre
t_node *tree(t_map);

// Fonction pour générer l'arbre à partir d'un noeud donné et d'une carte
// Paramètres : noeud, carte

void createtree(t_node* ,t_map);

// Fonction pour calculer le coût minimal dans l'arbre
// Paramètres : carte, noeud
// Retourne le coût minimal pour atteindre une feuille de l'arbre
int mincost(t_map,t_node *);

// Fonction pour afficher l'arbre en parcourant les noeuds récursivement
// Paramètre : noeud
void displaytree(t_node* );

// Fonction pour libérer la mémoire allouée à l'arbre
// Paramètre : noeud
void treememoryfree(t_node*);

int randomint(int );

void newtree(t_node* ,t_map ,int * );

t_move newmove(char * );

// Traverse et imprime l'arbre récursivement
void print_tree(t_node *node, int depth);

//_________________________________________________________________________________//