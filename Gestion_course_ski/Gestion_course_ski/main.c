#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <signal.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

//gestion de l'enregistrement des joueur
//gestion du temps pour la premiere manche 
// gestion abandon premier manche si temps = 0
//gestion de la deuxieme manche 
//trier par ordre croissant en fonction de l'addition des deux temps des joueurs 
//gestion abandon deuxxieme

typedef struct Skieur {
	char nom[20];
	int dossard;
	int temps;
	int temps1;
	int classement;

}skieur;

typedef struct Element {
	skieur skieurX;
	struct element* suivant;
}element;

typedef struct ListSkieur
{
	element* premier;
}listskieur;

//initialisation de la liste
listskieur* initialisation()
{
	listskieur* liste = malloc(sizeof(liste));
	element* element = malloc(sizeof(element));

	if (liste == NULL || element == NULL)
	{
		exit(EXIT_FAILURE);
	}

	element->skieurX;
	element->suivant = NULL;

	liste->premier = element;

	return liste;
}

void insertion(listskieur* liste, skieur nvSkieur)
{
	/* Création du nouvel skieur */
	element* nouveauSkieur = malloc(sizeof(*nouveauSkieur));
	if (liste == NULL || nouveauSkieur == NULL)
	{
		exit(EXIT_FAILURE);
	}
	nouveauSkieur->skieurX = nvSkieur;

	/* Insertion de l'élément au début de la liste */
	nouveauSkieur->suivant = liste->premier;
	liste->premier = nouveauSkieur;
}

//afficher les informations des skieurs avec leurs dossards et leurs temps sous la forme : nom dossard temps et classement sans afficher le dernier skieur qui est NULL
void afficherListe(listskieur* liste_fonc, int choix, int tour)
{
	if (liste_fonc == NULL)
	{
		exit(EXIT_FAILURE);
	}
	int value = 0;

	element* skieur_temp = liste_fonc->premier;
	if (skieur_temp == NULL && choix == 1) {
		printf("Aucun skieur enregistre \n");
	}
	if (tour == 1) {
		while (skieur_temp != NULL) {
				printf(CYN "Indice dans la liste : %d " RESET, value);
				printf(" Nom : | %s |, Dossard : | %d |\n", skieur_temp->skieurX.nom, skieur_temp->skieurX.dossard);
				value++;
				skieur_temp = skieur_temp->suivant;

				/*if (skieur_temp->suivant == NULL) {
					printf(RED "La liste est vide" RESET);
				}*/
			}
		}

	if (tour == 4) {
		while (skieur_temp != NULL) {
				printf(CYN "Indice dans la liste : %d " RESET, value);

				printf(" Nom : | %s |, Dossard : | %d |, Temps : | %d | \n", skieur_temp->skieurX.nom, skieur_temp->skieurX.dossard, skieur_temp->skieurX.temps);
				value++;
				skieur_temp = skieur_temp->suivant;
				/*if (skieur_temp->suivant == NULL) {
					printf(RED "La liste est vide" RESET);
				}*/

		}

	}
	if (tour == 3) {
		while (skieur_temp != NULL) {
			if (skieur_temp->skieurX.temps == 0)
			{
				printf(" Nom : | %s |, Dossard : | %d |, Temps 1 : | NA |, Temps 2 : | NA | \n", skieur_temp->skieurX.nom, skieur_temp->skieurX.dossard);
				skieur_temp = skieur_temp->suivant;
			}
			if (skieur_temp->skieurX.temps1 == 0)
			{
				printf(" Nom : | %s |, Dossard : | %d |, Temps 1 : | %d |, Temps 2 : | NA | \n", skieur_temp->skieurX.nom, skieur_temp->skieurX.dossard, skieur_temp->skieurX.temps);
				skieur_temp = skieur_temp->suivant;
			}
			
			if (skieur_temp->skieurX.temps != 0 && skieur_temp->skieurX.temps1 != 0)
			{
				printf(" Nom : | %s |, Dossard : | %d |, Temps 1 : | %d |, Temps 2 : | %d | \n", skieur_temp->skieurX.nom, skieur_temp->skieurX.dossard, skieur_temp->skieurX.temps, skieur_temp->skieurX.temps1);
				skieur_temp = skieur_temp->suivant;
			}

	}
	printf("--------------------------------------------------\n");

		}
	printf("\n");
}



