// Projet le compte est bon

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "biblio.h"

#define N_MAX 10


int main(){int i,k, A,distancemin=100000; //distancemin très grand pour l'initialiser

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

    char** operations = calloc(nb,sizeof(char*));
    for (int k = 0; k < nb; k++) {
        operations[k] = calloc(256,sizeof(char));
        operations[k][0] = '\0';
    }
    
    A=resolutionplusproche(tirage,nb,cible,distancemin,operations);
    if (A==0){ 
    puts("Une sequence pour atteindre la cible a ete trouvee. Les operations sont:\n");
    for (k=nb-1;k>0;k--){
        printf(" %s \n",operations[k]);
        }
    }
    else {
        printf("Il n'y a pas de sequence possible pour atteindre %d,",cible);
        printf("mais la distance minimum entre un des resultats et la cible est %d.",A);
        puts("Les operations pour atteindre le resultat le plus proche sont :\n");
        for (k=nb-1;k>0;k--){
        printf(" %s \n",operations[k]);
        }
    }
    free(tirage);
    for (int k = 0; k < nb; k++) {
        free(operations[k]);
        }
    free(operations);
    return 0;
}
