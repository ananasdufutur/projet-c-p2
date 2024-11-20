#include "arbre.h"
#include "map.h"
#include "loc.h"
#include "stdlib.h"

t_node *createNode(t_localisation loc1, int nb_sons,int depth,int cost)
{
    t_node *new_node;
    new_node = (t_node *)malloc(sizeof(t_node));
    new_node->loc.ori = loc1.ori;
    new_node->loc.pos = loc1.pos;
    new_node->nbSons = nb_sons;
    new_node->depth=depth;
    new_node->cost=cost;
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
    return new;
}

int mincost(t_map map,t_node *tree){


    if (tree->nbSons==0){
        return tree->cost;
    }
    int min=10000;
    for (int i=0;i<tree->nbSons;i++)
        if (mincost(map,tree->sons[i]+tree->cost)<min){
            min=mincost(map,tree->sons[i]+tree->cost);
        }

    return min;
}

int randomint(int a,int b){
    srand(1);
    return (rand()%a);
}

void createtree(t_node* tree,t_map map){
    if (tree->loc.pos.x<map.x_max && tree->depth<15){
        tree->nbSons++;
        t_localisation loc={RIGHT(tree->loc.pos),tree->loc.ori};
        tree->sons[tree->nbSons-1]= createNode(loc,0,tree->depth+1,map.costs[loc.pos.x][loc.pos.y]);
        createtree(tree->sons[tree->nbSons-1],map);
        printf("en x:%d et y:%d ori=%d\n",loc.pos.x,loc.pos.y,loc.ori);
    }
    if (tree->loc.pos.y<map.y_max && tree->depth<15){
        tree->nbSons++;
        t_localisation loc={DOWN(tree->loc.pos),tree->loc.ori};
        tree->sons[tree->nbSons-1]= createNode(loc,0,tree->depth+1,map.costs[loc.pos.x][loc.pos.y]);
        createtree(tree->sons[tree->nbSons-1],map);
        printf("en x:%d et y:%d ori=%d\n",loc.pos.x,loc.pos.y,loc.ori);
    }
    printf("en x:%d et y:%d cost=%d",tree->loc.pos.x,tree->loc.pos.y,tree->cost);

}

void displaytree(t_node* tree){
    printf("%d ",tree->cost);
    for(int i=0;i<tree->nbSons;i++){
        displaytree(tree->sons[i]);
    }

}