// Fonction qui demande de renseigner les informations d'un skieur et qui renvoie un skieur avec ces informations	
skieur* cree_skieur() {
	skieur* skieur = malloc(sizeof(*skieur));
	skieur->dossard = GénérerDossard();
	printf("Veuillez renseigner le nom du skieur : ");
	scanf_s("%s", &skieur->nom, 20);
	printf("Voici le dossard |%d| assigne au skieur  \n", skieur->dossard);
	return skieur;

}

int GénérerDossard(){
// Générer un dossard aléatoire entre 1 et 100 inclus
	return rand() % (100 - 1 + 1) + 1;
}

//fonction qui affiche le classement du premier tour en triant la liste en fonction du temps dans l'order croissant 




//foncion annimation terminal 
void game_annime(listskieur* liste_fonc, int choix, int tour) {
	listskieur* liste_temp = liste_fonc;
	//affichage des jouers qui participe a la course sous forme de tableau
	printf("--------------------------------------------------\n");
	printf("Voici les skieurs qui participent a la course :\n");
	afficherListe(liste_temp, choix, tour);
	printf("--------------------------------------------------\n");
	//affichage du compte a rebours
	printf("Le compte a rebours commence !\n");
	printf("--------------------------------------------------\n");
	//annimation ascii art dynamique
	printf("3\n");
	Sleep(1000);
	printf("2\n");
	Sleep(1000);
	printf("1\n");
	Sleep(1000);
	printf("GO !\n");
	//indiquer que la course com mence
	printf("La course commence !\n");
	printf("--------------------------------------------------\n");
	printf("La course est terminée !\n");
	Sleep(1000);
	system("cls");
}

//visualisation des joueur enregister dans la liste
void visualisation_joueur(listskieur* liste_fonc, int choix, int tour) {
	while (choix != 9) {
		afficherListe(liste_fonc, choix, tour);
		//demander si il a fini de regarder la liste
		printf("Avez vous fini de regarder la liste ?\n");

		printf("9 : Oui\n");
		printf("10 : Non\n");

		printf("\nVotre choix :  ");
		scanf_s("%d", &choix);
		system("cls");
	}
}

//enregistrement des skieurs dans la liste
void enregistrement_skieur(listskieur* liste_fonc, int choix) {
	int nbskieurTemp = 0;
	int nbskieur;
	printf("Combien de skieur voulez vous ajouter ? : ");
	scanf_s("%d", &nbskieur);
	while (nbskieurTemp != nbskieur) {

		insertion(liste_fonc, *cree_skieur());
		nbskieurTemp++;
	}
	system("cls");
}


