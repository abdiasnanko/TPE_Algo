#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int matricule;
    char nom[30];
    char prenom[30];
    int age;
    char sexe[10];
    char filiere[30];
    char region[30];
} Etudiant;

Etudiant etudiants[MAX];
int n = 0;
int matricule_auto = 1000;

void ajouterEtudiant() {
    if (n >= MAX) {
        printf("Liste pleine !\n");
        return;
    }

    etudiants[n].matricule = matricule_auto++;

    printf("Nom : ");
    scanf("%s", etudiants[n].nom);

    printf("Prenom : ");
    scanf("%s", etudiants[n].prenom);

    printf("Age : ");
    scanf("%d", &etudiants[n].age);
    printf("sexe:");
    scanf("%s", etudiants[n].sexe);
    printf("filiere:");
    scanf("%s", etudiants[n].filiere);
    printf("region d'origine:");
    scanf("%s", etudiants[n].region);
    n++;
    printf("Etudiant enregistre avec succes !\n");
}

void afficherEtudiants() {
    if (n == 0) {
        printf("Aucun etudiant enregistre.\n");
        return;
    }

    int i;
    for (i = 0; i < n; i++) {
        printf("\nMatricule : %d", etudiants[i].matricule);
        printf("\nNom : %s", etudiants[i].nom);
        printf("\nPrenom : %s", etudiants[i].prenom);
        printf("\nAge : %d\n", etudiants[i].age);
        printf("Sexe : %s\n", etudiants[i].sexe);
        printf("Filiere : %s\n", etudiants[i].filiere);
        printf("Region d'origine : %s\n", etudiants[i].region);
    }
}

void modifierEtudiant() {
    int mat, trouve = 0;
    printf("Entrer le matricule : ");
    scanf("%d", &mat);

    int i;
    for (i = 0; i < n; i++) {
        if (etudiants[i].matricule == mat) {
            printf("Nouveau nom : ");
            scanf("%s", etudiants[i].nom);

            printf("Nouveau prenom : ");
            scanf("%s", etudiants[i].prenom);

            printf("Nouvel age : ");
            scanf("%d", &etudiants[i].age);
            printf("Nouveau sexe : ");
            scanf("%s", etudiants[i].sexe);
            printf("Nouvelle filiere : ");
            scanf("%s", etudiants[i].filiere);
            printf("Nouvelle region d'origine : ");
            scanf("%s", etudiants[i].region);

            trouve = 1;
            printf("Modification reussie !\n");
            break;
        }
    }

    if (!trouve)
        printf("Etudiant non trouve.\n");
}

void supprimerEtudiant() {
    int mat, trouve = 0;
    printf("Entrer le matricule : ");
    scanf("%d", &mat);

    int i;
    for ( i= 0; i < n; i++) {
        if (etudiants[i].matricule == mat) {
            for (int j = i; j < n - 1; j++) {
                etudiants[j] = etudiants[j + 1];
            }
            n--;
            trouve = 1;
            printf("Etudiant supprime.\n");
            break;
        }
    }

    if (!trouve)
        printf("Etudiant non trouve.\n");
}

void trierAlphabetiquement() {
    Etudiant temp;
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(etudiants[i].nom, etudiants[j].nom) > 0) {
                temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
        }
    }
    printf("Tri alphabetique effectue.\n");
}

int rechercheDichotomique(char nom[]) {
    int debut = 0, fin = n - 1, milieu;

    while (debut <= fin) {
        milieu = (debut + fin) / 2;
        int cmp = strcmp(nom, etudiants[milieu].nom);

        if (cmp == 0)
            return milieu;
        else if (cmp < 0)
            fin = milieu - 1;
        else
            debut = milieu + 1;
    }
    return -1;
}

void menu() {
    int choix;
    char nomRecherche[30];

    do {
        printf("\n GESTION DES ETUDIANTS\n");
        printf("1. Enregistrer un etudiant\n");
        printf("2. Afficher les etudiants\n");
        printf("3. Modifier un etudiant\n");
        printf("4. Supprimer un etudiant\n");
        printf("5. Trier par ordre alphabetique\n");
        printf("6. Recherche dichotomique (par nom)\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: ajouterEtudiant(); break;
            case 2: afficherEtudiants(); break;
            case 3: modifierEtudiant(); break;
            case 4: supprimerEtudiant(); break;
            case 5: trierAlphabetiquement(); break;
            case 6:
                printf("Entrer le nom a rechercher : ");
                scanf("%s", nomRecherche);
                trierAlphabetiquement();
                int pos = rechercheDichotomique(nomRecherche);
                if (pos != -1) {
                    printf("Etudiant trouve : %s %s (Matricule %d)\n",
                           etudiants[pos].nom,
                           etudiants[pos].prenom,
                           etudiants[pos].matricule);
                } else {
                    printf("Etudiant non trouve.\n");
                }
                break;
            case 0: printf("Fin du programme.\n"); break;
            default: printf("Choix invalide !\n");
        }

    } while (choix != 0);
}
int main() {
    menu();
    return 0;
}