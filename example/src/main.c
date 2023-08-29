#include <stdio.h>
#include <stdlib.h>

#include "chiffrage.h"
#include "fichiers.h"
#include "vue.h"

int main()
{
    FILE* file_to_cipher = fopen(SOURCE_PATH,"r");
    FILE* result_destination = fopen(DEST,"w");
    s_charlist* parrot = fetchparrot();
    int ret = cipher(file_to_cipher, result_destination, parrot);
    discardparrot(parrot);
    return ret;
}