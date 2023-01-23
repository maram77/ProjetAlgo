#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "arbre.h"
#include "dico.h"

// Déclaration de structure arbre
typedef struct Tree {
   char character;
   int occurrencesNumber;
   struct Tree * swapChar; // fg
   struct Tree * nextChar; // fd 
} Tree;

char word [100];
int myIndex = 0;
// Fonction affichage dictionnaire
void dicoAfficher(Tree * tree){
    if(tree){
        // Remplissage du tableau word par les caractéres de l'arbre
        word[myIndex] = tree->character;
        myIndex++;
        dicoAfficher(tree->nextChar);
        // Afficher le mot si nous atteignons la fin ('\0')
        if(tree->character == '\0'){
            printf("\n\t %s",word);
        }
        myIndex--;
        if(tree->swapChar){
            dicoAfficher(tree->swapChar);
        }
    }
}
// Insertion d'un mot dans un dictionnaire
Tree * dicoInsererMot(char mot[], Tree *tree){
    int i = 0;
    Tree * currentTree = tree;
    Tree * lastTree = NULL;
    char prev = ' ';
    
    // Parcourir le mot char par char
    while(mot[i] != '\0'){

        if(currentTree->character == 0){ // Ajouter le caractère actuel mot[i] et créer un arbre vide dans nextChar
            currentTree->character = mot[i];
            currentTree->nextChar = arbreConsVide();
            lastTree = currentTree;
            currentTree = currentTree->nextChar;
            i++;
        }else if(mot[i] == currentTree->character){ // Si le caractére existe déjà donc il suffit de changer les pointeurs
            lastTree = currentTree;
            currentTree = currentTree->nextChar;
            prev = '=';
            i++;
        }else if(mot[i] > currentTree->character){ // Lorsque le caractère actuel (mot[i]) est plus grand que le caractère currentTree
            if(currentTree->swapChar){ // Si swapChar != NULL => passer au next swapChar
                lastTree = currentTree;
                currentTree = currentTree->swapChar;
            }else{ // Si swapChar == NULL => Créer un nouveau swapChar avec le caractère mot[i]
                Tree * newTree = arbreConsVide();
                newTree->character = mot[i];
                newTree->nextChar = arbreConsVide();

                currentTree->swapChar = newTree;

                lastTree = newTree;
                currentTree = newTree->nextChar;
                i++;
            }
            prev = '>';
        }else if(mot[i] < currentTree->character){ // Lorsque le caractère actuel (mot[i]) est plus petit que le caractère currentTree => insérer avant currentTree ou dans nextChar
            Tree * newTree = arbreConsVide();
            newTree->character = mot[i];
            newTree->swapChar = currentTree;
            newTree->nextChar = arbreConsVide();

            if(lastTree){
                if(prev == '=')
                    lastTree->nextChar = newTree; // Insérer newTree dans le dernier arbre nextChar (pour réorganiser les caractéres exp : e après insérer a => a -> e)
                else
                    lastTree->swapChar = newTree; // Insérer newTree entre lastTree et currentTree
            } else{
                tree = newTree; // Changer l'arbre en pramétre pour pointer sur newTree (réorganiser)
            }

            lastTree = newTree;
            currentTree = newTree->nextChar;
            i++;
            prev = '<';
        }
    }

    if(currentTree->character != '\0')
        currentTree->character = '\0'; // Ajouter '\0' pour indiquer qu'il s'agit de la fin d'un mot (cas d'insertion d'un nouveau mot)
    
    currentTree->occurrencesNumber++; // incrémenter le numéro d'occurrence

    return tree;
}

// Calculer de nombre d'occurrences de chaque mot
int dicoNbOcc(char mot[], Tree * tree){
    if(tree){
        int i = 0;
        while(tree && mot[i] != '\0'){
            if(tree->character == mot[i]){
                tree = tree->nextChar;
                i++;
            }
            else if(tree->character < mot[i])
                tree = tree->swapChar;
            else
                return 0; // Elimination de cas de supérieur puisque les mots sont ordonnés
        }
        if(tree && tree->character == '\0')
            return tree->occurrencesNumber;
    }
    return 0;
}

// Nombre des mots différents
int nbMotsDifferents = 0;
int dicoNbMotsDifferents(Tree * tree, int firstTime){
    
    if(firstTime == 1)
        nbMotsDifferents = 0;
    
    if(tree){
        dicoNbMotsDifferents(tree->nextChar,0);
        if(tree->character == '\0'){
            nbMotsDifferents++;
        }
        if(tree->swapChar){
            dicoNbMotsDifferents(tree->swapChar,0);
        }
    }
    
    return nbMotsDifferents;
}

