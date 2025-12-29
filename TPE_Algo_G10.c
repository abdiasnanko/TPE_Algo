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
            printf("Entrer le matricule de l'etudiant %d: \n", i+1);
                    scanf("%s",s1[i].matricule);
            printf("Entrer le nom de l'etudiant %d: \n", i+1);
                    scanf("%s",s1[i].nom);
            printf("Entrer le prenom de l'etudiant %d: \n", i+1);
                    scanf("%s",s1[i].prenom);
            printf("Entrer la date de naissance de l'etudiant %d (JJ/MM/AAAA): \n", i+1);
                    scanf("%s",s1[i].date_naiss);
            printf("Entrer le sexe de l'etudiant %d (M/F): \n", i+1);
                    scanf("%s",s1[i].sexe);
            printf("Entrer le departement de l'etudiant %d: \n", i+1);
                    scanf("%s",s1[i].departement);
            printf("Entrer la filiere de l'etudiant %d: \n", i+1);
                    scanf("%s",s1[i].filiere);
            printf("Entrer la region d'origine de l'etudiant %d: \n", i+1);
                    scanf("%s",s1[i].region_origine);
            printf("\n");
        }
            printf("\n Liste des etudiants inscrits: \n");
            printf("Num.\t\tMatricule\t\tNoms\t\tPrenoms\t\tdate_Naiss.\t\tSexe\t\tDepartement\t\tFiliere\t\tRegion D'origine\n");
        for ( i = 0; i < lignes; i++)
        {
            printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", i+1, s1[i].matricule, s1[i].nom, s1[i].prenom, s1[i].date_naiss, s1[i].sexe, s1[i].departement, s1[i].filiere, s1[i].region_origine);
        }
    return 0;
}