#include "chiffrage.h"

#define SUCCESS  0
char calc(char up, char down){
    return up - down;
}

int cipher(FILE* file_to_cipher, FILE* destination, const s_charlist* parrot){
    char c = 0;
    
    while (!feof(file_to_cipher)){
        c = fgetc(file_to_cipher);
        fputc(calc(c,parrot) , destination);
        parrot = parrot->next;
    }

    return SUCCESS;
}