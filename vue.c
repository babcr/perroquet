#include "vue.h"

#include <stdio.h>
#include <stdlib.h>

#define SOURCE_PATH "source.txt"
void presentation(){
    
}
char* file_to_cipher(){
    char* path = SOURCE_PATH;

    printf("Quel fichier souhaiterez vous chiffrer (ENTRER si déjà dans source.txt)?");
    scanf("%s",path);
    return path;
}
e_choice users_choice(){
    e_choice choice;
    printf("Quel action souhaitez-vous effectuer?(c -> chiffrer, d -> dechiffrer)");
    scanf("%s",&choice);
    return choice;
}