//
// Created by flasque on 19/10/2024.
//

#include "moves.h"
#include "stdio.h"
#include "stdlib.h"
#include "loc.h"
#include "map.h"


/* prototypes of local functions */
/* local functions are used only in this file, as helper functions */

/**
 * @brief Function to rotate the robot according to a move and its actual orientation
 * @param ori : the actual orientation of the robot
 * @param move : the move to do
 * @return the new orientation of the robot
 */
t_orientation rotate(t_orientation, t_move, t_map, t_localisation);

/**
 * @brief function to translate the robot according to a move and its actual position
 * @param loc : the actual localisation of the robot
 * @param move : the move to do
 * @return the new localisation of the robot
 */
t_localisation translate(t_localisation , t_move);

/* definition of local functions */

t_orientation rotate(t_orientation ori, t_move move, t_map map, t_localisation loc)
{
    int rst;
    switch (map.soils[loc.pos.x][loc.pos.y]) {
        case ERG:
            switch (move) {
                case U_TURN:
                    rst = (rand() % 2) * 2 + 1;
                default:
                    break;
            }
            break;
        default:

            if (map.soils[loc.pos.x][loc.pos.y] == PLAIN || map.soils[loc.pos.x][loc.pos.y] == REG) {
                switch (move) {
                    case T_LEFT:
                        rst = 3;
                        break;
                    case T_RIGHT:
                        rst = 1;
                        break;
                    case U_TURN:
                        rst = 2;
                        break;
                    default:
                        break;
                }
            }else {
                break;
            }
    }
    return (ori+rst)%4;
}

t_localisation translate(t_localisation loc, t_move move)
{
    /** rules for coordinates:
     *  - x grows to the right with step of +1
     *  - y grows to the bottom with step of +1
     *  - the origin (x=0, y=0) is at the top left corner
     */
    t_position res = loc.pos;
    switch (move) {
        case F_10:
            switch (loc.ori) {
                case NORTH:
                    if(loc.pos.y>0) {
                        res.y = loc.pos.y - 1;
                    }
                    break;
                case EAST:
                    if(loc.pos.x<6) {
                        res.x = loc.pos.x + 1;
                    }
                    break;
                case SOUTH:
                    if(loc.pos.y<7) {
                        res.y = loc.pos.y + 1;
                    }
                    break;
                case WEST:
                    if(loc.pos.x>0) {
                        res.x = loc.pos.x - 1;
                    }
                    break;
                default:
                    break;
            }
            break;
        case F_20:
            switch (loc.ori) {
                case NORTH:
                    if(loc.pos.y>2) {
                        res.y = loc.pos.y - 2;
                    }
                    break;
                case EAST:
                    if(loc.pos.x<5) {
                        res.x = loc.pos.x + 2;
                    }
                    break;
                case SOUTH:
                    if(loc.pos.y<6) {
                        res.y = loc.pos.y + 2;
                    }
                    break;
                case WEST:
                    if(loc.pos.x>1) {
                        res.x = loc.pos.x - 2;
                    }
                    break;
                default:
                    break;
            }
            break;
        case F_30:
            switch (loc.ori) {
                case NORTH:
                    if(loc.pos.y>2) {
                        res.y = loc.pos.y - 3;
                    }
                    break;
                case EAST:
                    if(loc.pos.x<4) {
                        res.x = loc.pos.x + 3;
                    }
                    break;
                case SOUTH:
                    if(loc.pos.y<5) {
                        res.y = loc.pos.y + 3;
                    }
                    break;
                case WEST:
                    if(loc.pos.x>2) {
                        res.x = loc.pos.x - 3;
                    }
                    break;
                default:
                    break;
            }
            break;
        case B_10:
            switch (loc.ori) {
                case NORTH:
                    if(loc.pos.y<7) {
                        res.y = loc.pos.y + 1;
                    }
                    break;
                case EAST:
                    if(loc.pos.x>0) {
                        res.x = loc.pos.x - 1;
                    }
                    break;
                case SOUTH:
                    if(loc.pos.y>0) {
                        res.y = loc.pos.y - 1;
                    }
                    break;
                case WEST:
                    if(loc.pos.x<6) {
                        res.x = loc.pos.x + 1;
                    }
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
    //printf("res.x= %d res.y= %d ",res.x,res.y);
        return loc_init(res.x, res.y, loc.ori);

}

/* definitions of exported functions */

char *getMoveAsString(t_move move)
{
    return _moves[move];
}

t_localisation move(t_localisation loc, t_move move,t_map map)
{
    t_localisation new_loc;
    new_loc.ori = rotate(loc.ori, move,map,loc);
    new_loc = translate(loc, move);
    return new_loc;
}

void updateLocalisation(t_localisation *p_loc, t_move m,t_map map)
{
    *p_loc = move(*p_loc,m, map);
    return;
}
