#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dico.h"
#include "arbre.h"

typedef struct Tree {
   char character;
   int occurrencesNumber;
   struct Tree * swapChar;
   struct Tree * nextChar;
} Tree; 

extern char motPioche [100];

int main(){
    printf(" +++++++++ Ajout de mots au dictionnaire +++++++++\n");
    Tree * tree = arbreConsVide();
    char mot [100] = "ahmed";
    tree = dicoInsererMot(mot,tree);
    
    strcpy(mot,"lamis");
    tree = dicoInsererMot(mot,tree);
    strcpy(mot,"khaled");
    tree = dicoInsererMot(mot,tree);
    strcpy(mot,"lamia");
    tree = dicoInsererMot(mot,tree);
    strcpy(mot,"anticonstitutionnellement");
    tree = dicoInsererMot(mot,tree);
    strcpy(mot,"anis");
    tree = dicoInsererMot(mot,tree);
    printf("\n\t %d mots ajoutés",dicoNbMotsDifferents(tree,1));
    printf("\n\n +++++++++ Affichage du dictionnaire +++++++++\n");
    dicoAfficher(tree);
    
    printf("\n\n +++++++++ Le nombre d'occurrences +++++++++\n");
    printf("\n\tLe nombre d'occurrences du mot %s est %d", "lamis", dicoNbOcc("lamis",tree));
    printf("\n\tLe nombre d'occurrences du mot %s est %d", "marwa", dicoNbOcc("marwa",tree));
    printf("\n\n\t\t=> En ajoutant à nouveau le mot lamis\n");
    strcpy(mot,"lamis");
    tree = dicoInsererMot(mot,tree);
    printf("\n\tLe nombre d'occurrences du mot %s est %d", "lamis", dicoNbOcc("lamis",tree));
    
    printf("\n\n +++++++++ Nombre de mots +++++++++\n");
    printf("\n\tLe nombre de mots différents %d",dicoNbMotsDifferents(tree,1));
    printf("\n\tLe nombre de mot total %d",dicoNbMotsTotal(tree,1));
    
    arbreAfficher(tree);
    
    printf("\n\n +++++++++ Test de suppression +++++++++\n");
    printf("\n\t appel de la fonction arbreEstVide(tree)  ->  ");
    arbreEstVide(tree);
    printf("\n\t appel de la fonction arbreSuppr(tree)");
    arbreSuppr(tree);
    printf("\n\t appel de la fonction arbreEstVide(tree)  ->  ");
    arbreEstVide(tree);
    
    tree = arbreConsVide();
    
    printf("\n\n +++++++++ Ajout de mots aléatoires au dictionnaire +++++++++\n");
    srand(time(NULL)); // pour obtenir des valeurs différentes
    for(int i = 0 ; i < 10 ; i++){
        piocherMot();
        tree = dicoInsererMot(motPioche,tree);
        printf("\t\t\t => inserted !\n");
    }
    
    printf("\n\n +++++++++ Affichage du dictionnaire +++++++++\n");
    dicoAfficher(tree);
    
    printf("\n\n +++++++++ Nombre de mots +++++++++\n");
    printf("\n\tLe nombre de mots différents %d",dicoNbMotsDifferents(tree,1));
    printf("\n\tLe nombre de mot total %d \n",dicoNbMotsTotal(tree,1));

    return 0;
}

