#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100


typedef struct {
    char matricule[25];
    char nom[30];
    char prenom[30];
    char date_naiss[15];
    char sexe[8];
    char region_origine[30];
    char departement_origine[30];
    char filiere[30];
} G10;

// Variables globales
G10 etudiants[MAX];
int n = 0;

// Prototypes des fonctions
void ajouterEtudiants();
void afficherEtudiants();
void modifierEtudiant();
void supprimerEtudiant();
void trierAlphabetiquement();
int rechercheDichotomique(char nom[]);
void menu();
void calculerAgeEtudiant();
void trierParFiliere();
int trouverEtudiantParMatricule(char matricule[]);

// Fonction pour trouver un étudiant par matricule
int trouverEtudiantParMatricule(char matricule[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(etudiants[i].matricule, matricule) == 0) {
            return i;
        }
    }
    return -1;
}

// Fonction modifiée pour enregistrer plusieurs étudiants
void ajouterEtudiants() {
    int nombre, i;
    
    printf("Combien d'etudiants voulez-vous enregistrer ? : ");
    scanf("%d", &nombre);
    
    if (n + nombre > MAX) {
        printf("Impossible ! La liste ne peut contenir que %d étudiants maximum.\n", MAX);
        printf("Il reste seulement %d places disponibles.\n", MAX - n);
        return;
    }
    
    for (i = 0; i < nombre; i++) {
        printf("\n=== ENREGISTREMENT ETUDIANT %d ===\n", n + 1);
        
        printf("Matricule : ");
        scanf("%s", etudiants[n].matricule);
        
        printf("Nom : ");
        scanf("%s", etudiants[n].nom);
        
        printf("Prenom : ");
        scanf("%s", etudiants[n].prenom);
        
        printf("Date de naissance (JJ/MM/AAAA) : ");
        scanf("%s", etudiants[n].date_naiss);
        
        printf("Sexe (M/F) : ");
        scanf("%s", etudiants[n].sexe);
        
        // Region avant département (comme demandé)
        printf("Region d'origine : ");
        scanf("%s", etudiants[n].region_origine);
        
        printf("Departement d'origine : ");
        scanf("%s", etudiants[n].departement_origine);
        
        printf("Filiere : ");
        scanf("%s", etudiants[n].filiere);
        
        n++;
        printf("Etudiant enregistre avec succes !\n");
    }
    
    printf("\n%d etudiants enregistres avec succes !\n", nombre);
}

// Fonction afficherEtudiants modifiée avec la nouvelle logique
void afficherEtudiants() {
    if (n == 0) {
        printf("Aucun etudiant enregistre.\n");
        return;
    }
    
    printf("\n=== LISTE (%d étudiants) ===\n", n);
    printf("%-15s %-15s %-15s %-15s\n", 
           "Matricule", "Nom", "Prenom", "Filiere");
    printf("--------------------------------------------------\n");
    
    for (int i = 0; i < n; i++) {
        printf("%-15s %-15s %-15s %-15s\n", 
               etudiants[i].matricule, etudiants[i].nom, 
               etudiants[i].prenom, etudiants[i].filiere);
    }
}

void modifierEtudiant() {
    char mat[25];
    int trouve = 0;
    printf("Entrer le matricule : ");
    scanf("%s", mat);

    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(etudiants[i].matricule, mat) == 0) {
            printf("Nouveau nom : ");
            scanf("%s", etudiants[i].nom);

            printf("Nouveau prenom : ");
            scanf("%s", etudiants[i].prenom);

            printf("Nouvelle date de naissance (JJ/MM/AAAA) : ");
            scanf("%s", etudiants[i].date_naiss);

            printf("Nouveau sexe (M/F) : ");
            scanf("%s", etudiants[i].sexe);

            printf("Nouvelle region d'origine : ");
            scanf("%s", etudiants[i].region_origine);

            printf("Nouveau departement d'origine : ");
            scanf("%s", etudiants[i].departement_origine);

            printf("Nouvelle filiere : ");
            scanf("%s", etudiants[i].filiere);

            trouve = 1;
            printf("Modification reussie !\n");
            break;
        }
    }

    if (!trouve)
        printf("Etudiant non trouve.\n");
}

