#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

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
} Gestion_etudiants;
Gestion_etudiants* Gestion; // Revoir aussi les pointeurs !
  char mat[25], nomrecherche[30];
  int confirmation,j=0,lignes,i,d=0,m,trouve,anneeactuelle,anneenaissance,age;
 
void liste(){
    printf("%-05s %-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s \n", "Num.", "Matricule",  "Noms",  "Prenoms",  "date_Naiss.",  "Sexe",  "Departement",  "Filiere",  "Region D'origine");
	    printf("\n");
		for ( i = 0; i < j; i++)
		{
      printf("%-05d %-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", i+1, Gestion[i].matricule, Gestion[i].nom, Gestion[i].prenom, Gestion[i].date_naiss, Gestion[i].sexe, Gestion[i].departement, Gestion[i].filiere, Gestion[i].region_origine);

		}
}  

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
		if (j==0){
            printf("AUCUN ETUDIANT ENREGISTRE ! \n");
	        printf("\n");
            return;
		}
        printf("\n Liste des etudiants inscrits: \n");
        liste();
}
void supprimer(){

    printf("Entrer le matricule de l'etudiant a supprimer : ");
    scanf("%s", &mat);

    for (i= 0; i < j; i++) {
        if (strcmp(Gestion[i].matricule, mat)==0) {
            trouve=1;
            for (int n = i; n < j - 1; n++) {
                Gestion[n] = Gestion[n + 1];
            }
            j--;
            break;
        }
    }

    if (trouve){
        printf("Etudiant supprimer avec succes.\n");
    } else{
        printf("\nMatricule non trouve: suppression impossible\n");
    } 
}  
void modifier(){
    
    printf("Entrer le matricule de l'etudiant a modifier : ");
    scanf("%s", &mat);

    for (i = 0; i < j; i++) {
        if (strcmp(Gestion[i].matricule, mat)==0) {
            trouve=1;
            printf("Entrer les nouvelles informations de l'etudiant\n");

            printf("Nouveau nom : ");
            scanf("%s", Gestion[i].nom);

            printf("Nouveau prenom : ");
            scanf("%s", Gestion[i].prenom);

            printf("nouvelle date de naissance : ");
            scanf("%s", Gestion[i].date_naiss);
            printf("Nouveau sexe : ");
            scanf("%s", Gestion[i].sexe);
            printf("Nouveau departement : ");
            scanf("%s", Gestion[i].departement);
            printf("Nouvelle filiere : ");
            scanf("%s", Gestion[i].filiere);
            printf("Nouvelle region d'origine : ");
            scanf("%s", Gestion[i].region_origine);
            break;
        }
    }
    if(trouve){
        printf("Information modifiees avec succes.\n");
    } else{
        printf("\nMatricule non trouve: modification impossible");

    }
}
void calculeage(){

    printf("entrer l'annne de naissance dudit etudiant:\n");
    scanf("%d",&anneenaissance);
    printf("entrer l'annne actuelle:\n");
    scanf("%d",&anneeactuelle);
    printf("entrer le matricule de l'etudiant a calculer son age\n");
    scanf("%s", &mat);
    for (i=0; i<j; i++){
        if(strcmp(Gestion[i].matricule, mat)==0){
            trouve=1;
            age=anneeactuelle-anneenaissance;
        }
            printf("L'age de cet etudiant est : %d ans\n", age);
    }
    if(!trouve){
        printf("\nMatricule non trouve: calcule de l'age impossible");
    }
}
void trialphabetique(){
        Gestion_etudiants temp;
    for (i = 0; i < j - 1; i++) {
        for ( int n = i + 1; n < j; n++) {
            if (strcmp(Gestion[i].nom, Gestion[n].nom) > 0 || (strcmp(Gestion[i].nom, Gestion[n].nom) == 0 && strcmp(Gestion[i].prenom, Gestion[n].prenom) > 0 )) {
                temp = Gestion[i];
                Gestion[i] = Gestion[n];
                Gestion[n] = temp;
            }
        }
    }
    printf("Liste des etudiants tries par ordre alphabetique :\n");
    liste();
}
void rechercheparmatricule(){

    printf("entrer le matricule de l'etudiant que vous voulez rechercher\n");
    scanf("%s", &mat);
    for(i = 0; i < j; i++) {
            if (strcmp(Gestion[i].matricule, mat) == 0) {
                trouve = 1;
                printf("\nEtudiant trouve :\n");
                liste();
                break;
           }
    }
    if(!trouve){
        printf("Aucun etudiant ne correspond a ce matricule : Veuillez reessayer!");
    }
}  
void triparFiliere(){
    Gestion_etudiants temp;
    for (i = 0; i < j - 1; i++) {
        for ( int n = i + 1; n < j; n++) {
            if (strcmp(Gestion[i].filiere, Gestion[n].filiere) > 0 || (strcmp(Gestion[i].filiere, Gestion[n].filiere) == 0 && strcmp(Gestion[i].nom, Gestion[n].nom) > 0) || (strcmp(Gestion[i].filiere, Gestion[n].filiere) == 0 && strcmp(Gestion[i].nom, Gestion[n].nom) == 0 && strcmp(Gestion[i].prenom, Gestion[n].prenom) > 0)) {
                temp = Gestion[i];
                Gestion[i] = Gestion[n];
                Gestion[n] = temp;
           }
       }
    }
    printf("\nListe des etudiants tries par filiere :\n");
    liste();
}
void rechercheDichotomique(){
    Gestion_etudiants temp; int f=j-1;
    for (i = 0; i < j - 1; i++) {
        for ( int n = i + 1; n < j; n++) {
            if (strcmp(Gestion[i].nom, Gestion[n].nom) > 0){
                temp = Gestion[i];
                Gestion[i] = Gestion[n];
                Gestion[n] = temp;
            }
        } 
    }
    printf("entrer le nom de l'etudiant que vous voulez rechercher:\n");
    scanf("%s", &nomrecherche);
    while(d<=f){
        m=(d+f)/2;
        if(strcmp(Gestion[m].nom,nomrecherche)==0){
            trouve=1;
            printf("\nEtudiant trouve\n");
            liste();
            break;
        } else if(strcmp(Gestion[m].nom,nomrecherche)>0){
                f=m-1;
            } else {
                d=m+1;
            }
        }
        if(!trouve){
            printf("\nNom non trouve\n");
        }
} 
void affichertitre(const char *titre){
    int longueur=strlen(titre);
    int largeur=longueur+4;
        printf("+--");
    for(int i=0;i<largeur;i++)
        printf("#");
        printf("-+\n");
        printf("|  \033[1;4;34m%s\033[0m  |\n", titre);
        printf("--+");
        for(int i=0;i<largeur;i++)
        printf("#");
        printf("-+\n");
}

  int main(){
    affichertitre("MENU DE GESTION");

  int choix;
	do {
continuation:
        printf("\n");
		printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", "\033[34m1. Enregistrer\033[0m", "\033[32m2. Modifier\033[0m", "\033[33m3. Recherher (matricule)\033[0m" , "\033[31m4. Supprimer\033[0m", "\033[35m5. Trier (ordre Alphabetique)\033[0m", "\033[38;5;94m6. Rechercher (Dichotomie)\033[0m", "7. Calculer age etudiant", "\033[30m8. Trier par Filiere\033[0m", "\033[38;5;208m9. Afficher la liste des etudiants\033[0m");
		printf("\033[31m0. Quitter le programme\033[0m\n");
      printf("Choisir une option [0-9]: \n");
		printf("Entrez votre choix \n");
			scanf("%d", &choix);
		printf("\n");
	switch (choix)
	{
	case 1:
				printf("Combien d'etudiants voulez vous enregistrer ?: ");
					scanf("%d", &lignes);
					Gestion=(Gestion_etudiants*)malloc(lignes * sizeof(Gestion_etudiants)); // Comprendre davantage l'allocation dynamique !
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
					modifier();
					break;
		case 3:
					rechercheparmatricule();
					break;
		case 4:
					supprimer();
                    break;
		case 5:
					trialphabetique();
					break;
		case 6:
					rechercheDichotomique();
					break;
		case 7:
					calculeage();
					break;
		case 8:
					triparFiliere();
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
  
