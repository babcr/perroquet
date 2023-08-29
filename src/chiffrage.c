#include "chiffrage.h"

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
        if (!feof(file_to_cipher)){ // important: second test de fin de ligne permettant d'éviter de prendre en compte le caractere de fin de ligne
            fputc(calc(c,cursor->c) , destination);
            cursor = cursor->next;
        }
    }while (!feof(file_to_cipher));
    erasefile(SOURCE_PATH);
    return EXIT_SUCCESS;
}

int decipher(FILE* file_to_decipher, FILE* destination, s_charlist* parrot){
    char c = 0;
    s_charlist* cursor = parrot;
    do {
        c = fgetc(file_to_decipher);
        if (!feof(file_to_decipher)){   // important: second test de fin de ligne permettant d'éviter de prendre en compte le caractere de fin de fichier
            fputc(uncalc(c,cursor->c) , destination);
            cursor = cursor->next;
        }
    }while (!feof(file_to_decipher));
    erasefile(DEST);
    return EXIT_SUCCESS;
}

int compare(char* word_to_compare,char* path){
    FILE* file = fopen(path, "r");
    int n = 0;
    char c = 0;
    int diff = EXIT_SUCCESS;
    do {
        c = fgetc(file);
        if (!feof(file)){               // important: second test de fin de ligne permettant d'éviter de prendre en compte le caractere de fin de fichier
            if (c != *(word_to_compare + n)){
                diff = EXIT_FAILURE;
            }
        }
        n++;
    }while (!feof(file));
    fclose(file);
    return diff;
}