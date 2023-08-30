#include "chiffrage.h"
#include <string.h> // trouver la taille des chaines de characteres avec strlen

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
        if (!feof(file_to_cipher)){ // important: second test de fin de fichier permettant d'éviter de prendre en compte le caractere de fin de fichier
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
        if (!feof(file_to_decipher)){   // important: second test de fin de fichier permettant d'éviter de prendre en compte le caractere de fin de fichier
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
    const unsigned long word_size = strlen(word_to_compare);
    do {
        c = fgetc(file);
        if (!feof(file)){               // important: second test de fin de ligne permettant d'éviter de prendre en compte le caractere de fin de fichier
            if (n+1 > word_size){       // eviter d'accéder aux addresses au-dela de la chaine de caractere à comparer
                diff = EXIT_FAILURE;
            }
            else{
                if (c != *(word_to_compare + n)){
                    diff = EXIT_FAILURE;
                }
            }
            n++;
        }
    }while (!feof(file));
    if (word_size != n) diff = EXIT_FAILURE; // comparaison des tailles de chaine
    fclose(file);
    return diff;
}