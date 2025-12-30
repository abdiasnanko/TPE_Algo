#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ETUDIANTS 100
#define MAX_NOM 50
#define MAX_PRENOM 50
#define MAX_DEPARTEMENT 50
#define MAX_FILIERE 50
#define MAX_REGION 50

typedef struct {
    char matricule[10];
    char nom[MAX_NOM];
    char prenom[MAX_PRENOM];
    char date_naissance[10];
    char sexe[10];
    char departement[MAX_DEPARTEMENT];
    char filiere[MAX_FILIERE];
    char region[MAX_REGION];
} Etudiant;

typedef struct {
    Etudiant etudiants[MAX_ETUDIANTS];
    int nombre_etudiants;
} Gestion_des_Etudiants;

// Fonction pour calculer l'âge de l'étudiant
int calculer_age(char* date_naissance) {
    int annee_naissance = atoi(strncpy((char*)malloc(5), date_naissance, 4));
    int annee_actuelle = 2023; // Remplacer par l'année actuelle
    return annee_actuelle - annee_naissance;
}
// Fonction pour modifier un étudiant
void modifier_etudiant(Gestion_des_Etudiants* gestion) {
    char matricule[10];
    printf("Entrez le matricule de l'étudiant à modifier : ");
    scanf("%s", matricule);
    for (int i = 0; i < gestion->nombre_etudiants; i++) {
        if (strcmp(gestion->etudiants[i].matricule, matricule) == 0) {
            printf("Entrez le nouveau nom : ");
            scanf("%s", gestion->etudiants[i].nom);
            printf("Entrez le nouveau prénom : ");
            scanf("%s", gestion->etudiants[i].prenom);
            printf("Entrez la nouvelle date de naissance (JJ/MM/AAAA) : naissance (JJ/MM/AAAA) : ");
            scanf("%s", gestion->etudiants[i].date_naissance);
            printf("Entrez le nouveau sexe : ");
            scanf("%s", gestion->etudiants[i].sexe);
            printf("Entrez le nouveau département : ");
            scanf("%s", gestion->etudiants[i].departement);
            printf("Entrez la nouvelle filière : ");
            scanf("%s", gestion->etudiants[i].filiere);
            printf("Entrez la nouvelle région d'origine : ");
            scanf("%s", gestion->etudiants[i].region);
        }
    }
    printf("Étudiant non trouvé !\n");
}