// Nombre total des mots
int nbMotsTotal = 0;
int dicoNbMotsTotal(Tree * tree, int firstTime){
    
    if(firstTime == 1)
        nbMotsTotal = 0;
        
    if(tree){
        dicoNbMotsTotal(tree->nextChar,0);
        if(tree->character == '\0'){
            nbMotsTotal += tree->occurrencesNumber;
        }
        if(tree->swapChar){
            dicoNbMotsTotal(tree->swapChar,0);
        }
    }
    return nbMotsTotal;
}

char treeChars[25][26];
int lineIndex = 0;
int maxLineIndex = 0;
int colIndex = 0;
int lastColIndex[25];

// Parcourir l'arbre pour insérer ces caractéres dans treeChars[25][26]
void makeTreeChars (Tree * tree){
    if(tree && tree->character != '\0'){
        treeChars[lineIndex][colIndex]=tree->character;
        if(treeChars[lineIndex][lastColIndex[lineIndex]] == '.')
            treeChars[lineIndex][lastColIndex[lineIndex]] = 0;
        treeChars[lineIndex][colIndex+1]='.';
        lastColIndex[lineIndex]=colIndex+1;
        
        if(tree->nextChar){
            lineIndex++;
            if(lineIndex > maxLineIndex)
                maxLineIndex = lineIndex;
            makeTreeChars(tree->nextChar);
            lineIndex--;
        }
        if(tree->swapChar){
            colIndex++;
            makeTreeChars(tree->swapChar);
        }
    }
}

// Initialiser les variables globales et appeller la méthode makeTreeChars (Tree * tree) aprés afficher treeChars[25][26]
void arbreAfficher(Tree * tree){

	// Initialiser les variables globales
    for(int i = 0; i < 25 ; i++){
        lastColIndex[i]=0;
        for(int j = 0; j < 26 ; j++){
            treeChars[i][j]=0;
        }
    }
    lineIndex = 0;
    maxLineIndex = 0;
    colIndex = 0;
    
    // Appeller la méthode makeTreeChars (Tree * tree) 
    makeTreeChars(tree);
    
    printf("\n\n +++++++++ Affichage d'arbre +++++++++\n");
    for(int i = 0; i < maxLineIndex ; i++){ // Parcourir treeChars[25][26] pour afficher chaque caractère
        int j = 0;
        while(treeChars[i][j] != '.'){
            if(treeChars[i][j] == 0){
                printf("     ");
            }else{
                printf(" (%c) ",treeChars[i][j]);
            }
            j++;
        }
        printf("\n");
    }
}
/////////////////////////////////////////////

int nombreAleatoire(int nombreMax) {
    return (rand() % nombreMax);
}

char motPioche [100];
int piocherMot(){
    
    FILE* dico = NULL; // Le pointeur de fichier qui va contenir notre fichier
    int nombreMots = 0, numMotChoisi = 0; 
    int caractereLu = 0;
    dico = fopen("dico.txt", "r"); // On ouvre le dictionnaire en lecture seule
    
    
    // On vérifie si on a réussi à ouvrir le dictionnaire
    if (dico == NULL){ // Si on n'a pas réussi à ouvrir le fichier
        printf("\nImpossible de charger le dictionnaire de mots"); 
        return 0; // On retourne 0 pour indiquer que la fonction a échoué
    }// À la lecture du return, la fonction s'arrête immédiatement.
      
    // On compte le nombre de mots dans le fichier (il suffit de compter les
    // entrées \n
    
    do{ 
        caractereLu = fgetc(dico); 
        if (caractereLu == '\n') 
            nombreMots++; 
    } while(caractereLu != EOF);
    
    numMotChoisi = nombreAleatoire(nombreMots); // On pioche un mot au hasard
    
    // On recommence à lire le fichier depuis le début. On s'arrête lorsqu'on est arrivé au bon mot
    rewind(dico); 
    
    while (numMotChoisi > 0) { 
        caractereLu = fgetc(dico); 
        if (caractereLu == '\n')
            numMotChoisi--; 
    } 
    
    //Le curseur du fichier est positionné au bon endroit.
    //On n'a plus qu'à faire un fgets qui lira la ligne 
    
    fgets(motPioche, 100, dico);
    
    printf("\n\t generated word: %s",motPioche);
    
    // On vire le \n à la fin
    motPioche[strlen(motPioche) - 1] = '\0'; 
    fclose(dico); 
    
    return 1; // Tout s'est bien passé, on retourne 1
}


