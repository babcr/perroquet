#include "chiffrage.h"

#define SUCCESS  0

char calc(char up, char down){
    return up - down;
}

char uncalc(char up, char down){
    return up + down;
}

int cipher(FILE* file_to_cipher, FILE* destination, s_charlist* parrot){
    char c = 0;
    s_charlist* cursor = parrot;
    do {
        c = fgetc(file_to_cipher);
        if (!feof(file_to_cipher)){
            fputc(calc(c,cursor->c) , destination);
            cursor = cursor->next;
        }
    }while (!feof(file_to_cipher));
    erasefile(SOURCE_PATH);
    return SUCCESS;
}

int decipher(FILE* file_to_decipher, FILE* destination, s_charlist* parrot){
    char c = 0;
    s_charlist* cursor = parrot;
    do {
        c = fgetc(file_to_decipher);
        if (!feof(file_to_decipher)){
            fputc(uncalc(c,cursor->c) , destination);
            cursor = cursor->next;
        }
    }while (!feof(file_to_decipher));
    erasefile(DEST);
    return SUCCESS;
}

int compare(char* word_to_compare,char* path){
    return 0;
}