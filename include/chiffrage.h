#ifndef CHIFFRAGE_H
#define CHIFFRAGE_H

#include <stdio.h>
#include "fichiers.h"

char calc(char up, char down);
int cipher(FILE*, FILE*, s_charlist*);
int decipher(FILE*, FILE*, s_charlist*);
int compare(char* word_to_compare,char* path);
#endif