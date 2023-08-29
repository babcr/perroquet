#ifndef FICHIERS_H
#define FICHIERS_H

#include <stdio.h>
#include <stdlib.h>

#define SOURCE_PATH "ressources/source.txt" //fichier à chiffrer ou recepteur de déchiffrage
#define DEST "ressources/dest.crt"          //fichier destination du chiffrage ou à déchiffrer
#define PARROT_FILE "ressources/peroq.def"  //le perroquet à utiliser pour chiffrer et déchiffrer

typedef struct charlist {
    char c;
    struct charlist* next;
}s_charlist;

// Permet de charger le perroquet dans une liste chainer bouclée pour faciliter les parcours
s_charlist* fetchparrot();

// Permet effacer un fichier, prends le chemin du fichier en entrée
void erasefile(char*);

// Libère la memoire allouée lors du chargement du perroquet
void discardparrot(s_charlist*);
#endif