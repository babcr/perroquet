#ifndef CHIFFRAGE_H
#define CHIFFRAGE_H

#include <stdio.h>
#include "fichiers.h"

char calc(char up, char down);
int cipher(FILE*, FILE*, const s_charlist*);

#endif