void supprimerEtudiant() {
    char mat[25];
    int trouve = 0;
    printf("Entrer le matricule : ");
    scanf("%s", mat);

    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(etudiants[i].matricule, mat) == 0) {
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
    if (n == 0) {
        printf("Aucun étudiant à trier.\n");
        return;
    }
    
    G10 temp;
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
    
    // Affichage du résultat sous forme de tableau
    printf("\n=== LISTE TRIEE PAR ORDRE ALPHABETIQUE (%d étudiants) ===\n", n);
    printf("%-15s %-15s %-15s %-15s\n", 
           "Matricule", "Nom", "Prenom", "Filiere");
    printf("--------------------------------------------------\n");
    
    for (i = 0; i < n; i++) {
        printf("%-15s %-15s %-15s %-15s\n", 
               etudiants[i].matricule, etudiants[i].nom, 
               etudiants[i].prenom, etudiants[i].filiere);
    }
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

void calculerAgeEtudiant() {
    char mat[25];
    int trouve = 0;
    printf("Entrer le matricule : ");
    scanf("%s", mat);

    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(etudiants[i].matricule, mat) == 0) {
            // Extraire jour, mois, année
            int jour, mois, annee;
            if (sscanf(etudiants[i].date_naiss, "%d/%d/%d", &jour, &mois, &annee) != 3) {
                printf("Format de date invalide !\n");
                return;
            }
            
            // Date actuelle
            time_t t = time(NULL);
            struct tm *tm_info = localtime(&t);
            int annee_actuelle = tm_info->tm_year + 1900;
            int mois_actuel = tm_info->tm_mon + 1;
            int jour_actuel = tm_info->tm_mday;
            
            // Calcul âge
            int age = annee_actuelle - annee;
            if (mois_actuel < mois || (mois_actuel == mois && jour_actuel < jour)) {
                age--;
            }
            
            printf("Age de %s %s : %d ans\n", 
                   etudiants[i].prenom, etudiants[i].nom, age);
            trouve = 1;
            break;
        }
    }

    if (!trouve)
        printf("Etudiant non trouve.\n");
}

void trierParFiliere() {
    if (n == 0) {
        printf("Aucun étudiant à trier.\n");
        return;
    }
    
    G10 temp;
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            // Comparer d'abord par filière, puis par nom si même filière
            int cmp_filiere = strcmp(etudiants[i].filiere, etudiants[j].filiere);
            if (cmp_filiere > 0 || (cmp_filiere == 0 && strcmp(etudiants[i].nom, etudiants[j].nom) > 0)) {
                temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
        }
    }
    printf("Tri par filiere effectue.\n");
    
    // Affichage du résultat sous forme de tableau
    printf("\n=== LISTE TRIEE PAR FILIERE (%d étudiants) ===\n", n);
    printf("%-15s %-15s %-15s %-15s\n", 
           "Matricule", "Nom", "Prenom", "Filiere");
    printf("--------------------------------------------------\n");
    
    for (i = 0; i < n; i++) {
        printf("%-15s %-15s %-15s %-15s\n", 
               etudiants[i].matricule, etudiants[i].nom, 
               etudiants[i].prenom, etudiants[i].filiere);
    }
}

void menu() {
    int choix;
    char nomRecherche[30];

    do {
        printf("\n GESTION DES ETUDIANTS G10\n");
        printf("1. Enregistrer des etudiants\n");
        printf("2. Afficher les etudiants\n");
        printf("3. Modifier un etudiant\n");
        printf("4. Supprimer un etudiant\n");
        printf("5. Trier par ordre alphabetique\n");
        printf("6. Recherche dichotomique (par nom)\n");
        printf("7. Calculer l'âge d'un étudiant\n");
        printf("8. Trier par filiere\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: ajouterEtudiants(); break;
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
                    printf("Etudiant trouve : %s %s (Matricule %s)\n",
                           etudiants[pos].nom,
                           etudiants[pos].prenom,
                           etudiants[pos].matricule);
                } else {
                    printf("Etudiant non trouve.\n");
                }
                break;
            case 7: calculerAgeEtudiant(); break;
            case 8: trierParFiliere(); break;
            case 0: printf("Fin du programme.\n"); break;
            default: printf("Choix invalide !\n");
        }

    } while (choix != 0);
}

int main() {
    #ifdef _WIN32
        system("chcp 65001 > nul");
        system("cls");
    #endif
    
    printf("SYSTEME DE GESTION DES ETUDIANTS G10\n");
    printf("=====================================\n");
    
    menu();
    return 0;
}
