#include "arbre.h"
#include "map.h"
#include "loc.h"
#include "stdlib.h"

//_________________________________________________________________________________//

// Fonction pour créer un nouveau noeud dans l'arbre
// Prend en paramètre la localisation, le nombre de fils, la profondeur et le coût du noeud
t_node *createNode(t_localisation loc1, int nb_sons,int depth,int cost)
{
    t_node *new_node;
    new_node = (t_node *)malloc(sizeof(t_node)); // Alloue de la mémoire pour un nouveau noeud
    new_node->loc.ori = loc1.ori; // Initialise la direction
    new_node->loc.pos = loc1.pos; // Initialise la position
    new_node->nbSons = nb_sons; // Initialise le nombre de fils
    new_node->depth=depth; // Initialise la profondeur
    new_node->cost=cost; // Initialise le coût
    new_node->sons = (t_node **)malloc(nb_sons*sizeof(t_node *)); // Alloue de la mémoire pour les fils
    for (int i=0; i <nb_sons; i++) // Initialise tous les fils à NULL
    {
        new_node->sons[i]=NULL;
    }
    return new_node; // Retourne le noeud créé
}

//_________________________________________________________________________________//

// Fonction pour créer un arbre en partant d'une carte
// Prend en paramètre la carte à utiliser et retourne le premier noeud de l'arbre
t_node *tree(t_map map){
    t_localisation loc ={{0,0},NORTH}; // Initialisation de la localisation (Origine)
    t_node *new= createNode(loc,5,0,0); // Crée un noeud avec cette localisation
    return new;
}

//_________________________________________________________________________________//

// Fonction récursive pour calculer le coût minimum d'un arbre
// Prend en paramètre la carte et un noeud de l'arbre
int mincost(t_map map,t_node *tree){
    if (tree->nbSons==0){
        return tree->cost;
    }
    int min=10000; // Initialisation d'un coût très élevé
    for (int i=0;i<tree->nbSons;i++)
        if (mincost(map,tree->sons[i]+tree->cost)<min){ // Récursivité du coût pour chaque fils
            min=mincost(map,tree->sons[i]+tree->cost);
        }
    return min; // Retourne le coût minimal trouvé
}

//_________________________________________________________________________________//

// Fonction pour générer un nombre entier aléatoire entre a et b
int randomint(int a,int b){
    srand(1); // Initialise le générateur de nombres aléatoires
    return (rand()%a);
}

//_________________________________________________________________________________//

// Fonction pour créer un arbre en fonction d'une carte donnée
// Génère récursivement un arbre avec une certaine profondeur et Les coûts associés
void createtree(t_node* tree,t_map map){
    if (tree->loc.pos.x<map.x_max && tree->depth<10){
        tree->nbSons++;
        t_localisation loc={RIGHT(tree->loc.pos),tree->loc.ori};
        tree->sons[tree->nbSons-1]= createNode(loc,0,tree->depth+1,map.costs[loc.pos.x][loc.pos.y]);
        createtree(tree->sons[tree->nbSons-1],map);
    }
    if (tree->loc.pos.y<map.y_max && tree->depth<10){
        tree->nbSons++;
        t_localisation loc={DOWN(tree->loc.pos),tree->loc.ori};
        tree->sons[tree->nbSons-1]= createNode(loc,0,tree->depth+1,map.costs[loc.pos.x][loc.pos.y]);
        createtree(tree->sons[tree->nbSons-1],map);
    }
    // Affiche les coordonnées (x et y) du noeud actuel et son coût
    printf("en x:%d et y:%d cost=%d",tree->loc.pos.x,tree->loc.pos.y,tree->cost);
}

//_________________________________________________________________________________//

// Fonction pour afficher l'arbre avec les coûts associés
void displaytree(t_node* tree){
    printf("%d ",tree->cost);
    for(int i=0;i<tree->nbSons;i++){ // Parcourt les noeuds récursivement
        displaytree(tree->sons[i]);
    }
}

//_________________________________________________________________________________//

// Fonction pour libérer la mémoire allouée
// Libère la mémoire des noeuds et de leurs fils (récursivement)
void treememoryfree(t_node* node) {
    if (node == NULL) { // Si NULL la fonction se termine
        return;
    }
    for (int j = 0; j < node->nbSons; j++) { // Libère la mémoire
        treememoryfree(node->sons[j]);
    }
    free(node->sons);
    free(node);
}

//_________________________________________________________________________________//