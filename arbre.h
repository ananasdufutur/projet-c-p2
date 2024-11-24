//
// Created by pouss on 13/11/2024.
//

#ifndef UNTITLED1_ARBRE_H
#define UNTITLED1_ARBRE_H

#endif //UNTITLED1_ARBRE_H
#include "stdlib.h"
#include "stdio.h"
#include "moves.h"
#include "map.h"


#define ROWS 7
#define COLS 6

typedef struct s_node
{
    t_localisation loc;
    t_move *availableMove;
    int sizeAvailableMove;
    t_map map;
    int nbMoveRemaining;
    t_move lastMove;
    struct s_node *nextNode; //initialisé à NULL
} t_node;

t_node *createNode(t_localisation, t_move *, int, t_map, int, t_move);
void sonNod(t_node *, t_map);

t_map createMapFromFile(char *filename);
void print_map(int map[ROWS][COLS]);
void generate_map(int map[ROWS][COLS]);
void displayMap(t_map map);
