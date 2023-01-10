// Projet le compte est bon

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "biblio.h"

#define N_MAX 10


int main(){int i, A;

    int nb, cible,* tirage;                                           


    // récupération d'un jeu à partir des fichier .txt fournis
    //char * file_name = "jeu6-1.txt";     
    
    char file_name[15];                 // Ouvre le fichier .txt souhaité 
    puts("Entrez le nom du fichier");
    gets(file_name);
    lecture_file(file_name, tirage, &nb, &cible);
    


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
