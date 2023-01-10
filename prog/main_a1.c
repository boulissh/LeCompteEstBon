// Projet le compte est bon

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "biblio.h"



int main(){int i, A;

    int nb, cible;

    // récupération d'un jeu aléatoirement
    puts("Choisir la valeur de N: ");
    scanf("%d", &nb);
    if (nb > N_MAX){
        printf("N est trop grand.");
        return 1;
    }
    puts("Choisir la valeur de la cible: ");
    scanf("%d", &cible);
    

    int * tirage = calloc(nb, sizeof(int));
    random_tirage(tirage, nb);



    printf("\ntirage initial: ");
    for (i=0; i < nb; i++) printf("%d ", *(tirage+i));

    char ** operations = (char**) calloc(nb, sizeof(char*));            // création du tableau operations
    for (i = 0; i< nb; i++) operations[i] = (char*) calloc(256, sizeof(char));


    A = resolution(tirage, nb, cible, operations);

    if (A == 1){
        printf("\nIl n'y pas de solution.\n");
        return 0;
    }
    puts("");
    printf("\nLes operations sont: \n");

    for (i = nb-1; i >= 0; i--) puts(operations[i]);  // affichage du résultat

    for (i = 0; i < nb; i++) free(operations[i]);
    free(operations);
    free(tirage);
    return 0;
}