//menu de sélection des actions
void menu(int etat) {
	if (etat == 0) {
		printf("----------Enregistrement des skieurs et assignation des dossarts-------------- \n");
		printf("Que voulez vous faire ?\n\n");
		printf("1 : Ajouter un skieur \n");
		printf("------------------------------------------------------- \n");
		printf("10 : Quitter\n");
	}
	if (etat == 6) {
		printf("Que voulez vous faire ?\n\n");
		printf("2 : Afficher la liste des skieurs\n");
		printf("3 : Lancer la course\n");
		printf("------------------------------------------------------- \n");
		printf("10 : Quitter\n");
	}
	if (etat == 7) {
		printf("Que voulez vous faire ?\n\n");
		printf("3 : Lancer la course\n");
		printf("------------------------------------------------------- \n");
		printf("10 : Quitter\n");
	}
	if (etat == 1) {
		printf("----------La premiere manche est fini-------------- \n");
		printf("5 : Afficher le classement du premier tour \n");
		printf("------------------------------------------------------- \n");
		printf("10 : Quitter\n");
	}
	if (etat == 5) {
		printf("7 : Deuxieme manche \n");
		printf("------------------------------------------------------- \n");
		printf("10 : Quitter\n");
	}
	if (etat == 2) {
		printf("----------Deuxieme tour -------------- \n");
		printf("Que voulez vous faire ?\n\n");
		printf("2 : Afficher la liste des skieurs qui participe au deuxieme tour \n");
		printf("3 : Lancer la course\n");
		printf("------------------------------------------------------- \n");
		printf("10 : Quitter\n");
	}
	if (etat == 9) {
		printf("----------Deuxieme tour -------------- \n");
		printf("Que voulez vous faire ?\n\n");
		printf("3 : Lancer la course\n");
		printf("------------------------------------------------------- \n");
		printf("10 : Quitter\n");
	}
	if (etat == 3) {
		printf("----------Deuxieme tour est fini -------------- \n");
		printf("5 : Afficher le classement du deuxieme tour \n");
		printf("-------------------FINI------------------------------------ \n");
		printf("10 : Quitter\n");
		

	}
	if (etat == 4) {
		printf("----------Deuxieme tour est fini -------------- \n");
		printf("La course est fini voici le classement final \n");
		printf("------------------------------------------------------- \n");
		printf("10 : Quitter\n");
	}



}

//enregistrement du temps de chaque jouer dans la liste
void enregistrement_temps(listskieur* liste_fonc, listskieur* skieur_temp, int tour) {

	if (tour == 1) {
		while (liste_fonc->premier != NULL) {
			printf("Veuillez renseigner le temps du skieur %s : ", liste_fonc->premier->skieurX.nom);
			scanf_s("%d", &liste_fonc->premier->skieurX.temps);
			insertion(skieur_temp, liste_fonc->premier->skieurX);
			liste_fonc->premier = liste_fonc->premier->suivant;
		}
	}
	if (tour == 3) {
		while (liste_fonc->premier != NULL) {
			printf("Veuillez renseigner le temps du skieur %s : ", liste_fonc->premier->skieurX.nom);
			scanf_s("%d", &liste_fonc->premier->skieurX.temps1);
			insertion(skieur_temp, liste_fonc->premier->skieurX);
			liste_fonc->premier = liste_fonc->premier->suivant;
		}
	}

	system("cls");

}



//afficher le classement du premier tour en triant la liste en fonction du temps dans l'order croissant
void afficher_classement(listskieur* liste, listskieur* listeabandon, listskieur* classementliste, int choix, int tour) {
	element* skieur_temp = liste->premier;
	
	printf("Voici le classement du premier tour : \n");

	if (skieur_temp == NULL) {
		printf("ça buuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuug \n");
	}

	if (tour == 2) {
		while (skieur_temp != NULL) {
			if (skieur_temp->skieurX.temps != 0) {
				insertion(classementliste, skieur_temp->skieurX);
				printf(CYN "Qualification de :     | %s |, | %d | \n" RESET, classementliste->premier->skieurX.nom, classementliste->premier->skieurX.temps);

				skieur_temp = skieur_temp->suivant;
			}
			else {

				insertion(listeabandon, skieur_temp->skieurX);
				printf(RED "Abandon de :           | %s | | NA |  \n" RESET, listeabandon->premier->skieurX.nom);

				skieur_temp = skieur_temp->suivant;
			}
		}



	}
	if (tour == 3) {
		while (skieur_temp != NULL) {
			if (skieur_temp->skieurX.temps1 != 0) {
				insertion(classementliste, skieur_temp->skieurX);
				printf("Qualification de :     | %s |, | %d |, | %d |\n", classementliste->premier->skieurX.nom, listeabandon->premier->skieurX.temps, listeabandon->premier->skieurX.temps1);

				skieur_temp = skieur_temp->suivant;
			}
			else {
				insertion(listeabandon, skieur_temp->skieurX);
				printf("Abandon de :           | %s |, | %d |, |1 NA | \n", listeabandon->premier->skieurX.nom, listeabandon->premier->skieurX.temps);

				skieur_temp = skieur_temp->suivant;
			}
		}



	}
	if (tour == 4) {
		while (skieur_temp != NULL) {
			if (skieur_temp->skieurX.temps1 != 0) {
				insertion(classementliste, skieur_temp->skieurX);
				printf("je suis la ");
				printf("Qualification de :     | %s |, | %d |, | %d |, | %d |\n", classementliste->premier->skieurX.nom, listeabandon->premier->skieurX.temps, listeabandon->premier->skieurX.temps1);

				skieur_temp = skieur_temp->suivant;
			}
			else {
				insertion(listeabandon, skieur_temp->skieurX);
				printf("Abandon de :           | %s |, | %d |, | %d |, | NA | \n", listeabandon->premier->skieurX.nom, listeabandon->premier->skieurX.temps);

				skieur_temp = skieur_temp->suivant;
			}
		}



	}
}


