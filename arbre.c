#include "arbre.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Déclaration de structure arbre
typedef struct Tree {
   char character;
   int occurrencesNumber;
   struct Tree * swapChar;
   struct Tree * nextChar;
} Tree;

// Construction arbre vide
Tree * arbreConsVide(){
    Tree * tree = malloc(sizeof(Tree *));
    tree->character = 0;
    tree->occurrencesNumber=0;
    tree->swapChar = NULL;
    tree->nextChar = NULL;
    return tree;
}

// Construction d'un arbre avec des paramètres
Tree * arbreCons(char c, int n, Tree * fg, Tree * fd){
    Tree * tree = malloc(sizeof(Tree *));
    tree->character = c;
    tree->swapChar = fg;
    tree->nextChar = fd;
    tree->occurrencesNumber=n;
    return tree;
}

// Test d'un arbre vide ou non
int arbreEstVide(Tree * tree){
    if(tree->character >= 0){
        printf("Votre dictionnaire n'est pas vide :)");
        return 1;
    }
    
    printf("Votre dictionnaire est vide :(");
    return 0;
}

// Fonction qui retourne la lettre stockée dans le nœud racine de l’arbre passé en paramètre
char arbreRacineLettre(Tree * tree){
    if(arbreEstVide(tree) == 1)
        return tree->character;

    return 0;
}

// Fonction qui retourne le nombre d'occurrence stocké dans le nœud racine de l’arbre passé en paramètre
int arbreRacineNbOcc(Tree * tree){
    if(arbreEstVide(tree) == 1)
        return tree->occurrencesNumber;

    return 0;
}

// Fonction qui retourne le sous-arbre droit de l’arbre passé en paramètre
Tree * arbreFilsDroit(Tree * tree){
    if(arbreEstVide(tree) == 1){
        if(tree->swapChar)
            return tree->swapChar;
        else{
            printf("fd = NULL !");
            return NULL;
        }
    }
    return NULL;
}

// Fonction qui retourne le sous-arbre gauche de l’arbre passé en paramètre
Tree * arbreFilsGauche(Tree * tree){
    if(arbreEstVide(tree) == 1){
        if(tree->nextChar)
            return tree->nextChar;
        else{
            printf("fg = NULL !");
            return NULL;
        }
    }
    return NULL;
} 

// Fonction qui permet de supprimer l’arbre passé en paramètre
void arbreSuppr(Tree * tree){
    if(tree){
        arbreSuppr(tree->swapChar);
        arbreSuppr(tree->nextChar);
        free(tree);
    }
} 

