# Version minimale requise de CMake
cmake_minimum_required(VERSION 3.16)

# Nom du projet
project(MonProjetC VERSION 1.0 LANGUAGES C)

# Options de compilation
set(CMAKE_C_STANDARD 11) # Utiliser le standard C11
set(CMAKE_C_STANDARD_REQUIRED ON) # Exiger ce standard
set(CMAKE_C_EXTENSIONS OFF) # Désactiver les extensions non standard

# Variables pour les fichiers sources
set(SOURCES
        main.c
        map.h
        map.c
        arbre.c
        arbre.h
        loc.c
        loc.h
        moves.c
        moves.h
        queue.c
        queue.h
        stack.c
        stack.h


)



# Ajout de l'exécutable principal
add_executable(MonExecutable ${SOURCES}
        main.c
        map.h
        map.c
        arbre.c
        arbre.h
        loc.c
        loc.h
        moves.c
        moves.h
        queue.c
        queue.h
        stack.c
        stack.h)

# Options supplémentaires pour les compilateurs


# Lien avec des bibliothèques externes, si nécessaire
# target_link_libraries(MonExecutable PRIVATE m) # Par exemple, pour libm (math)

# Installation de l'exécutable
install(TARGETS MonExecutable DESTINATION bin)

# Configuration pour les tests (facultatif)
enable_testing()
add_test(NAME TestMonExecutable COMMAND MonExecutable)
