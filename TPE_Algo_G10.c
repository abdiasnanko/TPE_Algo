#include <stdio.h>
#include<math.h>
#include<string.h>

typedef struct{
    char matricule[30];
    char nom[30];
    char prenom[30];
    char date_naiss[30];
    char sexe[8];
    char departement[30];
    char filiere[30];
    char region_origine[30];

                }G10;
int main() {

    int i;
    int lignes;

            printf("combien d'etudiants voulez vous enregistrer ? \n");
                    scanf("%d",&lignes);
G10 s1[lignes];

        for (i = 0; i < lignes; i++)
        {
            printf("Entrer le matricule de l'etudiant %d: \n",i+1);
                    scanf("%s",s1[i].matricule);

            printf("Entrer le nom de l'etudiant %d: \n", i+1);
                    scanf("%s",s1[i].nom);

            printf("Entrer le prenom de l'etudiant %d: \n",i+1);
                    scanf("%s",s1[i].prenom);

            printf("Entrer la date de naissance de l'etudiant %d: \n",i+1);
                    scanf("%s",s1[i].date_naiss);

            printf("Entrer le sexe de l'etudiant %d: \n",i+1);
                    scanf("%s",s1[i].sexe);

            printf("Entrer le departement de l'etudiant %d: \n",i+1);
                    scanf("%s",s1[i].departement);

            printf("Entrer la filiere de l'etudiant %d: \n",i+1);
                    scanf("%s",s1[i].filiere);

            printf("Entrer la region d'origine de l'etudiant %d: \n",i+1);
                    scanf("%s",s1[i].region_origine);
        }
            printf("\n Liste des etudiants inscrits: \n");
        for ( i = 0; i < lignes; i++)
        {
                printf("%d %s \t ", i+1, s1[i].matricule, s1[i].nom);
        }
            
        
    return 0;
}
