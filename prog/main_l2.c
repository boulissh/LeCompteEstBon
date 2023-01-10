// Projet le compte est bon

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "biblio.h"



int main(){int i, A,k;

    int nb, cible,distancemin=100000,*tirage;  //distancemin très grand pour initialiser                                 
    


    // récupération d'un jeu à partir des fichier .txt fournis
    //char * file_name = "jeu6-1.txt";     
    
    char file_name[15];                 // Ouvre le fichier .txt souhaité 
    puts("Entrez le nom du fichier");
    gets(file_name);

    lecture_file(file_name, tirage, &nb, &cible);
    

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
