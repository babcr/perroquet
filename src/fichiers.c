#include "fichiers.h"
s_charlist* fetchparrot(){
    s_charlist* parrot = (s_charlist * )malloc(sizeof(s_charlist));
    FILE* parrot_file = fopen(PARROT_FILE,"r");
    
    parrot->c = fgetc(parrot_file);
    s_charlist* cursor = parrot;
    while (!feof(parrot_file)){
        char c = fgetc(parrot_file);
        if (!feof(parrot_file)){
            cursor->next = (s_charlist*)malloc(sizeof(s_charlist));
            cursor = cursor->next;
            cursor->c = c;
        }
    }
    cursor->next = parrot;

    return parrot;
}

void erasefile(char* path){
    FILE *fc;
    fc=fopen(path,"w");;
    if(fc!=0) printf("\nfichier %s effacé\n", path);
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