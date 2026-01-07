#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
typedef struct {
    char nom[30];
    char prenom[30];
} etudiant;
//fonction de comparaison
int compareretudiant(const void *a, const void *b) {
    etudiant *p1 = (etudiant *)a;
    etudiant *p2 = (etudiant *)b;
    //comparaison des noms
    char g=strcmp(p1->nom, p2->nom);
    if (g != 0) {
        return g;
    } else {
        return strcmp(p1->prenom, p2->prenom);
    }
}
int main() {
    etudiant liste[]={
        {"leroy", "champion"},
        {"choupinette", "lagloire"},
    };
    int n=2;
    //tri de la liste
    qsort(liste, n, sizeof(etudiant), compareretudiant);
    printf("liste triee par nom et prenom :\n");
    for (int i=0; i<n; i++){
        printf("%s %s\n", liste[i].nom, liste[i].prenom);
    }
    return 0;
}