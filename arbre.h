//
// Created by pouss on 13/11/2024.
//

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
    int nbSons; // taille physique du tableau
    // more to come !
} t_node;

t_node *createNode(t_localisation ,int, int , int);

t_node *tree(t_map);
