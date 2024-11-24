# ROVER RUN PROJET ! P2 - 2024

## Résumé des étapes obligatoires

- Etape n°1 : Création de l'arbre mouvement et test des algorithmes
- Etape n°2 : Passage à l'échelle et indication de la compléxité

## Description 

On nous a donné pour projet en langage C de rendre un robot, envoyé sur Mars depuis la Terre, mobile. 
En prenant en compte que la position de 'base' est représenté par un 0 et que les coûts pour
chaque déplacement s'additionnent en fonction du type de terrain : 
|  Terrain  |   Plaine  |    Erg    |    Reg    |  Crevasse |
|-----------|-----------|-----------|-----------|-----------|
|   Coût    |     1     |     4     |     2     |   10.000  |

Note : le type de terrain affecte également le déplacement de MARC le robot
MARC peut effectuer les mouvements suivant :

|  Mouvement  |   Avancer  |    Reculer   |    Tourner    |  Demi-tour |
|-------------|------------|--------------|---------------|------------|
|    Type     |10m 20m 30m |      10m     | Droite Gauche |      \     |

## Objectif 
Le but étant de rendre MARC le robot martien mobile tout en minimisant le coût de déplacement, on est amené à
utiliser des arbres N-aire pour définir le chemin de MARC.
Chaque noeud comporte la position de MARC, le coût actuel par rapport à la position et les déplacements disponibles.  

## Tâches accomplie

- [Structure de l'arbre]
- [Création de noeuds]
- [Création de l'arbre]
- [Affichage de l'arbre]
- [Calcul du coût minimal]
- [Génération de la position du robot]
- [Déplacements du robot]
- [Analyse de la complexité]

## Analyse de complexité des fonctions utilisées 

1. createNode(t_localisation loc1, int nb_sons, int depth, int cost) :
   - Complexité : O(nb_sons)
   - Cette fonction alloue de la mémoire pour un tableau de taille nb_sons, initialisé à NULL. Les autres opérations (affectations) sont constantes.

2. tree(t_map map) :
   - Complexité : O(1)
   - Cette fonction crée le nœud racine de l'arbre avec une seule opération d'allocation.

3. mincost(t_map map, t_node *tree) :
   - Complexité : O(n)
   - La fonction effectue une traversée en profondeur (DFS) de l'arbre pour calculer le coût minimal, en visitant chaque nœud une seule fois.

4. randomint(int a, int b) :
   - Complexité : O(1)
   - Cette fonction génère un nombre aléatoire entre a et b avec une opération simple.

5. createtree(t_node *tree, t_map map) :
   - Complexité : O(2^10) (limitée par la profondeur de 10)
   - La fonction construit un arbre récursivement, avec une profondeur maximale de 10, ce qui limite l'explosion exponentielle des fils. La complexité est constante pour cette profondeur, mais exponentielle en cas de profondeur illimitée.

6. t_move newmove(char * moving) :
   - Complexité globale est O(k \cdot n), où 𝑘=7 (le nombre de conditions dans la fonction)

7. newtree(t_node* tree,t_map map,int * alvailable_move) :
   - Complexité temporelle est 𝑂(5𝑑)O(5 d ), où 𝑑=10d=10, ce qui est exponentiel
   - Complexité spatiale est 𝑂(5𝑑)O(5 d ) à cause de la structure de l’arbre.

8. displaytree(t_node *tree) :
   - Complexité : O(n)
   - Effectue une traversée DFS de l'arbre pour afficher les coûts de chaque nœud, visitant chaque nœud une seule fois.

9. treememoryfree(t_node *node) :
   - Complexité : O(n)
   - Libère la mémoire allouée à l'arbre en effectuant une traversée DFS pour libérer chaque noeud.
  
10. void print_tree(t_node *node, int depth) : 
    - Complexité : Si l'arbre contient 𝑁 noeuds, la complexité est O(N).
     
// les fonctions de l'arbre manipulent des structures de données en utilisant principalement des traversées DFS, avec des complexités allant de O(1) pour les opérations simples à O(n) pour les traversées de l'arbre. La fonction `createtree` peut avoir une complexité exponentielle (O(2^10)) si la profondeur de l'arbre n'est pas limitée.

