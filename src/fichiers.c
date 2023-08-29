#include "fichiers.h"
s_charlist* fetchparrot(){
    s_charlist* parrot = (s_charlist * )malloc(sizeof(s_charlist));
    FILE* parrot_file = fopen(PARROT_FILE,"r");
    
    parrot->c = fgetc(parrot_file);
    s_charlist* cursor = parrot;
    
    while (!feof(parrot_file)){
        cursor->next = (s_charlist*)malloc(sizeof(s_charlist));
        cursor = cursor->next;
        cursor->c = fgetc(parrot_file);
    }
    cursor->next = parrot;

    return parrot;
}
/*
void writetofile(char* str, char* filepath){
    FILE* f = fopen(filepath, "w");
    fwrite(str, sizeof(char), (int)(sizeof(str)/sizeof(char)),f);
}*/
void erasefile(char* path){
    FILE *fc;
    fc=fopen(path,"w");;
    if(fc!=0) printf("fichier effacer\n");
    fclose(fc);
}
void discardparrot(s_charlist* parrot){
    s_charlist* first = parrot;
    s_charlist* cursor;
    do {
        cursor = parrot;
        parrot = parrot->next;
        free(cursor);
    }while (parrot != first);
}