#ifndef FICHIERS_H
#define FICHIERS_H

#define DEST "dest.crt"
#include <stdio.h>
#include "vue.h"

char* fetchdata(){
    char* data;
    char* l = file_to_cipher();
    FILE* f = fopen(l,"r");
    FILE* d = fopen(DEST,"w");
    while (!feof(f))
    {

    }
    return data;
}

#endif