void insererSkieurParTemps(element** head_ref, element* new_element) {
	element* current;

	if (*head_ref == NULL || new_element->skieurX.temps < (*head_ref)->skieurX.temps) {
		new_element->suivant = *head_ref;
		*head_ref = new_element;
	}
	else {
		current = *head_ref;
		while (current->suivant != NULL && current->skieurX.temps < new_element->skieurX.temps) {
			current = current->suivant;
		}
		new_element->suivant = current->suivant;
		current->suivant = new_element;
	}
}

void trierListeParTemps(listskieur* liste) {
	if (liste->premier == NULL || liste->premier->suivant == NULL) {
		return; // La liste est déjà triée ou vide
	}

	element* sorted = NULL;
	element* current = liste->premier;

	while (current != NULL) {
		element* next = current->suivant;
		insererSkieurParTemps(&sorted, current);
		current = next;
	}

	liste->premier = sorted;
}

//liberer la liste
void libererListe(listskieur* liste) {
	element* courant = liste->premier;
	element* suivant;

	while (courant != NULL) {
		suivant = courant->suivant;
		free(courant);
		courant = suivant;
	}

	liste->premier = NULL;
}


int main() {
	srand(time(NULL));


	// Déclaration des variables

	int choix;
	int var = 0;
	int tour = 1;

	bool etat = true; //variable pour la boucle while

	listskieur* liste = initialisation();
	listskieur* listeFirst = initialisation();
	listskieur* listeSecond = initialisation();
	listskieur* listeSeconde = initialisation();
	listskieur* listeAbandon = initialisation();
	liste->premier = NULL;
	listeFirst->premier = NULL;
	listeSecond->premier = NULL;
	listeAbandon->premier = NULL;
	listeSeconde->premier = NULL;
	
	//libererListe(liste);
	//libererListe(listeFirst);
	//libererListe(listeSecond);
	//libererListe(listeAbandon);

	while (etat) {
		//menu de sélection des actions
		menu(var);
		printf("\nVotre choix :  ");

		scanf_s("%d", &choix);
		system("cls");

		switch (choix) {

		case 1:

			//enregistrement des skieursZ dans la liste
			//libererListe(liste);
			enregistrement_skieur(liste, choix);
			var = 6;
			
			break;
			
		case 2:
			//affichage de la liste des skieurs
			if (tour == 1){
				printf("Liste du premier tour \n");
				visualisation_joueur(liste, choix, tour);
				//visualisation_joueur(liste, choix, tour);
				var = 7;
			}
			if (tour == 3) {
				printf("Liste du second tour \n");
				visualisation_joueur(listeSecond, choix, tour);
				var = 9;
			}
			
			if (tour == 4) {
				printf("Liste fin des deux tours \n");
				visualisation_joueur(liste, choix, tour);
				var = 3;

			}


			break;
		case 3:

			//lancement de la course
			
			if (tour == 1) {
				printf(RED "--------------Voici la liste des skieurs qui participe au premier tour :----------------------- \n" RESET);
				game_annime(liste, choix, tour);
				var = 1;
				printf("Veuillez renseigner le temps de chaque skieur : \n");
				enregistrement_temps(liste, listeFirst, tour);
				libererListe(liste);
				tour = 2;
				
			}

			if (tour == 3) {
				printf(RED "--------------Voici la liste des skieurs qui participe au deuxieme tour  :----------------------- \n" RESET);
				game_annime(listeSecond, choix, tour);
				printf("Veuillez renseigner le temps de chaque skieur : \n");
				enregistrement_temps(listeSecond, listeSeconde, tour);
				//libererListe(listeSeconde);
				var = 3;
				tour = 4;
				//visualiser toute les liste 
				printf("Liste \n");
				visualisation_joueur(liste, choix, tour);
				printf("Liste First \n");
				visualisation_joueur(listeFirst, choix, tour);
				printf("Liste Second \n");
				visualisation_joueur(listeSecond, choix, tour);
				printf("Liste Seconde \n");
				visualisation_joueur(listeSeconde, choix, tour);
				printf("Liste Abandon \n");
				visualisation_joueur(listeAbandon, choix, tour);


			}
			break;
			
		case 5:
			//afficher le classement du premier tour en triant la liste en fonction du temps dans l'order croissant
			printf("-----------------------------------------\n");
			//Classement des joueurs qui ont fini la 
			printf(RED "--------------Voici la liste des skieurs qui sont qualifier et qui ont abandone :----------------------- \n" RESET);
			if (tour == 2) {
				afficher_classement(listeFirst, listeAbandon, listeSecond, choix, tour);
				//libererListe(listeFirst);
				//trierListeParTemps(listeSecond);
				printf("\n");
				printf("Premiere manche termine \n");
				printf("\n");
				var = 5;
			}

			if (tour == 4) {
				//visualiser toute les liste 
				printf("Liste \n");
				visualisation_joueur(liste, choix, tour);
				printf("Liste First \n");
				visualisation_joueur(listeFirst, choix, tour);
				printf("Liste Second \n");
				visualisation_joueur(listeSecond, choix, tour);
				printf("Liste Seconde \n");
				visualisation_joueur(listeSeconde, choix, tour);
				printf("Liste Abandon \n");
				visualisation_joueur(listeAbandon, choix, tour);

				printf("Valeuuuuur de tour %d \n", tour);
				afficher_classement(listeSeconde, listeAbandon, liste, choix, tour);
				//libererListe(liste);
				printf("Deuxieme manche fini\n");
				//visualiser toute les liste 
				printf("Liste \n");
				visualisation_joueur(liste, choix, tour);
				printf("Liste First \n");
				visualisation_joueur(listeFirst, choix, tour);
				printf("Liste Second \n");
				visualisation_joueur(listeSecond, choix, tour);
				printf("Liste Seconde \n");
				visualisation_joueur(listeSeconde, choix, tour);
				printf("Liste Abandon \n");
				visualisation_joueur(listeAbandon, choix, tour);
			}
			break;

		case 7:
			//deuxieme manche 
			printf(MAG "-----------Lancement de la deuxieme manche----------------\n" RESET);
			printf("-----------------------------------------\n");
			Sleep(1000);
			choix = 3;
			var = 2;
			tour = 3;
			break;
		case 10:
			etat = false;
			break;
		default :
			printf("La saisie n'est pas valide veuillez renseigner un chiffre ");


		}
	}

	return 0;

}