#ifndef FICHIERS_H
#define FICHIERS_H

#include <stdio.h>

#include "vue.h"

#define SOURCE_PATH "source.txt"
#define DEST "dest.crt"
#define PARROT_FILE "peroq.def"

typedef struct charlist {
    char c;
    struct charlist* next;
}s_charlist;

s_charlist* fetchparrot();

void discardparrot();

#endif