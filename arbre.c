//
// Created by pouss on 13/11/2024.
//
#include "arbre.h"
#include "map.h"
#include "loc.h"

t_node *createNode(t_localisation loc1, int nb_sons,int depth,int cost)
{
    t_node *new_node;
    new_node = (t_node *)malloc(sizeof(t_node));
    new_node->loc.ori = loc1.ori;
    new_node->loc.pos = loc1.pos;
    new_node->nbSons = nb_sons;
    new_node->depth=depth;
    new_node->sons = (t_node **)malloc(nb_sons*sizeof(t_node *));
    for (int i=0; i <nb_sons; i++)
    {
        new_node->sons[i]=NULL;
    }
    return new_node;
}

t_node *tree(t_map map){
    t_localisation loc ={{0,0},NORTH};
    t_node *new= createNode(loc,5,0,0);
}

