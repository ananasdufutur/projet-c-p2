#include <stdio.h>
#include "map.h"
#include "moves.h"
#include "queue.h"
#include "stack.h"
#include "loc.h"
#include "arbre.h"

//_________________________________________________________________________________//

int main() {
    t_map map;

    // The following preprocessor directive checks if the code is being compiled on a Windows system.
    // If either _WIN32 or _WIN64 is defined, it means we are on a Windows platform.
    // On Windows, file paths use backslashes (\), hence we use the appropriate file path for Windows.
#if defined(_WIN32) || defined(_WIN64)
    map = createMapFromFile("..\\maps\\example1.map");
#else
    map = createMapFromFile("../maps/example1.map");
#endif

//_________________________________________________________________________________//

    printf("Map created with dimensions %d x %d\n", map.y_max, map.x_max);
    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%d ", map.soils[i][j]);
        }
        printf("\n");
    }
    // printf the costs, aligned left 5 digits
    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%-5d ", map.costs[i][j]);
        }
        printf("\n");
    }

//_________________________________________________________________________________//
    int alvailablemoves[7]={22,15,7,7,21,21,7};
    displayMap(map);

    t_node * arbre=tree(map);

    newtree(arbre,map,alvailablemoves);

    displaytree(arbre);



    return 0;
}

//_________________________________________________________________________________//