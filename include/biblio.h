#ifndef BIBLIO_H
#define BIBLIO_H


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <errno.h>

#define N_MAX 10





void lecture_file(char* file_name, int* tirage, int* nb, int* cible);

void random_tirage(int * tirage, int nb);

void clonage(int* tirage, int* clone , int nb);

int resolutionplusproche(int* tirage, int nb, int cible,int distancemin, char** operations);

int resolution(int* tirage, int nb, int cible, char** operations);


#endif