#include "arbre.h"
#include "map.h"
#include "loc.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

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
    t_localisation loc ={{0,0},SOUTH}; // Initialisation de la localisation (Origine)
    t_node *new= createNode(loc,0,0,0); // Crée un noeud avec cette localisation
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
int randomint(int a){
    int b=rand()%a;
    //srand(3); // Initialise le générateur de nombres aléatoires
    return b;
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
    //printf("en x:%d et y:%d cost=%d",tree->loc.pos.x,tree->loc.pos.y,tree->cost);
}

//_________________________________________________________________________________//

// Vérifie si les chaînes d'entrées correspondent à un mouvement, retourne la valeur du mouvement
t_move newmove(char * moving){
    if (strcmp(moving,"F 10m")==0){
        t_move new=F_10;
        return new;
    }
    if (strcmp(moving,"F 20m")==0){
        t_move new=F_20;
        return new;
    }
    if (strcmp(moving,"F 30m")==0){
        t_move new=F_30;
        return new;
    }
    if (strcmp(moving,"B 10m")==0){
        t_move new=B_10;
        return new;
    }
    if (strcmp(moving,"T left")==0){
        t_move new=T_LEFT;
        return new;
    }
    if (strcmp(moving,"T right")==0){
        t_move new=T_RIGHT;
        return new;
    }
    if (strcmp(moving,"U-turn")==0){
        t_move new=U_TURN;
        return new;
    }
}

//_________________________________________________________________________________//

void newtree(t_node* tree,t_map map,int * alvailable_move){
    if(tree->cost>9999 || tree->depth>10) {
        free(tree);
    }
    else {
        if(tree->cost==0 && tree->depth!=0){
            printf("found");
        }
        else {
            int a;
            for (int i = 0; i < 5; i++) {
                do {
                    a = randomint(8);
                } while (alvailable_move[a] == 0);
                int *newalvailablemoves = alvailable_move;
                newalvailablemoves[a]--;
                tree->nbSons++;
                char *moving = _moves[a];
                //printf("%s",moving);
                t_move new = newmove(moving);
                //printf("%d",new);
                //printf("a= %d-",a);
                t_localisation loc = move(tree->loc, new,map);
                printf("%d %d",loc.pos.x,loc.pos.y);
                tree->sons[tree->nbSons - 1] = createNode(loc, 0, tree->depth + 1, map.costs[loc.pos.x][loc.pos.y]);
                printf("x=%d,y=%d,nb_sons=%d,depht=%d,cost=%d",tree->loc.pos.x,tree->loc.pos.y,tree->nbSons,tree->depth,tree->cost);
                newtree(tree->sons[tree->nbSons - 1], map, newalvailablemoves);
            }
            printf("fini");
        }
    }
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

// Traverse et imprime l'arbre récursivement
void print_tree(t_node *node, int depth) {
    if (node == NULL) {
        return;
    }
    printf("Node at depth %d: Location: (%d, %d), Moves: ", depth, node->loc.pos.x, node->loc.pos.y);
    printf("\n");
    for (int i = 0; i < node->nbSons; i++) {
        print_tree(node->sons[i], depth + 1);
    }
}

//_________________________________________________________________________________//