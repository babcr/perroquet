#ifndef FICHIERS_H
#define FICHIERS_H

#include <stdio.h>
#include <stdlib.h>

#include "vue.h"

#define SOURCE_PATH "ressources/source.txt"
#define DEST "ressources/dest.crt"
#define PARROT_FILE "ressources/peroq.def"

typedef struct charlist {
    char c;
    struct charlist* next;
}s_charlist;

s_charlist* fetchparrot();

void discardparrot(s_charlist*);
#endif