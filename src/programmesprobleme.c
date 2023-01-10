
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "biblio.h"



void clonage(int* tirage, int* clone , int nb){
    //on alloue dinamiquement clone avant
    int i;
    for (i=0;i<nb;i++) {
        clone[i]=tirage[i];
    }
    return;
}




int resolution(int* tirage, int nb, int cible, char** operations){
    char* operateurs[4]={"+","-","*","/"};
    int i,j,c,resultat, val1, val2;
    int* clone = calloc(nb,sizeof(int));
    for (i=0; i<nb; i++) { //on verifie si la cible est dans le tirage
        if (tirage[i] == cible) {
            return 0;
        }
    }

    for (i=0;i<nb;i++){ //on fait varier le premier nombre du couple (i,j)
        for (j=0;j<nb;j++) { //on fait varier le deuxieme nombre du couple (i,j)
            if (j!=i){ //i et j differents
                for (c=1;c<=4;c++){ //on essaie toutes les operations
                    clonage(tirage,clone,nb); //on sauvegarde les tableaux
                     //etude de chaque cas
                    val1=tirage[i];val2=tirage[j];    
                        if (c==1) {//addition
                            if (tirage[i]!=0 && tirage[j]!=0){ 
                                    resultat=tirage[i]+tirage[j];
                                    tirage[i]=resultat; //on remplace par le resultat
                                    tirage[j]=tirage[nb-1]; //on elimine la j-eme valeur
                                    }
                        }

                        if (c==2) {//soustraction
                            if (tirage[i]>tirage[j] && tirage[i]!=0 && tirage[j]!=0 ){ 
                            resultat=tirage[i]-tirage[j];
                            tirage[i]=resultat; //on remplace par le resultat
                            tirage[j]=tirage[nb-1];} //on elimine la j-eme valeur
                            }

                        if (c==3) {  //produit
                            if (tirage[i]!=0 && tirage[j]!=0 && tirage[j]!=1 && tirage[i]!=1){ 
                                    resultat=tirage[i]*tirage[j];
                                    tirage[i]=resultat; //on remplace par le resultat
                                    tirage[j]=tirage[nb-1]; //on elimine la j-eme valeur
                                    }
                            }

                        if (c==4) { 
                            if (tirage[j]!=0 && tirage[i]%tirage[j]==0 && tirage[j]>0 && tirage[i]>0 && tirage[j]!=1 && tirage[i]!=1) {
                                    resultat= tirage[i]/tirage[j]; //on elimine la division par 0 et on veut un entier
                                    tirage[i]=resultat; //on remplace par le resultat
                                    tirage[j]=tirage[nb-1];} //on elimine la j-eme valeur
                            }

                            
                            if (tirage[i]==cible || resolution(tirage,nb-1,cible,operations)==0){
                                sprintf(operations[nb-1],"%d %s %d = %d",val1,operateurs[c-1],val2,resultat);

                                clonage(clone,tirage,nb);
                                free(clone);
                                return 0;}

                            //fin operation
                            clonage(clone,tirage,nb);

                }
            }
        }
    }
    free(clone);
    return 1; //aucune sequence possible pour atteindre la cible
}


 // obtention du tirage à l'aide d'un fichier
void lecture_file(char* file_name, int* tirage, int* nb, int* cible){ char file_directory[100] = "fichiers utiles/jeux/"; //changer l'adresse si besoin
    strcat(file_directory, file_name);
    FILE* f1 = fopen(file_directory, "r");
    if (f1 == NULL){
        printf("Erreur lors de l'ouverture du fichier");
        return;
    }
    fscanf(f1, "%d", nb);       // recupération de N
    tirage=calloc(*nb,sizeof(int));
    int i;
    for (i = 0; i < *nb; i++){      // creéation du tableau tirage
        fscanf(f1, "%d", tirage+i);
    }

    fscanf(f1, "%d", cible);        // récupération du nombre cible
    return;
}



// obtention d'un tirage aléatoirement

void random_tirage(int * tirage, int nb){
    srand(time(NULL));
    int i, k;
    int plaques[24] = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,25,50,75,100};
    
    for (k = 0; k < nb; k++){
        i = rand() % (24 - k);
        *(tirage + k) = plaques[i];
        plaques[i] = plaques[23-k];
    }
    return;
}

int resolutionplusproche(int* tirage, int nb, int cible,int distancemin, char** operations){
    char* operateurs[4]={"+","-","*","/"};
    int i,j,c,resultat, val1, val2, val;
    int* clone = calloc(nb,sizeof(int));
    for (i=0; i<nb; i++) { //on verifie si la cible est dans le tirage
        if (tirage[i] == cible) {
            return 0;
        }
    }
    for (i=0;i<nb;i++){ //on fait varier le premier nombre du couple (i,j)
        for (j=0;j<nb;j++) { //on fait varier le deuxieme nombre du couple (i,j)
            if (j!=i){ //i et j differents
                for (c=1;c<=4;c++){ //on essaie toutes les operations
                        clonage(tirage,clone,nb); //on sauvegarde les tableaux
                        //etude de chaque cas
                        val1=tirage[i];val2=tirage[j];    
                            if (c==1) {//addition
                                if (tirage[i]!=0 && tirage[j]!=0){ 
                                    resultat=tirage[i]+tirage[j];
                                    tirage[i]=resultat; //on remplace par le resultat
                                    tirage[j]=tirage[nb-1]; //on elimine la j-eme valeur
                                    }
                            }

                            if (c==2) {//soustraction
                                if (tirage[i]>tirage[j] && tirage[i]!=0 && tirage[j]!=0){ 
                                resultat=tirage[i]-tirage[j];
                                tirage[i]=resultat; //on remplace par le resultat
                                tirage[j]=tirage[nb-1];} //on elimine la j-eme valeur
                                }

                            if (c==3) {  //produit
                                if (tirage[i]!=0 && tirage[j]!=0 && tirage[j]!=1 && tirage[i]!=1){ 
                                    resultat=tirage[i]*tirage[j];
                                    tirage[i]=resultat; //on remplace par le resultat
                                    tirage[j]=tirage[nb-1]; //on elimine la j-eme valeur
                                    }
                                }
                            
                            if (c==4) { 
                                if (tirage[j]!=0 && tirage[i]%tirage[j]==0 && tirage[j]>0 && tirage[i]>0 && tirage[j]!=1 && tirage[i]!=1) {
                                    resultat= tirage[i]/tirage[j]; //on elimine la division par 0 et on veut un entier
                                    tirage[i]=resultat; //on remplace par le resultat
                                    tirage[j]=tirage[nb-1];} //on elimine la j-eme valeur
                                }

                            if (abs(cible - resultat)<abs(distancemin)){

                                distancemin=cible-resultat;
                                sprintf(operations[nb-1],"%d %s %d = %d",val1,operateurs[c-1],val2,resultat);

                            }
                            
                            val=resolutionplusproche(tirage,nb-1,cible,distancemin,operations);
                            
                            if (tirage[i]==cible || val==0){
                                sprintf(operations[nb-1],"%d %s %d = %d",val1,operateurs[c-1],val2,resultat);

                                clonage(clone,tirage,nb);

                                free(clone);

                                return 0;}

                            if (abs(distancemin)>abs(val)) {
                                distancemin=val;
                                sprintf(operations[nb-1],"%d %s %d = %d",val1,operateurs[c-1],val2,resultat);
                            }

                            //fin operation
                            clonage(clone,tirage,nb);
                }
            }
        }
    }
    free(clone);
    return distancemin; //aucune sequence possible pour atteindre la cible
}
