# boulissh_martinh2

Jalon visé : Jalon 6


*/!\ Le fichier Makefile ne marchant pas pour nous, nous avons décidés de vous faire copier/coller les lignes pour compiler le code afin de tout tester.


*On a organisé les programmes de sorte que les fonctions qui réalisent les tirages aléatoires et les lectures de tirage soient testées avec la fonction resolution et resolutionplusproche dans deux main différents.


/*Compilation dans le dossier boulissh_martinh2


$gcc src/*.c -g -Wall -Wextra -c -Iinclude

$gcc prog/*.c -g -Wall -Wextra -c -Iinclude                        //les warnings sont normaux




// TIRAGE ALEATOIRE (avec les deux versions de résolution)

$gcc main_a1.o programmesprobleme.o -o bin/prog1                  //test avec resolution

$gcc main_a1.o programmesprobleme.o -o bin/prog2                  //test avec resolutionplusproche




// LECTURE TIRAGE

$gcc main_l1.o programmesprobleme.o -o bin/prog3                //test avec resolution

$gcc main_l2.o programmesprobleme.o -o bin/prog4                //test avec resolutionplusproche




// Fin compilation



$del *.o //on supprime les executables inutiles

/* Fin compilation


