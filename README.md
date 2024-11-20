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
- []
- []
