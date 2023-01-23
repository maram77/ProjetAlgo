#ifndef TREE
#define TREE

struct Tree * arbreConsVide();

struct Tree * arbreCons(char c, int n,struct  Tree * fg,struct  Tree * fd);

int arbreEstVide(struct Tree * tree);

char arbreRacineLettre(struct Tree * tree);

int arbreRacineNbOcc(struct Tree * tree);

struct Tree * arbreFilsDroit(struct Tree * tree);

struct Tree * arbreFilsGauche(struct Tree * tree);

void arbreSuppr(struct Tree * tree);


#endif
