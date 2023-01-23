#ifndef DICO
#define DICO

struct Tree * dicoInsererMot(char mot[],struct Tree *tree);

int dicoNbOcc(char mot[],struct Tree * tree);

int dicoNbMotsDifferents(struct Tree * tree, int firstTime);

int dicoNbMotsTotal(struct Tree * tree, int firstTime);

void makeTreeChars (struct Tree * tree);

void arbreAfficher(struct Tree * tree);

int nombreAleatoire(int nombreMax) ;

int piocherMot();

void dicoAfficher(struct Tree * tree);

#endif
