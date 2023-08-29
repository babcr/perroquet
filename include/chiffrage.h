#ifndef CHIFFRAGE_H
#define CHIFFRAGE_H

#include <stdio.h>
#include "fichiers.h"

/*  
Fonction permettant de chiffrer le premier fichier en paramètre vers le
second fichier en parametre à l'aide du perroquet chargé en liste chainée
bouclée 
*/
int cipher(FILE* file_to_cipher, FILE* destination, s_charlist*);
/*  
Fonction permettant de dechiffrer le premier fichier en paramètre vers le
second fichier en parametre à l'aide du perroquet chargé en liste chainée
bouclée 
*/
int decipher(FILE* file_to_decipher, FILE* destination, s_charlist*);
/*
Fonction de comparaison d'un mot sous forme de chaine de caracteres avec un
mot situé dans un fichier dont le chemin est donné en second paramètre
*/
int compare(char* word_to_compare,char* path);
#endif