#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct
{
  char matricule[25];
    char nom[30];
    char prenom[30];
    char date_naiss[15];
    char sexe[8];
    char departement[30];
    char filiere[30];
    char region_origine[30];
} G10;
G10* Gestion; // Revoir aussi les pointeurs !

  int j=0;
  int lignes=0;
  int i;
  int confirmation;

void enregistrer(){
      printf("\n Entrer le matricule de l'etudiant %d: \n", i+1);
        scanf("%s",Gestion[i].matricule);
      printf("Entrer le nom de l'etudiant %d: \n", i+1);
        scanf(" %30[^\n]",Gestion[i].nom);
      printf("Entrer le prenom de l'etudiant %d: \n", i+1);
        scanf(" %30[^\n]",Gestion[i].prenom);
      printf("Entrer la date de naissance de l'etudiant %d (JJ/MM/AAAA): \n", i+1);
        scanf("%s",Gestion[i].date_naiss);
      printf("Entrer le sexe de l'etudiant %d (M/F): \n", i+1);
        scanf("%s",Gestion[i].sexe);
      printf("Entrer le departement de l'etudiant %d: \n", i+1);
        scanf("%s",Gestion[i].departement);
      printf("Entrer la filiere de l'etudiant %d: \n", i+1);
        scanf("%s",Gestion[i].filiere);
      printf("Entrer la region d'origine de l'etudiant %d: \n", i+1);
        scanf("%s",Gestion[i].region_origine);
      printf("\n");
    j++;
      printf("Etudiant enregistre avec succes !\n");
}
void afficher(){
		if (j==0)
		{
      printf("AUCUN ETUDIANT ENREGISTRE ! \n");
			printf("\n");
      return;
		}
      printf("\n Liste des etudiants inscrits: \n");
      printf("%-05s %-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s \n", "Num.", "Matricule",  "Noms",  "Prenoms",  "date_Naiss.",  "Sexe",  "Departement",  "Filiere",  "Region D'origine");
			printf("\n");
		for ( i = 0; i < j; i++)
		{
      printf("%-05d %-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", i+1, Gestion[i].matricule, Gestion[i].nom, Gestion[i].prenom, Gestion[i].date_naiss, Gestion[i].sexe, Gestion[i].departement, Gestion[i].filiere, Gestion[i].region_origine);

			//printf("\n");
		}
}
  int main(){

  int choix;
	do {
continuation:
		printf("\n MENU DE GESTION \n");
		printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", "1. Enregistrer", "2. Modifier", "3. Recherher (matricule)" , "4. Supprimer", "5. Trier (ordre Alphabetique)", "6. Rechercher (Dichotomie)", "7. Calculateur d'option", "8. Trier par Filiere", "9. Afficher la liste des etudiants");
		//printf("\n");
		printf("0. Quitter le programme \n");
      printf("Choisir une option [0-9]: \n");
		printf("Entrez votre choix \n");
			scanf("%d", &choix);
		printf("\n");
	switch (choix)
	{
	case 1:
				printf("Combien d'etudiants voulez vous enregistrer ?: ");
					scanf("%d", &lignes);
					Gestion=(G10*)malloc(lignes * sizeof(G10)); // Comprendre davantage l'allocation dynamique !
							if (Gestion==0) {
				printf("Vous ne pouvez pas enregistrer 0 etudiants !");
							return 1; 
															}
							for ( i = 0; i < lignes; i++){
									enregistrer();
																						}
					break;
	case 9:
					afficher();
					break;
		case 2:
					printf("Hello 2");
					break;
		case 3:
					printf("Hello 3");
					break;
		case 4:
					printf("Hello 4");
		case 5:
					printf("Hello 5");
					break;
		case 6:
					printf("Hello 6");
					break;
		case 7:
					printf("Hello 7");
					break;
		case 8:
					printf("Hello 8");
					break;
		case 0:
          printf("Voulez vous vraiment sortir de l'application?\n  1. Oui  2. Non \n");
          scanf("%d",&confirmation);
				if (confirmation==1)
				{
					
					printf("Au revoir !");
					break;
				} else {
goto continuation;
								}
				
		default:
			if (choix>=10)
			{
					printf(" \n ERREUR ! choisir entre [0-9] \n");
					printf("\n");
			}
						break;
	} 
	}while(choix!=0);
  
  return 0; 
  }