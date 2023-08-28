#include "fichiers.h"

s_charlist* fetchparrot(){
    FILE* parrot_file = fopen(PARROT_FILE,"r");

    s_charlist* parrot = (s_charlist * )malloc(sizeof(s_charlist));
    parrot->c = fgetc(parrot_file);
    s_charlist* firstc = parrot;
    parrot = parrot->next;
    
    while (!feof(parrot_file)){
        parrot = (s_charlist*)malloc(sizeof(s_charlist)); 
        parrot->c = fgetc(parrot_file);
        parrot = parrot->next;
    }
    parrot->next = firstc;

    return parrot;
}

void discardparrot(){

}