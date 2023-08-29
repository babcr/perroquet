#include "vue.h"

#include <stdio.h>
#include <stdlib.h>

#include "fichiers.h"
#include "chiffrage.h"

void presentation(){
    printf("Ce programme vous permettra d'utiliser l'algorithme du perroquet afin de chiffrer le contenu d'un fichier de votre choix.");
    printf("\nFichiers:");
    printf("\n    - source.txt : le fichier à chiffrer (Attention: il sera supprimé après chiffrage)");
    printf("\n    - dest.crt : le fichier de destination du chiffrage");
    printf("\n    - peroq.def : le fichier contenant la clé du chiffrage, un mot de votre choix");
}

void userparrot(){
    char perroquet[CHAR_MAX_PARROT];
    printf("\nDonnez le perroquet puis taper sur ENTRER: ");
    gets(perroquet);
    int result = compare(perroquet, PARROT_FILE);
    switch (result){
        case EXIT_SUCCESS:
            printf("\nAccepté");
            break;
        default:
            printf("\nAccés Refusé");
            userparrot();
    }
}
char users_choice(){
    char choice;
    printf("\nQuelle action souhaitez-vous effectuer? (c -> chiffrer, d -> dechiffrer)");
    scanf("%c",&choice);
    return choice;
}

void instructions(char choice){
    int ret = EXIT_FAILURE;
    char key;
    while (ret==EXIT_FAILURE){
        switch (choice) {
            case 'c':
                printf("\nNous allons chiffrer le contenu du fichier %s vers %s.", SOURCE_PATH , DEST);
                printf("\nAssurez-vous que le contenu de %s soit bien celui que vous souhaitez chiffrer puis appuyez sur une touche.", SOURCE_PATH);
                scanf("%s",&key);
                ret = EXIT_SUCCESS;
                break;
            case 'd':
                printf("\nNous allons dechiffrer le contenu du fichier %s vers %s.", DEST,  SOURCE_PATH);
                printf("\nAssurez-vous que le contenu de %s soit bien celui que vous souhaitez dechiffrer puis appuyez sur une touche.", DEST);
                scanf("%s",&key);
                ret = EXIT_SUCCESS;
                break;
            default:
                printf("\nChoix inconnu.");
                ret = EXIT_FAILURE;
        }
    }  
}

void conclusion(char choice){
    switch (choice) {
        case 'c':
            printf("\nLe contenu du fichier %s a bien été chiffré vers %s.", SOURCE_PATH , DEST);
            break;
        case 'd':
            printf("\nLe contenu du fichier %s a bien été dechiffré vers %s.", DEST, SOURCE_PATH);
            break;
        default:
            NULL;
    }  
}

void intro(char* choice){  
    presentation();
    userparrot();
    *choice = users_choice();
    instructions(*choice);
    conclusion(*choice);
}

void maintask(){
    char choice = 0;
    intro(&choice);
    int ret;

    switch (choice){
        FILE* file_to_cipher = NULL;
        FILE* result_destination = NULL;
        s_charlist* parrot = NULL;
        case 'c':
            file_to_cipher = fopen(SOURCE_PATH,"r");
            result_destination = fopen(DEST,"w");
            parrot = fetchparrot();
            ret = cipher(file_to_cipher, result_destination, parrot);
            discardparrot(parrot);
            fclose(file_to_cipher);
            fclose(result_destination);
            break;
        case 'd':
            file_to_cipher = fopen(SOURCE_PATH,"w");
            result_destination = fopen(DEST,"r");
            parrot = fetchparrot();
            ret = decipher(result_destination, file_to_cipher, parrot);
            discardparrot(parrot);
            fclose(file_to_cipher);
            fclose(result_destination);
            break;
        default:
            printf("\nChoix inconnu.");
            maintask();
    }
    
}