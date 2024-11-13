//
// Created by pouss on 13/11/2024.
//

#ifndef UNTITLED1_ARBRE_H
#define UNTITLED1_ARBRE_H

#endif //UNTITLED1_ARBRE_H
#include "stdlib.h"
#include "stdio.h"
#include "moves.h"
typedef struct s_node
{
    int value;
    int depth;
    struct s_node **sons;
    int nbSons; // taille physique du tableau
    // more to come !
} t_node;

t_node *createNode(int value, int nb_sons, int depth);

