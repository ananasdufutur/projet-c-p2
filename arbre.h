#ifndef UNTITLED1_ARBRE_H
#define UNTITLED1_ARBRE_H

#endif //UNTITLED1_ARBRE_H
#include "stdlib.h"
#include "stdio.h"
#include "moves.h"
#include "loc.h"
#include "map.h"

typedef struct s_node
{
    t_localisation loc;
    int depth;
    int cost;

    struct s_node **sons;
    int nbSons; // Taille physique du tableau
} t_node;

t_node *createNode(t_orientation, int, int, int);

